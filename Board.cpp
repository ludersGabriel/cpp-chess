#include "Board.hpp"

#include <vector>
#include <algorithm>
#include <iostream>

namespace chess {

const std::array<std::array<EnumFenRepresentation, 8>, 8> Board::initialBoard =
    {{{{EnumFenRepresentation::BLACK_ROOK, EnumFenRepresentation::BLACK_KNIGHT,
        EnumFenRepresentation::BLACK_BISHOP, EnumFenRepresentation::BLACK_QUEEN,
        EnumFenRepresentation::BLACK_KING, EnumFenRepresentation::BLACK_BISHOP,
        EnumFenRepresentation::BLACK_KNIGHT,
        EnumFenRepresentation::BLACK_ROOK}},
      {{EnumFenRepresentation::BLACK_PAWN, EnumFenRepresentation::BLACK_PAWN,
        EnumFenRepresentation::BLACK_PAWN, EnumFenRepresentation::BLACK_PAWN,
        EnumFenRepresentation::BLACK_PAWN, EnumFenRepresentation::BLACK_PAWN,
        EnumFenRepresentation::BLACK_PAWN, EnumFenRepresentation::BLACK_PAWN}},
      {{EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY,
        EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY,
        EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY,
        EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY}},
      {{EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY,
        EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY,
        EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY,
        EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY}},
      {{EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY,
        EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY,
        EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY,
        EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY}},
      {{EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY,
        EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY,
        EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY,
        EnumFenRepresentation::EMPTY, EnumFenRepresentation::EMPTY}},
      {{EnumFenRepresentation::WHITE_PAWN, EnumFenRepresentation::WHITE_PAWN,
        EnumFenRepresentation::WHITE_PAWN, EnumFenRepresentation::WHITE_PAWN,
        EnumFenRepresentation::WHITE_PAWN, EnumFenRepresentation::WHITE_PAWN,
        EnumFenRepresentation::WHITE_PAWN, EnumFenRepresentation::WHITE_PAWN}},
      {{EnumFenRepresentation::WHITE_ROOK, EnumFenRepresentation::WHITE_KNIGHT,
        EnumFenRepresentation::WHITE_BISHOP, EnumFenRepresentation::WHITE_QUEEN,
        EnumFenRepresentation::WHITE_KING, EnumFenRepresentation::WHITE_BISHOP,
        EnumFenRepresentation::WHITE_KNIGHT,
        EnumFenRepresentation::WHITE_ROOK}}}};

Board::Board(const EnumPiecesColors& turn) : turn{turn} {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      EnumSquareColors color = EnumSquareColors::LIGHT;
      if ((i + j) % 2 != 0) {
        color = EnumSquareColors::DARK;
      }

      std::string file = Square::indexToFile.at(j);
      std::string rank = Square::indexToRank.at(i);

      int rankIndex = Square::rankToIndex.at(rank);
      int fileIndex = Square::fileToIndex.at(file);

      this->squares[rankIndex][fileIndex] =
          std::make_shared<Square>(file, rank, color);
      this->squares[rankIndex][fileIndex]->initializePiece(
          Board::initialBoard[i][j]);
    }
  }
}

std::array<std::array<EnumFenRepresentation, 8>, 8> Board::getFenBoard() const {
  std::array<std::array<EnumFenRepresentation, 8>, 8> charBoard;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; j++) {
      charBoard[i][j] = this->squares[i][j]->getFen();
    }
  }
  return charBoard;
}

std::string Board::getFen() const {
  std::string fen = "";
  int emptyCounter = 0;

  for (int i = 0; i < 8; ++i) {
    emptyCounter = 0;
    for (int j = 0; j < 8; ++j) {
      if (this->squares[i][j]->getFen() == EnumFenRepresentation::EMPTY) {
        ++emptyCounter;
      } else {
        if (emptyCounter != 0) {
          fen += std::to_string(emptyCounter);
          emptyCounter = 0;
        }
        fen += static_cast<char>(this->squares[i][j]->getFen());
      }
    }
    if (emptyCounter != 0) {
      fen += std::to_string(emptyCounter);
    }
    if (i != 7) {
      fen += "/";
    }
  }

  fen += " ";

  if (this->turn == EnumPiecesColors::WHITE) {
    fen += "w";
  } else {
    fen += "b";
  }

  // ! TOOD: this needs to be validaded and not fixed
  // fen += " KQkq - 0 1";

  return fen;
}

std::shared_ptr<Square>& Board::operator[](const std::string& uciPosition) {
  int rank = Square::rankToIndex.at(uciPosition.substr(1, 1));
  int file = Square::fileToIndex.at(uciPosition.substr(0, 1));

  return this->squares[rank][file];
}

void Board::cpuUpdate(const std::string& uciMove) {
  if (uciMove.length() != 4) {
    return;
  }

  std::string from = uciMove.substr(0, 2);
  std::string to = uciMove.substr(2, 2);

  std::shared_ptr<Square> fromSquare = (*this)[from];
  std::shared_ptr<Square> toSquare = (*this)[to];

  fromSquare->movePieceTo(*toSquare);
}

bool Board::playerUpdate(const std::string& uciMove) {
  if (uciMove.length() != 4) {
    return false;
  }

  std::string from = uciMove.substr(0, 2);
  std::string to = uciMove.substr(2, 2);

  std::shared_ptr<Square> fromSquare = (*this)[from];
  std::shared_ptr<Square> toSquare = (*this)[to];

  std::vector<std::string> possibleMoves =
      fromSquare->possibleMoves(this->getSquares());

  for (auto& move : possibleMoves) std::cout << move << " ";
  std::cout << std::endl;
  std::cout << "to: " << to << std::endl;
  std::cout << "from: " << from << std::endl;

  if (std::find(possibleMoves.begin(), possibleMoves.end(), to) ==
      possibleMoves.end()) {
    return false;
  }

  fromSquare->movePieceTo(*toSquare);

  if (toSquare->validateIfMyKinCheck(to, this->getSquares())) {
    fromSquare->undoMovePieceTo(*toSquare);
    return false;
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      this->squares[i][j]->resetOldFen();
    }
  }

  return true;
}

std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& Board::getSquares()
    const {
  return this->squares;
}

void Board::undoMove(const std::string& uciMove) {
  if (uciMove.length() != 4) {
    return;
  }

  std::string from = uciMove.substr(0, 2);
  std::string to = uciMove.substr(2, 2);

  std::shared_ptr<Square> fromSquare = (*this)[from];
  std::shared_ptr<Square> toSquare = (*this)[to];

  toSquare->undoMovePieceTo(*fromSquare);
}

EnumPiecesColors Board::getTurn() const { return this->turn; }

void Board::setTurn(const EnumPiecesColors& turn) { this->turn = turn; }

}  // namespace chess