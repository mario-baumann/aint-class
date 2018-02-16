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
// aint_operator_assignment.cxx (assignment operators)

#include "impl.hxx"

namespace astd {

aint& aint::operator=(const aint& rhs) {
    if (this != &rhs) {
        *impl_ = *rhs.impl_;
    }
    return(*this);
}
aint& aint::operator=(aint&& rhs) {
    if (this != &rhs) {
        *impl_ = std::move(*rhs.impl_);
    }
    return(*this);
}
aint& aint::operator=(const char* s) {
    this->impl_->ctorC(s);
    return(*this);
}
aint& aint::operator=(const std::string& s) {
    this->impl_->ctorC(s.c_str());
    return(*this);
}
aint& aint::operator=(const int i) {
    this->impl_->ctorLL(i);
    return(*this);
}
aint& aint::operator=(const long int i) {
    this->impl_->ctorLL(i);
    return(*this);
}
aint& aint::operator=(const long long int i) {
    this->impl_->ctorLL(i);
    return(*this);
}
aint& aint::operator=(const unsigned int i) {
    this->impl_->ctorULL(i);
    return(*this);
}
aint& aint::operator=(const unsigned long int i) {
    this->impl_->ctorULL(i);
    return(*this);
}
aint& aint::operator=(const unsigned long long int i) {
    this->impl_->ctorULL(i);
    return(*this);
}

} // end of namespace astd
