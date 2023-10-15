#include "Renderer.hpp"
#include <glad/glad.h>

Renderer::Renderer() : shader{new Shader()} {}

Renderer::~Renderer() { delete shader; }

void Renderer::draw(const Renderable& object) {
  shader->use();

  glBindVertexArray(object.getVAO());
  glDrawElements(GL_TRIANGLES, object.getIndices().size(), GL_UNSIGNED_INT, 0);

  glBindVertexArray(0);
}

void Renderer::clear() {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}