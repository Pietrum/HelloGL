cmake_minimum_required(VERSION 3.8)
project(client)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)

add_executable(client ${SOURCE_FILES})

find_package(glfw3 3.2 REQUIRED)
target_link_libraries(client glfw)

find_package(glew REQUIRED)
target_link_libraries(client ${GLEW_LIBRARIES})

find_package(OpenGL REQUIRED)
target_link_libraries(client ${OPENGL_gl_LIBRARY})
