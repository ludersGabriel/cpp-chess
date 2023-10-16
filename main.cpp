#include "Engine.hpp"
#include "ChessBoard.hpp"

int main() {
  Engine* engine = Engine::getInstance();

  new ChessBoard("textures/chessboard.png");

  engine->run();

  engine->shutdown();

  return 0;
}