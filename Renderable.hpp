#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include <glm/glm.hpp>

#include <string>
#include <vector>

#include "Engine.hpp"

struct Vertex {
  float x, y, z;  // positions
  float u, v;     // texture coords
};

typedef unsigned int index;

class Renderable {
 public:
  Renderable(const std::vector<Vertex>& vertices,
             const std::vector<index>& indices, const std::string& texturePath,
             const glm::vec3& position = glm::vec3(0.0f),
             const glm::vec3& scale = glm::vec3(1.0f),
             const glm::vec3& rotation = glm::vec3(0.0f));
  virtual ~Renderable();

  unsigned int getVAO() const;
  unsigned int getVBO() const;
  unsigned int getEBO() const;

  // TODO: ask about this in class
  unsigned int setUpTexture(std::string path);

  const std::vector<Vertex>& getVertices() const;
  const std::vector<index>& getIndices() const;

 protected:
  unsigned int VAO;
  unsigned int VBO;
  unsigned int EBO;
  unsigned int textureID;

  const std::vector<Vertex> vertices;
  const std::vector<index> indices;

  glm::vec3 position;
  glm::vec3 scale;
  glm::vec3 rotation;
};

#endif