#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <glm/glm.hpp>

class Transform {
 public:
  Transform(const glm::vec3& position = glm::vec3(0.0f),
            const glm::vec3& scale = glm::vec3(1.0f),
            const glm::vec3& rotation = glm::vec3(0.0f));

  virtual ~Transform() = default;

  glm::mat4 getTransformationMatrix() const;

  glm::vec3 getPosition() const;
  glm::vec3 getScale() const;
  glm::vec3 getRotation() const;

  void setPosition(const glm::vec3& position);
  void setScale(const glm::vec3& scale);
  void setRotation(const glm::vec3& rotation);

 private:
  glm::vec3 position;
  glm::vec3 scale;
  glm::vec3 rotation;
};

#endif