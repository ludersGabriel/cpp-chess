#ifndef PAWN_HPP
#define PAWN_HPP

#include "EnumFenRepresentation.hpp"
#include "Square.hpp"
#include "Piece.hpp"

namespace chess {

class Pawn : public Piece {
 public:
  Pawn(Square* square, const EnumFenRepresentation& fenRepresentation);
  virtual ~Pawn() = default;

  int getValue() const override;

  std::vector<std::string> possibleMoves() const override;

 private:
  constexpr static int value = 1;
};

}  // namespace chess

#endif