# -*- CMakeLists.txt generated by CodeLite IDE. Do not edit by hand -*-

cmake_minimum_required(VERSION 2.8.11)

# Project name
project(pystring_extend)

# This setting is useful for providing JSON file used by CodeLite for code completion
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Set default locations
set(CL_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../cmake-build-Debug/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CL_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CL_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CL_OUTPUT_DIRECTORY})

set(CONFIGURATION_NAME "Debug")

# Projects


# Top project
# Define some variables
set(PROJECT_pystring_extend_PATH "${CMAKE_CURRENT_LIST_DIR}")
set(WORKSPACE_PATH "${CMAKE_CURRENT_LIST_DIR}/..")



#{{{{ User Code 1
# Place your code here
#}}}}

include_directories(
    .
    .

)


# Compiler options
add_definitions(-g)
add_definitions(-std=c++17)
add_definitions(-Wall)

# Linker options


if(WIN32)
    # Resource options
endif(WIN32)

# Library path
link_directories(
    .
)

# Define the CXX sources
set ( CXX_SRCS
    ${CMAKE_CURRENT_LIST_DIR}/../../source/format_function.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../source/convert_data.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../source/UnicodeConv.cpp
)

set_source_files_properties(
    ${CXX_SRCS} PROPERTIES COMPILE_FLAGS 
    " -g -std=c++17 -Wall")

if(WIN32)
    enable_language(RC)
    set(CMAKE_RC_COMPILE_OBJECT
        "<CMAKE_RC_COMPILER> ${RC_OPTIONS} -O coff -i <SOURCE> -o <OBJECT>")
endif(WIN32)



#{{{{ User Code 2
# Place your code here
#}}}}

add_library(pystring_extend SHARED ${RC_SRCS} ${CXX_SRCS} ${C_SRCS})
target_link_libraries(pystring_extend ${LINK_OPTIONS})



#{{{{ User Code 3
# Place your code here
#}}}}

