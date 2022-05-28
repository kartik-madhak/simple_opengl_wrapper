#ifndef OPENGL_TEST_SHADERPROGRAM_H
#define OPENGL_TEST_SHADERPROGRAM_H

#include <map>
#include "Shader.h"

namespace SOW {

class ShaderProgram {
public:
  ShaderProgram(std::initializer_list<Shader> shaders);

  void use();

  bool setUniform4f(std::string uniformName, float x, float y, float z, float w);
private:
  unsigned int id;
  std::map<std::string, int> uniformLocationCache;
};

} // SOW

#endif //OPENGL_TEST_SHADERPROGRAM_H
