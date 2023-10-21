#include "ChessBoard.hpp"
#include "Engine.hpp"

#include <iostream>

ChessBoard::ChessBoard() {
  Engine* engine = Engine::getInstance();

  float width = engine->getWindowWidth();
  float height = engine->getWindowHeight();

  float quadSize = (height - 0.1f * height) / this->boardSize;

  float xOffset = quadSize / 2;
  float yOffset = quadSize / 2;

  for (int row = 0; row < this->boardSize; ++row) {
    for (int col = 0; col < this->boardSize; ++col) {
      glm::vec3 position(xOffset + col * quadSize, yOffset + row * quadSize,
                         1.0f);

      this->squares.push_back(new Square(row, col, position, quadSize));
    }
  }
}