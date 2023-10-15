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

 private:
  Shader* shader;
};

#endif
