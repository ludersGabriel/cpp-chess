#include "Board.hpp"

#include "Piece.hpp"

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

const std::unordered_map<std::string, int> Board::fileToIndex = {
    {"a", 0}, {"b", 1}, {"c", 2}, {"d", 3},
    {"e", 4}, {"f", 5}, {"g", 6}, {"h", 7}};

const std::unordered_map<std::string, int> Board::rankToIndex = {
    {"1", 7}, {"2", 6}, {"3", 5}, {"4", 4},
    {"5", 3}, {"6", 2}, {"7", 1}, {"8", 0}};

const std::unordered_map<int, std::string> Board::indexToFile = {
    {0, "a"}, {1, "b"}, {2, "c"}, {3, "d"},
    {4, "e"}, {5, "f"}, {6, "g"}, {7, "h"}};

const std::unordered_map<int, std::string> Board::indexToRank = {
    {7, "1"}, {6, "2"}, {5, "3"}, {4, "4"},
    {3, "5"}, {2, "6"}, {1, "7"}, {0, "8"}};

const std::string Board::bgLight = "\033[101m";
const std::string Board::bgDark = "\033[103m";
const std::string Board::bgReset = "\033[0m";

Board::Board(const EnumPiecesColors& turn) : turn{turn} {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      EnumSquareColors color = EnumSquareColors::LIGHT;
      if ((i + j) % 2 != 0) {
        color = EnumSquareColors::DARK;
      }

      std::string file = Board::indexToFile.at(j);
      std::string rank = Board::indexToRank.at(i);

      int rankIndex = Board::rankToIndex.at(rank);
      int fileIndex = Board::fileToIndex.at(file);

      this->squares[rankIndex][fileIndex] =
          std::make_shared<Square>(file, rank, color);
      this->squares[rankIndex][fileIndex]->initializePiece(
          Board::initialBoard[i][j]);
    }
  }
}

std::array<std::array<std::string, 8>, 8> Board::getCharBoard() const {
  std::array<std::array<std::string, 8>, 8> charBoard;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; j++) {
      charBoard[i][j] = static_cast<char>(this->squares[i][j]->getFen());
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
  int rank = Board::rankToIndex.at(uciPosition.substr(1, 1));
  int file = Board::fileToIndex.at(uciPosition.substr(0, 1));

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

  // ! Need to treat special move as well, like castles

  if (toSquare->getFen() != EnumFenRepresentation::EMPTY) {
    toSquare->removePiece();
  }

  fromSquare->changePieces(*toSquare);
  toSquare->getPiece()->setLocation(toSquare);
}

EnumPiecesColors Board::getTurn() const { return this->turn; }

void Board::setTurn(const EnumPiecesColors& turn) { this->turn = turn; }

std::string Board::getBgLight() const { return Board::bgLight; }

std::string Board::getBgDark() const { return Board::bgDark; }

std::string Board::getBgReset() const { return Board::bgReset; }

}  // namespace chess