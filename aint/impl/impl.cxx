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
// impl.hxx (class implementation)

#include "impl.hxx"

namespace {

// array with powers of 10
const size_t power10[10] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000
};

} // end of namespace

namespace astd {

//
// width of a singleComp
//
// NOTE: 2.408 ~= log(2) * 8, where 8 is the number of bits per byte
//
const int aint::impl::C_SINGLE_COMP_WIDTH  = (int) (2.408 * sizeof(singleComp));

//
// maximum number (plus 1) stored in a singleComp type
//
const aint::impl::singleComp aint::impl::C_SINGLE_COMP_MAX_P1 = power10[C_SINGLE_COMP_WIDTH];

} // end of namespace astd
