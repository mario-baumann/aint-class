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
#include "aint_calc.hxx"
#include <iostream>

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
    // unary tests
    CPPUNIT_ASSERT( testCalcHelper("1") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("1 ") == 1 );
    CPPUNIT_ASSERT( testCalcHelper(" 1") == 1 );
    CPPUNIT_ASSERT( testCalcHelper(" 1 ") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("(1)") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("(((((1)))))") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("-(-(-(-(-(-(-1))))))") == -1 );
    CPPUNIT_ASSERT( testCalcHelper("+1") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("+(1)") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("++1") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("+(+1)") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("+++1") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("+(++1)") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("-1") == -1 );
    CPPUNIT_ASSERT( testCalcHelper("-(1)") == -1 );
    CPPUNIT_ASSERT( testCalcHelper("--1") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("-(-1)") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("---1") == -1 );
    CPPUNIT_ASSERT( testCalcHelper("-(--1)") == -1 );
    CPPUNIT_ASSERT( testCalcHelper("-+-1") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("-+(-1)") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("-(+-1)") == 1 );

    // plus/minus tests
    CPPUNIT_ASSERT( testCalcHelper("1+0") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("4+1") == 5 );
    CPPUNIT_ASSERT( testCalcHelper("4-1") == 3 );
    CPPUNIT_ASSERT( testCalcHelper("-4+1") == -3 );
    CPPUNIT_ASSERT( testCalcHelper("-4-1") == -5 );
    CPPUNIT_ASSERT( testCalcHelper("1+4") == 5 );
    CPPUNIT_ASSERT( testCalcHelper("1-4") == -3 );
    CPPUNIT_ASSERT( testCalcHelper("-1+4") == 3 );
    CPPUNIT_ASSERT( testCalcHelper("-1-4") == -5 );
    CPPUNIT_ASSERT( testCalcHelper("(4)+(1)") == 5 );
    CPPUNIT_ASSERT( testCalcHelper("(4)+(-1)") == 3 );
    CPPUNIT_ASSERT( testCalcHelper("(-4)+(1)") == -3 );
    CPPUNIT_ASSERT( testCalcHelper("(-4)+(-1)") == -5 );
    CPPUNIT_ASSERT( testCalcHelper("(1)+(4)") == 5 );
    CPPUNIT_ASSERT( testCalcHelper("(1)+(-4)") == -3 );
    CPPUNIT_ASSERT( testCalcHelper("(-1)+(4)") == 3 );
    CPPUNIT_ASSERT( testCalcHelper("(-1)+(-4)") == -5 );
    CPPUNIT_ASSERT( testCalcHelper("2 -4  +6 -1    -1- 0      +8") == 10 );
    CPPUNIT_ASSERT( testCalcHelper("1-1  + 2 -    2       +    4-4                 +6") == 6 );

    // times tests
    CPPUNIT_ASSERT( testCalcHelper("2*0") == 0 );
    CPPUNIT_ASSERT( testCalcHelper("2*3") == 6 );
    CPPUNIT_ASSERT( testCalcHelper("2*-3") == -6 );
    CPPUNIT_ASSERT( testCalcHelper("-2*3") == -6 );
    CPPUNIT_ASSERT( testCalcHelper("-2*-3") == 6 );
    CPPUNIT_ASSERT( testCalcHelper("(2)*(3)") == 6 );
    CPPUNIT_ASSERT( testCalcHelper("(2)*(-3)") == -6 );
    CPPUNIT_ASSERT( testCalcHelper("(-2)*(3)") == -6 );
    CPPUNIT_ASSERT( testCalcHelper("(-2)*(-3)") == 6 );
    CPPUNIT_ASSERT( testCalcHelper(" 2*3 *5     * 4 ") == 120 );
  
    // divide/modulo tests
    CPPUNIT_ASSERT( testCalcHelper("3/2") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("3/-2") == -1 );
    CPPUNIT_ASSERT( testCalcHelper("-3/2") == -1 );
    CPPUNIT_ASSERT( testCalcHelper("-3/-2") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("3%2") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("3%-2") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("-3%2") == -1 );
    CPPUNIT_ASSERT( testCalcHelper("-3%-2") == -1 );

    // power/towerposer tests
    CPPUNIT_ASSERT( testCalcHelper("2^(-1)") == 0 );
    CPPUNIT_ASSERT( testCalcHelper("2^0") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("2^1") == 2 );
    CPPUNIT_ASSERT( testCalcHelper("2^2") == 4 );
    CPPUNIT_ASSERT( testCalcHelper("2^10") == 1024 );
    CPPUNIT_ASSERT( testCalcHelper("2^^(-1)") == 0 );
    CPPUNIT_ASSERT( testCalcHelper("2^^0") == 1 );
    CPPUNIT_ASSERT( testCalcHelper("2^^1") == 2 );
    CPPUNIT_ASSERT( testCalcHelper("2^^2") == 4 );
    CPPUNIT_ASSERT( testCalcHelper("2^^4") == 65536 );

    // common tests
    CPPUNIT_ASSERT( testCalcHelper("1+2*3") == 7 );
    CPPUNIT_ASSERT( testCalcHelper("1+2*3^4") == 163 );
    CPPUNIT_ASSERT( testCalcHelper("1-3^2") == -8 );
    CPPUNIT_ASSERT( testCalcHelper("1+3/2") == 2 );
    CPPUNIT_ASSERT( testCalcHelper(" 2*3 - 4*5 + 6/3 + 20%8") == -8 );

    // common tests  (result calculated with bc)
    CPPUNIT_ASSERT( testCalcHelper("(4 + 4 % (((((5 * (((5 % (3 + 11 + 8 * (7 % ((11 * ((3 ^ (6 + 5 + 8)) % 5 + 5 + 3) - 6 - 4) / 9))) - 8 - 10) % 5) / 11) - 6) % 7) % 4) % 11 + 5) / 3)) * 3") == 12 );
    CPPUNIT_ASSERT( testCalcHelper("(((7 + ((7 * (((8 + (((8 + 7 * 5 ^ 9 * 3 % 8 % 7 / 9 - 8) * 2) / 3 - 9 + 11) * 11 - 8 - 7) * 6) / 7) - 6) ^ 11) * 8 + 9) * 5 - 7) / 6 + 6) % 11") == 10 );
    CPPUNIT_ASSERT( testCalcHelper("(((6 ^ ((4 + 3 % ((8 * (11 ^ ((5 ^ (7 ^ (10 ^ (4 ^ ((3 ^ 9 ^ 3 * 9 ^ 10 * 11 / 3 % 5 / 5 - 10) / 6)))) + 6) / 10)) - 3) / 6) - 4 - 2) % 9)) * 9) / 3) / 6") == 3);
    CPPUNIT_ASSERT( testCalcHelper("((8 + ((8 ^ (6 % (11 % (2 * ((9 * (2 ^ (2 % ((((((7 % (4 + (5 * 7 - 7) / 9) - 5) * 5) % 9) * 5) ^ 11) * 4 - 4)))) ^ 10 + 5))))) / 5) / 2) ^ 11) / 5 - 2 - 7 - 2") == 806035072224950350147480695726377446727567241614_A );
    CPPUNIT_ASSERT( testCalcHelper("5 % (3 + (((((6 * (11 ^ (2 + ((7 + 10 % ((9 * (8 % (4 * ((((4 - 9) % 4) * 8) * 11)))) * 9)) / 4) % 11 - 9 + 7) - 2 - 6)) * 9 - 9) / 7) / 3) / 7 + 10) / 3 - 3)") == 5 );
    CPPUNIT_ASSERT( testCalcHelper("((11 + ((6 % (11 ^ ((3 ^ (8 ^ (((((4 + 3 % (7 + 8 + 10 - 3)) / 8) ^ 10) / 6) % 6 - 6 - 8)) - 5 - 4 + 3) ^ 6) + 6)) % 7 - 3 + 7) * 5 + 4) * 9) / 6 + 5") == 102 );
    CPPUNIT_ASSERT( testCalcHelper("(5 * (6 % (6 * ((4 + 7 * (((((((((2 + 7 % (11 + 7 ^ (9 * ((7 * (3 + 5 * 11) + 4) / 7)) + 8)) ^ 7 + 7 - 11) / 9) * 5) % 3) ^ 9) / 5) / 7) / 4 + 3)) / 3)))) ^ 4") == 810000 ); 
    CPPUNIT_ASSERT( testCalcHelper("5 * ((((((((2 % ((5 + (2 % (((9 % ((5 + 11 ^ 11 * 7 ^ 6 * 10) / 6)) * 7) % 6)) / 2 + 2 - 11 + 2 + 8 + 5) * 6)) / 11) / 4) * 2) / 9) / 7) / 10) / 7) - 4 - 9") == -13 );
    CPPUNIT_ASSERT( testCalcHelper("((2 + 4 * ((((((9 % (2 + 10 % ((7 * (((8 * (7 ^ 4 % 10 / 10 - 5 - 10 - 11)) * 3) * 5)) ^ 7 - 10) + 4)) % 9) % 6) * 5) * 8 + 9 - 3) * 6 + 10 - 6)) / 8) / 5") == 4 );
    CPPUNIT_ASSERT( testCalcHelper("(4 ^ (5 + 7 + (((5 + (10 ^ (3 ^ (7 ^ (3 * (((10 + 3 ^ (6 * (((6 - 3) / 8) / 4 - 11) - 7) - 8 - 11) * 11) / 7) + 3) - 3 - 4 - 5))) * 11) / 11) ^ 5) % 5)) * 3") == 201326592 );
    CPPUNIT_ASSERT( testCalcHelper("9 + ((2 % ((((11 + ((6 * (11 + 11 % (5 * ((2 ^ ((((((7 / 11 + 3) / 11) ^ 6) / 3 - 11) / 7 - 8) % 7)) % 7) - 5)) - 10 - 9) % 2) ^ 8) / 9) * 4 - 9) ^ 2)) * 2) * 10") == 49 );
    CPPUNIT_ASSERT( testCalcHelper("(4 % (3 + (9 + ((((3 % ((((((2 + (10 + ((9 + (((2 % (4 * (((9 ^ ((10 * (6 + (((((2 * (4 + 8 % 10 * 4 + 5) - 7) ^ 9 + 3) * 10) % 3) ^ 3) ^ 5)) / 5)) * 6 - 2) % 10))) * 9) / 2) % 3 + 7) / 10) / 6) / 10 - 6) * 2) ^ 8) * 6) * 7) / 10 - 8)) * 2) * 9 + 5) * 8) / 2) ^ 4)) ^ 3") == 64 );
    CPPUNIT_ASSERT( testCalcHelper("3 + 7 * (3 % (9 * ((6 * (7 + (((9 * (((9 ^ (6 * ((((2 * ((11 % ((((9 + 9 * (2 + (4 % (5 + (2 % ((4 % (3 ^ (((8 + (8 + 11 % 11 - 9) / 6 - 7) ^ 2 + 8) / 4) - 10)) / 11 + 5) - 10 - 8) / 2)) % 8 - 9)) / 5) / 8) / 10 + 5 - 2 + 5) - 10) % 5)) / 4) / 2 - 3) * 7))) ^ 4) / 11)) / 5) ^ 8) / 2 + 8 + 7)) * 4) - 4) + 5) + 9") == 68 );
    CPPUNIT_ASSERT( testCalcHelper("3 % ((3 * ((((3 ^ (11 % ((((7 + 10 + 10 + (6 * (((((((4 ^ (((8 % (3 % (10 + (((((((((3 ^ ((10 % (2 + 7 * 2 / 3 / 4 / 2) - 5 + 4) / 9)) / 5 - 7) % 7) ^ 11) / 3 + 8) % 10) * 3) / 7) * 7) / 6 + 6)) - 7) % 2 + 7 - 10 + 2) ^ 11)) % 3) % 2) % 11) ^ 5 - 3 + 7 + 6) * 2 + 11) * 8)) / 11 + 2) ^ 7) / 10) ^ 4))) ^ 6) / 10) / 2)) * 7)") == 3 );
    CPPUNIT_ASSERT( testCalcHelper("5 + (10 % ((2 * (((6 % ((2 ^ (3 + ((((6 ^ (((5 + 10 % (((9 % (3 + 6 + 9 * (11 ^ (4 + (((4 ^ (((6 + 3 + ((3 * (2 - 7 - 8 - 7)) / 2 - 9) ^ 4 - 8) % 10 + 10) / 3 - 4) - 11) * 5) % 8) / 6)))) ^ 5 - 9 - 10) / 4) + 11) % 6) * 2)) % 5) / 5) * 7) / 5 - 10 - 4 + 9 - 4 - 5) + 6) / 2)) ^ 8 - 11) % 4)) % 9) - 6) ^ 6 - 7") == 62 );
    CPPUNIT_ASSERT( testCalcHelper("((10 + (((8 % (6 + (4 + (((8 % ((10 + ((11 + (((2 + (((9 + (((((9 + (7 ^ (11 % (5 + 11 ^ (11 + 11 ^ ((10 + 5 - 11 - 6 - 11) / 3 + 3)) - 5 - 3))) / 3) * 7) * 3) / 11 - 5) ^ 6) ^ 7 - 9 - 4) / 7) % 9 - 6) / 7 - 7 + 4) ^ 8) / 4 - 5 - 10 - 8) ^ 11) / 10) / 3 - 10) % 7)) / 2) / 11) / 6) % 11 - 9)) ^ 5) % 10) * 9) * 11) / 7") == 15 );
    CPPUNIT_ASSERT( testCalcHelper("(8 + (11 * ((4 * ((6 * ((3 % (5 ^ ((11 * (11 + (((((3 ^ ((10 + 3 + 4 ^ (((7 * (((((((((((11 % (((8 ^ (3 ^ ((2 + (10 * (7 + 7)) / 4) % 2))) ^ 9) ^ 8)) ^ 5) ^ 6) ^ 9) / 6) % 2) % 2) ^ 5) * 7 + 10) * 6) / 3 - 9) - 8) ^ 2) % 8)) % 9)) % 5) / 5 - 7) % 5) ^ 5) % 5)) * 4 - 7 + 4))) * 8)) * 7)) / 7) - 6 - 9) ^ 5 - 9) / 2 + 11 + 10 - 6") == 5045438954795567815_A );
    CPPUNIT_ASSERT( testCalcHelper("((((5 * (9 + (4 + 7 * (4 ^ ((8 + (8 + ((((5 + 7 + (4 + 11 ^ ((4 + 11 * ((8 % (2 + (((10 + 2 ^ ((3 * (((((7 + (6 * (((3 ^ (9 % 9 - 5)) ^ 3 + 10) ^ 6)) % 2 - 11) * 8) / 9) % 10 + 9) % 5)) / 2)) ^ 9 - 3) / 6 - 11) ^ 8)) % 11)) / 4)) / 2) / 8) ^ 11) % 7 + 8) % 7) / 4 - 7 - 4) ^ 5) - 10) - 7) ^ 6)) ^ 8 - 11) / 9) * 11) ^ 4") == 297597984488737393221798308291626706906908354972097685986685987711744781213731956584098936942565407116495740286387981086988315962544861436977332472979267219319288328982372532000410736307545917161819452873739725131022725685933731886827735537838265207489523806742450692724035958916549945880472446041037617381689177269489681945334446995525273405000339566728028511682364436710115311616_A );
    CPPUNIT_ASSERT( testCalcHelper("10 + (((11 + (4 * ((((7 * (((((5 * ((2 ^ (3 + (((((((5 + 6 ^ ((2 + (((((((((((11 % 7 / 6 - 6) / 10 - 7 - 9) * 7 - 4) ^ 7 + 3) / 3 - 9) / 11) % 2) * 11) ^ 6) * 5) ^ 3) ^ 7 - 6) % 9) - 11) / 7 + 7) % 7 - 10) ^ 11) ^ 4) / 5) ^ 3) % 10)) / 2)) / 9) * 5) * 3 + 10 - 5 - 2) % 10)) * 5) % 5) ^ 6)) ^ 10 - 8) / 3) / 3) ^ 4 - 3 - 9") == -2 );

}

// eof
