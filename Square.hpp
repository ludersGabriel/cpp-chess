#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Renderable.hpp"

class Square : public Renderable {
 public:
  Square(const unsigned int rank, const unsigned int file,
         const glm::vec3 position);

  virtual ~Square() = default;

  static float getQuadSize();

 private:
  static constexpr float QUAD_SIZE = .125f;  // 1.0 / 8.0

  static const glm::vec3 lightSquare;
  static const glm::vec3 lightDanger;
  static const glm::vec3 darkSquare;
  static const glm::vec3 darkDanger;

  unsigned int rank;  // linha
  unsigned int file;  // coluna
  bool isLight;

  const std::vector<Vertex> getSquareVertices(const glm::vec3 position) const;
  const std::vector<index> getSquareIndices() const;
  const glm::vec3 getSquareColor(const unsigned int rank,
                                 const unsigned int file) const;
};

#endif