#minimum cmake required VERSION
cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_FLAGS "-Wall")
#project name
project(fxnoob)
#  enabling -I
include_directories(
	include
	)

ADD_LIBRARY( Sort STATIC
	sort.c )
set( APP_SORT test_sort )

ADD_EXECUTABLE( ${APP_SORT}
	test_sort.c )

TARGET_LINK_LIBRARIES( ${APP_SORT}
	Sort )
