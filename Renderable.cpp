#include "Renderable.hpp"

#include <glad/glad.h>
#include <iostream>
#include "stb_image.h"

Renderable::Renderable(const std::vector<Vertex>& vertices,
                       const std::vector<index>& indices,
                       const std::string& texturePath,
                       const glm::vec3& position, const glm::vec3& scale,
                       const glm::vec3& rotation, const glm::vec3& color,
                       const bool onlyColor)
    : vertices{vertices},
      indices{indices},
      position{position},
      scale{scale},
      rotation{rotation},
      color{color},
      onlyColor{onlyColor} {
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

  if (!onlyColor) {
    // setting textures
    this->texture = new Texture(texturePath);
  }

  // add myself to the renderer array
  Engine::getInstance()->addRenderable(this);
}

Renderable::~Renderable() {
  glDeleteVertexArrays(1, &this->VAO);
  glDeleteBuffers(1, &this->VBO);
  glDeleteBuffers(1, &this->EBO);

  if (!this->onlyColor) delete this->texture;
}

unsigned int Renderable::getVAO() const { return this->VAO; }

unsigned int Renderable::getVBO() const { return this->VBO; }

unsigned int Renderable::getEBO() const { return this->EBO; }

const std::vector<Vertex>& Renderable::getVertices() const {
  return this->vertices;
}

const std::vector<index>& Renderable::getIndices() const {
  return this->indices;
}

const glm::vec3& Renderable::getColor() const { return this->color; }

const bool Renderable::getOnlyColor() const { return this->onlyColor; }
