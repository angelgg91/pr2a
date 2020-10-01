

cmake_minimum_required(VERSION 3.17)
project(pr2a)

set(CMAKE_CXX_STANDARD 14)

# prefer newer versions of OpenGL
set(OpenGL_GL_PREFERENCE "LEGACY")
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(SRCS
        src/pr2a.cpp
        src/igvInterfaz.h src/igvInterfaz.cpp
        src/igvEscena3D.h src/igvEscena3D.cpp)

add_executable(pr1
        ${SRCS})

target_link_libraries(pr1
        OpenGL::OpenGL
        OpenGL::GLU
        ${GLUT_LIBRARIES})