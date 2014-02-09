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

void aintTest::testOperatorIncrement() {

    CPPUNIT_ASSERT( ++aint(   "-1") ==     0 );
    CPPUNIT_ASSERT( ++aint(    "0") ==     1 );
    CPPUNIT_ASSERT( ++aint(    "1") ==     2 );
    CPPUNIT_ASSERT( ++aint( "9998") ==  9999 );
    CPPUNIT_ASSERT( ++aint( "9999") == 10000 );
    CPPUNIT_ASSERT( ++aint("10000") == 10001 );

    CPPUNIT_ASSERT( aint(   "-1")++ ==    -1 );
    CPPUNIT_ASSERT( aint(    "0")++ ==     0 );
    CPPUNIT_ASSERT( aint(    "1")++ ==     1 );
    CPPUNIT_ASSERT( aint( "9998")++ ==  9998 );
    CPPUNIT_ASSERT( aint( "9999")++ ==  9999 );
    CPPUNIT_ASSERT( aint("10000")++ == 10000 );

    *a1 = 0;
    *a2 = 0;
    for (int j = 0; j < 10000; ++j, ++(*a1), (*a2)++) {
    	;
    }
    CPPUNIT_ASSERT( *a1 == 10000 );
    CPPUNIT_ASSERT( *a2 == 10000 );
}

// eof
