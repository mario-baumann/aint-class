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

void aintTest::testMember() {

    CPPUNIT_ASSERT( aint(        -1).digits() == 1 );
    CPPUNIT_ASSERT( aint(         0).digits() == 1 );
    CPPUNIT_ASSERT( aint(         1).digits() == 1 );
    CPPUNIT_ASSERT( aint(         9).digits() == 1 );
    CPPUNIT_ASSERT( aint(        10).digits() == 2 );
    CPPUNIT_ASSERT( aint(        12).digits() == 2 );
    CPPUNIT_ASSERT( aint(        19).digits() == 2 );
    CPPUNIT_ASSERT( aint(       100).digits() == 3 );
    CPPUNIT_ASSERT( aint(      1000).digits() == 4 );
    CPPUNIT_ASSERT( aint(     10000).digits() == 5 );
    CPPUNIT_ASSERT( aint(    100000).digits() == 6 );
    CPPUNIT_ASSERT( aint(   1000000).digits() == 7 );
    CPPUNIT_ASSERT( aint(  10000000).digits() == 8 );
    CPPUNIT_ASSERT( aint( 100000000).digits() == 9 );
    CPPUNIT_ASSERT( aint(1000000000).digits() == 10 );
    CPPUNIT_ASSERT( aint("354224848179261915075").digits() == 21 );

    CPPUNIT_ASSERT( aint( 0).factorial() == 1 );
    CPPUNIT_ASSERT( aint( 1).factorial() == 1 );
    CPPUNIT_ASSERT( aint( 10).factorial() == 3628800 );
    CPPUNIT_ASSERT( aint( 20).factorial() == 2432902008176640000_A );
    CPPUNIT_ASSERT( aint( 21).factorial() == 51090942171709440000_A );
    CPPUNIT_ASSERT( aint(100).factorial() == 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000_A );
}

// eof
