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
// aint_operator_divide.cxx (division operator(s))

#include "impl.hxx"

namespace astd {

const aint aint::operator/(const aint& rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, rhs, quot, rem);
    return(quot);
}
const aint aint::operator/(const int rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, aint(rhs), quot, rem);
    return(quot);
}
const aint aint::operator/(const long int rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, aint(rhs), quot, rem);
    return(quot);
}
const aint aint::operator/(const long long int rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, aint(rhs), quot, rem);
    return(quot);
}
const aint aint::operator/(const unsigned int rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, aint(rhs), quot, rem);
    return(quot);
}
const aint aint::operator/(const unsigned long int rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, aint(rhs), quot, rem);
    return(quot);
}
const aint aint::operator/(const unsigned long long int rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, aint(rhs), quot, rem);
    return(quot);
}
const aint operator/(const int lhs, const aint& rhs) throw(std::overflow_error) {
    aint quot;
    aint rem;
    rhs.impl_->operatorDivide(aint(lhs), rhs, quot, rem);
    return(quot);
}
const aint operator/(const long int lhs, const aint& rhs) throw(std::overflow_error) {
    aint quot;
    aint rem;
    rhs.impl_->operatorDivide(aint(lhs), rhs, quot, rem);
    return(quot);
}
const aint operator/(const long long int lhs, const aint& rhs) throw(std::overflow_error) {
    aint quot;
    aint rem;
    rhs.impl_->operatorDivide(aint(lhs), rhs, quot, rem);
    return(quot);
}
const aint operator/(const unsigned int lhs, const aint& rhs) throw(std::overflow_error) {
    aint quot;
    aint rem;
    rhs.impl_->operatorDivide(aint(lhs), rhs, quot, rem);
    return(quot);
}
const aint operator/(const unsigned long int lhs, const aint& rhs) throw(std::overflow_error) {
    aint quot;
    aint rem;
    rhs.impl_->operatorDivide(aint(lhs), rhs, quot, rem);
    return(quot);
}
const aint operator/(const unsigned long long int lhs, const aint& rhs) throw(std::overflow_error) {
    aint quot;
    aint rem;
    rhs.impl_->operatorDivide(aint(lhs), rhs, quot, rem);
    return(quot);
}



const aint aint::operator%(const aint& rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, rhs, quot, rem);
    return(rem);
}
const aint aint::operator%(const int rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, aint(rhs), quot, rem);
    return(rem);
}
const aint aint::operator%(const long int rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, aint(rhs), quot, rem);
    return(rem);
}
const aint aint::operator%(const long long int rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, aint(rhs), quot, rem);
    return(rem);
}
const aint aint::operator%(const unsigned int rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, aint(rhs), quot, rem);
    return(rem);
}
const aint aint::operator%(const unsigned long int rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, aint(rhs), quot, rem);
    return(rem);
}
const aint aint::operator%(const unsigned long long int rhs) const throw(std::overflow_error) {
    aint quot;
    aint rem;
    this->impl_->operatorDivide(*this, aint(rhs), quot, rem);
    return(rem);
}
const aint operator%(const int lhs, const aint& rhs) throw(std::overflow_error) {
    aint quot;
    aint rem;
    rhs.impl_->operatorDivide(aint(lhs), rhs, quot, rem);
    return(rem);
}
const aint operator%(const long int lhs, const aint& rhs) throw(std::overflow_error) {
    aint quot;
    aint rem;
    rhs.impl_->operatorDivide(aint(lhs), rhs, quot, rem);
    return(rem);
}
const aint operator%(const long long int lhs, const aint& rhs) throw(std::overflow_error) {
    aint quot;
    aint rem;
    rhs.impl_->operatorDivide(aint(lhs), rhs, quot, rem);
    return(rem);
}
const aint operator%(const unsigned int lhs, const aint& rhs) throw(std::overflow_error) {
    aint quot;
    aint rem;
    rhs.impl_->operatorDivide(aint(lhs), rhs, quot, rem);
    return(rem);
}
const aint operator%(const unsigned long int lhs, const aint& rhs) throw(std::overflow_error) {
    aint quot;
    aint rem;
    rhs.impl_->operatorDivide(aint(lhs), rhs, quot, rem);
    return(rem);
}
const aint operator%(const unsigned long long int lhs, const aint& rhs) throw(std::overflow_error) {
    aint quot;
    aint rem;
    rhs.impl_->operatorDivide(aint(lhs), rhs, quot, rem);
    return(rem);
}

const aint::adiv aint::div(const aint& rhs) const throw(std::overflow_error) {
    std::pair<aint,aint> res;
    this->impl_->operatorDivide(*this, rhs, res.first, res.second);
    return(res);
}

} // end of namespace astd
