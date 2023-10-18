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

  const glm::vec3 lightSquare =
      glm::vec3(236.0f / 255.0f, 229.0f / 255.0f, 203.0f / 255.0f);
  const glm::vec3 lightDanger =
      glm::vec3(215.0f / 255.0f, 80.0f / 255.0f, 62.0f / 255.0f);
  const glm::vec3 darkSquare =
      glm::vec3(0.0f, 134.0f / 255.0f, 125.0f / 255.0f);
  const glm::vec3 darkDanger =
      glm::vec3(168.0f / 255.0f, 49.0f / 255.0f, 49.0f / 255.0f);

  std::vector<const Renderable*> squares;
};

#endif