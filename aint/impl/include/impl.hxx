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
// impl.hxx (class implementation)
#ifndef IMPL_HXX
#define IMPL_HXX

#include "aint.hxx"
#include <cstdint> // int32_t, ...
#include <vector>  // std::vector
#include <iostream>

#if ! defined(SINGLE_8) && ! defined(SINGLE_16) && ! defined(SINGLE_32)
#define SINGLE_16
#endif

namespace astd {

class aint::impl {

public:
    // data types for single and double components
#if defined(SINGLE_8)
    typedef int8_t  singleComp;
    typedef int16_t doubleComp;
#elif defined(SINGLE_16)
    typedef int16_t singleComp;
    typedef int32_t doubleComp;
#elif defined(SINGLE_32)
    typedef int32_t singleComp;
    typedef int64_t doubleComp;
#endif

    //! decimal-width of a single component
    static const int C_SINGLE_COMP_WIDTH;

    //! maximum number (+ 1) of a single component
    static const singleComp C_SINGLE_COMP_MAX_P1;

    //! sign of integer, positive or zero (=\b true) or negative (=\b false)
    bool positive_;

    //! typedef for data container which stores single components
    typedef std::vector<singleComp> data;

    //! data container which stores single components
    data data_;

    // ctor(s)
    impl();
    impl(const impl& a); // copy ctor
    impl(const char* s);
    impl(const std::string& s);
    impl(const int i);
    impl(const long int i);
    impl(const long long int i);
    impl(const unsigned int i);
    impl(const unsigned long int i);
    impl(const unsigned long long int i);

    // dtor
    ~impl();

    //! clears the data container and sets sign to \b true
    void clear();

    //! removes leading zeros from a data container
    void removeLeadingZeros();

    //! resizes the data container to \b size and sets all components to zero
    //! \param size New size of data container
    void resizeAndZeroise(size_t size);

    //! ensure a zero has a positive sign
    void makeZeroPositive();

    // helper functions for operators
    void ctorC(  const char*);
    void ctorLL( const long long int i);
    void ctorULL(const unsigned long long int i);
    //
    bool operatorLtAbs(const aint& lhs, const aint& rhs) const;
    bool operatorLtLL( const aint& lhs, const long long int rhs ) const;
    bool operatorLtULL(const aint& lhs, const unsigned long long int rhs ) const;
    //
    bool operatorEqLL( const aint& lhs, const long long int rhs ) const;
    bool operatorEqULL(const aint& lhs, const unsigned long long int rhs ) const;
    //
    bool operatorPlusChk(const aint& lhs, const aint& rhs) const;
    void operatorPlusAdd(const aint& lhs, const aint& rhs, aint& res) const;
    void operatorPlusSub(const aint& lhs, const aint& rhs, aint& res) const;
    void operatorPlus(   const aint& lhs, const aint& rhs, aint& res, bool minusSwitch=false) const;
    //
    void operatorTimesSingle(const aint& lhs, const singleComp rhs, aint& res) const;
    void operatorTimes(const aint& lhs, const aint& rhs, aint& res) const;
    //
    void operatorDivideMinusLeft(aint& lhs, const aint& rhs, const int p);
    bool operatorDivideLessLeft(aint& lhs, const aint& rhs, const int p);
    void operatorDivideSingle(const aint& lhs, const singleComp rhs, aint& quot, aint& rem) const;
    void operatorDivide(const aint& lhs, const aint& rhs, aint& quot, aint& rem) const;

    aint operatorPower(const aint& base, const aint& exp) const;
    aint operatorPowerTower(const aint& base, const aint& ord) const;

    aint factorialIterative(const aint& n) const;
    aint factorialRecursiveProduct(const aint& start, const aint& width) const;
};

} // end of namespace astd

#endif /* IMPL_HXX */
