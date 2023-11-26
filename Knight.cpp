#include "Knight.hpp"

using namespace chess;

Knight::Knight(std::shared_ptr<Square> square,
               const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Knight::getValue() const { return Knight::value; }

std::vector<std::string> Knight::possibleMoves() const {
  std::shared_ptr<Square> location = getLocation();
  std::vector<std::string> possibleMoves;

  if (location == nullptr) {
    return possibleMoves;
  }

  std::string baseFile = (getLocation())->getFile();
  std::string baseRank = (getLocation())->getFile();

  return possibleMoves;
}