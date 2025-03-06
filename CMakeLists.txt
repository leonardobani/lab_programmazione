cmake_minimum_required(VERSION 3.16)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)


include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.15.2
)
FetchContent_MakeAvailable(googletest)


enable_testing()


include(GoogleTest)

add_executable(4real
        main.cpp
        Category.h
        CategoryCounter.h
        Note.h)


add_executable(runTests
        test/test_main.cpp
        test/test_Category.cpp
        test/test_CategoryCounter.cpp
        test/test_Note.cpp
        Category.h
        CategoryCounter.h
        Note.h)

# Linka GoogleTest solo ai test
target_link_libraries(runTests gtest gtest_main)
include(GoogleTest)
add_test(NAME MyTests COMMAND MyTests)
