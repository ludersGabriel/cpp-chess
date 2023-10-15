#include "Renderable.hpp"

#include <glad/glad.h>
#include <iostream>
#include "stb_image.h"

Renderable::Renderable(const std::vector<Vertex>& vertices,
                       const std::vector<index>& indices,
                       const std::string& texturePath,
                       const glm::vec3& position, const glm::vec3& scale,
                       const glm::vec3& rotation)
    : vertices{vertices},
      indices{indices},
      position{position},
      scale{scale},
      rotation{rotation} {
  glGenVertexArrays(1, &this->VAO);
  glGenBuffers(1, &this->VBO);
  glGenBuffers(1, &this->EBO);

  glBindVertexArray(this->VAO);

  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex),
               &vertices[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               this->indices.size() * sizeof(unsigned int), &indices[0],
               GL_STATIC_DRAW);

  // ppp (position coords)
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void*)offsetof(Vertex, x));
  glEnableVertexAttribArray(0);

  // tt (texture coords)
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void*)offsetof(Vertex, u));
  glEnableVertexAttribArray(1);

  // unbinding the VAO
  glBindVertexArray(0);

  // setting textures
  this->textureID = this->setUpTexture(texturePath);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, this->textureID);

  // add myself to the renderer array
  Engine::getInstance()->addRenderable(this);
}

Renderable::~Renderable() {
  glDeleteVertexArrays(1, &this->VAO);
  glDeleteBuffers(1, &this->VBO);
  glDeleteBuffers(1, &this->EBO);
  glDeleteTextures(1, &this->textureID);
}

unsigned int Renderable::getVAO() const { return this->VAO; }

unsigned int Renderable::getVBO() const { return this->VBO; }

unsigned int Renderable::getEBO() const { return this->EBO; }

unsigned int Renderable::setUpTexture(std::string path) {
  unsigned int texture;
  int height, width, nrChannels;

  stbi_set_flip_vertically_on_load(true);

  unsigned char* data =
      stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

  if (!data) {
    std::cerr << "Failed to load texture: " << path << std::endl;
    return 0;
  }

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  GLenum format;
  if (nrChannels == 1) {
    format = GL_RED;
  } else if (nrChannels == 3) {
    format = GL_RGB;
  } else if (nrChannels == 4) {
    format = GL_RGBA;
  } else {
    std::cerr << "Unsupported number of channels: " << nrChannels << std::endl;
    return 0;
  }

  glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
               GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(data);

  return texture;
}

const std::vector<Vertex>& Renderable::getVertices() const {
  return this->vertices;
}

const std::vector<index>& Renderable::getIndices() const {
  return this->indices;
}
