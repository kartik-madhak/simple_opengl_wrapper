//
// Created by kartik on 6/4/22.
//

#include <glad/glad.h>
#include "Texture.h"
#include "../vendor/stb_image/stb_image.h"

namespace SOW {
Texture::Texture(TextureData textureData, int textureUnit) {
  init(textureData, textureUnit);
}
Texture::Texture(GLenum target,
                 const std::string &imagePath,
                 int textureUnit,
                 GLint storeFormat,
                 GLenum sourceFormat,
                 GLenum sourceDataType,
                 bool flipVertically) {
  int width, height, nrChannels;
  stbi_set_flip_vertically_on_load(flipVertically);
  unsigned char *data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, 0);

  init(TextureData(target, storeFormat, width, height, sourceFormat, sourceDataType, data), textureUnit);
  stbi_image_free(data);
}
void Texture::use() const {
  glActiveTexture(GL_TEXTURE0 + textureUnit);
  glBindTexture(target, id);
}
void Texture::init(TextureData textureData, int TextureUnit) {
  this->textureUnit = TextureUnit;
  this->target = textureData.target;
  glGenTextures(1, &id);
  glBindTexture(target, id);
  glTexImage2D(target,
               0,
               textureData.storeFormat,
               textureData.width,
               textureData.height,
               0,
               textureData.sourceFormat,
               textureData.sourceDataType,
               textureData.data);
  glGenerateMipmap(target);
}
int Texture::getTextureUnit() const {
  return textureUnit;
}
void Texture::setParam(GLenum pName, GLint param) const {
  glTextureParameteri(id, pName, param);
}
TextureData::TextureData(GLenum Target,
                         GLint StoreFormat,
                         int Width,
                         int Height,
                         GLenum SourceFormat,
                         GLenum SourceDataType,
                         void *Data)
    : target(Target), storeFormat(StoreFormat), width(Width), height(Height), sourceFormat(SourceFormat),
      sourceDataType(SourceDataType), data(Data) {}
} // SOW