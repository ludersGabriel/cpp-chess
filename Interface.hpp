#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>
#include <unordered_map>
#include "Board.hpp"
#include "EnumFenRepresentation.hpp"

namespace chess {

class Interface {
 public:
  Interface() = delete;
  Interface(const Interface&) = delete;
  Interface(Interface&&) = delete;
  Interface& operator=(const Interface&) = delete;
  Interface& operator=(Interface&&) = delete;

  static std::string greetings();
  static std::string getUserCommand();

  static void printBoard(const Board& board, bool isUnicode = false);

  static void help();
  static void farewell();
  static void clearScreen();

  static void printError(const std::string& error);

 private:
  static const std::string bgLight;
  static const std::string bgDark;
  static const std::string bgReset;

  static const std::string whiteColor;
  static const std::string blackColor;

  static const std::unordered_map<EnumFenRepresentation, std::string>
      fenToUnicode;

  static void printUnicodeBoard(const Board& board);
};

}  // namespace chess

#endif