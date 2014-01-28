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

void aintTest::testOperatorLess() {

    CPPUNIT_ASSERT( aint("+1"            ) < aint("+2"            ) ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1"            ) < aint("+1"            ) ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-2"            ) < aint("-1"            ) ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( aint("-1"            ) < aint("+0"            ) ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"            ) < aint("+1"            ) ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1000000"      ) < aint("+2000000"      ) ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000"      ) < aint("+1000000"      ) ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-2000000"      ) < aint("-1000000"      ) ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( aint("-1000000"      ) < aint("+0"            ) ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"            ) < aint("+1000000"      ) ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1000000000000") < aint("+2000000000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000000000") < aint("+1000000000000") ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-2000000000000") < aint("-1000000000000") ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( aint("-1000000000000") < aint("+0"            ) ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"            ) < aint("+1000000000000") ); // less where lhs == 0 and rhs > 0

    CPPUNIT_ASSERT( aint("+1") <  2    ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1") <  1    ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-2") < -1    ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( aint("-1") <  0    ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0") <  1    ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1") <  2L   ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1") <  1L   ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-2") < -1L   ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( aint("-1") <  0L   ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0") <  1L   ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1") <  2LL  ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1") <  1LL  ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-2") < -1LL  ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( aint("-1") <  0LL  ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0") <  1LL  ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1") <  2U   ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1") <  1U   ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1") <  0U   ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0") <  1U   ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1") <  2UL  ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1") <  1UL  ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1") <  0UL  ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0") <  1UL  ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1") <  2ULL ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1") <  1ULL ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1") <  0ULL ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0") <  1ULL ); // less where lhs == 0 and rhs > 0

    CPPUNIT_ASSERT( aint("+1000000") <  2000000    ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000") <  1000000    ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-2000000") < -1000000    ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( aint("-1000000") <        0    ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"      ) <  1000000    ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1000000") <  2000000L   ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000") <  1000000L   ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-2000000") < -1000000L   ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( aint("-1000000") <        0L   ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"      ) <  1000000L   ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1000000") <  2000000LL  ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000") <  1000000LL  ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-2000000") < -1000000LL  ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( aint("-1000000") <        0LL  ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"      ) <  1000000LL  ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1000000") <  2000000U   ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000") <  1000000U   ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000") <        0U   ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"      ) <  1000000U   ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1000000") <  2000000UL  ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000") <  1000000UL  ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000") <        0UL  ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"      ) <  1000000UL  ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1000000") <  2000000ULL ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000") <  1000000ULL ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000") <        0ULL ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"      ) <  1000000ULL ); // less where lhs == 0 and rhs > 0

    CPPUNIT_ASSERT( aint("+1000000000000") <  2000000000000    ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000000000") <  1000000000000    ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-2000000000000") < -1000000000000    ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( aint("-1000000000000") <              0    ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"            ) <  1000000000000    ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1000000000000") <  2000000000000L   ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000000000") <  1000000000000L   ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-2000000000000") < -1000000000000L   ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( aint("-1000000000000") <              0L   ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"            ) <  1000000000000L   ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1000000000000") <  2000000000000LL  ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000000000") <  1000000000000LL  ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-2000000000000") < -1000000000000LL  ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( aint("-1000000000000") <              0LL  ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"            ) <  1000000000000LL  ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1000000000000") <  2000000000000U   ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000000000") <  1000000000000U   ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000000000") <              0U   ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"            ) <  1000000000000U   ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1000000000000") <  2000000000000UL  ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000000000") <  1000000000000UL  ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000000000") <              0UL  ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"            ) <  1000000000000UL  ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT( aint("+1000000000000") <  2000000000000ULL ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000000000") <  1000000000000ULL ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( aint("-1000000000000") <              0ULL ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT( aint("+0"            ) <  1000000000000ULL ); // less where lhs == 0 and rhs > 0

    CPPUNIT_ASSERT(  1    < aint("+2") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( -1    < aint("+1") ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( -2    < aint("-1") ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( -1    < aint( "0") ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT(  0    < aint("+1") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1L   < aint("+2") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( -1L   < aint("+1") ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( -2L   < aint("-1") ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( -1L   < aint( "0") ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT(  0L   < aint("+1") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1LL  < aint("+2") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( -1LL  < aint("+1") ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( -2LL  < aint("-1") ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( -1LL  < aint( "0") ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT(  0LL  < aint("+1") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1U   < aint("+2") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT(  0U   < aint("+1") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1UL  < aint("+2") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT(  0UL  < aint("+1") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1ULL < aint("+2") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT(  0ULL < aint("+1") ); // less where lhs == 0 and rhs > 0

    CPPUNIT_ASSERT(  1000000    < aint("+2000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( -1000000    < aint("+1000000") ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( -2000000    < aint("-1000000") ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( -1000000    < aint(       "0") ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT(        0    < aint("+1000000") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1000000L   < aint("+2000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( -1000000L   < aint("+1000000") ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( -2000000L   < aint("-1000000") ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( -1000000L   < aint(       "0") ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT(        0L   < aint("+1000000") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1000000LL  < aint("+2000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( -1000000LL  < aint("+1000000") ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( -2000000LL  < aint("-1000000") ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( -1000000LL  < aint(       "0") ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT(        0LL  < aint("+1000000") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1000000U   < aint("+2000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT(        0U   < aint("+1000000") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1000000UL  < aint("+2000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT(        0UL  < aint("+1000000") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1000000ULL < aint("+2000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT(        0ULL < aint("+1000000") ); // less where lhs == 0 and rhs > 0

    CPPUNIT_ASSERT(  1000000000000    < aint("+2000000000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( -1000000000000    < aint("+1000000000000") ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( -2000000000000    < aint("-1000000000000") ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( -1000000000000    < aint(             "0") ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT(              0    < aint("+1000000000000") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1000000000000L   < aint("+2000000000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( -1000000000000L   < aint("+1000000000000") ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( -2000000000000L   < aint("-1000000000000") ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( -1000000000000L   < aint(             "0") ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT(              0L   < aint("+1000000000000") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1000000000000LL  < aint("+2000000000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT( -1000000000000LL  < aint("+1000000000000") ); // less where lhs < 0 and rhs > 0
    CPPUNIT_ASSERT( -2000000000000LL  < aint("-1000000000000") ); // less where lhs < 0 and rhs < 0
    CPPUNIT_ASSERT( -1000000000000LL  < aint(             "0") ); // less where lhs < 0 and rhs == 0
    CPPUNIT_ASSERT(              0LL  < aint("+1000000000000") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1000000000000U   < aint("+2000000000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT(              0U   < aint("+1000000000000") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1000000000000UL  < aint("+2000000000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT(              0UL  < aint("+1000000000000") ); // less where lhs == 0 and rhs > 0
    CPPUNIT_ASSERT(  1000000000000ULL < aint("+2000000000000") ); // less where lhs > 0 and rhs > 0
    CPPUNIT_ASSERT(              0ULL < aint("+1000000000000") ); // less where lhs == 0 and rhs > 0
}

// eof
