#include "ChessBoard.hpp"

ChessBoard::ChessBoard() {
  for (int row = 0; row < 8; ++row) {
    for (int col = 0; col < 8; ++col) {
      glm::vec3 position(col * Square::getQuadSize() - BOARD_OFFSET,
                         row * Square::getQuadSize() - BOARD_OFFSET, 0.0f);

      this->squares.push_back(new Square(row, col, position));
    }
  }
}