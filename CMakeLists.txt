cmake_minimum_required(VERSION 3.3)
project(nenr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    calculated_fuzzy_set.h
    domain.cpp
    domain.h
    domain_element.cpp
    domain_element.h
    main.cpp
    fuzzy_set.h
    mutable_fuzzy_set.cpp
    mutable_fuzzy_set.h
    operations.cpp
    operations.h
    simple_domain.cpp
    simple_domain.h
    standard_fuzzy_sets.h)

add_executable(nenr ${SOURCE_FILES})