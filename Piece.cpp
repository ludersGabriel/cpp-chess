#include "Piece.hpp"
#include "Square.hpp"
#include <iostream>

namespace chess {

Piece::Piece(std::shared_ptr<Square> square, const EnumFenRepresentation &rep)
    : location{square} {
  this->pieceColor = rep < EnumFenRepresentation::BLACK_BISHOP
                         ? EnumPiecesColors::WHITE
                         : EnumPiecesColors::BLACK;
  fenRep = rep;
}

std::shared_ptr<Square> Piece::getLocation() const {
  // retruns null if the location doesnt hold a square anymore
  return this->location.lock();
}

void Piece::setLocation(std::shared_ptr<Square> square) {
  this->location = square;
}

EnumPiecesColors Piece::getColor() const { return this->pieceColor; }

EnumFenRepresentation Piece::getFen() const { return this->fenRep; }

bool Piece::validateUciLimits(std::string uci) const {
  if (uci[0] < 'a' || uci[0] > 'h') {
    return false;
  }

  if (uci[1] < '1' || uci[1] > '8') {
    return false;
  }

  return true;
}

}  // namespace chess