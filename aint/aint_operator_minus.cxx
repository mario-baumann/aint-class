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
// aint_operator_minus.cxx (minus operator(s))

#include "impl.hxx"

namespace astd {

const aint aint::operator-() {
	if (this->impl_->data_.size() != 1 || this->impl_->data_[0] != 0) {
	    this->impl_->positive_ = !(this->impl_->positive_);
	}
	return(*this);
}
const aint aint::operator-(const aint& rhs) const {
    aint res;
    this->impl_->operatorPlus(*this, rhs, res, true);
    return(res);
}
const aint aint::operator-(const int rhs) const {
    aint res;
    this->impl_->operatorPlus(*this, aint(rhs), res, true);
    return(res);
}
const aint aint::operator-(const long int rhs) const {
    aint res;
    this->impl_->operatorPlus(*this, aint(rhs), res, true);
    return(res);
}
const aint aint::operator-(const long long int rhs) const {
    aint res;
    this->impl_->operatorPlus(*this, aint(rhs), res, true);
    return(res);
}
const aint aint::operator-(const unsigned int rhs) const {
    aint res;
    this->impl_->operatorPlus(*this, aint(rhs), res, true);
    return(res);
}
const aint aint::operator-(const unsigned long int rhs) const {
    aint res;
    this->impl_->operatorPlus(*this, aint(rhs), res, true);
    return(res);
}
const aint aint::operator-(const unsigned long long int rhs) const {
    aint res;
    this->impl_->operatorPlus(*this, aint(rhs), res, true);
    return(res);
}
const aint operator-(const int lhs, const aint& rhs) {
    aint res;
    rhs.impl_->operatorPlus(aint(lhs), rhs, res, true);
    return(res);
}
const aint operator-(const long int lhs, const aint& rhs) {
    aint res;
    rhs.impl_->operatorPlus(aint(lhs), rhs, res, true);
    return(res);
}
const aint operator-(const long long int lhs, const aint& rhs) {
    aint res;
    rhs.impl_->operatorPlus(aint(lhs), rhs, res, true);
    return(res);
}
const aint operator-(const unsigned int lhs, const aint& rhs) {
    aint res;
    rhs.impl_->operatorPlus(aint(lhs), rhs, res, true);
    return(res);
}
const aint operator-(const unsigned long int lhs, const aint& rhs) {
    aint res;
    rhs.impl_->operatorPlus(aint(lhs), rhs, res, true);
    return(res);
}
const aint operator-(const unsigned long long int lhs, const aint& rhs) {
    aint res;
    rhs.impl_->operatorPlus(aint(lhs), rhs, res, true);
    return(res);
}

} // end of namespace astd
