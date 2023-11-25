// PieceFactory.cpp
#include "PieceFactory.hpp"

namespace chess {

std::unique_ptr<Piece> PieceFactory::createPiece(
    Square* square, const EnumFenRepresentation& fenRepresentation) {
  switch (fenRepresentation) {
    case EnumFenRepresentation::WHITE_BISHOP:
    case EnumFenRepresentation::BLACK_BISHOP:
      return std::make_unique<Bishop>(square, fenRepresentation);
    // ... Add cases for other piece types
    default:
      // Handle unexpected fenRepresentation values
      return nullptr;
  }
}

}  // namespace chess
