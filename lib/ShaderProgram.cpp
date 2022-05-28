#include <iostream>
#include "ShaderProgram.h"

namespace SOW {
ShaderProgram::ShaderProgram(std::initializer_list<Shader> shaders) {
  this->id = glCreateProgram();

  for (const Shader &s : shaders) {
    glAttachShader(this->id, s.getId());
  }

  int success;
  glLinkProgram(this->id);
  glGetProgramiv(this->id, GL_LINK_STATUS, &success);
  if (!success) {
    char infoLog[512];
    glGetProgramInfoLog(this->id, 512, nullptr, infoLog);
    std::cout << "ERROR::SHADER::LINKING_FAILED\n" << infoLog << std::endl;
    throw std::runtime_error("LINKING FAILED");
  }

  for (const Shader &s : shaders) {
    glDeleteShader(s.getId());
  }
}

void ShaderProgram::use() {
  glUseProgram(this->id);
}
bool ShaderProgram::setUniform4f(std::string uniformName, float x, float y, float z, float w) {
  auto iterator = this->uniformLocationCache.find(uniformName);
  if (iterator == this->uniformLocationCache.end()) {
    this->uniformLocationCache[uniformName] = glGetUniformLocation(this->id, uniformName.c_str());
  }
  use();
  glUniform4f(this->uniformLocationCache[uniformName], x, y, z, w);
}

} // SOW