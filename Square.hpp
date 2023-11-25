#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "EnumSquareColors.hpp"
class Piece;  // Forward Declaration

#include <string>

namespace chess {

class Square {
 public:
  Square() = default;
  Square(const std::string file, const std::string rank, EnumSquareColors color);
  virtual ~Square() = default;

  std::string getFile() const;
  std::string getRank() const;

  bool isOccupied() const;
  void setOccupant(Piece *p);
  Piece *getOccupant();

  const std::string getFen() const;

 private:
  std::string file;  // vertical line of chess
  std::string rank;  // horizontal line of chess

  EnumSquareColors squareColor;
  Piece *piece;
};

}  // namespace chess

#endif