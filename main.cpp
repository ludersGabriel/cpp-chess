#include "Engine.hpp"
#include "ChessBoard.hpp"

int main() {
  Engine* engine = Engine::getInstance();

  ChessBoard* board = new ChessBoard();

  engine->run();

  engine->shutdown();

  delete board;
  return 0;
}