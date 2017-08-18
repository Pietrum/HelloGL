cmake_minimum_required(VERSION 3.8)
project(client)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp
        src/graphics/buffers/iBuffer.h
        src/graphics/buffers/IndexBuffer.cpp
        src/graphics/buffers/IndexBuffer.h
        src/graphics/buffers/VertexBuffer.cpp
        src/graphics/buffers/VertexBuffer.h
        src/graphics/buffers/VertexArray.cpp
        src/graphics/buffers/VertexArray.h

        src/graphics/renderers/iRenderer2D.h
        src/graphics/renderers/BatchRenderer2D.cpp
        src/graphics/renderers/BatchRenderer2D.h
        src/graphics/renderers/Renderable2D.cpp
        src/graphics/renderers/Renderable2D.h
        src/graphics/renderers/Sprite2D.cpp
        src/graphics/renderers/Sprite2D.h

        src/graphics/Window.cpp src/graphics/Window.h
        src/graphics/Shader.cpp src/graphics/Shader.h

        src/maths/Vec2.cpp src/maths/Vec2.h
        src/maths/Vec3.cpp src/maths/Vec3.h
        src/maths/Vec4.cpp src/maths/Vec4.h
        src/maths/Mat4.cpp src/maths/Mat4.h

        src/inputs/Keyboard.cpp src/inputs/Keyboard.h
        src/inputs/Mouse.cpp src/inputs/Mouse.h

        src/utils/File.cpp src/utils/File.h)

add_executable(client ${SOURCE_FILES})

find_package(glfw3 3.2 REQUIRED)
target_link_libraries(client glfw)

find_package(glew REQUIRED)
target_link_libraries(client ${GLEW_LIBRARIES})

find_package(OpenGL REQUIRED)
target_link_libraries(client ${OPENGL_gl_LIBRARY})
