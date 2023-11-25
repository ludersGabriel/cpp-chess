#ifndef PIECE_HPP
#define PIECE_HPP

#include <vector>
#include <string>

#include "Square.hpp"
#include "EnumPiecesColors.hpp"
#include "EnumFenRepresentation.hpp"

namespace chess {

class Piece {
 public:
  Piece() = default;
  Piece(Square *square, const EnumFenRepresentation &rep);
  virtual ~Piece() = default;

  EnumPiecesColors getColor() const;

  Square *getLocation() const;
  void setLocation(Square *square);

  EnumFenRepresentation getFen() const;

  virtual int getValue() const = 0;
  virtual std::vector<std::string> possibleMoves() const = 0;

 private:
  EnumPiecesColors pieceColor;
  Square *location;

  EnumFenRepresentation fenRep;
};

}  // namespace chess

#endif