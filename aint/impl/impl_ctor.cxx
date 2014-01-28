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

// arbitrary long integer
// impl_ctor.cxx (impl ctor(s))

#include "impl.hxx"

namespace astd {

// helper(s)
void aint::impl::ctorC(const char* s) throw(std::invalid_argument) {
    this->clear();
    data& d = this->data_;
    // check for vaintd input
    if (NULL == s) {
        d.push_back(0);
        return;
    }
    // handle signum
    switch (s[0]) {
    case '-':
        this->positive_ = false;
        ++s;
        break;
    case '+':
        this->positive_ = true;
        ++s;
        break;
    }
    // get size of s
    size_t sL = 0;
    char* ps = const_cast<char*>(s);
    while (*ps) {
        if (*ps < '0' || *ps > '9') {
            throw std::invalid_argument( "non integer value in: " + std::string(__FUNCTION__) + "(" + s + ")" );
        }
        ++sL;
        ++ps;
    }
    size_t sLd = sL / C_SINGLE_COMP_WIDTH;
    size_t sLm = sL % C_SINGLE_COMP_WIDTH;
    size_t dim = sLd + (sLm > 0 ? 1 : 0);
    d.resize(dim);
    singleComp x = 0;
    if (sLm > 0) {
        for (int j = 0; j < sLm; ++j) {
            x = 10 * x + ((*s) - '0');
            ++s;
        }
        d[--dim] = x;
    }
    for (int j = 0; j < sLd; ++j) {
        x = 0;
        for (int i = 0; i < C_SINGLE_COMP_WIDTH; ++i) {
            x = 10 * x + ((*s) - '0');
            ++s;
        }
        d[--dim] = x;
    }
}

void aint::impl::ctorLL(const long long int i) {
    const int C_INT_WIDTH = (int) (2.408 * sizeof(long long int));
    this->clear();
    this->data_.reserve(C_INT_WIDTH / aint::impl::C_SINGLE_COMP_WIDTH + 1);
    singleComp mod = 0;
    long long int tmp = i;
    if (i < 0) {
        this->positive_ = false;
        tmp = -i;
    }
    do {
        mod = tmp % C_SINGLE_COMP_MAX_P1;
        tmp = tmp / C_SINGLE_COMP_MAX_P1;
        this->data_.push_back(mod);
    } while (tmp > 0);
}

void aint::impl::ctorULL(const unsigned long long int i) {
    const int C_INT_WIDTH = (int) (2.408 * sizeof(unsigned long long int));
    this->clear();
    this->data_.reserve(C_INT_WIDTH / aint::impl::C_SINGLE_COMP_WIDTH + 1);
    singleComp mod = 0;
    unsigned long long int tmp = i;
    do {
        mod = tmp % C_SINGLE_COMP_MAX_P1;
        tmp = tmp / C_SINGLE_COMP_MAX_P1;
        this->data_.push_back(mod);
    } while (tmp > 0);
}

// ctor(s)
aint::impl::impl() : positive_(true) {
    data_.push_back(0);
}
aint::impl::impl(const char* s) throw(std::invalid_argument) : positive_(true) {
    this->ctorC(s);
}
aint::impl::impl(const std::string& s) throw(std::invalid_argument) : positive_(true) {
    this->ctorC(s.c_str());
}
aint::impl::impl(const int i) : positive_(true) {
    this->ctorLL(i);
}
aint::impl::impl(const long int i) : positive_(true) {
    this->ctorLL(i);
}
aint::impl::impl(const long long int i) : positive_(true) {
    this->ctorLL(i);
}
aint::impl::impl(const unsigned int i) : positive_(true) {
    this->ctorULL(i);
}
aint::impl::impl(const unsigned long int i) : positive_(true) {
    this->ctorULL(i);
}
aint::impl::impl(const unsigned long long int i) : positive_(true) {
    this->ctorULL(i);
}
aint::impl::impl(const impl& a) { // copy ctor
    positive_ = a.positive_;
    data_ = a.data_;
}

} // end of namespace astd
