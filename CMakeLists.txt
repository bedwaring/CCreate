cmake_minimum_required(VERSION 3.20)
project(ccreate)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCES 
    src/main.c
)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_EXE_LINKER_FLAGS "--static")
endif()

add_executable(ccreate ${SOURCES})
