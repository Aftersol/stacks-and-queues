cmake_minimum_required (VERSION 2.8.12)

include_directories(include)
set(CMAKE_CXX_STANDARD 11)	

project (tests)

add_executable(TEST_QUEUE_ARRAY
    tests/test_queueArr.cpp;
)

add_executable(TEST_QUEUE_LIKNED
    tests/test_queueLinked.cpp;
)

add_executable(TEST_STACK_ARRAY
    tests/test_stackArr.cpp;
)

add_executable(TEST_STACK_LINKED
    tests/test_stackLinked.cpp;
)