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
// aint_member.cxx (members)

#include "impl.hxx"
#include <iomanip>

namespace astd {

std::string aint::dump() const {
    size_t dim = this->impl_->data_.size();
    std::stringstream ss;
    ss << "dump(\n";
    ss << "  sc(w/m+1). " << (int) this->impl_->C_SINGLE_COMP_WIDTH << " / " << (int) this->impl_->C_SINGLE_COMP_MAX_P1 << "\n";
    ss << "  positive.. " << std::boolalpha << this->impl_->positive_ << "\n";
    ss << "  dim....... " << dim << "\n";
    ss << "  data...... \n";
    int j = dim;
    for (auto rit = this->impl_->data_.crbegin(); rit != this->impl_->data_.crend(); ++rit) {
        ss << "    [" << std::setw(3) << j << "]... " << (int) *rit << "\n";
        --j;
    }
    ss << ")";
    return(ss.str());
}


int aint::digits() const {
    // returns the number of digits 'd' for the current aint
    // d = digits of data[dim - 1] + C_SINGLE_COMP_WIDTH * (dim - 1)
    size_t dim = this->impl_->data_.size();
    aint::impl::singleComp t = this->impl_->data_[dim - 1];
    int d = aint::impl::C_SINGLE_COMP_WIDTH * (dim - 1);
    //
    if (t < 10) return(d + 1);
    if (t < 100) return(d + 2);
#if defined(SINGLE_8)
    return(d + 3);
#else
    if (t < 1000) return(d + 3);
    if (t < 10000) return(d + 4);
#if defined(SINGLE_16)
    return(d + 5);
#else
    if (t < 100000) return(d + 5);
    if (t < 1000000) return(d + 6);
    if (t < 10000000) return(d + 7);
    if (t < 100000000) return(d + 8);
    if (t < 1000000000) return(d + 9);
    return(d + 10);
#endif
#endif
}

bool aint::even() const {
    // returns true if the aint is even and otherwise false
    return((this->impl_->data_[0]) % 2 == 0);
}

aint aint::factorial() {
    if (*this < 100) {
        return(this->impl_->factorialIterative(*this));
    }
    return(this->impl_->factorialRecursiveProduct(1, *this));
}

aint aint::power(const aint& exp) {
    return(this->impl_->operatorPower(*this, exp));
}

aint aint::powertower(const aint& ord) {
    return(this->impl_->operatorPowerTower(*this, ord));
}


} // end of namespace astd
