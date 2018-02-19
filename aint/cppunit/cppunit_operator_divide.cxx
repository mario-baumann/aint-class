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

void aintTest::testOperatorDivide()
{
    CPPUNIT_ASSERT( aint("+1") / aint("+1") == aint("+1") );
    CPPUNIT_ASSERT( aint("+1") / aint("+2") == aint("+0") );

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

    // some random test (generated with ./gen-div-test.sh)
    CPPUNIT_ASSERT( aint("630117642690728144247")     / aint("417530467693679131")     == aint("1509")      );
    CPPUNIT_ASSERT( aint("343013520236615931595")     / aint("501922806668882")        == aint("683398")    );
    CPPUNIT_ASSERT( aint("537599207192691449")        / aint("561211730795")           == aint("957925")    );
    CPPUNIT_ASSERT( aint("26647207533088")            / aint("394020614")              == aint("67628")     );
    CPPUNIT_ASSERT( aint("362242238140")              / aint("36829")                  == aint("9835788")   );
    CPPUNIT_ASSERT( aint("115337930")                 / aint("681")                    == aint("169365")    );
    CPPUNIT_ASSERT( aint("396063740625009400288190")  / aint("341798766356591896")     == aint("1158762")   );
    CPPUNIT_ASSERT( aint("85768798985559927661")      / aint("562929919811216")        == aint("152361")    );
    CPPUNIT_ASSERT( aint("176746309367103306")        / aint("225780399315")           == aint("782823")    );
    CPPUNIT_ASSERT( aint("545187676591109")           / aint("696790159")              == aint("782427")    );
    CPPUNIT_ASSERT( aint("159746536958")              / aint("106499")                 == aint("1499981")   );
    CPPUNIT_ASSERT( aint("576246082")                 / aint("21")                     == aint("27440289")  );
    CPPUNIT_ASSERT( aint("47726510044250646644496")   / aint("518780663957118723")     == aint("91997")     );
    CPPUNIT_ASSERT( aint("161535597700403413567")     / aint("91152990043274")         == aint("1772137")   );
    CPPUNIT_ASSERT( aint("441372403411481597")        / aint("6915498146")             == aint("63823660")  );
    CPPUNIT_ASSERT( aint("2812831530799")             / aint("12527644")               == aint("224529")    );
    CPPUNIT_ASSERT( aint("147345896775")              / aint("742")                    == aint("198579375") );
    CPPUNIT_ASSERT( aint("490418140")                 / aint("415")                    == aint("1181730")   );
    CPPUNIT_ASSERT( aint("563146025268852810033084")  / aint("101510106331794763")     == aint("5547684")   );
    CPPUNIT_ASSERT( aint("50254077357200553468")      / aint("1504885924194")          == aint("33393944")  );
    CPPUNIT_ASSERT( aint("18107340051597150")         / aint("53720972553")            == aint("337062")    );
    CPPUNIT_ASSERT( aint("549155621379169")           / aint("69129046")               == aint("7943920")   );
    CPPUNIT_ASSERT( aint("371069152401")              / aint("96941")                  == aint("3827783")   );
    CPPUNIT_ASSERT( aint("88732662")                  / aint("551")                    == aint("161039")    );

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

