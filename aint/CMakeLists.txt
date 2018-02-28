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

add_definitions(-DSINGLE_${AINT_SINGLE_SIZE})

set(TARGET_LIBS "")
if(MINGW)
    # get static c++/pthread libraries via C++ compiler
    if (${CMAKE_CXX_COMPILER_ARG1} MATCHES "-m32")
        set(ARCH "-m32")
    else()
        set(ARCH "-m64")
    endif()
    execute_process(
        COMMAND ${CMAKE_CXX_COMPILER} ${ARCH} -print-file-name=libstdc++.a
        OUTPUT_VARIABLE LIBSTDCXX_A
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    execute_process(
        COMMAND ${CMAKE_CXX_COMPILER} ${ARCH} -print-file-name=libpthread.a
        OUTPUT_VARIABLE LIBPTHREAD_A
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    
    # set global target libraries
    set(TARGET_LIBS "${LIBSTDCXX_A};${LIBPTHREAD_A}")
endif()

# set linker flags for executables and shared libraris
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-libgcc -static-libstdc++")
endif()

file(GLOB Sources "*.cxx" "impl/*.cxx" "include/*.hxx" "impl/include/*.hxx")

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/impl/include"
)


add_library(aint SHARED ${Sources})
if(MINGW)
    set_target_properties(aint PROPERTIES PREFIX "" IMPORT_PREFIX "" LINK_FLAGS "${CMAKE_CURRENT_SOURCE_DIR}/aint_export_mingw.def")
elseif(UNIX AND NOT APPLE)
    set_target_properties(aint PROPERTIES LINK_FLAGS "-Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/aint_export_linux.txt")
endif()
if(NOT "${TARGET_LIBS}" STREQUAL "")
    target_link_libraries(aint ${TARGET_LIBS})
endif()
set_target_properties(aint PROPERTIES PUBLIC_HEADER "include/aint.hxx")
install(TARGETS aint DESTINATION lib PUBLIC_HEADER DESTINATION include)


add_library(aint-static ${Sources})
install(TARGETS aint-static DESTINATION lib)


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
