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
// impl_operator.cxx (helper functions for operators)

#include "impl.hxx"

namespace astd {

void aint::impl::clear() {
    this->data_.clear();
    this->positive_ = true;
}

void aint::impl::removeLeadingZeros() {
    data& d = this->data_;
    size_t j = d.size() - 1;
    while (j > 0 && d[j] == 0) {
        --j;
    }
    if (j + 1 < d.size()) {
        d.resize(j + 1);
    }
}

void aint::impl::resizeAndZeroise(size_t size) {
    data& d = this->data_;
    d.resize(size);
    std::fill(d.begin(), d.end(), 0);
}

void aint::impl::makeZeroPositive() {
    if (!this->positive_ && this->data_.size() == 1 && this->data_[0] == 0) {
        this->positive_ = true;
    }
}

aint aint::impl::operatorPower(const aint& base, const aint& exp) const {
    // compute base^exp with "exponentiation by squaring"
    // see also http://en.wikipedia.org/wiki/Exponentiation_by_squaring
    if (exp < 0) {
        return(aint(0));
    } else if (exp == 0) {
        return(aint(1));
    } else if (exp == 1) {
        return(base);
    } else if (exp.even()) {
        return(aint::impl::operatorPower(base * base, exp / 2));
    } else {
        return(base * aint::impl::operatorPower(base * base, (exp - 1)/ 2));
    }
}

} // end of namespace astd
