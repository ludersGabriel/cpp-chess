#include "Game.hpp"
#include "Interface.hpp"

#include <string>

using namespace chess;

Game::Game() : cpu{std::make_unique<Cpu>()}, turn{EnumPiecesColors::WHITE} {}

void Game::run() {
  Interface::clearScreen();

  std::string response = Interface::greetings();

  if (response == "1") {
    this->playerColor = EnumPiecesColors::WHITE;
    this->cpuColor = EnumPiecesColors::BLACK;
  } else if (response == "2") {
    this->playerColor = EnumPiecesColors::BLACK;
    this->cpuColor = EnumPiecesColors::WHITE;
  }

  this->cpu->setColor(this->playerColor);

  while (response != "quit") {
    Interface::clearScreen();
    if (this->turn == this->playerColor) {
      response = Interface::getUserCommand();
    } else {
      // response = this->cpu->getMove();
    }
  }

  Interface::farewell();
}