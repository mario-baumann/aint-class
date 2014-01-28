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

namespace astd {

aint aint::impl::factorialIterative(const aint& n) const {
    const unsigned long long int facTable[] = {
    	1ULL, // == 0!
    	1ULL,
    	2ULL,
    	6ULL,
    	24ULL,
    	120ULL,
    	720ULL,
    	5040ULL,
    	40320ULL,
    	362880ULL,
    	3628800ULL, // == 10!
    	39916800ULL,
    	479001600ULL,
    	6227020800ULL,
    	87178291200ULL,
    	1307674368000ULL,
    	20922789888000ULL,
    	355687428096000ULL,
    	6402373705728000ULL,
    	121645100408832000ULL,
    	2432902008176640000ULL // == 20!
    };
    const size_t facTableSize = sizeof(facTable) / sizeof(facTable[0]);
    if (n < facTableSize) {
    	aint fac = facTable[n.impl_->data_[0]];
    	return(fac);
    }
    aint fac = facTable[facTableSize - 1];
    for (size_t j = facTableSize; j <= n; ++j) {
    	fac = fac * j;
    }
    return(fac);
}

aint aint::impl::factorialRecursiveProduct(const aint& start, const aint& width) const {
    if (width < 2) {
        return(start);
    }
    aint i = width / 2;
    return(factorialRecursiveProduct(start,             i)
         * factorialRecursiveProduct(start + i, width - i));
}

} // end of namespace astd
