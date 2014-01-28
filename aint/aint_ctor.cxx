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
// aint_ctor.cxx (constructors)

#include "impl.hxx"

namespace astd {

// ctor(s)
aint::aint() : impl_(new impl()) {
}
aint::aint(const char* s) throw(std::invalid_argument) : impl_(new impl(s)) {
}
aint::aint(const std::string& s) throw(std::invalid_argument) : impl_(new impl(s)) {
}
aint::aint(const int i) : impl_(new impl(i)) {
}
aint::aint(const long int i) : impl_(new impl(i)) {
}
aint::aint(const long long int i) : impl_(new impl(i)) {
}
aint::aint(const unsigned int i) : impl_(new impl(i)) {
}
aint::aint(const unsigned long int i) : impl_(new impl(i)) {
}
aint::aint(const unsigned long long int i) : impl_(new impl(i)) {
}
aint::aint(const aint& a) : impl_(new impl(*a.impl_)) {
//	std::cout << __FUNCTION__ << " (aint copy ctor)" << std::endl;
}
aint::aint(aint&& a) : impl_(std::move(a.impl_)) {
//	std::cout << __FUNCTION__ << " (aint move ctor)" << std::endl;
}
} // end of namespace astd
