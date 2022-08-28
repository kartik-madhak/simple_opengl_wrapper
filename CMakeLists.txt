cmake_minimum_required(VERSION 3.22)
project(opengl_test)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES glad.c main.cpp lib/Shader.cpp lib/Shader.h lib/ShaderProgram.cpp lib/ShaderProgram.h lib/Buffer.h lib/VertexArray.h lib/Buffer.cpp lib/VertexAttribute.cpp lib/VertexAttribute.h lib/VertexLayout.cpp lib/VertexLayout.h lib/VertexArray.cpp vendor/stb_image/stb_image.cpp lib/Texture.cpp lib/Texture.h)

add_executable(opengl_test ${SOURCE_FILES})
target_link_libraries(opengl_test -lglfw -ldl -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl)
