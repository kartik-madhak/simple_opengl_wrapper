#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <valarray>
#include "lib/Shader.h"
#include "lib/ShaderProgram.h"
#include "lib/Buffer.h"
#include "lib/VertexArray.h"
#include "lib/VertexLayout.h"
#include "vendor/stb_image/stb_image.h"
#include "lib/Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void error_callback(int error, const char *description) {
  fprintf(stderr, "Error: %s\n", description);
}

void GLAPIENTRY
MessageCallback(GLenum source,
                GLenum type,
                GLuint id,
                GLenum severity,
                GLsizei length,
                const GLchar *message,
                const void *userParam) {
  fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
          (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
          type, severity, message);
}

void processKeys(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

int main() {
  if (!glfwInit()) {
    std::cout << "GLFW initialization failed" << std::endl;
    return -1;
  }
  glfwSetErrorCallback(error_callback);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  GLFWwindow *window = glfwCreateWindow(800, 600, "first window", nullptr, nullptr);
  if (!window) {
    std::cout << "window initialization failed" << std::endl;
    return -1;
  }

  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cout << "Failed to initialize OpenGL context" << std::endl;
    return -1;
  }

  // During init, enable debug output
  glEnable(GL_DEBUG_OUTPUT);
  glDebugMessageCallback(MessageCallback, 0);

  glViewport(0, 0, 800, 600);

  float zoomF = 1.0f;
  float vertices[] = {
      // Position                       // Colors                     // Text Coords
      -0.5f, -0.5f, 0.0f, 0.3f, 0.5f, 0.8f, 0.0f, 0.0f,
      0.5f, -0.5f, 0.0f, 0.8f, 0.3f, 0.5f, zoomF, 0.0f,
      0.5f, 0.5f, 0.0f, 0.3f, 0.8f, 0.5f, zoomF, zoomF,
      -0.5f, 0.5f, 0.0f, 0.5f, 0.8f, 0.3f, 0.0f, zoomF,
  };
  unsigned int indices[] = {
      0, 1, 2,
      2, 3, 0
  };

  SOW::Texture texture1(GL_TEXTURE_2D, "../texture_examples/container.jpg", 0);
  SOW::Texture
      texture2(GL_TEXTURE_2D, "../texture_examples/awesomeface.png", 1, GL_RGB, GL_RGBA, GL_UNSIGNED_BYTE, true);

  SOW::VertexArray VAO;

  SOW::Buffer VBO(GL_ARRAY_BUFFER, vertices, sizeof vertices);
  SOW::Buffer IBO(GL_ELEMENT_ARRAY_BUFFER, indices, sizeof indices);

  SOW::VertexLayout vertexLayout(
      {
          SOW::VertexAttribute(3, GL_FLOAT, false),
          SOW::VertexAttribute(3, GL_FLOAT, false),
          SOW::VertexAttribute(2, GL_FLOAT, false),
      });

  VAO.unbind();

  SOW::ShaderProgram shaderProgram(
      {
          SOW::Shader("../shaders_example/vertex.glsl", GL_VERTEX_SHADER),
          SOW::Shader("../shaders_example/fragment.glsl", GL_FRAGMENT_SHADER)
      });

  texture1.use();
  texture2.use();
  shaderProgram.setUniform1i("ourTexture1", texture1.getTextureUnit());
  shaderProgram.setUniform1i("ourTexture2", texture2.getTextureUnit());

//  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
    trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
    shaderProgram.setUniformMat4fv("transform", glm::value_ptr(trans));

    VAO.bind();
    shaderProgram.use();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    float timeValue = glfwGetTime();
    shaderProgram.setUniform4f("uColor", 0.5f, sin(timeValue) / 2.0f + 0.5f, 0.0f, 1.0f);

    glfwSwapBuffers(window);
    glfwPollEvents();
    processKeys(window);
  }

  glfwTerminate();
  return 0;
}