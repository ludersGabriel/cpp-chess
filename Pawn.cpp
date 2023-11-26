#include "Pawn.hpp"

using namespace chess;

Pawn::Pawn(std::shared_ptr<Square> square,
           const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Pawn::getValue() const { return Pawn::value; }

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
  std::string firstRank;
  if (this->getColor() == EnumPiecesColors::WHITE) {
    mod = 1;
    firstRank = "2";
  } else {
    mod = -1;
    firstRank = "7";
  }

  std::shared_ptr<Square> square;
  int i;
  int j;

  std::string rank;
  std::string file;

  // se é o primeiro movimento, pode se mover duas vezes
  if (uci[1] == firstRank[0]) {
    uci[1] += mod*2;

    rank = uci.substr(1, 1);
    file = uci.substr(0, 1);

    if(rank >= "1" && rank <= "8" && file >= "a" && file <= "h"){
      i = Square::rankToIndex.at(rank);
      j = Square::fileToIndex.at(file);

      if (boardState[i][j]->getPiece() == nullptr) {
        possibleMoves.push_back(uci);
      }
    }
    uci[1] -= mod*2;
  }

  // peão move uma vez para frente
  uci[1] += mod;

  rank = uci.substr(1, 1);
  file = uci.substr(0, 1);

  if(rank >= "1" && rank <= "8" && file >= "a" && file <= "h"){
    i = Square::rankToIndex.at(rank);
    j = Square::fileToIndex.at(file);

    if (boardState[i][j]->getPiece() == nullptr) {
      possibleMoves.push_back(uci);
    }
  }

  // captura à esquerda
  uci[0]--;

  rank = uci.substr(1, 1);
  file = uci.substr(0, 1);

  if(rank >= "1" && rank <= "8" && file >= "a" && file <= "h"){
    i = Square::rankToIndex.at(rank);
    j = Square::fileToIndex.at(file);

    square = boardState[i][j];

    if (square->getPiece() != nullptr) {
      if (square->getPiece()->getColor() != this->getColor()) {
        possibleMoves.push_back(uci);
      }
    }
  }

  // captura à direita
  uci[0] += 2;

  rank = uci.substr(1, 1);
  file = uci.substr(0, 1);

  if(rank >= "1" && rank <= "8" && file >= "a" && file <= "h"){
    i = Square::rankToIndex.at(rank);
    j = Square::fileToIndex.at(file);

    square = boardState[i][j];

    if (square->getPiece() != nullptr &&
        square->getPiece()->getColor() != this->getColor()) {
      possibleMoves.push_back(uci);
    }
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