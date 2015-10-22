project(nenr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES
  calculated_fuzzy_set.h
  domain.cpp
  domain.h
  domain_element.cpp
  domain_element.h
  main.cpp
  fuzzy_set.h
  fuzzy_set.cpp
  mutable_fuzzy_set.h
  operations.cpp
  operations.h
  simple_domain.cpp
  simple_domain.h
  standard_fuzzy_sets.h
  standard_fuzzy_sets.cpp)

add_executable(nenr ${SOURCE_FILES})
