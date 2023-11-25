#include "Piece.hpp"

namespace chess {

Piece::Piece(Square *square, const EnumFenRepresentation &rep)
    : location{square} {
  this->pieceColor = rep >= EnumFenRepresentation::WHITE_BISHOP
                         ? EnumPiecesColors::WHITE
                         : EnumPiecesColors::BLACK;
  fenRep = rep;
}

EnumPiecesColors Piece::getColor() const { return this->pieceColor; }

Square *Piece::getLocation() const { return this->location; }

void Piece::setLocation(Square *square) { this->location = square; }

EnumFenRepresentation Piece::getFen() const { return this->fenRep; }

}  // namespace chess