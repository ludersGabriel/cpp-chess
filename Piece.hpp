#ifndef PIECE_HPP
#define PIECE_HPP

#include "Square.hpp"
#include "EnumPiecesColors.hpp"
#include "EnumFenRepresentation.hpp"
#include <vector>

namespace chess {

class Piece {
 public:
  Piece() = default;
  Piece(Square *square, const int value, const EnumFenRepresentation &rep);
  virtual ~Piece() = default;

  EnumPiecesColors getColor() const;
  int getValue() const;

  Square *getLocation() const;
  void setLocation(Square *square);

  EnumFenRepresentation getFen() const;

  //   virtual std::vector<Square> const &possibleMoves(Square *square) const =
  //   0;

 private:
  int value;
  EnumPiecesColors pieceColor;
  Square *location;

  EnumFenRepresentation fenRep;
};

}  // namespace chess

#endif