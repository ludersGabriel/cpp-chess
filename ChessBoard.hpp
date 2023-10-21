#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include "Square.hpp"

#include <glm/glm.hpp>
#include <string>
#include <vector>

class ChessBoard {
 public:
  ChessBoard();
  virtual ~ChessBoard() = default;

 private:
  static constexpr float boardSize = 8.0f;

  std::vector<Square*> squares;
};

#endif