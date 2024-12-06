cmake_minimum_required(VERSION 3.18)
project(itec-se VERSION 0.2.0)
enable_language(C)


# -----------------------------------
# Set Environment Variables for development
# Add directories for inlucdes
# -----------------------------------

# Add Environment Variable to include debug symbols to the build
set(CMAKE_BUILD_TYPE Debug)

# Add Environment Variable to enable VERBOSE Mode
set(CMAKE_VERBOSE_MAKEFILE 1)

# add the src folder as include directory
include_directories(${CMAKE_SOURCE_DIR}/src/)

# -----------------------------------
# One file executables
# -----------------------------------

add_executable(code-intro-ex ./src/c-intro.c)

add_executable(arg-ex ./src/argument-example.c)

# -----------------------------------
# Example Executable with external Library for Math Functions
# -----------------------------------

add_executable(runtime-ex ./src/runtime-test-example.c)
target_link_libraries(runtime-ex PRIVATE m) #libm.so windows: libm.dll


# -----------------------------------
# Build a Library with your own files - called: libitec.so
# -----------------------------------

# build Library: The source files for the library are passed as an argument 
# to add_library(). This looks like the following line:

add_library(itec SHARED 
    ./src/itec-lib/itec.c
    ./src/itec-lib/quicksort.c
    ./src/itec-lib/mergesort.c
    ./src/itec-lib/patternsearch.c
    )

# Now let's use our library. 
add_executable(sort_comp_with_lib-ex  ./src/sort-comp-main.c)

# Next, the new library target is linked to the executable target using 
# target_link_libraries().
target_link_libraries(sort_comp_with_lib-ex PUBLIC itec)


add_executable(text-suche_with_lib-ex ./src/text-suche-example.c)
target_link_libraries(text-suche_with_lib-ex PUBLIC itec)


# -----------------------------------
# Include Unit Testing
# -----------------------------------

include(cmake/FetchCMocka.cmake)

add_executable(CMockaExample test/cmocka-example-main.c)
#target_compile_features(CMockaExample PRIVATE c_std_99)
target_link_libraries(CMockaExample PRIVATE cmocka)

add_executable(sort-test test/sort-test-main.c)
target_link_libraries(sort-test PRIVATE cmocka itec)

add_executable(itec-util-test test/sort-test-main.c)
target_link_libraries(itec-util-test PRIVATE cmocka itec)

add_executable(itec-pattern-test test/pattern-search-text-main.c)
target_link_libraries(itec-pattern-test PRIVATE cmocka itec)


enable_testing()
add_test(NAME CMockaExample COMMAND CMockaExample)
add_test(NAME sort-test COMMAND sort-test)
add_test(NAME itec-util-test COMMAND itec-util-test)
add_test(NAME itec-pattern-test COMMAND itec-pattern-test)