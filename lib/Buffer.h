#ifndef OPENGL_TEST_BUFFER_H
#define OPENGL_TEST_BUFFER_H

#include <glad/glad.h>

namespace SOW {

class Buffer {
public:
  Buffer(GLenum bufferType, void *arr, unsigned int size, GLenum method = GL_STATIC_DRAW);

  void bind() const;

  void unbind() const;
protected:
  unsigned int id;
  GLenum bufferType;
};

} // SOW

#endif //OPENGL_TEST_BUFFER_H
