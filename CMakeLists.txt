cmake_minimum_required (VERSION 2.6)
project (metamove)

add_subdirectory( src )

file(GLOB SRCS src/*.cpp src/*.h)
add_executable(${PROJECT_NAME} ${SRCS} )