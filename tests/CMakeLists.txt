add_executable(tests
  test.cpp
  testLabel.cpp
 testTrans.cpp)

target_link_libraries(tests
  Catch2::Catch2WithMain
)

include(Catch)
catch_discover_tests(tests)
