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

# aint library - cmake

file(GLOB Sources "*.cxx" "impl/*.cxx" "include/*.hxx" "impl/include/*.hxx")

add_library(aint SHARED ${Sources})
if(MINGW)
    set_target_properties(aint PROPERTIES PREFIX "" IMPORT_PREFIX "")
endif()

add_library(aint-static ${Sources})

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/impl/include"
)

set_target_properties(aint
    PROPERTIES PUBLIC_HEADER "include/aint.hxx"
)

set(INSTALL_BIN_DIR     ${CMAKE_INSTALL_PREFIX}/aint/bin     CACHE PATH "Installation directory for executables" )
set(INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/aint/include CACHE PATH "Installation directory for header files")
set(INSTALL_LIB_DIR     ${CMAKE_INSTALL_PREFIX}/aint/lib     CACHE PATH "Installation directory for libraries"   )
set(INSTALL_CMAKE_DIR   ${CMAKE_INSTALL_PREFIX}/aint/cmake   CACHE PATH "Installation directory for cmake files" )

install(TARGETS aint
    # IMPORTANT: Add the aint library to the "export-set"
    EXPORT aintTargets
    ARCHIVE DESTINATION "${INSTALL_LIB_DIR}" COMPONENT lib
    LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT lib
    PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/aint"
    COMPONENT dev
)
install(TARGETS aint-static
    # IMPORTANT: Add the aint-static library to the "export-set"
    EXPORT aintTargets
    ARCHIVE DESTINATION "${INSTALL_LIB_DIR}" COMPONENT lib
)

find_package(Boost 1.53)
find_package(CppUnit)

if (Boost_FOUND)
    add_subdirectory(calc)
endif()

if (CPPUNIT_FOUND)
    add_subdirectory(cppunit)
endif()

add_subdirectory(example)

# eof
