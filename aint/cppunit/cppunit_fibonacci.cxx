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

// fibonacci with arbitrary long integer
// aint unit tests

#include "cppunit.hxx"
#include <iostream>
#if defined(PRINT_CPPUNIT_FIBONACCI)
#include <iostream>
#include <iomanip>
#endif

void aintTest::testFibonacci() {
    aint f1("-1"); // F_{-2}
    aint f2("+1"); // F_{-1}
    aint fj;
    for (int j = 0; j <= 300; ++j) {
        fj = f1 + f2;
#if defined(PRINT_CPPUNIT_FIBONACCI)
        if (j < 10 || j % 10 == 0) {
            std::cout << "fibonacci[" << std::setw(3) << std::setfill('0') << j << "] = " << fj << std::endl;
        }
#endif
        f1 = f2;
        f2 = fj;
    }
    aint F_300 = fj;
    // http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibtable.html
    aint F_300_ref = aint("222232244629420445529739893461909967206666939096499764990979600");
    CPPUNIT_ASSERT( F_300 == F_300_ref );
}

// eof
