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
bool ShaderProgram::setUniform4f(const std::string &uniformName, float x, float y, float z, float w) {
  storeLocationInCache(uniformName);
  use();
  glUniform4f(this->uniformLocationCache[uniformName], x, y, z, w);
}
void ShaderProgram::storeLocationInCache(const std::string &uniformName) {
  auto iterator = uniformLocationCache.find(uniformName);
  if (iterator == uniformLocationCache.end()) {
    uniformLocationCache[uniformName] = glGetUniformLocation(id, uniformName.c_str());
  }
}
bool ShaderProgram::setUniform1i(const std::string &uniformName, int value) {
  storeLocationInCache(uniformName);
  use();
  glUniform1i(this->uniformLocationCache[uniformName], value);
}
bool ShaderProgram::setUniformMat4fv(const std::string &uniformName, const float *mat, int matCount, bool transpose) {
  storeLocationInCache(uniformName);
  use();
  glUniformMatrix4fv(this->uniformLocationCache[uniformName], matCount, transpose, mat);
}

} // SOW