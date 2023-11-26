#include "Square.hpp"
#include "EnumSquareColors.hpp"
#include "PieceFactory.hpp"
#include "Piece.hpp"

namespace chess {

Square::Square(const std::string file, const std::string rank,
               EnumSquareColors color)
    : file{file}, rank{rank}, squareColor{color} {}

void Square::initializePiece(const EnumFenRepresentation& fenRepresentation) {
  this->piece =
      PieceFactory::createPiece(shared_from_this(), fenRepresentation);
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

void Square::changePieces(Square& other) {
  std::swap(this->piece, other.piece);
}

void Square::removePiece() { this->piece = nullptr; }

}  // namespace chess