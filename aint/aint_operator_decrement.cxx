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
// aint_operator_decrement.cxx (decrement operators)

#include "impl.hxx"

namespace astd {

aint& aint::operator--() {
    if (this->impl_->positive_) {
        // aint is positvie
        if (this->impl_->data_[0] == 0) {
            // handle underflow in last data segment
            this->impl_->operatorPlus(aint(*this), aint(1), *this, true);
        } else {
            this->impl_->data_[0] -= 1;
        }
    } else {
        // aint is negative
        if (this->impl_->data_[0] == this->impl_->C_SINGLE_COMP_MAX_P1 - 1) {
            // handle overflow in last data segment
            this->impl_->operatorPlus(aint(*this), aint(1), *this);
        } else {
            this->impl_->data_[0] += 1;
        }
    }
    return(*this);
}

const aint aint::operator--(int) {
    aint res(*this); // store current state
    --(*this);       // apply above operator
    return(res);     // return saved state
}

} // end of namespace astd
