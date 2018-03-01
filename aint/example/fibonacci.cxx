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

// aint example
#include "aint.hxx"
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <typeindex>

using namespace std;
using namespace astd;

template<typename T>
const char* typeidStr() {
    if (typeid(T) == typeid(aint   )) return("aint" );
    if (typeid(T) == typeid(int16_t)) return("int16");
    if (typeid(T) == typeid(int32_t)) return("int32");
    if (typeid(T) == typeid(int64_t)) return("int64");
    return("fixme");
}

template<typename T>
static void fibonacci() {
    T fa = -1; // F_{-2}
    T fb =  1; // F_{-1}
    cout << setw(6) << typeidStr<T>();
    for (int j = 0; j <= 100; ++j) {
        T fj = fa + fb;
        if (j < 7) {
            cout << ", " << setw(3) << fj;
        } else if (j % 20 == 0) {
            cout << ", " << setw(j/5 + 1) << fj;
        }
        fa = fb;
        fb = fj;
    }
    cout << endl;
}

int main(int argc, char* argv[]) {

    try {
        cout << endl;
        cout << "Fibonacci numbers F_j := F_{j-1} + F_{j-2}, with F_0 := 0 and F_1 := 1" << endl;
        cout << endl;
        cout << "typeid, F_0, F_1, F_2, F_3, F_4, F_5, F_6,  F_20,      F_40,          F_60,              F_80,                 F_100" << endl;
        cout << setw(120) << setfill('-') << " " << setfill(' ') << endl;
        fibonacci<int16_t>();
        fibonacci<int32_t>();
        fibonacci<int64_t>();
        fibonacci<aint>();
        cout << endl;
    }
    catch(std::string& ex) {
        cout << "Exception: " << ex << endl;
    }
    return(0);
}

// eof
