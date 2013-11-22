cmake_minimum_required(VERSION 2.8)

project(log_test)

set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib" CACHE PATH
    "Output directory for library" )
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin" CACHE PATH
     "Output directory for executables" )
##########################
# bins
##########################
set(TARGET "log_test")
aux_source_directory("src" SRC_DIR)
add_executable(${TARGET} ${SRC_DIR})
