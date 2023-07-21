cmake_minimum_required(VERSION 3.0.0)
project(template-visibility LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(template-visibility SHARED templates.cpp templates.h compiler.h xcoff.cpp xcoff.h)
set_target_properties(template-visibility PROPERTIES
                      CXX_VISIBILITY_PRESET hidden
                      VISIBILITY_INLINES_HIDDEN YES)

add_executable(test test.cpp)

target_link_libraries(test template-visibility)
