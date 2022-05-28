#ifndef OPENGL_TEST_LIB_VERTEXLAYOUT_H
#define OPENGL_TEST_LIB_VERTEXLAYOUT_H

#include <list>
#include "VertexAttribute.h"
namespace SOW {

class VertexLayout {
public:
  VertexLayout(const std::initializer_list<VertexAttribute> &vertexAttributes);
private:
  std::list<VertexAttribute> vertexAttributes;
};

} // SOW

#endif //OPENGL_TEST_LIB_VERTEXLAYOUT_H
