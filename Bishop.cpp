#include "Bishop.hpp"

using namespace chess;

Bishop::Bishop(std::shared_ptr<Square> square,
               const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Bishop::getValue() const { return Bishop::value; }

std::vector<std::string> Bishop::possibleMoves() const {
  std::shared_ptr<Square> location = getLocation();
  std::vector<std::string> possibleMoves;

  if (location == nullptr) {
    return possibleMoves;
  }

  std::string baseFile = (getLocation())->getFile();
  std::string baseRank = (getLocation())->getFile();

  return possibleMoves;
}