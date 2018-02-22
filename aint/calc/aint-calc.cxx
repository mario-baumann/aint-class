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

// aint-calc
// based on http://stackoverflow.com/questions/17619113/expression-grammar-with-exponentiation-operator-using-boost-spirit

#include <boost/spirit/include/qi.hpp>
#include "aint_calc.hxx"

int main(int argc, char* argv[]) {
    typedef std::string::const_iterator iterator_type;
    typedef client::calculator<iterator_type> calculator;
    boost::spirit::ascii::space_type space; // Our skipper
    calculator calc; // Our grammar

    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'd') {
        client::dbg = true;
        --argc;
        ++argv;
    }
        
    if (argc == 1) {
        if (client::dbg) {
	    std::cout << "Type an expression or [q or Q] to quit" << std::endl;
        }
	std::string input;
        while (std::getline(std::cin, input)) {
            if (input.empty() || input[0] == 'q' || input[0] == 'Q') {
                break;
            }
            auto iter = input.cbegin();
            auto end = input.cend();
            bool r = phrase_parse(iter, end, calc, space);
            if (r && iter == end) {
                if (client::dbg) {
                    std::cout << "Parsing succeeded" << std::endl;
                    std::cout << "Result: ";
                }
                std::cout << client::stck.top() << std::endl;
            } else {
                std::string rest(iter, end);
                std::cout << "Parsing failed" << std::endl;
                std::cout << "stopped at: \" " << rest << "\"" << std::endl;
            }
        }
    } else {
	std::string input;
        for (int j = 1; j < argc; ++j) {
            input += ' ';
            input += argv[j];
        }
        //cout << "Expression: " << input << endl;
        auto iter = input.cbegin();
        auto end  = input.cend();
        bool r = phrase_parse(iter, end, calc, space);
        if (r && iter == end) {
            if (client::dbg) {
                std::cout << "Parsing succeeded" << std::endl;
                std::cout << "Result: ";
            }
            std::cout << client::stck.top() << std::endl;
        } else {
	    std::string rest(iter, end);
            std::cerr << "Parsing failed" << std::endl;
            std::cerr << "stopped at: \" " << rest << "\"" << std::endl;
        }
    }
    return(0);
}

