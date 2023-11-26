#include "Knight.hpp"
#include "iostream"

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

  // constroi uci
  std::string uci = location->getFile() + location->getRank();

  // L cima esquerda/direita
  uci[1]+=2;
  uci[0]--;
  possibleMoves.push_back(uci);
  uci[0]+=2;
  possibleMoves.push_back(uci);

  // L baixo direita/esquerda
  uci[1]-=4;
  possibleMoves.push_back(uci);
  uci[0]-=2;
  possibleMoves.push_back(uci);

  // L esquerda baixo/cima
  uci[1]++;
  uci[0]--;
  possibleMoves.push_back(uci);
  uci[1]+=2;
  possibleMoves.push_back(uci);

  // L direita cima/baixo
  uci[0]+=4;
  possibleMoves.push_back(uci);
  uci[1]-=2;
  possibleMoves.push_back(uci);

  //captura à esquerda
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