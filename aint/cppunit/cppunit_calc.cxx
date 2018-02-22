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

// aint unit tests for calc

#include "cppunit.hxx"
#include <iostream>
#include "../calc/include/aint_calc.hxx"

static const aint passingFailed(-1234567890_A);

static const aint& testCalcHelper(std::string input) {
    typedef std::string::const_iterator iterator_type;
    typedef client::calculator<iterator_type> calculator;
    boost::spirit::ascii::space_type space; // Our skipper
    calculator calc; // Our grammar

    auto iter = input.cbegin();
    auto end = input.cend();
    bool r = phrase_parse(iter, end, calc, space);
    if (r && iter == end) {
	return (client::stck.top()); // passed
    }

    // error handling
    std::string rest(iter, end);
    std::cout << "Parsing of '" << input << "' failed (stopped at '" << rest << "')!" << std::endl;
    return (passingFailed);
}

void aintTest::testCalc() {

    CPPUNIT_ASSERT( testCalcHelper("1") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("1+0") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("1+1") == 2 );
    CPPUNIT_ASSERT( testCalcHelper("1-1") == 0 );
    CPPUNIT_ASSERT( testCalcHelper("1-2") == -1 );
    CPPUNIT_ASSERT( testCalcHelper("1-2*3") == -5 );
}

// eof
