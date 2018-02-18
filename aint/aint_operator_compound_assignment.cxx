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
// aint_operator_compound_assignment.cxx (compound assignment operators)

#include "impl.hxx"

namespace astd {

aint& aint::operator+=(const aint& rhs) {
    if (this != &rhs) {
        aint res;
        this->impl_->operatorPlus(*this, rhs, res);
        *this = res;
    }
    return(*this);
}
aint& aint::operator+=(const char* s) {
    aint res;
    this->impl_->operatorPlus(*this, aint(s), res);
    *this = res;
    return(*this);
}
aint& aint::operator+=(const std::string& s) {
    aint res;
    this->impl_->operatorPlus(*this, aint(s), res);
    *this = res;
    return(*this);
}
aint& aint::operator+=(const int i) {
    aint res;
    this->impl_->operatorPlus(*this, aint(i), res);
    *this = res;
    return(*this);
}
aint& aint::operator+=(const long int i) {
    aint res;
    this->impl_->operatorPlus(*this, aint(i), res);
    *this = res;
    return(*this);
}
aint& aint::operator+=(const long long int i) {
    aint res;
    this->impl_->operatorPlus(*this, aint(i), res);
    *this = res;
    return(*this);
}
aint& aint::operator+=(const unsigned int i) {
    aint res;
    this->impl_->operatorPlus(*this, aint(i), res);
    *this = res;
    return(*this);
}
aint& aint::operator+=(const unsigned long int i) {
    aint res;
    this->impl_->operatorPlus(*this, aint(i), res);
    *this = res;
    return(*this);
}
aint& aint::operator+=(const unsigned long long int i) {
    aint res;
    this->impl_->operatorPlus(*this, aint(i), res);
    *this = res;
    return(*this);
}

} // end of namespace astd
