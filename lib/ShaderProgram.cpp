#include <iostream>
#include "ShaderProgram.h"

namespace SOW {
ShaderProgram::ShaderProgram(std::initializer_list<Shader> shaders) {
  this->shaderProgramId = glCreateProgram();

  for (const Shader &s : shaders) {
    glAttachShader(this->shaderProgramId, s.getId());
  }

  int success;
  glLinkProgram(this->shaderProgramId);
  glGetProgramiv(this->shaderProgramId, GL_LINK_STATUS, &success);
  if (!success) {
    char infoLog[512];
    glGetProgramInfoLog(this->shaderProgramId, 512, nullptr, infoLog);
    std::cout << "ERROR::SHADER::LINKING_FAILED\n" << infoLog << std::endl;
    throw std::runtime_error("LINKING FAILED");
  }

  for (const Shader &s : shaders) {
    glDeleteShader(s.getId());
  }
}

void ShaderProgram::use() {
  glUseProgram(this->shaderProgramId);
}

} // SOW