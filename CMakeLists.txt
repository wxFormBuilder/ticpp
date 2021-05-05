cmake_minimum_required(VERSION 3.7.2)
project(ticpp LANGUAGES CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_DEBUG_POSTFIX "d")

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=c++11)
endif()

if(BUILD_SHARED_LIBS)
    add_definitions(-DBUILD_TICPP_DLL)
endif(BUILD_SHARED_LIBS)

add_library(ticpp
    ticpp.cpp
    tinystr.cpp
    tinyxml.cpp
    tinyxmlerror.cpp
    tinyxmlparser.cpp
)
target_include_directories(ticpp
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_definitions(ticpp
    PUBLIC TIXML_USE_TICPP
)
