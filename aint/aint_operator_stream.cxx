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
// aint_operator.cxx (operators)

#include "impl.hxx"
#include <iomanip>
#include <iostream>
#include <sstream>

namespace astd {

std::ostream& operator<< (std::ostream& out, const aint& a) {
	std::stringstream ss;
	if (!a.impl_->positive_) {
        ss << '-';
    }
    for (auto rit = a.impl_->data_.crbegin(); rit != a.impl_->data_.crend(); ++rit) {
        ss << std::setw(rit == a.impl_->data_.rbegin() ? 0 : aint::impl::C_SINGLE_COMP_WIDTH);
        ss << std::setfill('0') ;
        ss << (int) *rit;
    }
#if defined(DUMP)
    ss << "\n" << a.dump();
#endif

    out << ss.str();
    return(out); 
}

} // end of namespace astd
