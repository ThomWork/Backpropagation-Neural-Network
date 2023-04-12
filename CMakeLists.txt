cmake_minimum_required(VERSION 3.0)
project( BackpropNetwork CXX )

set( CMAKE_BULD_TYPE Debug )

include_directories(
	${CMAKE_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/src
)

add_executable( testexec buildtest/main.cpp )
