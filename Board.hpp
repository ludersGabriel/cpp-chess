#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <memory>
#include <unordered_map>
#include <string>

#include "Square.hpp"
#include "EnumSquareColors.hpp"
#include "EnumFenRepresentation.hpp"
#include "EnumPiecesColors.hpp"

namespace chess {

class Board {
 public:
  Board(const EnumPiecesColors& turn);
  virtual ~Board() = default;

  std::array<std::array<std::string, 8>, 8> getCharBoard() const;
  std::string getFen() const;

  std::string getBgLight() const;
  std::string getBgDark() const;
  std::string getBgReset() const;

  EnumPiecesColors getTurn() const;
  std::shared_ptr<Square>& operator[](const std::string& uciPosition);

  void setTurn(const EnumPiecesColors& turn);
  void cpuUpdate(const std::string& uciMove);

 private:
  EnumPiecesColors turn;
  std::array<std::array<std::shared_ptr<Square>, 8>, 8> squares;

  static const std::array<std::array<EnumFenRepresentation, 8>, 8> initialBoard;
  static const std::unordered_map<std::string, int> fileToIndex;
  static const std::unordered_map<std::string, int> rankToIndex;
  static const std::unordered_map<int, std::string> indexToFile;
  static const std::unordered_map<int, std::string> indexToRank;

  static const std::string bgLight;
  static const std::string bgDark;
  static const std::string bgReset;
};

}  // namespace chess

#endif