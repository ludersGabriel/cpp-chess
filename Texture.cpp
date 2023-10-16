#include <glad/glad.h>
#include <iostream>

#include "Texture.hpp"
#include "stb_image.h"

Texture::Texture(const std::string& path) { this->loadTexture(path); }

void Texture::loadTexture(const std::string& path) {
  int height, width, nrChannels;

  stbi_set_flip_vertically_on_load(true);

  unsigned char* data =
      stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

  if (!data) {
    std::cerr << "Failed to load texture: " << path << std::endl;
    return;
  }

  glGenTextures(1, &this->textureID);
  glBindTexture(GL_TEXTURE_2D, this->textureID);

  GLenum format;
  if (nrChannels == 1) {
    format = GL_RED;
  } else if (nrChannels == 3) {
    format = GL_RGB;
  } else if (nrChannels == 4) {
    format = GL_RGBA;
  } else {
    std::cerr << "Unsupported number of channels: " << nrChannels << std::endl;
    return;
  }

  glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
               GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(data);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, this->textureID);
}

Texture::~Texture() { glDeleteTextures(1, &this->textureID); }