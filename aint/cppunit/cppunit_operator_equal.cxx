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

void aintTest::testOperatorEqual()        {

    CPPUNIT_ASSERT( aint("0") == 0    );
    CPPUNIT_ASSERT( aint("0") == 0L   );
    CPPUNIT_ASSERT( aint("0") == 0LL  );
    CPPUNIT_ASSERT( aint("0") == 0U   );
    CPPUNIT_ASSERT( aint("0") == 0UL  );
    CPPUNIT_ASSERT( aint("0") == 0ULL );

    CPPUNIT_ASSERT( aint("-1") == -1    );
    CPPUNIT_ASSERT( aint("-1") == -1L   );
    CPPUNIT_ASSERT( aint("-1") == -1LL  );
    CPPUNIT_ASSERT( aint( "1") ==  1    );
    CPPUNIT_ASSERT( aint( "1") ==  1L   );
    CPPUNIT_ASSERT( aint( "1") ==  1LL  );
    CPPUNIT_ASSERT( aint( "1") ==  1U   );
    CPPUNIT_ASSERT( aint( "1") ==  1UL  );
    CPPUNIT_ASSERT( aint( "1") ==  1ULL );

    CPPUNIT_ASSERT( aint("-1000000"      ) ==       -1000000    );
    CPPUNIT_ASSERT( aint( "1000000"      ) ==        1000000    );
    CPPUNIT_ASSERT( aint( "1000000"      ) ==        1000000U   );
    CPPUNIT_ASSERT( aint("-1000000000"   ) ==    -1000000000L   );
    CPPUNIT_ASSERT( aint( "1000000000"   ) ==     1000000000L   );
    CPPUNIT_ASSERT( aint( "1000000000"   ) ==     1000000000UL  );
    CPPUNIT_ASSERT( aint("-1000000000000") == -1000000000000LL  );
    CPPUNIT_ASSERT( aint( "1000000000000") ==  1000000000000LL  );
    CPPUNIT_ASSERT( aint( "1000000000000") ==  1000000000000ULL );

    CPPUNIT_ASSERT(       -1000000    == aint("-1000000"      ) );
    CPPUNIT_ASSERT(        1000000    == aint( "1000000"      ) );
    CPPUNIT_ASSERT(        1000000U   == aint( "1000000"      ) );
    CPPUNIT_ASSERT(    -1000000000L   == aint("-1000000000"   ) );
    CPPUNIT_ASSERT(     1000000000L   == aint( "1000000000"   ) );
    CPPUNIT_ASSERT(     1000000000UL  == aint( "1000000000"   ) );
    CPPUNIT_ASSERT( -1000000000000LL  == aint("-1000000000000") );
    CPPUNIT_ASSERT(  1000000000000LL  == aint( "1000000000000") );
    CPPUNIT_ASSERT(  1000000000000ULL == aint( "1000000000000") );

    CPPUNIT_ASSERT( (*a1 = aint("0")) == 0    );
    CPPUNIT_ASSERT( (*a1 = aint("0")) == 0L   );
    CPPUNIT_ASSERT( (*a1 = aint("0")) == 0LL  );
    CPPUNIT_ASSERT( (*a1 = aint("0")) == 0U   );
    CPPUNIT_ASSERT( (*a1 = aint("0")) == 0UL  );
    CPPUNIT_ASSERT( (*a1 = aint("0")) == 0ULL );

    CPPUNIT_ASSERT( (*a1 = aint("-1")) == -1    );
    CPPUNIT_ASSERT( (*a1 = aint("-1")) == -1L   );
    CPPUNIT_ASSERT( (*a1 = aint("-1")) == -1LL  );
    CPPUNIT_ASSERT( (*a1 = aint( "1")) ==  1    );
    CPPUNIT_ASSERT( (*a1 = aint( "1")) ==  1L   );
    CPPUNIT_ASSERT( (*a1 = aint( "1")) ==  1LL  );
    CPPUNIT_ASSERT( (*a1 = aint( "1")) ==  1U   );
    CPPUNIT_ASSERT( (*a1 = aint( "1")) ==  1UL  );
    CPPUNIT_ASSERT( (*a1 = aint( "1")) ==  1ULL );

    CPPUNIT_ASSERT( (*a1 =       -1000000   ) == aint(      -1000000   ) );
    CPPUNIT_ASSERT( (*a1 =        1000000   ) == aint(       1000000   ) );
    CPPUNIT_ASSERT( (*a1 =        1000000U  ) == aint(       1000000U  ) );
    CPPUNIT_ASSERT( (*a1 =    -1000000000L  ) == aint(   -1000000000L  ) );
    CPPUNIT_ASSERT( (*a1 =     1000000000L  ) == aint(    1000000000L  ) );
    CPPUNIT_ASSERT( (*a1 =     1000000000UL ) == aint(    1000000000UL ) );
    CPPUNIT_ASSERT( (*a1 = -1000000000000LL ) == aint(-1000000000000LL ) );
    CPPUNIT_ASSERT( (*a1 =  1000000000000LL ) == aint( 1000000000000LL ) );
    CPPUNIT_ASSERT( (*a1 =  1000000000000ULL) == aint( 1000000000000ULL) );

    CPPUNIT_ASSERT( (*a1 = "1000000000000"  ) == aint( 1000000000000LL ) );
    CPPUNIT_ASSERT( (*a1 = std::string("1000000000000")  ) == aint( 1000000000000LL ) );
}

// eof
