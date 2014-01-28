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

// aint unit tests
#ifndef CPPUNIT_HXX
#define CPPUNIT_HXX

#include "aint.hxx"
#include <iostream>
#include <string>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>

using namespace astd;

class aintTest : public CppUnit::TestFixture {
private:
    aint *a1;
    aint *a2;
    aint::adiv ad;
public:
    void setUp() {
        a1 = new aint(0);
        a2 = new aint(0);
    }
    void tearDown() {
        delete a1;
        delete a2;
    }
    void testCtor();
    void testMember();
    void testOperatorEqual();
    void testOperatorNotEqual();
    void testOperatorLess();
    void testOperatorLessEqual();
    void testOperatorGreater();
    void testOperatorGreaterEqual();
    void testOperatorPlus();
    void testOperatorMinus();
    void testOperatorTimes();
    void testOperatorDivide();
    void testFibonacci();
    static CppUnit::TestSuite *suite() {
        CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("aintTest");
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testCtor",         &aintTest::testCtor                ));
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testMember",       &aintTest::testMember              ));
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testEqual",        &aintTest::testOperatorEqual       ));
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testNotEqual",     &aintTest::testOperatorNotEqual    ));
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testLess",         &aintTest::testOperatorLess        ));
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testLessEqual",    &aintTest::testOperatorLessEqual   ));
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testGreater",      &aintTest::testOperatorGreater     ));
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testGreaterEqual", &aintTest::testOperatorGreaterEqual));
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testPlus",         &aintTest::testOperatorPlus        ));
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testMinus",        &aintTest::testOperatorMinus       ));
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testTimes",        &aintTest::testOperatorTimes       ));
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testDivide",       &aintTest::testOperatorDivide      ));
        suiteOfTests->addTest(new CppUnit::TestCaller<aintTest>("testFibonacci",    &aintTest::testFibonacci           ));
        return(suiteOfTests);
    }
};

#endif /* CPPUNIT_HXX */

