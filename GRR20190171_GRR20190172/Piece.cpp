#include "Piece.hpp"
#include "Square.hpp"
#include <iostream>

namespace chess {

Piece::Piece(std::shared_ptr<Square> square, const EnumFenRepresentation& rep)
    : location{square} {
  this->pieceColor = rep < EnumFenRepresentation::BLACK_BISHOP
                         ? EnumPiecesColors::WHITE
                         : EnumPiecesColors::BLACK;
  fenRep = rep;
}

std::shared_ptr<Square> Piece::getLocation() const {
  // retruns null if the location doesnt hold a square anymore
  return this->location.lock();
}

void Piece::setLocation(std::shared_ptr<Square> square) {
  this->location = square;
}

EnumPiecesColors Piece::getColor() const { return this->pieceColor; }

EnumFenRepresentation Piece::getFen() const { return this->fenRep; }

bool Piece::validateUciLimits(std::string uci,
                              std::array<std::array<std::shared_ptr<Square>, 8>,
                                         8> const& boardState) const {
  if (uci[0] < 'a' || uci[0] > 'h') {
    return false;
  }

  if (uci[1] < '1' || uci[1] > '8') {
    return false;
  }

  int i = Square::rankToIndex.at(uci.substr(1, 1));
  int j = Square::fileToIndex.at(uci.substr(0, 1));

  if (boardState[i][j]->getPiece() != nullptr &&
      boardState[i][j]->getPiece()->getColor() == this->getColor()) {
    return false;
  }

  return true;
}

bool Piece::validateIfMyKingIsInCheck(
    std::string uci,
    std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState)
    const {
  EnumFenRepresentation kingRep = this->getColor() == EnumPiecesColors::WHITE
                                      ? EnumFenRepresentation::WHITE_KING
                                      : EnumFenRepresentation::BLACK_KING;
  std::shared_ptr<Square> myKingLocation = nullptr;

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (boardState[i][j]->getPiece() != nullptr &&
          boardState[i][j]->getPiece()->getFen() == kingRep) {
        myKingLocation = boardState[i][j];
        break;
      }
    }
  }

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      std::shared_ptr<Square> square = boardState[i][j];
      std::unique_ptr<Piece> const& piece = square->getPiece();

      if (!piece) continue;

      if (piece->getColor() == this->getColor()) continue;

      if (piece->getFen() == EnumFenRepresentation::WHITE_KING ||
          piece->getFen() == EnumFenRepresentation::BLACK_KING)
        continue;

      std::vector<std::string> possibleMoves = piece->possibleMoves(boardState);

      for (auto mv : possibleMoves) {
        if (mv == myKingLocation->getFile() + myKingLocation->getRank()) {
          return true;
        }
      }
    }
  }

  return false;
}

}  // namespace chess