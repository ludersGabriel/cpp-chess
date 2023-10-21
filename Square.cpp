#include "Square.hpp"

#include <iostream>

const glm::vec3 Square::lightSquare =
    glm::vec3(236.0f / 255.0f, 229.0f / 255.0f, 203.0f / 255.0f);
const glm::vec3 Square::lightDanger =
    glm::vec3(215.0f / 255.0f, 80.0f / 255.0f, 62.0f / 255.0f);
const glm::vec3 Square::darkSquare =
    glm::vec3(0.0f, 134.0f / 255.0f, 125.0f / 255.0f);
const glm::vec3 Square::darkDanger =
    glm::vec3(168.0f / 255.0f, 49.0f / 255.0f, 49.0f / 255.0f);

Square::Square(const unsigned int rank, const unsigned int file,
               const glm::vec3 position, const float quadSize)
    : Renderable{this->getSquareVertices(position, quadSize),
                 this->getSquareIndices(),
                 "",
                 position,
                 glm::vec3(1.0f, 1.0f, 1.0f),
                 glm::vec3(0.0f),
                 this->getSquareColor(rank, file),
                 true},
      rank{rank},
      file{file},
      quadSize{quadSize} {
  this->isLight = (rank + file) % 2 != 0;
}

const std::vector<index> Square::getSquareIndices() const {
  return {0, 1, 2, 2, 3, 0};
}

const std::vector<Vertex> Square::getSquareVertices(
    const glm::vec3 position, const float quadSize) const {
  float halfSize = quadSize / 2.0f;  // Half the size of a square
  return {{halfSize, halfSize, 0.0f, 0.0f, 0.0f},
          {halfSize, -halfSize, 0.0f, 1.0f, 0.0f},
          {-halfSize, -halfSize, 0.0f, 1.0f, 1.0f},
          {-halfSize, halfSize, 0.0f, 0.0f, 1.0f}};
}

float Square::getQuadSize() { return this->quadSize; }

const glm::vec3 Square::getSquareColor(const unsigned int rank,
                                       const unsigned int file) const {
  return (rank + file) % 2 != 0 ? lightSquare : darkSquare;
}
