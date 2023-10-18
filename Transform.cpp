#include "Transform.hpp"
#include <glm/gtc/matrix_transform.hpp>

Transform::Transform(const glm::vec3& position, const glm::vec3& scale,
                     const glm::vec3& rotation)
    : position{position}, scale{scale}, rotation{rotation} {}

glm::mat4 Transform::getTransformationMatrix() const {
  glm::mat4 transform = glm::mat4(1.0f);

  // Rotate
  transform = glm::rotate(transform, glm::radians(rotation.x),
                          glm::vec3(1.0f, 0.0f, 0.0f));
  transform = glm::rotate(transform, glm::radians(rotation.y),
                          glm::vec3(0.0f, 1.0f, 0.0f));
  transform = glm::rotate(transform, glm::radians(rotation.z),
                          glm::vec3(0.0f, 0.0f, 1.0f));

  // Scale
  transform = glm::scale(transform, scale);

  return transform;
}

glm::vec3 Transform::getPosition() const { return position; }

glm::vec3 Transform::getScale() const { return scale; }

glm::vec3 Transform::getRotation() const { return rotation; }

void Transform::setPosition(const glm::vec3& position) {
  this->position = position;
}

void Transform::setScale(const glm::vec3& scale) { this->scale = scale; }

void Transform::setRotation(const glm::vec3& rotation) {
  this->rotation = rotation;
}