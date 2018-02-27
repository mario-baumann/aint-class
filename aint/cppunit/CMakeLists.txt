##
 #  This file is part of aint.
 #
 #  aint provides a C++ class for arbitrary long integers which can be
 #  used the same way as the C/C++ integer types (e.g. int or long),
 #  but has no restriction on the length (if there is enough memory).
 #  Aim of this project is to include fast integer multiplications
 #  like the Toom-Cook algorithm or the Schoenhage-Strassen algorithm.
 #  Copyright (C) 2014 Mario Baumann (mario-baumann@web.de)
 #
 #  aint is free software: you can redistribute it and/or modify it
 #  under the terms of the GNU General Public License as published by
 #  the Free Software Foundation, either version 3 of the License, or
 #  (at your option) any later version.
 #
 #  aint is distributed in the hope that it will be useful, but
 #  WITHOUT ANY WARRANTY; without even the implied warranty of
 #  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 #  General Public License for more details.
 #
 #  You should have received a copy of the GNU General Public License
 #  along with aint.  If not, see <http://www.gnu.org/licenses/>.
 #
 ###########################################################################

# aint cppunit - cmake

file(GLOB Sources "*.cxx" "include/*.hxx")
if (NOT Boost_FOUND)
    file(GLOB DummySources "dummy/*.cxx")
endif()

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CPPUNIT_INCLUDE_DIR}")

add_executable(aint-unit ${Sources} ${DummySources})
if (Boost_FOUND)
    target_link_libraries(aint-unit aint-calc-unit)
endif()
target_link_libraries(aint-unit aint-static)
target_link_libraries(aint-unit ${CPPUNIT_LIBRARY})
if(NOT "${TARGET_LIBS}" STREQUAL "")
    target_link_libraries(aint-unit ${TARGET_LIBS})
endif()

# add run-aint-unit target to run unit tests
add_custom_target(run-aint-unit ALL
    ./cppunit/aint-unit 
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../
    COMMENT "Running aint unit test" VERBATIM
)
add_dependencies(run-aint-unit aint-unit)

# eof

