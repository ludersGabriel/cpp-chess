#include "Pawn.hpp"

using namespace chess;

Pawn::Pawn(std::shared_ptr<Square> square,
           const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Pawn::getValue() const { return Pawn::value; }

std::vector<std::string> Pawn::possibleMoves() const {
  std::shared_ptr<Square> location = getLocation();
  std::vector<std::string> possibleMoves;

  if (location == nullptr) {
    return possibleMoves;
  }

  std::string baseFile = (getLocation())->getFile();
  std::string baseRank = (getLocation())->getFile();

  return possibleMoves;
}
