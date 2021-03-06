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

// aint unit tests
#include "cppunit.hxx"

void aintTest::testOperatorCompoundAssignmentDivide()
{
    *a1 = 13; CPPUNIT_ASSERT( (*a1 /= aint(2)) == 6 );
    *a1 = 13; CPPUNIT_ASSERT( (*a1 /= "2")  == 6 );
    *a1 = 13; CPPUNIT_ASSERT( (*a1 /= std::string("2")) == 6 );
    *a1 = 13; CPPUNIT_ASSERT( (*a1 /= 2)    == 6 );
    *a1 = 13; CPPUNIT_ASSERT( (*a1 /= 2L)   == 6 );
    *a1 = 13; CPPUNIT_ASSERT( (*a1 /= 2LL)  == 6 );
    *a1 = 13; CPPUNIT_ASSERT( (*a1 /= 2U)   == 6 );
    *a1 = 13; CPPUNIT_ASSERT( (*a1 /= 2UL)  == 6 );
    *a1 = 13; CPPUNIT_ASSERT( (*a1 /= 2ULL) == 6 );
    *a1 = 13; CPPUNIT_ASSERT( ((*a1 /= "2") /= "3") == 2 );
}

// eof
