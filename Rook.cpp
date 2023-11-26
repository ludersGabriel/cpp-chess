#include "Rook.hpp"

using namespace chess;

Rook::Rook(std::shared_ptr<Square> square,
           const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Rook::getValue() const { return Rook::value; }

std::vector<std::string> Rook::possibleMoves() const {
  std::shared_ptr<Square> location = getLocation();
  std::vector<std::string> possibleMoves;

  if (location == nullptr) {
    return possibleMoves;
  }

  std::string baseFile = (getLocation())->getFile();
  std::string baseRank = (getLocation())->getFile();

  return possibleMoves;
}