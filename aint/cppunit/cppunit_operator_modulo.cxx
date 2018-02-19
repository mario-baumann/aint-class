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

void aintTest::testOperatorModulo()
{
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

    // some random test (generated with ./gen-mod-test.sh)
    CPPUNIT_ASSERT( aint("247864133182739061709665")  % aint("75161073912661379")      == aint("48143633920562077") );
    CPPUNIT_ASSERT( aint("29260703937555036860")      % aint("61846723655687")         == aint("29428471026168") );
    CPPUNIT_ASSERT( aint("16324159833309793")         % aint("209771577036")           == aint("155251522345") );
    CPPUNIT_ASSERT( aint("118749018944734")           % aint("628800791")              == aint("618365175") );
    CPPUNIT_ASSERT( aint("381907890085")              % aint("226738")                 == aint("152619") );
    CPPUNIT_ASSERT( aint("198245866")                 % aint("440")                    == aint("346") );
    CPPUNIT_ASSERT( aint("476220794594304471314703")  % aint("744195371093477472")     == aint("502091764021774767") );
    CPPUNIT_ASSERT( aint("430026179359660743794")     % aint("479727185769180")        == aint("169217725099334") );
    CPPUNIT_ASSERT( aint("351592821468607817")        % aint("234367352804")           == aint("74873808705") );
    CPPUNIT_ASSERT( aint("363251958169375")           % aint("447681757")              == aint("294449033") );
    CPPUNIT_ASSERT( aint("383001171735")              % aint("476931")                 == aint("301392") );
    CPPUNIT_ASSERT( aint("4065472")                   % aint("205")                    == aint("117") );
    CPPUNIT_ASSERT( aint("209629104076305505390420")  % aint("70881051638170957")      == aint("24120602577994931") );
    CPPUNIT_ASSERT( aint("116361337657463925341")     % aint("112850048130471")        == aint("73129461450647") );
    CPPUNIT_ASSERT( aint("183822886575974938")        % aint("23543679267")            == aint("7303206892") );
    CPPUNIT_ASSERT( aint("188708312511306")           % aint("65573179")               == aint("47509273") );
    CPPUNIT_ASSERT( aint("170597308037")              % aint("760598")                 == aint("500823") );
    CPPUNIT_ASSERT( aint("58976984")                  % aint("178")                    == aint("66") );
    CPPUNIT_ASSERT( aint("145122317176238838946891")  % aint("43851813369585145")      == aint("3047201151786791") );
    CPPUNIT_ASSERT( aint("728832504790571076264")     % aint("225872573234185")        == aint("211960323735179") );
    CPPUNIT_ASSERT( aint("49705926792363495")         % aint("513067282034")           == aint("481576191609") );
    CPPUNIT_ASSERT( aint("387108630501980")           % aint("889673364")              == aint("184071848") );
    CPPUNIT_ASSERT( aint("9561835063")                % aint("68813")                  == aint("62274") );
    CPPUNIT_ASSERT( aint("204005197")                 % aint("284")                    == aint("45") );
}

// eof

