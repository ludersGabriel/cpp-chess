#include "Square.hpp"
#include "EnumSquareColors.hpp"
#include "PieceFactory.hpp"

namespace chess {

const std::unordered_map<std::string, int> Square::fileToIndex = {
    {"a", 0}, {"b", 1}, {"c", 2}, {"d", 3},
    {"e", 4}, {"f", 5}, {"g", 6}, {"h", 7}};

const std::unordered_map<std::string, int> Square::rankToIndex = {
    {"1", 7}, {"2", 6}, {"3", 5}, {"4", 4},
    {"5", 3}, {"6", 2}, {"7", 1}, {"8", 0}};

const std::unordered_map<int, std::string> Square::indexToFile = {
    {0, "a"}, {1, "b"}, {2, "c"}, {3, "d"},
    {4, "e"}, {5, "f"}, {6, "g"}, {7, "h"}};

const std::unordered_map<int, std::string> Square::indexToRank = {
    {7, "1"}, {6, "2"}, {5, "3"}, {4, "4"},
    {3, "5"}, {2, "6"}, {1, "7"}, {0, "8"}};

Square::Square(const std::string file, const std::string rank,
               EnumSquareColors color)
    : file{file}, rank{rank}, squareColor{color} {}

void Square::initializePiece(const EnumFenRepresentation& fenRepresentation) {
  this->piece =
      PieceFactory::createPiece(shared_from_this(), fenRepresentation);
}

std::vector<std::string> Square::possibleMoves(
    std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState)
    const {
  if (this->piece) {
    return this->piece->possibleMoves(boardState);
  } else {
    return {};
  }
}

std::unique_ptr<Piece> const& Square::getPiece() const { return this->piece; }

std::string Square::getFile() const { return this->file; }

std::string Square::getRank() const { return this->rank; }

const EnumFenRepresentation Square::getFen() const {
  if (this->piece == nullptr) {
    return EnumFenRepresentation::EMPTY;
  } else {
    return this->piece->getFen();
  }
}

void Square::movePieceTo(Square& destination) {
  if (this->piece) {
    if (destination.piece) {
      destination.piece = nullptr;
    }

    this->piece->setLocation(destination.shared_from_this());
    destination.piece = std::move(this->piece);
  }
}

void Square::removePiece() { this->piece = nullptr; }

}  // namespace chess