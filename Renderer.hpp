#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Shader.hpp"
#include "Renderable.hpp"

class Renderer {
 public:
  Renderer();
  virtual ~Renderer();

  void draw(const Renderable& object);
  void clear();

  void setProjectionMatrix(const glm::mat4& projectionMatrix) const;
  void setModelMatrix(const glm::mat4& modelMatrix) const;

 private:
  Shader* shader;
};

#endif
