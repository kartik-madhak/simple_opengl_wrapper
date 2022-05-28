#include "Shader.h"

#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>

namespace SOW {
Shader::Shader(std::string sourcePath, GLenum shaderType)
    : sourcePath(std::move(sourcePath)), shaderType(shaderType) {
  std::ifstream t(this->sourcePath);
  std::stringstream buffer;
  buffer << t.rdbuf();
  this->source = buffer.str();

  this->id = glCreateShader(this->shaderType);
  const char *src = this->source.c_str();
  glShaderSource(this->id, 1, &src, nullptr);
  glCompileShader(this->id);

  int success;
  glGetShaderiv(this->id, GL_COMPILE_STATUS, &success);
  if (!success) {
    char infoLog[512];
    glGetShaderInfoLog(this->id, 512, nullptr, infoLog);
    std::cout << this->sourcePath << std::endl;
    std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    throw std::runtime_error("COMPILATION FAILED");
  }
}

unsigned int Shader::getId() const {
  return id;
}

} // SOW