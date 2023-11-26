#include "Pawn.hpp"

using namespace chess;

Pawn::Pawn(std::shared_ptr<Square> square,
           const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation), isFirstMove{true} {}

int Pawn::getValue() const { return Pawn::value; }

bool Pawn::notMovedYet() const { return isFirstMove; }

std::vector<std::string> Pawn::possibleMoves(
    std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState)
    const {
  std::shared_ptr<Square> location = getLocation();
  std::vector<std::string> possibleMoves;

  if (location == nullptr) {
    return possibleMoves;
  }

  // constroi uci -> posicao atual
  std::string uci = location->getFile() + location->getRank();

  // checa orientação baseado na cor da peça
  int mod;
  if (this->getColor() == EnumPiecesColors::WHITE) {
    mod = 1;
  } else {
    mod = -1;
  }

  std::shared_ptr<Square> square;
  int i;
  int j;

  // peão move uma vez para frente
  uci[1] += mod;

  i = Square::rankToIndex.at(uci.substr(1, 1));
  j = Square::fileToIndex.at(uci.substr(0, 1));

  if (boardState[i][j]->getPiece() == nullptr) {
    possibleMoves.push_back(uci);
  }

  // se é o primeiro movimento, pode se mover duas vezes
  if (notMovedYet()) {
    uci[1] += mod;

    i = Square::rankToIndex.at(uci.substr(1, 1));
    j = Square::fileToIndex.at(uci.substr(0, 1));

    if (boardState[i][j]->getPiece() == nullptr) {
      possibleMoves.push_back(uci);
    }

    uci[1] -= mod;
  }

  // captura à esquerda
  uci[0]--;

  i = Square::rankToIndex.at(uci.substr(1, 1));
  j = Square::fileToIndex.at(uci.substr(0, 1));

  square = boardState[i][j];

  if (square->getPiece() != nullptr) {
    if (square->getPiece()->getColor() != this->getColor()) {
      possibleMoves.push_back(uci);
    }
  }

  // captura à direita
  uci[0] += 2;
  i = Square::rankToIndex.at(uci.substr(1, 1));
  j = Square::fileToIndex.at(uci.substr(0, 1));

  square = boardState[i][j];

  if (square->getPiece() != nullptr &&
      square->getPiece()->getColor() != this->getColor()) {
    possibleMoves.push_back(uci);
  }

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