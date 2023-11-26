#include "Interface.hpp"

#include "Piece.hpp"

#include <iostream>
#include <iomanip>
#include <cctype>

namespace chess {

const std::string Interface::bgLight = "\033[101m";
const std::string Interface::bgDark = "\033[103m";
const std::string Interface::bgReset = "\033[0m";

const std::string Interface::whiteColor = "\033[1;37m";
const std::string Interface::blackColor = "\033[1;30m";

const std::unordered_map<EnumFenRepresentation, std::string>
    Interface::fenToUnicode = {
        {EnumFenRepresentation::WHITE_KING, "🤴🏻"},
        {EnumFenRepresentation::WHITE_QUEEN, "👸🏻"},
        {EnumFenRepresentation::WHITE_ROOK, "🏛️"},
        {EnumFenRepresentation::WHITE_BISHOP, "🧙🏻‍♂️"},
        {EnumFenRepresentation::WHITE_KNIGHT, "🦄"},
        {EnumFenRepresentation::WHITE_PAWN, "🎳"},
        {EnumFenRepresentation::EMPTY, " "},
        {EnumFenRepresentation::BLACK_KING, "🤴🏾"},
        {EnumFenRepresentation::BLACK_QUEEN, "👸🏾"},
        {EnumFenRepresentation::BLACK_ROOK, "🕋"},
        {EnumFenRepresentation::BLACK_BISHOP, "🧙🏾‍"},
        {EnumFenRepresentation::BLACK_KNIGHT, "🐴"},
        {EnumFenRepresentation::BLACK_PAWN, "♟"}};

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
  std::cout << "\tQuit: quit\n\n";
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
          command[3] < '1' || command[3] > '8' ||
          (command[1] == command[3] && command[0] == command[2])) {
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

void Interface::printBoard(const Board& board, bool isUnicode) {
  if (isUnicode) {
    Interface::printUnicodeBoard(board);
    return;
  }

  std::cout << "   a  b  c  d  e  f  g  h\n";

  std::array<std::array<EnumFenRepresentation, 8>, 8> charBoard =
      board.getFenBoard();

  for (int i = 0; i < 8; ++i) {
    std::cout << 8 - i << " ";
    for (int j = 0; j < 8; ++j) {
      std::string bgColor = ((i + j) % 2 != 0) ? bgLight : bgDark;
      std::string pieceColor =
          (charBoard[i][j] < EnumFenRepresentation::BLACK_BISHOP) ? whiteColor
                                                                  : blackColor;

      std::string out = std::string(1, static_cast<char>(charBoard[i][j]));

      std::cout << bgColor << pieceColor << " " << std::setw(1) << out << " "
                << bgReset;
    }
    std::cout << " " << 8 - i << "\n";
  }

  std::cout << "   a  b  c  d  e  f  g  h\n" << bgReset;
}

void Interface::printUnicodeBoard(const Board& board) {
  std::array<std::array<EnumFenRepresentation, 8>, 8> charBoard =
      board.getFenBoard();

  for (int i = 0; i < 8; ++i) {
    std::cout << 8 - i << " ";
    for (int j = 0; j < 8; ++j) {
      std::string bgColor = ((i + j) % 2 != 0) ? bgLight : bgDark;
      std::string pieceColor =
          (charBoard[i][j] < EnumFenRepresentation::BLACK_BISHOP) ? whiteColor
                                                                  : blackColor;

      std::string out = fenToUnicode.at(charBoard[i][j]);

      std::cout << bgColor << pieceColor << " " << std::setw(1) << out << " "
                << bgReset;
    }
    std::cout << " " << 8 - i << "\n";
  }
}

void Interface::printError(const std::string& error) {
  std::cout << error << "\n";
}

}  // namespace chess
