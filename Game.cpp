#include "Game.hpp"
#include "Interface.hpp"

#include <string>
#include <iostream>

using namespace chess;

Game::Game()
    : board{std::make_unique<Board>(EnumPiecesColors::WHITE)},
      cpu{std::make_unique<Cpu>()},
      turn{EnumPiecesColors::WHITE} {}

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
    Interface::printBoard(*this->board);

    bool playerTurn = this->turn == this->playerColor;
    if (playerTurn) {
      response = Interface::getUserCommand();

      if (response == "quit") {
        break;
      }

      bool validMove;
      while (!(validMove = this->board->playerUpdate(response))) {
        Interface::printError("Invalid move, try again");
        response = Interface::getUserCommand();

        if (response == "quit") {
          break;
        }
      }

    } else {
      std::string fen = this->board->getFen();
      // std::cout << "FEN: " << fen << std::endl;

      response = this->cpu->getMove(fen);
      // std::cout << "CPU move: " << response << std::endl;

      if (response == "none") {
        std::cout
            << "CPU has no moves, something bad happenned. Ending the game!"
            << std::endl;
        break;
      }

      this->board->cpuUpdate(response);
    }

    this->turn = this->turn == EnumPiecesColors::WHITE
                     ? EnumPiecesColors::BLACK
                     : EnumPiecesColors::WHITE;

    this->board->setTurn(this->turn);
  }

  Interface::farewell();
}