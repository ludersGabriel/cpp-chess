#include "King.hpp"

using namespace chess;

King::King(std::shared_ptr<Square> square,
           const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int King::getValue() const { return King::value; }

std::vector<std::string> King::possibleMoves() const {
  std::shared_ptr<Square> location = getLocation();
  std::vector<std::string> possibleMoves;

  if (location == nullptr) {
    return possibleMoves;
  }

  std::string baseFile = (getLocation())->getFile();
  std::string baseRank = (getLocation())->getFile();

  return possibleMoves;
}