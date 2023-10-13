#include "Interface.hpp"
#include "ChessBoard.hpp"

int main() {
  ChessBoard boardl = ChessBoard("textures/chessboard.png");
  Interface inter = Interface();

  inter.addGameObject(&boardl);

  inter.run();

  return 0;
}