cmake_minimum_required(VERSION 3.21)

project(ticpp VERSION 2.5.3 LANGUAGES CXX)

get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(PROJECT_IS_TOP_LEVEL)
  set(buildTypes "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
  set(defaultBuildType "Debug")
  if(NOT isMultiConfig)
    if(NOT CMAKE_BUILD_TYPE)
      message(STATUS "Setting build type to '${defaultBuildType}' as none was specified.")
      set(CMAKE_BUILD_TYPE "${defaultBuildType}" CACHE STRING "Choose the type of build." FORCE)
      set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${buildTypes}")
    elseif(NOT CMAKE_BUILD_TYPE IN_LIST buildTypes)
      message(FATAL_ERROR "Unknown build type: '${CMAKE_BUILD_TYPE}'")
    endif()
  endif()
endif()

if(NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
elseif(CMAKE_CXX_STANDARD LESS 17)
  message(FATAL_ERROR "The CMAKE_CXX_STANDARD value needs to be at least 17, current value: ${CMAKE_CXX_STANDARD}")
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (NOT DEFINED CMAKE_CXX_EXTENSIONS)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

add_library(ticpp_ticpp)
add_library(ticpp::ticpp ALIAS ticpp_ticpp)
set_target_properties(ticpp_ticpp PROPERTIES
  OUTPUT_NAME ticpp
)

target_sources(ticpp_ticpp
  PRIVATE
    ticpp.h
    ticpp.cpp
    ticppapi.h
    ticpprc.h
    tinystr.h
    tinystr.cpp
    tinyxml.h
    tinyxml.cpp
    tinyxmlerror.cpp
    tinyxmlparser.cpp
)

target_compile_definitions(ticpp_ticpp
  PUBLIC
    TIXML_USE_TICPP
    $<$<BOOL:${BUILD_SHARED_LIBS}>:BUILD_TICPP_DLL>
)
target_include_directories(ticpp_ticpp
  INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

install(TARGETS ticpp_ticpp
  RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE
    EXCLUDE_FROM_ALL
)
