#ifndef OPENGL_TEST_LIB_VERTEXATTRIBUTE_H
#define OPENGL_TEST_LIB_VERTEXATTRIBUTE_H

#include <glad/glad.h>
namespace SOW {

class VertexAttribute {
public:
  [[nodiscard]] int getSize() const;
  [[nodiscard]] GLenum getType() const;
  [[nodiscard]] bool isNormalized() const;
  VertexAttribute(int Size, GLenum Type, bool Normalized);
private:
  int size;
  GLenum type;
  bool normalized;
};


} // SOW

#endif //OPENGL_TEST_LIB_VERTEXATTRIBUTE_H
