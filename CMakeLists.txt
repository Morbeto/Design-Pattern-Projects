cmake_minimum_required (VERSION 3.14)
project(CMakeProject3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Catch2
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.3
)

FetchContent_MakeAvailable(Catch2)

# Add test executable and sources
add_executable(tests
    tests/testTrans.cpp
    src/decorators/TextDecoration.cpp
    # add other .cpp files here as needed
 "headers/decorators/CyclingDecoration.h" "src/decorators/CyclingDecoration.cpp" "headers/decorators/RandomDecoration.h" "src/decorators/RandomDecoration.cpp" "headers/transformations/CompositeTrans.h" "src/transformation/CompositeTrans.cpp" "headers/transformations/transFactory.h" "src/transformation/transFactory.cpp" "headers/labels/ProxyLabel.h" "src/labels/ProxyLabels.cpp" "headers/labels/helpText.h" "src/labels/Labels.cpp" "headers/labels/LabelPrinter.h" "headers/labels/LabelBuilder.h" "src/labels/LabelBuilder.cpp")

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/headers)

include(CTest)
include(Catch)
catch_discover_tests(tests)

enable_testing()
