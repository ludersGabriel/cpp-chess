#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <glm/glm.hpp>

#include <vector>

#include "Shader.hpp"

struct Vertex {
  float x, y, z;  // positions
  float u, v;     // texture coords
};

typedef unsigned int index;

class GameObject {
 public:
  GameObject(const std::vector<Vertex>& vertices,
             const std::vector<index>& indices, const std::string& texturePath,
             const glm::vec3& position = glm::vec3(0.0f),
             const glm::vec3& scale = glm::vec3(1.0f),
             const glm::vec3& rotation = glm::vec3(0.0f));
  virtual ~GameObject();

  void render() const;

  unsigned int getVAO() const;
  unsigned int getVBO() const;
  unsigned int getEBO() const;

  // TODO: ask about this in class
  unsigned int setUpTexture(std::string path);

 protected:
  unsigned int VAO;
  unsigned int VBO;
  unsigned int EBO;
  unsigned int textureID;
  Shader shader;

  std::vector<Vertex> vertices;
  std::vector<index> indices;

  glm::vec3 position;
  glm::vec3 scale;
  glm::vec3 rotation;
};

#endif