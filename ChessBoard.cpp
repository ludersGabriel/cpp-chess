#include "ChessBoard.hpp"

ChessBoard::ChessBoard() {
  for (int row = 0; row < BOARD_SIZE; ++row) {
    for (int col = 0; col < BOARD_SIZE; ++col) {
      glm::vec3 position(col * QUAD_SIZE - BOARD_OFFSET,
                         row * QUAD_SIZE - BOARD_OFFSET, 0.0f);
      glm::vec3 color = (row + col) % 2 == 0 ? lightSquare : darkSquare;

      std::vector<Vertex> vertices = {
          {position.x, position.y, 0.0f, 0.0f, 0.0f},
          {position.x + QUAD_SIZE, position.y, 0.0f, 1.0f, 0.0f},
          {position.x + QUAD_SIZE, position.y + QUAD_SIZE, 0.0f, 1.0f, 1.0f},
          {position.x, position.y + QUAD_SIZE, 0.0f, 0.0f, 1.0f}};

      std::vector<index> indices = {0, 1, 2, 2, 3, 0};

      Renderable* quad = new Renderable(vertices, indices, "", position,
                                        glm::vec3(QUAD_SIZE, QUAD_SIZE, 1.0f),
                                        glm::vec3(0.0f), color, true);
      this->squares.push_back(quad);
    }
  }
}