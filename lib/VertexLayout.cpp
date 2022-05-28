#include <array>
#include <iostream>
#include <vector>
#include "VertexLayout.h"

namespace SOW {
VertexLayout::VertexLayout(const std::initializer_list<VertexAttribute> &vertexAttributes) : vertexAttributes(
    vertexAttributes) {

  int index = 0;
  std::vector<int> offsets;
  int stride = 0;
  for (VertexAttribute v : vertexAttributes) {
    offsets.push_back(stride);
    stride += v.getSize() * sizeof v.getType();
  }
  for (VertexAttribute v : vertexAttributes) {
    glVertexAttribPointer(index,
                          v.getSize(),
                          v.getType(),
                          v.isNormalized(),
                          stride,
                          (void*)offsets[index]);
    glEnableVertexAttribArray(index);
    ++index;
  }
}
} // SOW