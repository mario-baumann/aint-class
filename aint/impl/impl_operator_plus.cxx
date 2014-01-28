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
// impl_operator_plus.cxx (helper functions for operator plus and opeator minus)

#include "impl.hxx"

namespace astd {

void aint::impl::operatorPlusAdd(const aint& lhs, const aint& rhs, aint& res) const {
    // compute res = lhs + rhs, where abs(rhs) <= abs(lhs)
    data& u = lhs.impl_->data_;
    data& v = rhs.impl_->data_;
    data& w = res.impl_->data_;
    size_t m = u.size();
    size_t n = v.size();
    res.impl_->resizeAndZeroise(m + 1);
    doubleComp carry = 0;
    for (int j = 0; j < m; ++j) {
        // promote the first operand to doubleComp
        // to ensure doubleComp-arithmetic is used
        doubleComp tmp = static_cast<doubleComp>(u[j]) + ( j < n ? v[j] : 0 ) + carry;
        w[j]  = tmp % C_SINGLE_COMP_MAX_P1;
        carry = tmp / C_SINGLE_COMP_MAX_P1;
    }
    if (carry) {
        w[m] = carry;
    }
    res.impl_->removeLeadingZeros();
}

void aint::impl::operatorPlusSub(const aint& lhs, const aint& rhs, aint& res) const {
    // compute res = lhs - rhs, where abs(rhs) <= abs(lhs)
    data& u = lhs.impl_->data_;
    data& v = rhs.impl_->data_;
    data& w = res.impl_->data_;
    size_t m = u.size();
    size_t n = v.size();
    res.impl_->resizeAndZeroise(m);
    doubleComp borrow = 0;
    for (int j = 0; j < m; ++j) {
        // promote the first operand to doubleComp
        // to ensure doubleComp-arithmetic is used
        doubleComp tmp = static_cast<doubleComp>(u[j]) - ( j < n ? v[j] : 0 ) - borrow;
        if (tmp < 0) {
            // borrow from next element
            borrow = 1;
            tmp += C_SINGLE_COMP_MAX_P1;
        } else {
            borrow = 0;
        }
        w[j] = tmp;
    }
    res.impl_->removeLeadingZeros();
}

bool aint::impl::operatorPlusChk(const aint& lhs, const aint& rhs) const {
    // if abs(rhs) <= abs(lhs) then return true, otherwise return false
    size_t m = lhs.impl_->data_.size();
    size_t n = rhs.impl_->data_.size();
    if (n < m) {
        return(true);
    } else if (m < n) {
        return(false);
    } else {
        // m == n
        // use operator< to check if lhs < rhs OR rhs <= lhs
        if (this->operatorLtAbs(lhs, rhs)) {
            return(false);
        }
    }
    return(true);
}

void aint::impl::operatorPlus(const aint& lhs, const aint& rhs, aint& res, bool minusSwitch) const {
    typedef void (aint::impl::*Helper)(const aint& lhs, const aint& rhs, aint& res) const;
    struct entry {
        Helper helper;
        bool lhs_rhs;
        bool res_positive;
    };
    const struct entry table[8 + 8] = {
        //
        // +-- helper                                          +-- operator
        // |                            +-- lhs_rhs            |   +-- sign lhs
        // |                            |      + res_positive  |   |   +-- sign rhs
        // |                            |      |               |   |   |   +-- sign result
        // |                            |      |               |   |   |   |   +-- sign ( abs(lhs) - abs(rhs) ),
        // |                            |      |               |   |   |   |   |   ( if < 0, switch arguments )
        // | Plus table                 |      |               |   |   |   |   |   +-- subroutine with arguments
        // |                            |      |               |   |   |   |   |   |   A = operatorPlusAdd
        // |                            |      |               |   |   |   |   |   |   S = operatorPlusSub
        // |                            |      |               |   |   |   |   |   |        +-- example
        // |                            |      |               |   |   |   |   |   |        |
        { &aint::impl::operatorPlusAdd, true,  true  },    //  +   +   +   +   +   A(L,R)   L=4, R=1 =>   4  +   1  =  5
        { &aint::impl::operatorPlusAdd, false, true  },    //  +   +   +   +   -   A(R,L)   L=1, R=4 =>   1  +   4  =  5
        { &aint::impl::operatorPlusSub, true,  true  },    //  +   +   -   +   +   S(L,R)   L=4, R=1 =>   4  + (-1) =  3
        { &aint::impl::operatorPlusSub, false, false },    //  +   +   -   -   -   S(R,L)   L=1, R=4 =>   1  + (-4) = -3
        { &aint::impl::operatorPlusSub, true,  false },    //  +   -   +   -   +   S(L,R)   L=4, R=1 => (-4) +   1  = -3
        { &aint::impl::operatorPlusSub, false, true  },    //  +   -   +   +   -   S(R,L)   L=1, R=4 => (-1) +   4  =  3
        { &aint::impl::operatorPlusAdd, true,  false },    //  +   -   -   -   +   A(L,R)   L=4, R=1 => (-4) + (-1) = -5
        { &aint::impl::operatorPlusAdd, false, false },    //  +   -   -   -   -   A(R,L)   L=1, R=4 => (-1) + (-4) = -5
        // |                            |      |               |   |   |   |   |   |        |
        // | Minus table                |      |               |   |   |   |   |   |        |
        // | (MinusSwitch==true)        |      |               |   |   |   |   |   |        |
        // |                            |      |               |   |   |   |   |   |        |
        { &aint::impl::operatorPlusSub, true,  true  },    //  -   +   +   +   +   S(L,R)   L=4, R=1 =>   4  -   1  =  3
        { &aint::impl::operatorPlusSub, false, false },    //  -   +   +   -   -   S(R,L)   L=1, R=4 =>   1  -   4  = -3
        { &aint::impl::operatorPlusAdd, true,  true  },    //  -   +   -   +   +   A(L,R)   L=4, R=1 =>   4  - (-1) =  5
        { &aint::impl::operatorPlusAdd, false, true  },    //  -   +   -   +   -   A(R,L)   L=1, R=4 =>   1  - (-4) =  5
        { &aint::impl::operatorPlusAdd, true,  false },    //  -   -   +   -   +   A(L,R)   L=4, R=1 => (-4) -   1  = -5
        { &aint::impl::operatorPlusAdd, false, false },    //  -   -   +   -   -   A(R,L)   L=1, R=4 => (-1) -   4  = -5
        { &aint::impl::operatorPlusSub, true,  false },    //  -   -   -   -   +   S(L,R)   L=4, R=1 => (-4) - (-1) = -3
        { &aint::impl::operatorPlusSub, false, true  },    //  -   -   -   +   -   S(R,L)   L=1, R=4 => (-1) - (-4) =  3
        // |                            |      |                           |   |   |
        // |                            |      |                           |   |   |
        // |                            |      +-----------<---------------+   |   |
        // |                            +-----------------<--------------------+   |
        // +---------------------------------------------<-------------------------+
    };
    int sL = (lhs.impl_->positive_ ? 0 : 1); // sign of lhs (1 if negative, 0 otherwise)
    int sR = (rhs.impl_->positive_ ? 0 : 1); // likewise for rhs
    bool LgeR = operatorPlusChk(lhs, rhs);
    int sS = (!LgeR ? 1 : 0 );
    int id = 2 * (2 * sL + sR) + sS + (minusSwitch ? 8 : 0);
    const struct entry* e = &table[id];
    if (e->lhs_rhs) {
        ((*res.impl_).*(e->helper))(lhs, rhs, res);
    } else {
        ((*res.impl_).*(e->helper))(rhs, lhs, res);
    }
    res.impl_->positive_ = e->res_positive;
    // make sure 0 has positive sign
    res.impl_->makeZeroPositive();
}

} // end of namespace astd
