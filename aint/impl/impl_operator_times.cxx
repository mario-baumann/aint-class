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

void aint::impl::operatorTimesSingle( const aint& lhs, const singleComp rhs, aint& res) const {
    // compute res = lhs * rhs (where rhs is a singleComp)
    bool vPositive = (rhs < 0 ? false : true);
    data& u = lhs.impl_->data_;
    singleComp v = (vPositive ? rhs : (-rhs));
    data& w = res.impl_->data_;
    size_t m = u.size();
    res.impl_->resizeAndZeroise(m + 1);
    doubleComp carry = 0;
    for (int i = 0; i < m; ++i) {
        // promote the first operand to doubleComp
        // to ensure doubleComp-arithmetic is used
        doubleComp tmp = static_cast<doubleComp>(u[i]) * v + carry;
        w[i]  = tmp % C_SINGLE_COMP_MAX_P1;
        carry = tmp / C_SINGLE_COMP_MAX_P1;
    }
    w[m] = carry;
    res.impl_->removeLeadingZeros();
    // set sign of result
    res.impl_->positive_ = (lhs.impl_->positive_ == vPositive ? true : false);
}

void aint::impl::operatorTimes( const aint& lhs, const aint& rhs, aint& res) const {
    // compute res = lhs * rhs
    data& v = rhs.impl_->data_;
    size_t n = v.size();
    if (n == 1) {
        // use operatorTimesSgl from above
        this->operatorTimesSingle(lhs, (rhs.impl_->positive_ ? v[0] : -v[0]), res);
        return;
    }
    data& u = lhs.impl_->data_;
    data& w = res.impl_->data_;
    size_t m = u.size();
    // use D.Knuth's algorithm M from TAoCP, Vol 2, 4.3.1;
    res.impl_->resizeAndZeroise(m + n);
    // skip the 'for (int i = 0; i < m; ++i) { w[i] = 0; }' in algorithm M, because every entry in w is set to 0 by resizeAndZeroise
    for (int j = 0; j < n; ++j) {
        doubleComp carry = 0;
        for (int i = 0; i < m; ++i) {
            // promote the first operand to doubleComp
            // to ensure doubleComp-arithmetic is used
            doubleComp tmp = static_cast<doubleComp>(u[i]) * v[j] + w[i + j] + carry;
            w[i + j] = tmp % C_SINGLE_COMP_MAX_P1;
            carry    = tmp / C_SINGLE_COMP_MAX_P1;
        }
        w[m + j] = carry;
    }
    res.impl_->removeLeadingZeros();
    // set sign of result
    res.impl_->positive_ = (lhs.impl_->positive_ == rhs.impl_->positive_ ? true : false);
}

} // end of namespace astd
