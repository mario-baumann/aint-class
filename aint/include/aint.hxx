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
// aint.hxx (class)

#ifndef AINT_HXX
#define AINT_HXX

#include <string>    // std::string
#include <sstream>   // std::ostream
#include <memory>    // std::unique_ptr
#include <stdexcept> // std::invalid_argument

namespace astd {

/*!
@class aint

@brief (a)rbitary long (int)eger class

This class provides an arbitrary long integer which can be used the
same way as the C/C++ integer types (e.g. int or long), but has no
restriction on the length (if there is enough memory).

int - example:
@code
void factorial(int n) {
   int f = 1;
   for (int j = 1; j <= n; ++j) {
       f = f * j; // overflow if n > 12 and int is a 32 bit integer
   }
   cout << "factorial(" << n << ") = " << f << endl;
}
@endcode

aint - example:
@code
#include "aint.hxx"
using namespace astd;

void factorial(int n) {
   aint f = 1;
   for (int j = 1; j <= n; ++j) {
       f = f * j;
   }
   cout << "factorial(" << n << ") = " << f << endl;
}
@endcode
*/
class aint {
 
public:
    typedef           long      int  intL;
    typedef           long long int  intLL;
    typedef  unsigned           int  intU;
    typedef  unsigned long      int  intUL;
    typedef  unsigned long long int  intULL;

    // ctor(s)
    aint();
    aint(const aint& a);
    aint(      aint&& a);
    aint(const char*        s) throw(std::invalid_argument);
    aint(const std::string& s) throw(std::invalid_argument);
    aint(const int    i);
    aint(const intL   i);
    aint(const intLL  i);
    aint(const intU   i);
    aint(const intUL  i);
    aint(const intULL i);

    // dtor
    ~aint();

    // stream operator(s)
    friend std::ostream& operator<<(std::ostream& out, const aint& a);

    // assignment operator(s)
    aint& operator=(const aint& rhs);
    aint& operator=(      aint&& rhs);
    aint& operator=(const char*        s) throw(std::invalid_argument);
    aint& operator=(const std::string& s) throw(std::invalid_argument);
    aint& operator=(const int    i);
    aint& operator=(const intL   i);
    aint& operator=(const intLL  i);
    aint& operator=(const intU   i);
    aint& operator=(const intUL  i);
    aint& operator=(const intULL i);

    // less-than operator(s)
    bool operator<(const aint&  rhs) const;
    bool operator<(const int    rhs) const;
    bool operator<(const intL   rhs) const;
    bool operator<(const intLL  rhs) const;
    bool operator<(const intU   rhs) const;
    bool operator<(const intUL  rhs) const;
    bool operator<(const intULL rhs) const;
    friend bool operator<(const int    lhs, const aint& rhs);
    friend bool operator<(const intL   lhs, const aint& rhs);
    friend bool operator<(const intLL  lhs, const aint& rhs);
    friend bool operator<(const intU   lhs, const aint& rhs);
    friend bool operator<(const intUL  lhs, const aint& rhs);
    friend bool operator<(const intULL lhs, const aint& rhs);

    // equal operator(s)
    bool operator==(const aint&  rhs) const;
    bool operator==(const int    rhs) const;
    bool operator==(const intL   rhs) const;
    bool operator==(const intLL  rhs) const;
    bool operator==(const intU   rhs) const;
    bool operator==(const intUL  rhs) const;
    bool operator==(const intULL rhs) const;
    friend bool operator==(const int    lhs, const aint& rhs);
    friend bool operator==(const intL   lhs, const aint& rhs);
    friend bool operator==(const intLL  lhs, const aint& rhs);
    friend bool operator==(const intU   lhs, const aint& rhs);
    friend bool operator==(const intUL  lhs, const aint& rhs);
    friend bool operator==(const intULL lhs, const aint& rhs);

    // less-equal operator(s)
    bool operator<=(const aint&  rhs) const;
    bool operator<=(const int    rhs) const;
    bool operator<=(const intL   rhs) const;
    bool operator<=(const intLL  rhs) const;
    bool operator<=(const intU   rhs) const;
    bool operator<=(const intUL  rhs) const;
    bool operator<=(const intULL rhs) const;
    friend bool operator<=(const int    lhs, const aint& rhs);
    friend bool operator<=(const intL   lhs, const aint& rhs);
    friend bool operator<=(const intLL  lhs, const aint& rhs);
    friend bool operator<=(const intU   lhs, const aint& rhs);
    friend bool operator<=(const intUL  lhs, const aint& rhs);
    friend bool operator<=(const intULL lhs, const aint& rhs);

    // not-equal operator(s)
    bool operator!=(const aint&  rhs) const;
    bool operator!=(const int    rhs) const;
    bool operator!=(const intL   rhs) const;
    bool operator!=(const intLL  rhs) const;
    bool operator!=(const intU   rhs) const;
    bool operator!=(const intUL  rhs) const;
    bool operator!=(const intULL rhs) const;
    friend bool operator!=(const int    lhs, const aint& rhs);
    friend bool operator!=(const intL   lhs, const aint& rhs);
    friend bool operator!=(const intLL  lhs, const aint& rhs);
    friend bool operator!=(const intU   lhs, const aint& rhs);
    friend bool operator!=(const intUL  lhs, const aint& rhs);
    friend bool operator!=(const intULL lhs, const aint& rhs);

    // greater-than operator(s)
    bool operator>(const aint&  rhs) const;
    bool operator>(const int    rhs) const;
    bool operator>(const intL   rhs) const;
    bool operator>(const intLL  rhs) const;
    bool operator>(const intU   rhs) const;
    bool operator>(const intUL  rhs) const;
    bool operator>(const intULL rhs) const;
    friend bool operator>(const int    lhs, const aint& rhs);
    friend bool operator>(const intL   lhs, const aint& rhs);
    friend bool operator>(const intLL  lhs, const aint& rhs);
    friend bool operator>(const intU   lhs, const aint& rhs);
    friend bool operator>(const intUL  lhs, const aint& rhs);
    friend bool operator>(const intULL lhs, const aint& rhs);

    // greater-equal operator(s)
    bool operator>=(const aint&  rhs) const;
    bool operator>=(const int    rhs) const;
    bool operator>=(const intL   rhs) const;
    bool operator>=(const intLL  rhs) const;
    bool operator>=(const intU   rhs) const;
    bool operator>=(const intUL  rhs) const;
    bool operator>=(const intULL rhs) const;
    friend bool operator>=(const int    lhs, const aint& rhs);
    friend bool operator>=(const intL   lhs, const aint& rhs);
    friend bool operator>=(const intLL  lhs, const aint& rhs);
    friend bool operator>=(const intU   lhs, const aint& rhs);
    friend bool operator>=(const intUL  lhs, const aint& rhs);
    friend bool operator>=(const intULL lhs, const aint& rhs);

    // plus operator(s)
    const aint operator+(); // unary +
    const aint operator+(const aint&  rhs) const;
    const aint operator+(const int    rhs) const;
    const aint operator+(const intL   rhs) const;
    const aint operator+(const intLL  rhs) const;
    const aint operator+(const intU   rhs) const;
    const aint operator+(const intUL  rhs) const;
    const aint operator+(const intULL rhs) const;
    friend const aint operator+(const int    lhs, const aint& rhs);
    friend const aint operator+(const intL   lhs, const aint& rhs);
    friend const aint operator+(const intLL  lhs, const aint& rhs);
    friend const aint operator+(const intU   lhs, const aint& rhs);
    friend const aint operator+(const intUL  lhs, const aint& rhs);
    friend const aint operator+(const intULL lhs, const aint& rhs);

    // minus operator(s)
    const aint operator-(); // unary -
    const aint operator-(const aint&  rhs) const;
    const aint operator-(const int    rhs) const;
    const aint operator-(const intL   rhs) const;
    const aint operator-(const intLL  rhs) const;
    const aint operator-(const intU   rhs) const;
    const aint operator-(const intUL  rhs) const;
    const aint operator-(const intULL rhs) const;
    friend const aint operator-(const int    lhs, const aint& rhs);
    friend const aint operator-(const intL   lhs, const aint& rhs);
    friend const aint operator-(const intLL  lhs, const aint& rhs);
    friend const aint operator-(const intU   lhs, const aint& rhs);
    friend const aint operator-(const intUL  lhs, const aint& rhs);
    friend const aint operator-(const intULL lhs, const aint& rhs);

    // times operator(s)
    const aint operator*(const aint&  rhs) const;
    const aint operator*(const int    rhs) const;
    const aint operator*(const intL   rhs) const;
    const aint operator*(const intLL  rhs) const;
    const aint operator*(const intU   rhs) const;
    const aint operator*(const intUL  rhs) const;
    const aint operator*(const intULL rhs) const;
    friend const aint operator*(const int    lhs, const aint& rhs);
    friend const aint operator*(const intL   lhs, const aint& rhs);
    friend const aint operator*(const intLL  lhs, const aint& rhs);
    friend const aint operator*(const intU   lhs, const aint& rhs);
    friend const aint operator*(const intUL  lhs, const aint& rhs);
    friend const aint operator*(const intULL lhs, const aint& rhs);

    // divide operator(s)
    const aint operator/(const aint&  rhs) const throw(std::overflow_error);
    const aint operator/(const int    rhs) const throw(std::overflow_error);
    const aint operator/(const intL   rhs) const throw(std::overflow_error);
    const aint operator/(const intLL  rhs) const throw(std::overflow_error);
    const aint operator/(const intU   rhs) const throw(std::overflow_error);
    const aint operator/(const intUL  rhs) const throw(std::overflow_error);
    const aint operator/(const intULL rhs) const throw(std::overflow_error);
    friend const aint operator/(const int    lhs, const aint& rhs) throw(std::overflow_error);
    friend const aint operator/(const intL   lhs, const aint& rhs) throw(std::overflow_error);
    friend const aint operator/(const intLL  lhs, const aint& rhs) throw(std::overflow_error);
    friend const aint operator/(const intU   lhs, const aint& rhs) throw(std::overflow_error);
    friend const aint operator/(const intUL  lhs, const aint& rhs) throw(std::overflow_error);
    friend const aint operator/(const intULL lhs, const aint& rhs) throw(std::overflow_error);

    // modulo operator(s)
    const aint operator%(const aint&  rhs) const throw(std::overflow_error);
    const aint operator%(const int    rhs) const throw(std::overflow_error);
    const aint operator%(const intL   rhs) const throw(std::overflow_error);
    const aint operator%(const intLL  rhs) const throw(std::overflow_error);
    const aint operator%(const intU   rhs) const throw(std::overflow_error);
    const aint operator%(const intUL  rhs) const throw(std::overflow_error);
    const aint operator%(const intULL rhs) const throw(std::overflow_error);
    friend const aint operator%(const int    lhs, const aint& rhs) throw(std::overflow_error);
    friend const aint operator%(const intL   lhs, const aint& rhs) throw(std::overflow_error);
    friend const aint operator%(const intLL  lhs, const aint& rhs) throw(std::overflow_error);
    friend const aint operator%(const intU   lhs, const aint& rhs) throw(std::overflow_error);
    friend const aint operator%(const intUL  lhs, const aint& rhs) throw(std::overflow_error);
    friend const aint operator%(const intULL lhs, const aint& rhs) throw(std::overflow_error);

    // divide and modulo operator(s)
    typedef std::pair<aint, aint> adiv;
    const adiv div(const aint& rhs) const throw(std::overflow_error); // computes quotient and remainder simultaneously

    // power operator(s)
    const aint operator^(const aint& exp) const;

    // increment operator(s)
    aint& operator++();
    const aint operator++(int);

    // decrement operator(s)
    aint& operator--();
    const aint operator--(int);

    // member functions
    //! dumps to a string
    std::string dump() const;
    //! returns the number of digits
    int digits() const;
    //! returns true if it is an even number and false otherwise
    bool even() const;
    //! computes the factorial
    aint factorial();

private:
    // use pimpl idiom
    class impl; // forward declaration
    std::unique_ptr<impl> impl_;
};

} // end of namespace astd

namespace alit {
    astd::aint operator"" _A(const char* s) throw(std::invalid_argument);
} // end of namespace alit
using namespace alit;

#endif /* AINT_HXX */

