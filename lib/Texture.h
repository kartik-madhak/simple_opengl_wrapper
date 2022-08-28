//
// Created by kartik on 6/4/22.
//

#ifndef OPENGL_TEST_LIB_TEXTURE_H
#define OPENGL_TEST_LIB_TEXTURE_H

#include <string>
namespace SOW {

struct TextureData {
  GLenum target;
  GLint storeFormat;
  int width, height;
  GLenum sourceFormat;
  GLenum sourceDataType;
  void *data;

  TextureData(GLenum Target,
              GLint StoreFormat,
              int Width,
              int Height,
              GLenum SourceFormat,
              GLenum SourceDataType,
              void *Data);
};

class Texture {
public:
  Texture(TextureData textureData, int textureUnit);
  Texture(GLenum target,
          const std::string &imagePath,
          int textureUnit,
          GLint storeFormat = GL_RGB,
          GLenum sourceFormat = GL_RGB,
          GLenum sourceDataType = GL_UNSIGNED_BYTE,
          bool flipVertically = false);
  void use() const;
  void setParam(GLenum pName, GLint param) const;
private:
  unsigned int id;
  int textureUnit;
public:
  int getTextureUnit() const;
private:
  GLenum target;
  void init(TextureData textureData, int TextureUnit);
};

} // SOW

#endif //OPENGL_TEST_LIB_TEXTURE_H
