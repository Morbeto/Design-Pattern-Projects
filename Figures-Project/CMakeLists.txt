cmake_minimum_required(VERSION 3.10...3.30)

project(Figures)  
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests tests/test_triangle.cpp tests/test_rectangle.cpp tests/test_circle.cpp  src/triangle.cpp src/Figures.cpp "include/rectangle.h" "src/rectangle.cpp"  "include/circle.h" "src/circle.cpp"         "include/string_to_figure.h"  "tests/test_string_to_figure.cpp" "include/figure_factory.h" "include/random_figure_factory.h"  "src/random_factory.cpp" "include/stream_factory.h" "src/stream_factory.cpp" "tests/test_factorys.cpp" "include/abstract_factory.h" "src/abstract_factory.cpp" "include/to_string.h" )
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)