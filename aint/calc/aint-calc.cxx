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

#define BOOST_SPIRIT_NO_PREDEFINED_TERMINALS
//#define BOOST_SPIRIT_DEBUG

#include <stack>
#include <boost/spirit/include/qi.hpp>
#include "aint.hxx"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stack;
using astd::aint;

namespace client {
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;
    //using qi::lit;
    stack<aint> stck;
    bool dbg = false;

    ///////////////////////////////////////////////////////////////////////////////
    //  Semantic actions
    ///////////////////////////////////////////////////////////////////////////////
    namespace {
        enum opType {
            PLUS,
            MINUS,
            TIMES,
            DIVIDE,
            MODULO,
            FACTORIAL,
            DIGITS,
            POWER,
            POWER_TOWER
        };
        void do_int(std::vector<char> s) {
            s.push_back('\0');
            aint a(string(s.data()));
            stck.push(a);
            if (dbg) {
                cout << __FUNCTION__ << ": " << stck.top() << " integer" << endl;
            }
        }
        void do_op1(opType op) {
            aint a1 = stck.top(); stck.pop();
            switch (op) {
            default:
            case PLUS: stck.push(+a1); break;
            case MINUS: stck.push(-a1); break;
            case FACTORIAL: stck.push(a1.factorial()); break;
            case DIGITS: stck.push(a1.digits()); break;
            }
            if (dbg) {
                cout << __FUNCTION__ << ": " << stck.top() << " ( " << op << a1 << ")" << endl;
            }
        }
        void do_pos() { do_op1(PLUS); }
        void do_neg() { do_op1(MINUS); }
        void do_fac() { do_op1(FACTORIAL); }
        void do_dig() { do_op1(DIGITS); }
        void do_op2(opType op) {
            aint a2 = stck.top(); stck.pop();
            aint a1 = stck.top(); stck.pop();
            switch (op) {
            default:
            case PLUS: stck.push(a1 + a2); break;
            case MINUS: stck.push(a1 - a2); break;
            case TIMES: stck.push(a1 * a2); break;
            case DIVIDE: stck.push(a1 / a2); break;
            case MODULO: stck.push(a1 % a2); break;
            case POWER: stck.push(a1.power(a2)); break;
            case POWER_TOWER: stck.push(a1.powertower(a2)); break;
            }
            if (dbg) {
                cout << __FUNCTION__ << ": " << stck.top() << " ( " << a1 << " " << op << " " << a2 << " ) " << endl;
            }
        }
        void do_add() { do_op2(PLUS); }
        void do_sub() { do_op2(MINUS); }
        void do_mul() { do_op2(TIMES); }
        void do_div() { do_op2(DIVIDE); }
        void do_mod() { do_op2(MODULO); }
        void do_pow() { do_op2(POWER); }
        void do_ptw() { do_op2(POWER_TOWER); }
    }

    // calculator grammar
    template <typename Iterator>
    struct calculator : qi::grammar<Iterator, ascii::space_type> {
        calculator() : calculator::base_type(expression) {
            qi::digit_type digit_;

            expression =
                term >> *( ('+' >> term   [&do_add]) |
                           ('-' >> term   [&do_sub]) )
                ;

            term =
                factor >> *( ('*' >> factor [&do_mul]) |
                             ('/' >> factor [&do_div]) |
                             ('%' >> factor [&do_mod]) )
                ;

            factor =
                primary >> -( ("^^" >> factor [&do_ptw]) | 
                              ('^'  >> factor [&do_pow]) )
                ;

            primary =
                (+digit_) [&do_int]         |
                '(' >> expression >> ')'    |
                ('+' >> primary [&do_pos])  |
                ('-' >> primary [&do_neg])  |
                ('!' >> primary [&do_fac])  |
                ('#' >> primary [&do_dig])
                ;

            BOOST_SPIRIT_DEBUG_NODES((expression)(term)(factor)(primary));
        }
    private:
        qi::rule<Iterator, ascii::space_type> expression, term, factor, primary;
    };
}

///////////////////////////////////////////////////////////////////////////////
//  Main program
///////////////////////////////////////////////////////////////////////////////
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
            cout << "Type an expression or [q or Q] to quit" << endl;
        }
        string input;
        while (std::getline(std::cin, input)) {
            if (input.empty() || input[0] == 'q' || input[0] == 'Q') {
                break;
            }
            auto iter = input.cbegin();
            auto end = input.cend();
            bool r = phrase_parse(iter, end, calc, space);
            if (r && iter == end) {
                if (client::dbg) {
                    cout << "Parsing succeeded" << endl;
                    cout << "Result: ";
                }
                cout << client::stck.top() << endl;
            } else {
                std::string rest(iter, end);
                cout << "Parsing failed" << endl;
                cout << "stopped at: \" " << rest << "\"" << endl;
            }
        }
    } else {
        string input;
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
                cout << "Parsing succeeded" << endl;
                cout << "Result: ";
            }
            cout << client::stck.top() << endl;
        } else {
            string rest(iter, end);
            cerr << "Parsing failed" << endl;
            cerr << "stopped at: \" " << rest << "\"" << endl;
        }
    }
    return(0);
}
