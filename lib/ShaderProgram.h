#ifndef OPENGL_TEST_SHADERPROGRAM_H
#define OPENGL_TEST_SHADERPROGRAM_H

#include "Shader.h"

namespace SOW {

class ShaderProgram {
public:
  ShaderProgram(std::initializer_list<Shader> shaders);

  void use();

private:
  unsigned int shaderProgramId;
};

} // SOW

#endif //OPENGL_TEST_SHADERPROGRAM_H
