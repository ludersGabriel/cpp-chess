#include "Renderer.hpp"
#include <glad/glad.h>

#include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtx/string_cast.hpp>
#include <iostream>

Renderer::Renderer() : shader{new Shader()} {
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
}

Renderer::~Renderer() { delete shader; }

void Renderer::draw(const Renderable& object) {
  shader->use();

  shader->setBool("onlyColor", object.getOnlyColor());

  shader->setVec3("color", object.getColor());

  glm::mat4 model = glm::mat4(1.0f);
  model = glm::translate(model, object.getTransform()->getPosition());
  shader->setMat4("model", model);

  glm::mat4 view = glm::mat4(1.0f);
  view = glm::translate(view, glm::vec3{0.0f, 0.0f, -3.0f});
  shader->setMat4("view", view);

  glm::mat4 projection = glm::ortho(0.0f, 1600.0f, 0.0f, 900.0f, 0.1f, 100.0f);
  shader->setMat4("projection", projection);

  glBindVertexArray(object.getVAO());
  glDrawElements(GL_TRIANGLES, object.getIndices().size(), GL_UNSIGNED_INT, 0);

  glBindVertexArray(0);
}

void Renderer::clear() {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}