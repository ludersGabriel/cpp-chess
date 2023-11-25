#ifndef PIECE_FACTORY_HPP
#define PIECE_FACTORY_HPP

#include <memory>

#include "EnumPiecesColors.hpp"
#include "EnumFenRepresentation.hpp"

#include "Bishop.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"

namespace chess {

class PieceFactory {
 public:
  PieceFactory() = delete;

  static std::unique_ptr<Piece> createPiece(
      Square* square, const EnumFenRepresentation& fenRepresentation);
};

}  // namespace chess

#endif