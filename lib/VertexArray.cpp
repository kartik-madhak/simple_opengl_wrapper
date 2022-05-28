#include "VertexArray.h"

SOW::VertexArray::VertexArray() {
  glGenVertexArrays(1, &this->id);
  bind();
}
void SOW::VertexArray::unbind() {
  glBindVertexArray(0);
}
void SOW::VertexArray::bind() {
  glBindVertexArray(this->id);
}