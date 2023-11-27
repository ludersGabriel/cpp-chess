#include "King.hpp"

using namespace chess;

King::King(std::shared_ptr<Square> square,
           const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int King::getValue() const { return King::value; }

std::vector<std::string> King::possibleMoves(
    std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState)
    const {
  std::shared_ptr<Square> location = getLocation();
  std::vector<std::string> possibleMoves;

  if (location == nullptr) {
    return possibleMoves;
  }

  // constroi uci
  std::string uci = location->getFile() + location->getRank();

  // castle
  // if (notMovedYet()) {
  //   uci[0] -= 2;
  //   possibleMoves.push_back(uci);
  //   uci[0] += 4;
  //   possibleMoves.push_back(uci);
  //   uci[0] -= 2;
  // }

  // cima
  uci[1]++;
  possibleMoves.push_back(uci);

  // cima esquerda
  uci[0]--;
  possibleMoves.push_back(uci);

  // esquerda
  uci[1]--;
  possibleMoves.push_back(uci);

  // esquerda/baixo
  uci[1]--;
  possibleMoves.push_back(uci);

  // baixo
  uci[0]++;
  possibleMoves.push_back(uci);

  // baixo/direita
  uci[0]++;
  possibleMoves.push_back(uci);

  // direita
  uci[1]++;
  possibleMoves.push_back(uci);

  // direita/cima
  uci[1]++;
  possibleMoves.push_back(uci);

  // captura à esquerda
  std::vector<std::string>::iterator movit{possibleMoves.begin()};
  for (; movit != possibleMoves.end();) {
    if (!validateUciLimits(*movit, boardState)) {
      movit = possibleMoves.erase(movit);
    } else {
      ++movit;
    }
  }

  return possibleMoves;
}