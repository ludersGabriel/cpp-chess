#include "Piece.hpp"
#include <iostream>
namespace chess {

// grey for white
// black for black
const std::string Piece::whiteColor = "\033[1;37m";
const std::string Piece::blackColor = "\033[1;30m";

Piece::Piece(std::shared_ptr<Square> square, const EnumFenRepresentation &rep)
    : location{square} {
  this->pieceColor = rep >= EnumFenRepresentation::WHITE_BISHOP
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

std::string Piece::getWhiteColor() { return whiteColor; }

std::string Piece::getBlackColor() { return blackColor; }
bool Piece::validateUciLimits(std::string uci) const{
  if(uci[0] < 'a' || uci[0] > 'h'){
    return false;
  }

  if(uci[1] < '1' || uci[1] > '8'){
    return false;
  }

  return true;
}

}  // namespace chess