#ifndef OPENGL_TEST_SHADERPROGRAM_H
#define OPENGL_TEST_SHADERPROGRAM_H

#include <map>
#include "Shader.h"

namespace SOW {

class ShaderProgram {
public:
  ShaderProgram(std::initializer_list<Shader> shaders);

  void use();

  bool setUniform4f(const std::string& uniformName, float x, float y, float z, float w);
  bool setUniform1i(const std::string& uniformName, int value);
  bool setUniformMat4fv(const std::string& uniformName, const float* mat, int matCount = 1, bool transpose = false);
private:
  unsigned int id;
  std::map<std::string, int> uniformLocationCache;
  void storeLocationInCache(const std::string &uniformName);
};

} // SOW

#endif //OPENGL_TEST_SHADERPROGRAM_H
