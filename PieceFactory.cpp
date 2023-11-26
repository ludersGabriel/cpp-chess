// PieceFactory.cpp
#include "PieceFactory.hpp"

namespace chess {

std::unique_ptr<Piece> PieceFactory::createPiece(
    std::shared_ptr<Square> square,
    const EnumFenRepresentation& fenRepresentation) {
  switch (fenRepresentation) {
    case EnumFenRepresentation::WHITE_BISHOP:
    case EnumFenRepresentation::BLACK_BISHOP:
      return std::make_unique<Bishop>(square, fenRepresentation);
    case EnumFenRepresentation::WHITE_KING:
    case EnumFenRepresentation::BLACK_KING:
      return std::make_unique<King>(square, fenRepresentation);
    case EnumFenRepresentation::WHITE_KNIGHT:
    case EnumFenRepresentation::BLACK_KNIGHT:
      return std::make_unique<Knight>(square, fenRepresentation);
    case EnumFenRepresentation::WHITE_PAWN:
    case EnumFenRepresentation::BLACK_PAWN:
      return std::make_unique<Pawn>(square, fenRepresentation);
    case EnumFenRepresentation::WHITE_QUEEN:
    case EnumFenRepresentation::BLACK_QUEEN:
      return std::make_unique<Queen>(square, fenRepresentation);
    case EnumFenRepresentation::WHITE_ROOK:
    case EnumFenRepresentation::BLACK_ROOK:
      return std::make_unique<Rook>(square, fenRepresentation);

    default:
      return nullptr;
  }
}

}  // namespace chess
