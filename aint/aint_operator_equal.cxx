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
// aint_operator_equal.cxx (equal operators)

#include "impl.hxx"

namespace astd {

bool aint::operator==(const aint& rhs) const {
    if (this->impl_->positive_ != rhs.impl_->positive_) {
	    return(false);
    }
    size_t LS = this->impl_->data_.size();
    size_t RS = rhs.impl_->data_.size();
    if (LS != RS) {
	    return(false);
    }
    // LS == RS
    for (size_t j = 0; j < LS; ++j) {
        if (this->impl_->data_[j] != rhs.impl_->data_[j]) {
            return(false);
        }
    }
    return(true);
}
bool aint::operator==(const int rhs) const {
	return(this->impl_->operatorEqLL(*this, rhs));
}
bool aint::operator==(const long int rhs) const {
	return(this->impl_->operatorEqLL(*this, rhs));
}
bool aint::operator==(const long long int rhs) const {
	return(this->impl_->operatorEqLL(*this, rhs));
}
bool aint::operator==(const unsigned int rhs) const {
	return(this->impl_->operatorEqULL(*this, rhs));
}
bool aint::operator==(const unsigned long int rhs) const {
	return(this->impl_->operatorEqULL(*this, rhs));
}
bool aint::operator==(const unsigned long long int rhs) const {
	return(this->impl_->operatorEqULL(*this, rhs));
}
bool operator==(const int lhs, const aint& rhs) {
	return(rhs.impl_->operatorEqLL(rhs, lhs));
}
bool operator==(const long int lhs, const aint& rhs) {
	return(rhs.impl_->operatorEqLL(rhs, lhs));
}
bool operator==(const long long int lhs, const aint& rhs) {
	return(rhs.impl_->operatorEqLL(rhs, lhs));
}
bool operator==(const unsigned int lhs, const aint& rhs) {
	return(rhs.impl_->operatorEqULL(rhs, lhs));
}
bool operator==(const unsigned long int lhs, const aint& rhs) {
	return(rhs.impl_->operatorEqULL(rhs, lhs));
}
bool operator==(const unsigned long long int lhs, const aint& rhs) {
	return(rhs.impl_->operatorEqULL(rhs, lhs));
}

} // end of namespace astd
