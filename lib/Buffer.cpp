#include "Buffer.h"

SOW::Buffer::Buffer(GLenum bufferType, void *arr, unsigned int size, GLenum method) {
  glGenBuffers(1, &this->id);
  this->bufferType = bufferType;
  bind();
  glBufferData(this->bufferType, size, arr, method);
}

void SOW::Buffer::bind() const {
  glBindBuffer(this->bufferType, this->id);
}

void SOW::Buffer::unbind() const {
  glBindBuffer(this->bufferType, 0);
}
