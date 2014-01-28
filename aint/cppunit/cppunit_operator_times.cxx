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

void aintTest::testOperatorTimes() {

    CPPUNIT_ASSERT( aint("+2") * aint("+2") == aint("+4") );
    CPPUNIT_ASSERT( aint("+2") * aint("+1") == aint("+2") );
    CPPUNIT_ASSERT( aint("+1") * aint("+2") == aint("+2") );
    CPPUNIT_ASSERT( aint("+2") * aint("-2") == aint("-4") );
    CPPUNIT_ASSERT( aint("+2") * aint("-1") == aint("-2") );
    CPPUNIT_ASSERT( aint("+1") * aint("-2") == aint("-2") );
    CPPUNIT_ASSERT( aint("-2") * aint("+2") == aint("-4") );
    CPPUNIT_ASSERT( aint("-2") * aint("+1") == aint("-2") );
    CPPUNIT_ASSERT( aint("-1") * aint("+2") == aint("-2") );
    CPPUNIT_ASSERT( aint("-2") * aint("-2") == aint("+4") );
    CPPUNIT_ASSERT( aint("-2") * aint("-1") == aint("+2") );
    CPPUNIT_ASSERT( aint("-1") * aint("-2") == aint("+2") );
    //
    CPPUNIT_ASSERT( aint("+20000000000") * aint("+20000000000") == aint("+400000000000000000000") );
    CPPUNIT_ASSERT( aint("+20000000000") * aint("+10000000000") == aint("+200000000000000000000") );
    CPPUNIT_ASSERT( aint("+10000000000") * aint("+20000000000") == aint("+200000000000000000000") );
    CPPUNIT_ASSERT( aint("+20000000000") * aint("-20000000000") == aint("-400000000000000000000") );
    CPPUNIT_ASSERT( aint("+20000000000") * aint("-10000000000") == aint("-200000000000000000000") );
    CPPUNIT_ASSERT( aint("+10000000000") * aint("-20000000000") == aint("-200000000000000000000") );
    CPPUNIT_ASSERT( aint("-20000000000") * aint("+20000000000") == aint("-400000000000000000000") );
    CPPUNIT_ASSERT( aint("-20000000000") * aint("+10000000000") == aint("-200000000000000000000") );
    CPPUNIT_ASSERT( aint("-10000000000") * aint("+20000000000") == aint("-200000000000000000000") );
    CPPUNIT_ASSERT( aint("-20000000000") * aint("-20000000000") == aint("+400000000000000000000") );
    CPPUNIT_ASSERT( aint("-20000000000") * aint("-10000000000") == aint("+200000000000000000000") );
    CPPUNIT_ASSERT( aint("-10000000000") * aint("-20000000000") == aint("+200000000000000000000") );
    //
    CPPUNIT_ASSERT( aint("+200000000000000000000") * aint("+200000000000000000000") == aint("+40000000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("+200000000000000000000") * aint("+100000000000000000000") == aint("+20000000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("+100000000000000000000") * aint("+200000000000000000000") == aint("+20000000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("+200000000000000000000") * aint("-200000000000000000000") == aint("-40000000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("+200000000000000000000") * aint("-100000000000000000000") == aint("-20000000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("+100000000000000000000") * aint("-200000000000000000000") == aint("-20000000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("-200000000000000000000") * aint("+200000000000000000000") == aint("-40000000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("-200000000000000000000") * aint("+100000000000000000000") == aint("-20000000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("-100000000000000000000") * aint("+200000000000000000000") == aint("-20000000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("-200000000000000000000") * aint("-200000000000000000000") == aint("+40000000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("-200000000000000000000") * aint("-100000000000000000000") == aint("+20000000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("-100000000000000000000") * aint("-200000000000000000000") == aint("+20000000000000000000000000000000000000000") );
    //
    CPPUNIT_ASSERT( aint("+100000000000000000000") * aint("+1") == aint("+100000000000000000000") );
    CPPUNIT_ASSERT( aint("+100000000000000000000") * aint("+0") == aint("+0" ) );

    CPPUNIT_ASSERT( aint("+2") * (+2) == aint("+4") );
    CPPUNIT_ASSERT( aint("+2") * (+1) == aint("+2") );
    CPPUNIT_ASSERT( aint("+1") * (+2) == aint("+2") );
    CPPUNIT_ASSERT( aint("+2") * (-2) == aint("-4") );
    CPPUNIT_ASSERT( aint("+2") * (-1) == aint("-2") );
    CPPUNIT_ASSERT( aint("+1") * (-2) == aint("-2") );
    CPPUNIT_ASSERT( aint("-2") * (+2) == aint("-4") );
    CPPUNIT_ASSERT( aint("-2") * (+1) == aint("-2") );
    CPPUNIT_ASSERT( aint("-1") * (+2) == aint("-2") );
    CPPUNIT_ASSERT( aint("-2") * (-2) == aint("+4") );
    CPPUNIT_ASSERT( aint("-2") * (-1) == aint("+2") );
    CPPUNIT_ASSERT( aint("-1") * (-2) == aint("+2") );
    CPPUNIT_ASSERT( (+2) * aint("+2") == aint("+4") );
    CPPUNIT_ASSERT( (+1) * aint("+2") == aint("+2") );
    CPPUNIT_ASSERT( (+2) * aint("+1") == aint("+2") );
    CPPUNIT_ASSERT( (-2) * aint("+2") == aint("-4") );
    CPPUNIT_ASSERT( (-1) * aint("+2") == aint("-2") );
    CPPUNIT_ASSERT( (-2) * aint("+1") == aint("-2") );
    CPPUNIT_ASSERT( (+2) * aint("-2") == aint("-4") );
    CPPUNIT_ASSERT( (+1) * aint("-2") == aint("-2") );
    CPPUNIT_ASSERT( (+2) * aint("-1") == aint("-2") );
    CPPUNIT_ASSERT( (-2) * aint("-2") == aint("+4") );
    CPPUNIT_ASSERT( (-1) * aint("-2") == aint("+2") );
    CPPUNIT_ASSERT( (-2) * aint("-1") == aint("+2") );
    //
    CPPUNIT_ASSERT( aint("+20000000000") * (+20000000000) == aint("+400000000000000000000") );
    CPPUNIT_ASSERT( aint("+20000000000") * (+10000000000) == aint("+200000000000000000000") );
    CPPUNIT_ASSERT( aint("+10000000000") * (+20000000000) == aint("+200000000000000000000") );
    CPPUNIT_ASSERT( aint("+20000000000") * (-20000000000) == aint("-400000000000000000000") );
    CPPUNIT_ASSERT( aint("+20000000000") * (-10000000000) == aint("-200000000000000000000") );
    CPPUNIT_ASSERT( aint("+10000000000") * (-20000000000) == aint("-200000000000000000000") );
    CPPUNIT_ASSERT( aint("-20000000000") * (+20000000000) == aint("-400000000000000000000") );
    CPPUNIT_ASSERT( aint("-20000000000") * (+10000000000) == aint("-200000000000000000000") );
    CPPUNIT_ASSERT( aint("-10000000000") * (+20000000000) == aint("-200000000000000000000") );
    CPPUNIT_ASSERT( aint("-20000000000") * (-20000000000) == aint("+400000000000000000000") );
    CPPUNIT_ASSERT( aint("-20000000000") * (-10000000000) == aint("+200000000000000000000") );
    CPPUNIT_ASSERT( aint("-10000000000") * (-20000000000) == aint("+200000000000000000000") );
    CPPUNIT_ASSERT( (+20000000000) * aint("+20000000000") == aint("+400000000000000000000") );
    CPPUNIT_ASSERT( (+10000000000) * aint("+20000000000") == aint("+200000000000000000000") );
    CPPUNIT_ASSERT( (+20000000000) * aint("+10000000000") == aint("+200000000000000000000") );
    CPPUNIT_ASSERT( (-20000000000) * aint("+20000000000") == aint("-400000000000000000000") );
    CPPUNIT_ASSERT( (-10000000000) * aint("+20000000000") == aint("-200000000000000000000") );
    CPPUNIT_ASSERT( (-20000000000) * aint("+10000000000") == aint("-200000000000000000000") );
    CPPUNIT_ASSERT( (+20000000000) * aint("-20000000000") == aint("-400000000000000000000") );
    CPPUNIT_ASSERT( (+10000000000) * aint("-20000000000") == aint("-200000000000000000000") );
    CPPUNIT_ASSERT( (+20000000000) * aint("-10000000000") == aint("-200000000000000000000") );
    CPPUNIT_ASSERT( (-20000000000) * aint("-20000000000") == aint("+400000000000000000000") );
    CPPUNIT_ASSERT( (-10000000000) * aint("-20000000000") == aint("+200000000000000000000") );
    CPPUNIT_ASSERT( (-20000000000) * aint("-10000000000") == aint("+200000000000000000000") );

    CPPUNIT_ASSERT( aint("+2") * (+2U) == aint("+4") );
    CPPUNIT_ASSERT( aint("+2") * (+1U) == aint("+2") );
    CPPUNIT_ASSERT( aint("+1") * (+2U) == aint("+2") );
    CPPUNIT_ASSERT( aint("-2") * (+2U) == aint("-4") );
    CPPUNIT_ASSERT( aint("-2") * (+1U) == aint("-2") );
    CPPUNIT_ASSERT( aint("-1") * (+2U) == aint("-2") );
    CPPUNIT_ASSERT( (+2U) * aint("+2") == aint("+4") );
    CPPUNIT_ASSERT( (+1U) * aint("+2") == aint("+2") );
    CPPUNIT_ASSERT( (+2U) * aint("+1") == aint("+2") );
    CPPUNIT_ASSERT( (+2U) * aint("-2") == aint("-4") );
    CPPUNIT_ASSERT( (+1U) * aint("-2") == aint("-2") );
    CPPUNIT_ASSERT( (+2U) * aint("-1") == aint("-2") );

    CPPUNIT_ASSERT( aint("+2000000000") * (+2000000000UL) == aint("+4000000000000000000") );
    CPPUNIT_ASSERT( aint("+2000000000") * (+1000000000UL) == aint("+2000000000000000000") );
    CPPUNIT_ASSERT( aint("+1000000000") * (+2000000000UL) == aint("+2000000000000000000") );
    CPPUNIT_ASSERT( aint("-2000000000") * (+2000000000UL) == aint("-4000000000000000000") );
    CPPUNIT_ASSERT( aint("-2000000000") * (+1000000000UL) == aint("-2000000000000000000") );
    CPPUNIT_ASSERT( aint("-1000000000") * (+2000000000UL) == aint("-2000000000000000000") );
    CPPUNIT_ASSERT( (+2000000000UL) * aint("+2000000000") == aint("+4000000000000000000") );
    CPPUNIT_ASSERT( (+1000000000UL) * aint("+2000000000") == aint("+2000000000000000000") );
    CPPUNIT_ASSERT( (+2000000000UL) * aint("+1000000000") == aint("+2000000000000000000") );
    CPPUNIT_ASSERT( (+2000000000UL) * aint("-2000000000") == aint("-4000000000000000000") );
    CPPUNIT_ASSERT( (+1000000000UL) * aint("-2000000000") == aint("-2000000000000000000") );
    CPPUNIT_ASSERT( (+2000000000UL) * aint("-1000000000") == aint("-2000000000000000000") );

    CPPUNIT_ASSERT( aint("+2000000000000000000") * (+2000000000000000000ULL) == aint("+4000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("+2000000000000000000") * (+1000000000000000000ULL) == aint("+2000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("+1000000000000000000") * (+2000000000000000000ULL) == aint("+2000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("-2000000000000000000") * (+2000000000000000000ULL) == aint("-4000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("-2000000000000000000") * (+1000000000000000000ULL) == aint("-2000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( aint("-1000000000000000000") * (+2000000000000000000ULL) == aint("-2000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( (+2000000000000000000ULL) * aint("+2000000000000000000") == aint("+4000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( (+1000000000000000000ULL) * aint("+2000000000000000000") == aint("+2000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( (+2000000000000000000ULL) * aint("+1000000000000000000") == aint("+2000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( (+2000000000000000000ULL) * aint("-2000000000000000000") == aint("-4000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( (+1000000000000000000ULL) * aint("-2000000000000000000") == aint("-2000000000000000000000000000000000000") );
    CPPUNIT_ASSERT( (+2000000000000000000ULL) * aint("-1000000000000000000") == aint("-2000000000000000000000000000000000000") );
}

// eof
