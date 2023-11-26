#include "Rook.hpp"

using namespace chess;

Rook::Rook(std::shared_ptr<Square> square,
           const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Rook::getValue() const { return Rook::value; }

std::vector<std::string> Rook::possibleMoves(
    std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState)
    const {
  std::shared_ptr<Square> location = getLocation();
  std::vector<std::string> possibleMoves;

  if (location == nullptr) {
    return possibleMoves;
  }

  // constroi uci
  std::string uci = location->getFile() + location->getRank();

  char initialFile = uci[0];
  char initialRank = uci[1];
  char i;

  // direita
  for (i = initialFile + 1; i < 'i'; ++i) {
    uci[0] = i;
    possibleMoves.push_back(uci);
  }

  // esquerda
  for (i = initialFile - 1; i >= 'a'; --i) {
    uci[0] = i;
    possibleMoves.push_back(uci);
  }

  uci[0] = initialFile;

  // cima
  for (i = initialRank + 1; i < '9'; ++i) {
    uci[1] = i;
    possibleMoves.push_back(uci);
  }

  // cima
  for (i = initialRank - 1; i > '0'; --i) {
    uci[1] = i;
    possibleMoves.push_back(uci);
  }

  // filtra os movimentos fora da board
  std::vector<std::string>::iterator movit{possibleMoves.begin()};
  for (; movit != possibleMoves.end();) {
    if (!validateUciLimits(*movit)) {
      movit = possibleMoves.erase(movit);
    } else {
      ++movit;
    }
  }

  return possibleMoves;
}