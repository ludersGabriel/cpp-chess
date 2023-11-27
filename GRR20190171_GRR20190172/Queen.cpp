#include "Queen.hpp"

using namespace chess;

Queen::Queen(std::shared_ptr<Square> square,
             const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Queen::getValue() const { return Queen::value; }

bool Queen::checkMove(std::string uci,
                      std::array<std::array<std::shared_ptr<Square>, 8>,
                                 8> const& boardState) const {
  int i = Square::rankToIndex.at(uci.substr(1, 1));
  int j = Square::fileToIndex.at(uci.substr(0, 1));

  std::shared_ptr<Square> square;

  square = boardState[i][j];

  return square->getPiece() != nullptr;
}

std::vector<std::string> Queen::possibleMoves(
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
  char i, j;

  // direita
  for (i = initialFile + 1; i < 'i'; ++i) {
    uci[0] = i;
    possibleMoves.push_back(uci);

    if (this->checkMove(uci, boardState)) {
      break;
    }
  }

  // esquerda
  for (i = initialFile - 1; i >= 'a'; --i) {
    uci[0] = i;
    possibleMoves.push_back(uci);

    if (this->checkMove(uci, boardState)) {
      break;
    }
  }

  uci[0] = initialFile;

  // cima
  for (i = initialRank + 1; i < '9'; ++i) {
    uci[1] = i;
    possibleMoves.push_back(uci);

    if (this->checkMove(uci, boardState)) {
      break;
    }
  }

  // cima
  for (i = initialRank - 1; i > '0'; --i) {
    uci[1] = i;
    possibleMoves.push_back(uci);

    if (this->checkMove(uci, boardState)) {
      break;
    }
  }

  // direita cima
  for (i = initialFile + 1, j = initialRank + 1; i < 'i' && j < '9'; ++i, ++j) {
    uci[0] = i;
    uci[1] = j;
    possibleMoves.push_back(uci);

    if (this->checkMove(uci, boardState)) {
      break;
    }
  }

  // direita baixo
  for (i = initialFile + 1, j = initialRank - 1; i < 'i' && j > '0'; ++i, --j) {
    uci[0] = i;
    uci[1] = j;
    possibleMoves.push_back(uci);

    if (this->checkMove(uci, boardState)) {
      break;
    }
  }

  uci[0] = initialFile;
  uci[1] = initialRank;

  // direita cima
  for (i = initialFile - 1, j = initialRank + 1; i >= 'a' && j < '9';
       --i, ++j) {
    uci[0] = i;
    uci[1] = j;
    possibleMoves.push_back(uci);

    if (this->checkMove(uci, boardState)) {
      break;
    }
  }

  // direita baixo
  for (i = initialFile - 1, j = initialRank - 1; i >= 'a' && j > '0';
       --i, --j) {
    uci[0] = i;
    uci[1] = j;
    possibleMoves.push_back(uci);

    if (this->checkMove(uci, boardState)) {
      break;
    }
  }

  // filtra os movimentos fora da board
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