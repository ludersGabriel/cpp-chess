#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include <glm/glm.hpp>

#include <string>
#include <vector>

#include "Engine.hpp"
#include "Texture.hpp"
#include "Transform.hpp"

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
             const glm::vec3& rotation = glm::vec3(0.0f),
             const glm::vec3& color = glm::vec3(1.0f),
             const bool onlyColor = false);
  virtual ~Renderable();

  unsigned int getVAO() const;
  unsigned int getVBO() const;
  unsigned int getEBO() const;

  const glm::vec3& getColor() const;
  const bool getOnlyColor() const;

  const std::vector<Vertex>& getVertices() const;
  const std::vector<index>& getIndices() const;

  const Transform* const getTransform() const;

 protected:
  unsigned int VAO;
  unsigned int VBO;
  unsigned int EBO;
  Texture* texture;

  std::vector<Vertex> vertices;
  std::vector<index> indices;

  Transform* transform;
  glm::vec3 color;
  bool onlyColor;

  void updateVertexData(const std::vector<Vertex>& newVertices);
};

#endif