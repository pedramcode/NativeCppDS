cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
project(cppds LANGUAGES CXX VERSION 0.0.1)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cc)

add_executable(${PROJECT_NAME}_test ${CMAKE_SOURCE_DIR}/src/test.cc)
target_include_directories(${PROJECT_NAME}_test PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_test(
        NAME UnitTest
        COMMAND ${PROJECT_NAME}_test
)
enable_testing()

# Install the header files
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        DESTINATION include
        )
