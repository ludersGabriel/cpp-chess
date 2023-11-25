#include "Interface.hpp"

#include <iostream>

using namespace chess;

std::string Interface::greetings() {
  std::cout << "Welcome to the cpp chess game!\n\n";
  std::cout << "When entering moves, enter them in the UCI format:\n";
  std::cout << "\te2e4 -> This moves the piece from e2 to e4\n";
  std::cout << "You can also ask for the moves of a piece:\n";
  std::cout << "\te2\n\n";

  std::cout << "If you want to quit the game, at any time, enter 'quit'\n";
  std::cout << "If you want to see the list of inputs again, enter 'help'\n\n";

  std::cout << "If you want to proceed, choose a color:\n";
  std::cout << "1. White\n";
  std::cout << "2. Black\n\n > ";

  std::string command;
  std::getline(std::cin, command);

  while (command != "1" && command != "2" && command != "quit") {
    std::cout << "Invalid input, try again (1, 2, quit)\n > ";
    std::getline(std::cin, command);
  }

  return command;
}

void Interface::help() {
  std::cout << "\nPossible inputs:\n";
  std::cout << "\tAsk for moves: e2\n";
  std::cout << "\tMake a move: e2e4\n";
  std::cout << "\tAsk for help: help\n";
  std::cout << "Quit: quit\n\n";
}

std::string Interface::getUserCommand() {
  std::string command;

  do {
    std::cout << " > ";
    std::getline(std::cin, command);

    if (command == "help") {
      Interface::help();
      continue;
    }

    if (command == "quit") {
      break;
    }

    if (command.size() == 2) {
      if (command[0] < 'a' || command[0] > 'h' || command[1] < '1' ||
          command[1] > '8') {
        std::cout << "Invalid input, try again\n";
        continue;
      }

      return command;
    } else if (command.size() == 4) {
      if (command[0] < 'a' || command[0] > 'h' || command[1] < '1' ||
          command[1] > '8' || command[2] < 'a' || command[2] > 'h' ||
          command[3] < '1' || command[3] > '8') {
        std::cout << "Invalid input, try again\n";
        continue;
      }

      return command;
    } else {
      std::cout << "Invalid input, try again\n";
      continue;
    }

  } while (command != "quit");

  return command;
}

void Interface::farewell() { std::cout << "Thanks for playing!\n"; }

void Interface::clearScreen() {
  std::cout << "\033[2J\033[1;1H";
  std::cout.flush();
}
