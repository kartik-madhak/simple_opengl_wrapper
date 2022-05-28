#include "VertexAttribute.h"

namespace SOW {

VertexAttribute::VertexAttribute(int Size, GLenum Type, bool Normalized)
    : size(Size), type(Type), normalized(Normalized) {}
int VertexAttribute::getSize() const {
  return size;
}
GLenum VertexAttribute::getType() const {
  return type;
}
bool VertexAttribute::isNormalized() const {
  return normalized;
}
} // SOW