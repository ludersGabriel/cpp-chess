#include "ChessBoard.hpp"

ChessBoard::ChessBoard(std::string texturePath)
    : Renderable(this->generateVertices(), this->generateIndices(),
                 texturePath) {}

std::vector<Vertex> ChessBoard::generateVertices() const {
  return {
      // Positions         // Texture Coords
      {-1.0f, 1.0f, 0.0f, 0.0f, 1.0f},  // Top-left
      {1.0f, 1.0f, 0.0f, 1.0f, 1.0f},   // Top-right
      {1.0f, -1.0f, 0.0f, 1.0f, 0.0f},  // Bottom-right
      {-1.0f, -1.0f, 0.0f, 0.0f, 0.0f}  // Bottom-left
  };
}

std::vector<index> ChessBoard::generateIndices() const {
  // Define indices for the two triangles of the quad.
  return {
      0, 1, 2,  // First Triangle
      2, 3, 0   // Second Triangle
  };
}