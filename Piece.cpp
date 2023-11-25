#include "Piece.hpp"

namespace chess {

Piece::Piece(Square *square, const int value, const EnumFenRepresentation &rep)
    : value{value}, location{square} {
  this->pieceColor = rep >= EnumFenRepresentation::WHITE_BISHOP
                         ? EnumPiecesColors::WHITE
                         : EnumPiecesColors::BLACK;
  fenRep = rep;
}

EnumPiecesColors Piece::getColor() const { return this->pieceColor; }

int Piece::getValue() const { return this->value; }

Square *Piece::getLocation() const { return this->location; }

void Piece::setLocation(Square *square) { this->location = square; }

EnumFenRepresentation Piece::getFen() const { return this->fenRep; }

}  // namespace chess