cmake_minimum_required(VERSION 3.28.3)
project(cpp_prog)

set(CMAKE_CXX_STANDARD 20)


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(cpp_prog main.cpp
        liniaerAlg.cpp
        liniaerAlg.h
)

target_link_libraries(cpp_prog ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})