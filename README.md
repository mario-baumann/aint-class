aint-class
==========

aint provides a C++ class for arbitrary long integers which can be used the same
way as the C/C++ integer types (e.g. int or long), but has no restriction on the
length (if there is enough memory).

Aim of this project is to include fast integer multiplications like the
Toom-Cook algorithm or the Schoenhage-Strassen algorithm.

What tools/libraries are used in this project:
     - cmake to generate an eclipse project
     - gnu tools (make, g++, ...) to build 
     - doxygen for documentation
     - cppunit for unit testing
     - boost spirit for a formula parser used in aint-calc
    
What C++ techniques are used:
     - pimpl idiom as the compilation firewall
     - moved constructors and move assignment operators

What is already working:
     - arithmetic operations: +, -, *, /, %, ^ (power)
     - relational operations: ==, !=, <, <=, >, >=
     - special functions: dump(), digits(), even(), factorial()
     - small calc program (aint-calc) similar to bc, e.g.
       ./aint-calc '5^4^3^2'
       => will generate an integer with 183231 digits (compare results at
          http://rosettacode.org/wiki/Arbitrary-precision_integers_%28included%29)

What is still missing:
     - increment, decrement operations: ++, --
     - compound  assignment operations: +=, -=, *=, /=, %=, ^=
     - fast integer multiplications like the Toom-Cook algorithm or the
       Schoenhage-Strassen algorithm
 
#