#include "Engine.hpp"
#include "ChessBoard.hpp"

int main() {
  Engine inter = Engine();
  ChessBoard boardl = ChessBoard("textures/chessboard.png");

  inter.addRenderable(&boardl);

  inter.run();

  return 0;
}