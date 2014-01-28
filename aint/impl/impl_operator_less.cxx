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
// impl_operator_less.cxx (helper functions for operator less than)

#include "impl.hxx"

namespace astd {

bool aint::impl::operatorLtLL(const aint& lhs, const long long int rhs) const {
	// checks if lhs < rhs

    // try to avoid the generic operator call
    if (rhs > 0) {
    	if (!lhs.impl_->positive_) {
    	    return(true);
    	} else if (lhs.impl_->data_.size() == 1) {
  			return(lhs.impl_->data_[0] < rhs ? true : false);
    	}
    } else {
    	if (lhs.impl_->positive_) {
    	    return(false);
    	} else if (lhs.impl_->data_.size() == 1) {
  			return(lhs.impl_->data_[0] <= (-rhs) ? false : true);
    	}
    }
	return(lhs.operator<(aint(rhs)));
}

bool aint::impl::operatorLtULL(const aint& lhs, const unsigned long long int rhs) const {
	// checks if lhs < rhs

    // try to avoid the generic operator call
    if (!lhs.impl_->positive_) {
        return(true);
    } else if (lhs.impl_->data_.size() == 1) {
  		return(lhs.impl_->data_[0] < rhs ? true : false);
    }
	return(lhs.operator<(aint(rhs)));
}

bool aint::impl::operatorLtAbs(const aint& lhs, const aint& rhs) const {
	// checks if abs(lhs) < abs(rhs)
    size_t LS = lhs.impl_->data_.size();
    size_t RS = rhs.impl_->data_.size();
    if (LS < RS) {
        return(true);
    }
    if (RS < LS) {
        return(false);
    }
    // LS == RS
    for (int j = LS - 1; j >= 0; --j) {
        if (lhs.impl_->data_[j] < rhs.impl_->data_[j]) {
            return(true);
        }
        if (rhs.impl_->data_[j] < lhs.impl_->data_[j]) {
            return(false);
        }
    }
    return(false); // this == rhs
}

} // end of namespace astd
