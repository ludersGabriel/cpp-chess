#include "Queen.hpp"

using namespace chess;

Queen::Queen(std::shared_ptr<Square> square,
             const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Queen::getValue() const { return Queen::value; }

std::vector<std::string> Queen::possibleMoves() const {
  std::shared_ptr<Square> location = getLocation();
  std::vector<std::string> possibleMoves;

  if (location == nullptr) {
    return possibleMoves;
  }

  std::string baseFile = (getLocation())->getFile();
  std::string baseRank = (getLocation())->getFile();

  return possibleMoves;
}