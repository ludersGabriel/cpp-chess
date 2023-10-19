#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include "Square.hpp"
#include "Engine.hpp"

#include <glm/glm.hpp>
#include <string>
#include <vector>

class ChessBoard {
 public:
  ChessBoard();
  virtual ~ChessBoard() = default;

 private:
  static constexpr float BOARD_OFFSET = 0.5;

  std::vector<const Square*> squares;
};

#endif