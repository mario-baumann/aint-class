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

void aintTest::testOperatorDivide() {

	CPPUNIT_ASSERT( aint("+1") / aint("+1") == aint("+1") );
	CPPUNIT_ASSERT( aint("+1") / aint("+2") == aint("+0") );

    //
	CPPUNIT_ASSERT( aint("+2") / aint("+2") == +1 );
	CPPUNIT_ASSERT( aint("+2") / aint("+1") == +2 );
	CPPUNIT_ASSERT( aint("+1") / aint("+2") == +0 );
	CPPUNIT_ASSERT( aint("+2") / aint("-2") == -1 );
	CPPUNIT_ASSERT( aint("+2") / aint("-1") == -2 );
	CPPUNIT_ASSERT( aint("+1") / aint("-2") == +0 );
	CPPUNIT_ASSERT( aint("-2") / aint("+2") == -1 );
	CPPUNIT_ASSERT( aint("-2") / aint("+1") == -2 );
	CPPUNIT_ASSERT( aint("-1") / aint("+2") == +0 );
	CPPUNIT_ASSERT( aint("-2") / aint("-2") == +1 );
	CPPUNIT_ASSERT( aint("-2") / aint("-1") == +2 );
	CPPUNIT_ASSERT( aint("-1") / aint("-2") == +0 );
    //
	CPPUNIT_ASSERT( aint("+2") % aint("+2") == +0 );
	CPPUNIT_ASSERT( aint("+2") % aint("+1") == +0 );
	CPPUNIT_ASSERT( aint("+1") % aint("+2") == +1 );
	CPPUNIT_ASSERT( aint("+2") % aint("-2") == +0 );
	CPPUNIT_ASSERT( aint("+2") % aint("-1") == +0 );
	CPPUNIT_ASSERT( aint("+1") % aint("-2") == +1 );
	CPPUNIT_ASSERT( aint("-2") % aint("+2") == +0 );
	CPPUNIT_ASSERT( aint("-2") % aint("+1") == +0 );
	CPPUNIT_ASSERT( aint("-1") % aint("+2") == -1 );
	CPPUNIT_ASSERT( aint("-2") % aint("-2") == +0 );
	CPPUNIT_ASSERT( aint("-2") % aint("-1") == +0 );
	CPPUNIT_ASSERT( aint("-1") % aint("-2") == -1 );
    //
	CPPUNIT_ASSERT( aint("+20000000000") / aint("+20000000000") == +1 );
	CPPUNIT_ASSERT( aint("+20000000000") / aint("+10000000000") == +2 );
	CPPUNIT_ASSERT( aint("+10000000000") / aint("+20000000000") == +0 );
	CPPUNIT_ASSERT( aint("+20000000000") / aint("-20000000000") == -1 );
	CPPUNIT_ASSERT( aint("+20000000000") / aint("-10000000000") == -2 );
	CPPUNIT_ASSERT( aint("+10000000000") / aint("-20000000000") == +0 );
	CPPUNIT_ASSERT( aint("-20000000000") / aint("+20000000000") == -1 );
	CPPUNIT_ASSERT( aint("-20000000000") / aint("+10000000000") == -2 );
	CPPUNIT_ASSERT( aint("-10000000000") / aint("+20000000000") == +0 );
	CPPUNIT_ASSERT( aint("-20000000000") / aint("-20000000000") == +1 );
	CPPUNIT_ASSERT( aint("-20000000000") / aint("-10000000000") == +2 );
	CPPUNIT_ASSERT( aint("-10000000000") / aint("-20000000000") == +0 );
    //
	CPPUNIT_ASSERT( aint("+20000000000") % aint("+20000000000") == +0 );
	CPPUNIT_ASSERT( aint("+20000000000") % aint("+10000000000") == +0 );
	CPPUNIT_ASSERT( aint("+10000000000") % aint("+20000000000") == aint("+10000000000") );
	CPPUNIT_ASSERT( aint("+20000000000") % aint("-20000000000") == +0 );
	CPPUNIT_ASSERT( aint("+20000000000") % aint("-10000000000") == +0 );
	CPPUNIT_ASSERT( aint("+10000000000") % aint("-20000000000") == aint("+10000000000") );
	CPPUNIT_ASSERT( aint("-20000000000") % aint("+20000000000") == +0 );
	CPPUNIT_ASSERT( aint("-20000000000") % aint("+10000000000") == +0 );
	CPPUNIT_ASSERT( aint("-10000000000") % aint("+20000000000") == aint("-10000000000") );
	CPPUNIT_ASSERT( aint("-20000000000") % aint("-20000000000") == +0 );
	CPPUNIT_ASSERT( aint("-20000000000") % aint("-10000000000") == +0 );
	CPPUNIT_ASSERT( aint("-10000000000") % aint("-20000000000") == aint("-10000000000") );
    //
	CPPUNIT_ASSERT( aint("+200000000000000000000") / aint("+200000000000000000000") == +1 );
	CPPUNIT_ASSERT( aint("+200000000000000000000") / aint("+100000000000000000000") == +2 );
	CPPUNIT_ASSERT( aint("+100000000000000000000") / aint("+200000000000000000000") == +0 );
	CPPUNIT_ASSERT( aint("+200000000000000000000") / aint("-200000000000000000000") == -1 );
	CPPUNIT_ASSERT( aint("+200000000000000000000") / aint("-100000000000000000000") == -2 );
	CPPUNIT_ASSERT( aint("+100000000000000000000") / aint("-200000000000000000000") == +0 );
	CPPUNIT_ASSERT( aint("-200000000000000000000") / aint("+200000000000000000000") == -1 );
	CPPUNIT_ASSERT( aint("-200000000000000000000") / aint("+100000000000000000000") == -2 );
	CPPUNIT_ASSERT( aint("-100000000000000000000") / aint("+200000000000000000000") == +0 );
	CPPUNIT_ASSERT( aint("-200000000000000000000") / aint("-200000000000000000000") == +1 );
	CPPUNIT_ASSERT( aint("-200000000000000000000") / aint("-100000000000000000000") == +2 );
	CPPUNIT_ASSERT( aint("-100000000000000000000") / aint("-200000000000000000000") == +0 );
    //
	CPPUNIT_ASSERT( aint("+200000000000000000000") % aint("+200000000000000000000") == +0 );
	CPPUNIT_ASSERT( aint("+200000000000000000000") % aint("+100000000000000000000") == +0 );
	CPPUNIT_ASSERT( aint("+100000000000000000000") % aint("+200000000000000000000") == aint("+100000000000000000000") );
	CPPUNIT_ASSERT( aint("+200000000000000000000") % aint("-200000000000000000000") == +0 );
	CPPUNIT_ASSERT( aint("+200000000000000000000") % aint("-100000000000000000000") == +0 );
	CPPUNIT_ASSERT( aint("+100000000000000000000") % aint("-200000000000000000000") == aint("+100000000000000000000") );
	CPPUNIT_ASSERT( aint("-200000000000000000000") % aint("+200000000000000000000") == +0 );
	CPPUNIT_ASSERT( aint("-200000000000000000000") % aint("+100000000000000000000") == +0 );
	CPPUNIT_ASSERT( aint("-100000000000000000000") % aint("+200000000000000000000") == aint("-100000000000000000000") );
	CPPUNIT_ASSERT( aint("-200000000000000000000") % aint("-200000000000000000000") == +0 );
	CPPUNIT_ASSERT( aint("-200000000000000000000") % aint("-100000000000000000000") == +0 );
	CPPUNIT_ASSERT( aint("-100000000000000000000") % aint("-200000000000000000000") == aint("-100000000000000000000") );

	//
	CPPUNIT_ASSERT( aint("+2") / (+2) == +1 );
	CPPUNIT_ASSERT( aint("+2") / (+1) == +2 );
	CPPUNIT_ASSERT( aint("+1") / (+2) == +0 );
	CPPUNIT_ASSERT( aint("+2") / (-2) == -1 );
	CPPUNIT_ASSERT( aint("+2") / (-1) == -2 );
	CPPUNIT_ASSERT( aint("+1") / (-2) == +0 );
	CPPUNIT_ASSERT( aint("-2") / (+2) == -1 );
	CPPUNIT_ASSERT( aint("-2") / (+1) == -2 );
	CPPUNIT_ASSERT( aint("-1") / (+2) == +0 );
	CPPUNIT_ASSERT( aint("-2") / (-2) == +1 );
	CPPUNIT_ASSERT( aint("-2") / (-1) == +2 );
	CPPUNIT_ASSERT( aint("-1") / (-2) == +0 );
	CPPUNIT_ASSERT( (+2) / aint("+2") == +1 );
	CPPUNIT_ASSERT( (+1) / aint("+2") == +0 );
	CPPUNIT_ASSERT( (+2) / aint("+1") == +2 );
	CPPUNIT_ASSERT( (-2) / aint("+2") == -1 );
	CPPUNIT_ASSERT( (-1) / aint("+2") == +0 );
	CPPUNIT_ASSERT( (-2) / aint("+1") == -2 );
	CPPUNIT_ASSERT( (+2) / aint("-2") == -1 );
	CPPUNIT_ASSERT( (+1) / aint("-2") == +0 );
	CPPUNIT_ASSERT( (+2) / aint("-1") == -2 );
	CPPUNIT_ASSERT( (-2) / aint("-2") == +1 );
	CPPUNIT_ASSERT( (-1) / aint("-2") == +0 );
	CPPUNIT_ASSERT( (-2) / aint("-1") == +2 );
	//
	CPPUNIT_ASSERT( aint("+2") % (+2) == +0 );
	CPPUNIT_ASSERT( aint("+2") % (+1) == +0 );
	CPPUNIT_ASSERT( aint("+1") % (+2) == +1 );
	CPPUNIT_ASSERT( aint("+2") % (-2) == +0 );
	CPPUNIT_ASSERT( aint("+2") % (-1) == +0 );
	CPPUNIT_ASSERT( aint("+1") % (-2) == +1 );
	CPPUNIT_ASSERT( aint("-2") % (+2) == +0 );
	CPPUNIT_ASSERT( aint("-2") % (+1) == +0 );
	CPPUNIT_ASSERT( aint("-1") % (+2) == -1 );
	CPPUNIT_ASSERT( aint("-2") % (-2) == +0 );
	CPPUNIT_ASSERT( aint("-2") % (-1) == +0 );
	CPPUNIT_ASSERT( aint("-1") % (-2) == -1 );
	CPPUNIT_ASSERT( (+2) % aint("+2") == +0 );
	CPPUNIT_ASSERT( (+1) % aint("+2") == +1 );
	CPPUNIT_ASSERT( (+2) % aint("+1") == +0 );
	CPPUNIT_ASSERT( (-2) % aint("+2") == +0 );
	CPPUNIT_ASSERT( (-1) % aint("+2") == -1 );
	CPPUNIT_ASSERT( (-2) % aint("+1") == +0 );
	CPPUNIT_ASSERT( (+2) % aint("-2") == +0 );
	CPPUNIT_ASSERT( (+1) % aint("-2") == +1 );
	CPPUNIT_ASSERT( (+2) % aint("-1") == +0 );
	CPPUNIT_ASSERT( (-2) % aint("-2") == +0 );
	CPPUNIT_ASSERT( (-1) % aint("-2") == -1 );
	CPPUNIT_ASSERT( (-2) % aint("-1") == +0 );

	//
	CPPUNIT_ASSERT( aint("+20000000000") / (+20000000000) == +1 );
	CPPUNIT_ASSERT( aint("+20000000000") / (+10000000000) == +2 );
	CPPUNIT_ASSERT( aint("+10000000000") / (+20000000000) == +0 );
	CPPUNIT_ASSERT( aint("+20000000000") / (-20000000000) == -1 );
	CPPUNIT_ASSERT( aint("+20000000000") / (-10000000000) == -2 );
	CPPUNIT_ASSERT( aint("+10000000000") / (-20000000000) == +0 );
	CPPUNIT_ASSERT( aint("-20000000000") / (+20000000000) == -1 );
	CPPUNIT_ASSERT( aint("-20000000000") / (+10000000000) == -2 );
	CPPUNIT_ASSERT( aint("-10000000000") / (+20000000000) == +0 );
	CPPUNIT_ASSERT( aint("-20000000000") / (-20000000000) == +1 );
	CPPUNIT_ASSERT( aint("-20000000000") / (-10000000000) == +2 );
	CPPUNIT_ASSERT( aint("-10000000000") / (-20000000000) == +0 );
	CPPUNIT_ASSERT( (+20000000000) / aint("+20000000000") == +1 );
	CPPUNIT_ASSERT( (+10000000000) / aint("+20000000000") == +0 );
	CPPUNIT_ASSERT( (+20000000000) / aint("+10000000000") == +2 );
	CPPUNIT_ASSERT( (-20000000000) / aint("+20000000000") == -1 );
	CPPUNIT_ASSERT( (-10000000000) / aint("+20000000000") == +0 );
	CPPUNIT_ASSERT( (-20000000000) / aint("+10000000000") == -2 );
	CPPUNIT_ASSERT( (+20000000000) / aint("-20000000000") == -1 );
	CPPUNIT_ASSERT( (+10000000000) / aint("-20000000000") == +0 );
	CPPUNIT_ASSERT( (+20000000000) / aint("-10000000000") == -2 );
	CPPUNIT_ASSERT( (-20000000000) / aint("-20000000000") == +1 );
	CPPUNIT_ASSERT( (-10000000000) / aint("-20000000000") == +0 );
	CPPUNIT_ASSERT( (-20000000000) / aint("-10000000000") == +2 );
    //
	CPPUNIT_ASSERT( aint("+20000000000") % (+20000000000) == +0 );
	CPPUNIT_ASSERT( aint("+20000000000") % (+10000000000) == +0 );
	CPPUNIT_ASSERT( aint("+10000000000") % (+20000000000) == aint("+10000000000") );
	CPPUNIT_ASSERT( aint("+20000000000") % (-20000000000) == +0 );
	CPPUNIT_ASSERT( aint("+20000000000") % (-10000000000) == +0 );
	CPPUNIT_ASSERT( aint("+10000000000") % (-20000000000) == aint("+10000000000") );
	CPPUNIT_ASSERT( aint("-20000000000") % (+20000000000) == +0 );
	CPPUNIT_ASSERT( aint("-20000000000") % (+10000000000) == +0 );
	CPPUNIT_ASSERT( aint("-10000000000") % (+20000000000) == aint("-10000000000") );
	CPPUNIT_ASSERT( aint("-20000000000") % (-20000000000) == +0 );
	CPPUNIT_ASSERT( aint("-20000000000") % (-10000000000) == +0 );
	CPPUNIT_ASSERT( aint("-10000000000") % (-20000000000) == aint("-10000000000") );
	CPPUNIT_ASSERT( (+20000000000) % aint("+20000000000") == +0 );
	CPPUNIT_ASSERT( (+10000000000) % aint("+20000000000") == aint("+10000000000") );
	CPPUNIT_ASSERT( (+20000000000) % aint("+10000000000") == +0 );
	CPPUNIT_ASSERT( (-20000000000) % aint("+20000000000") == +0 );
	CPPUNIT_ASSERT( (-10000000000) % aint("+20000000000") == aint("-10000000000") );
	CPPUNIT_ASSERT( (-20000000000) % aint("+10000000000") == +0 );
	CPPUNIT_ASSERT( (+20000000000) % aint("-20000000000") == +0 );
	CPPUNIT_ASSERT( (+10000000000) % aint("-20000000000") == aint("+10000000000") );
	CPPUNIT_ASSERT( (+20000000000) % aint("-10000000000") == +0 );
	CPPUNIT_ASSERT( (-20000000000) % aint("-20000000000") == +0 );
	CPPUNIT_ASSERT( (-10000000000) % aint("-20000000000") == aint("-10000000000") );
	CPPUNIT_ASSERT( (-20000000000) % aint("-10000000000") == +0 );

	//
	CPPUNIT_ASSERT( aint("+2") / (+2U) == +1 );
	CPPUNIT_ASSERT( aint("+2") / (+1U) == +2 );
	CPPUNIT_ASSERT( aint("+1") / (+2U) == +0 );
	CPPUNIT_ASSERT( aint("-2") / (+2U) == -1 );
	CPPUNIT_ASSERT( aint("-2") / (+1U) == -2 );
	CPPUNIT_ASSERT( aint("-1") / (+2U) == +0 );
	CPPUNIT_ASSERT( (+2U) / aint("+2") == +1 );
	CPPUNIT_ASSERT( (+1U) / aint("+2") == +0 );
	CPPUNIT_ASSERT( (+2U) / aint("+1") == +2 );
	CPPUNIT_ASSERT( (+2U) / aint("-2") == -1 );
	CPPUNIT_ASSERT( (+1U) / aint("-2") == +0 );
	CPPUNIT_ASSERT( (+2U) / aint("-1") == -2 );
    //
	CPPUNIT_ASSERT( aint("+2") % (+2U) == +0 );
	CPPUNIT_ASSERT( aint("+2") % (+1U) == +0 );
	CPPUNIT_ASSERT( aint("+1") % (+2U) == +1 );
	CPPUNIT_ASSERT( aint("-2") % (+2U) == +0 );
	CPPUNIT_ASSERT( aint("-2") % (+1U) == +0 );
	CPPUNIT_ASSERT( aint("-1") % (+2U) == -1 );
	CPPUNIT_ASSERT( (+2U) % aint("+2") == +0 );
	CPPUNIT_ASSERT( (+1U) % aint("+2") == +1 );
	CPPUNIT_ASSERT( (+2U) % aint("+1") == +0 );
	CPPUNIT_ASSERT( (+2U) % aint("-2") == +0 );
	CPPUNIT_ASSERT( (+1U) % aint("-2") == +1 );
	CPPUNIT_ASSERT( (+2U) % aint("-1") == +0 );

	//
	CPPUNIT_ASSERT( aint("+2000000000") / (+2000000000UL) == +1 );
	CPPUNIT_ASSERT( aint("+2000000000") / (+1000000000UL) == +2 );
	CPPUNIT_ASSERT( aint("+1000000000") / (+2000000000UL) == +0 );
	CPPUNIT_ASSERT( aint("-2000000000") / (+2000000000UL) == -1 );
	CPPUNIT_ASSERT( aint("-2000000000") / (+1000000000UL) == -2 );
	CPPUNIT_ASSERT( aint("-1000000000") / (+2000000000UL) == +0 );
	CPPUNIT_ASSERT( (+2000000000UL) / aint("+2000000000") == +1 );
	CPPUNIT_ASSERT( (+1000000000UL) / aint("+2000000000") == +0 );
	CPPUNIT_ASSERT( (+2000000000UL) / aint("+1000000000") == +2 );
	CPPUNIT_ASSERT( (+2000000000UL) / aint("-2000000000") == -1 );
	CPPUNIT_ASSERT( (+1000000000UL) / aint("-2000000000") == +0 );
	CPPUNIT_ASSERT( (+2000000000UL) / aint("-1000000000") == -2 );
    //
	CPPUNIT_ASSERT( aint("+2000000000") % (+2000000000UL) == +0 );
	CPPUNIT_ASSERT( aint("+2000000000") % (+1000000000UL) == +0 );
	CPPUNIT_ASSERT( aint("+1000000000") % (+2000000000UL) == aint("+1000000000") );
	CPPUNIT_ASSERT( aint("-2000000000") % (+2000000000UL) == +0 );
	CPPUNIT_ASSERT( aint("-2000000000") % (+1000000000UL) == +0 );
	CPPUNIT_ASSERT( aint("-1000000000") % (+2000000000UL) == aint("-1000000000") );
	CPPUNIT_ASSERT( (+2000000000UL) % aint("+2000000000") == +0 );
	CPPUNIT_ASSERT( (+1000000000UL) % aint("+2000000000") == +1000000000UL );
	CPPUNIT_ASSERT( (+2000000000UL) % aint("+1000000000") == +0 );
	CPPUNIT_ASSERT( (+2000000000UL) % aint("-2000000000") == +0 );
	CPPUNIT_ASSERT( (+1000000000UL) % aint("-2000000000") == +1000000000UL );
	CPPUNIT_ASSERT( (+2000000000UL) % aint("-1000000000") == +0 );

	//
	CPPUNIT_ASSERT( aint("+2000000000000000000") / (+2000000000000000000ULL) == +1 );
	CPPUNIT_ASSERT( aint("+2000000000000000000") / (+1000000000000000000ULL) == +2 );
	CPPUNIT_ASSERT( aint("+1000000000000000000") / (+2000000000000000000ULL) == +0 );
	CPPUNIT_ASSERT( aint("-2000000000000000000") / (+2000000000000000000ULL) == -1 );
	CPPUNIT_ASSERT( aint("-2000000000000000000") / (+1000000000000000000ULL) == -2 );
	CPPUNIT_ASSERT( aint("-1000000000000000000") / (+2000000000000000000ULL) == +0 );
	CPPUNIT_ASSERT( (+2000000000000000000ULL) / aint("+2000000000000000000") == +1 );
	CPPUNIT_ASSERT( (+1000000000000000000ULL) / aint("+2000000000000000000") == +0 );
	CPPUNIT_ASSERT( (+2000000000000000000ULL) / aint("+1000000000000000000") == +2 );
	CPPUNIT_ASSERT( (+2000000000000000000ULL) / aint("-2000000000000000000") == -1 );
	CPPUNIT_ASSERT( (+1000000000000000000ULL) / aint("-2000000000000000000") == +0 );
	CPPUNIT_ASSERT( (+2000000000000000000ULL) / aint("-1000000000000000000") == -2 );
    //
	CPPUNIT_ASSERT( aint("+2000000000000000000") % (+2000000000000000000ULL) == +0 );
	CPPUNIT_ASSERT( aint("+2000000000000000000") % (+1000000000000000000ULL) == +0 );
	CPPUNIT_ASSERT( aint("+1000000000000000000") % (+2000000000000000000ULL) == aint("+1000000000000000000") );
	CPPUNIT_ASSERT( aint("-2000000000000000000") % (+2000000000000000000ULL) == +0 );
	CPPUNIT_ASSERT( aint("-2000000000000000000") % (+1000000000000000000ULL) == +0 );
	CPPUNIT_ASSERT( aint("-1000000000000000000") % (+2000000000000000000ULL) == aint("-1000000000000000000") );
	CPPUNIT_ASSERT( (+2000000000000000000ULL) % aint("+2000000000000000000") == +0 );
	CPPUNIT_ASSERT( (+1000000000000000000ULL) % aint("+2000000000000000000") == +1000000000000000000ULL );
	CPPUNIT_ASSERT( (+2000000000000000000ULL) % aint("+1000000000000000000") == +0 );
	CPPUNIT_ASSERT( (+2000000000000000000ULL) % aint("-2000000000000000000") == +0 );
	CPPUNIT_ASSERT( (+1000000000000000000ULL) % aint("-2000000000000000000") == +1000000000000000000ULL );
	CPPUNIT_ASSERT( (+2000000000000000000ULL) % aint("-1000000000000000000") == +0 );

    // some random test (generated with ./gen-div-test.sh)
	aint("630117642690728144247")     / aint("417530467693679131")     == aint("1509");
	aint("343013520236615931595")     / aint("501922806668882")        == aint("683398");
	aint("537599207192691449")        / aint("561211730795")           == aint("957925");
	aint("26647207533088")            / aint("394020614")              == aint("67628");
	aint("362242238140")              / aint("36829")                  == aint("9835788");
	aint("115337930")                 / aint("681")                    == aint("169365");
	aint("396063740625009400288190")  / aint("341798766356591896")     == aint("1158762");
	aint("85768798985559927661")      / aint("562929919811216")        == aint("152361");
	aint("176746309367103306")        / aint("225780399315")           == aint("782823");
	aint("545187676591109")           / aint("696790159")              == aint("782427");
	aint("159746536958")              / aint("106499")                 == aint("1499981");
	aint("576246082")                 / aint("21")                     == aint("27440289");
	aint("47726510044250646644496")   / aint("518780663957118723")     == aint("91997");
	aint("161535597700403413567")     / aint("91152990043274")         == aint("1772137");
	aint("441372403411481597")        / aint("6915498146")             == aint("63823660");
	aint("2812831530799")             / aint("12527644")               == aint("224529");
	aint("147345896775")              / aint("742")                    == aint("198579375");
	aint("490418140")                 / aint("415")                    == aint("1181730");
	aint("563146025268852810033084")  / aint("101510106331794763")     == aint("5547684");
	aint("50254077357200553468")      / aint("1504885924194")          == aint("33393944");
	aint("18107340051597150")         / aint("53720972553")            == aint("337062");
	aint("549155621379169")           / aint("69129046")               == aint("7943920");
	aint("371069152401")              / aint("96941")                  == aint("3827783");
	aint("88732662")                  / aint("551")                    == aint("161039");

    // some random test (generated with ./gen-mod-test.sh)
	aint("247864133182739061709665")  % aint("75161073912661379")      == aint("48143633920562077");
	aint("29260703937555036860")      % aint("61846723655687")         == aint("29428471026168");
	aint("16324159833309793")         % aint("209771577036")           == aint("155251522345");
	aint("118749018944734")           % aint("628800791")              == aint("618365175");
	aint("381907890085")              % aint("226738")                 == aint("152619");
	aint("198245866")                 % aint("440")                    == aint("346");
	aint("476220794594304471314703")  % aint("744195371093477472")     == aint("502091764021774767");
	aint("430026179359660743794")     % aint("479727185769180")        == aint("169217725099334");
	aint("351592821468607817")        % aint("234367352804")           == aint("74873808705");
	aint("363251958169375")           % aint("447681757")              == aint("294449033");
	aint("383001171735")              % aint("476931")                 == aint("301392");
	aint("4065472")                   % aint("205")                    == aint("117");
	aint("209629104076305505390420")  % aint("70881051638170957")      == aint("24120602577994931");
	aint("116361337657463925341")     % aint("112850048130471")        == aint("73129461450647");
	aint("183822886575974938")        % aint("23543679267")            == aint("7303206892");
	aint("188708312511306")           % aint("65573179")               == aint("47509273");
	aint("170597308037")              % aint("760598")                 == aint("500823");
	aint("58976984")                  % aint("178")                    == aint("66");
	aint("145122317176238838946891")  % aint("43851813369585145")      == aint("3047201151786791");
	aint("728832504790571076264")     % aint("225872573234185")        == aint("211960323735179");
	aint("49705926792363495")         % aint("513067282034")           == aint("481576191609");
	aint("387108630501980")           % aint("889673364")              == aint("184071848");
	aint("9561835063")                % aint("68813")                  == aint("62274");
	aint("204005197")                 % aint("284")                    == aint("45");

	// long division plus sign checks
	*a1 = aint("+1234567890111111"); *a2 = aint("+1234554321"); ad = a1->div(*a2); CPPUNIT_ASSERT( (*a1) == (*a2) * ad.first + ad.second );
	*a1 = aint("-1234567890111111"); *a2 = aint("+1234554321"); ad = a1->div(*a2); CPPUNIT_ASSERT( (*a1) == (*a2) * ad.first + ad.second );
	*a1 = aint("+1234567890111111"); *a2 = aint("-1234554321"); ad = a1->div(*a2); CPPUNIT_ASSERT( (*a1) == (*a2) * ad.first + ad.second );
	*a1 = aint("-1234567890111111"); *a2 = aint("-1234554321"); ad = a1->div(*a2); CPPUNIT_ASSERT( (*a1) == (*a2) * ad.first + ad.second );
	// short division plus sign checks
	*a1 = aint("+1234567890111111"); *a2 = aint("+123"); ad = a1->div(*a2); CPPUNIT_ASSERT( (*a1) == (*a2) * ad.first + ad.second );
	*a1 = aint("-1234567890111111"); *a2 = aint("+123"); ad = a1->div(*a2); CPPUNIT_ASSERT( (*a1) == (*a2) * ad.first + ad.second );
	*a1 = aint("+1234567890111111"); *a2 = aint("-123"); ad = a1->div(*a2); CPPUNIT_ASSERT( (*a1) == (*a2) * ad.first + ad.second );
	*a1 = aint("-1234567890111111"); *a2 = aint("-123"); ad = a1->div(*a2); CPPUNIT_ASSERT( (*a1) == (*a2) * ad.first + ad.second );

	// long division example for [D6] if using SINGLE_16
	*a1 = aint("+1000000000000000"); *a2 = aint("+1002985889"); ad = a1->div(*a2); CPPUNIT_ASSERT( (*a1) == (*a2) * ad.first + ad.second );
	*a1 = aint("-1000000000000000"); *a2 = aint("+1002985889"); ad = a1->div(*a2); CPPUNIT_ASSERT( (*a1) == (*a2) * ad.first + ad.second );
	*a1 = aint("+1000000000000000"); *a2 = aint("-1002985889"); ad = a1->div(*a2); CPPUNIT_ASSERT( (*a1) == (*a2) * ad.first + ad.second );
	*a1 = aint("-1000000000000000"); *a2 = aint("-1002985889"); ad = a1->div(*a2); CPPUNIT_ASSERT( (*a1) == (*a2) * ad.first + ad.second );


}

// eof
