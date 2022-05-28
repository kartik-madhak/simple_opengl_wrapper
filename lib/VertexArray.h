//
// Created by kartik on 5/28/22.
//

#ifndef OPENGL_TEST_VERTEXARRAY_H
#define OPENGL_TEST_VERTEXARRAY_H

#include <glad/glad.h>
namespace SOW {

class VertexArray {
public:
  VertexArray();
  void bind();
  void unbind();
private:
  unsigned int id;
};

} // SOW

#endif //OPENGL_TEST_VERTEXARRAY_H
