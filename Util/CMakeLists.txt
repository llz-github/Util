cmake_minimum_required(VERSION 3.1.0)

include(..//module_standard.cmake)

set(THIRD_LIBRARY_LIST boost pugixml)

string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
	message(STATUS "test:${CURRENT_FOLDER}")
	
generate_framework_project(${CURRENT_FOLDER})


