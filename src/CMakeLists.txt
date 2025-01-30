cmake_minimum_required(VERSION 3.27)

project(ballistic_calc C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# target_link_libraries(${PROJECT_NAME} m)

# add inc
include_directories(${PROJECT_SOURCE_DIR}/..)

set(PRO_ROOT_DIR ${CMAKE_SOURCE_DIR}/..)

file(GLOB SUBDIRECTORIES RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/*)

file(GLOB_RECURSE COMPONENTS_SOURCES ${PRO_ROOT_DIR}/components/*.c)

foreach(SUBDIR ${SUBDIRECTORIES})
    if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${SUBDIR}" AND EXISTS "${CMAKE_SOURCE_DIR}/${SUBDIR}/main.c")
        # Add executable named after the subdirectory
        add_executable(${SUBDIR} ${CMAKE_SOURCE_DIR}/${SUBDIR}/main.cpp ${COMPONENTS_SOURCES})
    endif()
endforeach()
