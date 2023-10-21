#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Renderable.hpp"

class Square : public Renderable {
 public:
  Square(const unsigned int rank, const unsigned int file,
         const glm::vec3 position, const float quadSize);

  virtual ~Square() = default;

  float getQuadSize();

 private:
  static const glm::vec3 lightSquare;
  static const glm::vec3 lightDanger;
  static const glm::vec3 darkSquare;
  static const glm::vec3 darkDanger;

  unsigned int rank;  // linha
  unsigned int file;  // coluna
  bool isLight;
  float quadSize;

  const std::vector<Vertex> getSquareVertices(const glm::vec3 position,
                                              const float quadSize) const;
  const std::vector<index> getSquareIndices() const;
  const glm::vec3 getSquareColor(const unsigned int rank,
                                 const unsigned int file) const;
};

#endif