#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include "GameObject.hpp"
#include "Interface.hpp"
#include <string>
#include <vector>

class ChessBoard : public GameObject {
 public:
  ChessBoard(const std::string texturePath);
  virtual ~ChessBoard() = default;

  std::vector<Vertex> generateVertices() const;
  std::vector<index> generateIndices() const;

 private:
  std::string texturePath;
};

#endif