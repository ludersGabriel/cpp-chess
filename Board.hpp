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

  std::array<std::array<EnumFenRepresentation, 8>, 8> getFenBoard() const;
  std::string getFen() const;

  EnumPiecesColors getTurn() const;
  std::shared_ptr<Square>& operator[](const std::string& uciPosition);

  std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& getSquares()
      const;

  void setTurn(const EnumPiecesColors& turn);
  void cpuUpdate(const std::string& uciMove);

  bool playerUpdate(const std::string& uciMove);

 private:
  EnumPiecesColors turn;
  std::array<std::array<std::shared_ptr<Square>, 8>, 8> squares;

  static const std::array<std::array<EnumFenRepresentation, 8>, 8> initialBoard;
};

}  // namespace chess

#endif