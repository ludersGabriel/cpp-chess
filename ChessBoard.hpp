#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include "Renderable.hpp"
#include "Engine.hpp"

#include <glm/glm.hpp>
#include <string>
#include <vector>

class ChessBoard {
 public:
  ChessBoard();
  virtual ~ChessBoard() = default;

 private:
  static constexpr int BOARD_SIZE = 8;
  static constexpr float QUAD_SIZE = .125f;
  static constexpr float BOARD_OFFSET = 0.5;

  const glm::vec3 lightSquare = glm::vec3(236, 229, 203);
  const glm::vec3 lightDanger = glm::vec3(215, 80, 62);
  const glm::vec3 darkSquare = glm::vec3(0, 134, 125);
  const glm::vec3 darkDanger = glm::vec3(168, 49, 49);

  std::vector<const Renderable*> squares;
};

#endif