/*
 *  This file is part of aint.
 *
 *  aint provides a C++ class for arbitrary long integers which can be
 *  used the same way as the C/C++ integer types (e.g. int or long),
 *  but has no restriction on the length (if there is enough memory).
 *  Aim of this project is to include fast integer multiplications
 *  like the Toom-Cook algorithm or the Schoenhage-Strassen algorithm.
 *  Copyright (C) 2014 Mario Baumann (mario-baumann@web.de)
 *
 *  aint is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  aint is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with aint.  If not, see <http://www.gnu.org/licenses/>.
 *
 **************************************************************************/

// arbitrary long integer
// impl_operator_times.cxx (helper functions for operator times)

#include "impl.hxx"
#include <iostream>

namespace astd {

//
// sign handling for u/v and u%v
//
// C++ 11 5.6 -4
// The binary / operator yields the quotient, and the binary % operator yields the remainder
// from the division of the first expression by the second. If the second operand of / or %
// is zero the behavior is undefined. For integral operands the / operator yields the algebraic
// quotient with any fractional part discarded;81 if the quotient a/b is representable in the
// type of the result, (u/v)*v + u%v is equal to u.
//
// => sign(u/v) = sign(u) / sign(v)
// => sign(u%v) = sign(u)
//

void aint::impl::operatorDivideSingle(const aint& lhs, const singleComp rhs, aint& quot, aint& rem) const throw(std::overflow_error) {
    // compute lhs = rhs * quot + rem   (short division => rhs is a singleComp)

    // check for division by zero
    if (rhs == 0) {
        throw std::overflow_error("Divide by zero");
    }
    bool vPositive = (rhs < 0 ? false : true);
    data& u = lhs.impl_->data_;
    singleComp v = (vPositive ? rhs : (-rhs));
    data& w = quot.impl_->data_;
    data& e = rem.impl_->data_;
    size_t m = u.size();
    quot.impl_->resizeAndZeroise(m);
    doubleComp carry = 0;
    for (int j = m - 1; j >= 0; --j) {
        doubleComp tmp = static_cast<doubleComp>(u[j]) + carry * C_SINGLE_COMP_MAX_P1;
        w[j]  = tmp / v;
        carry = tmp - static_cast<doubleComp>(w[j]) * v;
    }
    quot.impl_->removeLeadingZeros();
    quot.impl_->positive_ = (lhs.impl_->positive_ == vPositive ? true : false);
    quot.impl_->makeZeroPositive();
    e[0] = carry;
    rem.impl_->positive_ = lhs.impl_->positive_;
    rem.impl_->makeZeroPositive();
}

bool aint::impl::operatorDivideLessLeft(aint& lhs, const aint& rhs, const int p) {
    // check if lhs < rhs by working on the (>= p) left components of lhs
    data& u = lhs.impl_->data_;
    data& v = rhs.impl_->data_;
    size_t m = u.size() - p;
    size_t n = v.size();
    if (m < n) {
        return(true);
    }
    if (n < m) {
        return(false);
    }
    // m == n
    for (int j = m - 1; j >= 0; --j) {
        if (u[p + j] < v[j]) {
            return(true);
        }
        if (v[j] < u[p + j]) {
            return(false);
        }
    }
    return(false);
}

void aint::impl::operatorDivideMinusLeft(aint& lhs, const aint& rhs, const int p) {
    // compute lhs = lhs - rhs by working on the (>= p) left components of lhs

    data& u = lhs.impl_->data_;
    data& v = rhs.impl_->data_;
    //size_t m = u.size();
    size_t n = v.size();

    doubleComp borrow = 0;
    for (int i = 0; i < n + 1; ++i) {
        // promote the first operand to doubleComp
        // to ensure doubleComp-arithmetic is used
        doubleComp tmp = static_cast<doubleComp>(u[p + i]) - (i < n ? v[i] : 0) - borrow;
        if (tmp < 0) {
            // borrow from next element
            borrow = 1;
            tmp += C_SINGLE_COMP_MAX_P1;
        } else {
            borrow = 0;
        }
        u[p + i] = tmp;
    }
    lhs.impl_->removeLeadingZeros();
}


void aint::impl::operatorDivide(const aint& lhs, const aint& rhs, aint& quot, aint& rem) const throw(std::overflow_error) {
    // compute lhs = rhs * quot + rem  (long division)

    // check for division by zero
    if (rhs == 0) {
        throw std::overflow_error("Divide by zero");
    }
    // handle trivial case 1
    if (this->operatorLtAbs(lhs, rhs)) {
        quot = 0;
        rem = lhs;
        return;
    }
    // handle trivial case 2
    if (lhs == rhs) {
        quot = 1;
        rem = 0;
        return;
    }
    // handle short division
    data& v0 = rhs.impl_->data_;
    size_t n = v0.size();
    if (n == 1) {
        this->operatorDivideSingle(lhs, (rhs.impl_->positive_ ? v0[0] : -v0[0]), quot, rem);
        return;
    }

    // use D.Knuth's algorithm D from TAoCP, Vol 2, 4.3.1;
    data& u0 = lhs.impl_->data_;
    data&  q = quot.impl_->data_;
    size_t m = u0.size() - n;
    quot.impl_->resizeAndZeroise(m + 1);
    rem.impl_->resizeAndZeroise(n);

    // [D1] Normalise
    singleComp b = C_SINGLE_COMP_MAX_P1;
    singleComp d = b / (v0[n - 1] + 1); // see Early errata for Volume 2 (3rd ed.)
    aint lhsd = lhs * d;
    aint rhsd = rhs * d;
    data& u = lhsd.impl_->data_;
    data& v = rhsd.impl_->data_;

    // [D2] Initialise j
    for (int j = m; j >= 0; --j) {
        // [D3] Calculate q-hat
        // promote the first operand to doubleComp to ensure doubleComp-arithmetic is used
        doubleComp tmp = static_cast<doubleComp>(u[j + n]) * b + u[j + n - 1];
        doubleComp qh = tmp / v[n - 1];
        doubleComp rh = tmp % v[n - 1];
        if ( qh >= b // see Early errata for Volume 2 (3rd ed.)
             || qh * v[n - 2] > b * rh + u[j + n - 2]) {
            qh -= 1;
            rh += v[n - 1];
        }
        // [D5] Test remainer
        if (lhsd.impl_->operatorDivideLessLeft(lhsd, rhsd * qh, j)) {
            // [D6] Add back
            qh -= 1;
        }
        // [D4] Multiply and subtract
        lhsd.impl_->operatorDivideMinusLeft(lhsd, rhsd * qh, j);
        q[j] = qh;
    }
    // [D7] loop on j

    // [D8] Unnormalise
    rem = lhsd / d;

    // finalise reminder
    rem.impl_->removeLeadingZeros();
    rem.impl_->positive_ = lhs.impl_->positive_;
    rem.impl_->makeZeroPositive();

    // finalise quotient
    quot.impl_->removeLeadingZeros();
    quot.impl_->positive_ = (lhs.impl_->positive_ == rhs.impl_->positive_ ? true : false);
    quot.impl_->makeZeroPositive();
}

} // end of namespace astd
