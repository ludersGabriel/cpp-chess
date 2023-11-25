#ifndef ROOK_HPP
#define ROOK_HPP

#include "EnumFenRepresentation.hpp"
#include "Square.hpp"
#include "Piece.hpp"

namespace chess {

class Rook : public Piece {
 public:
  Rook(Square* square, const EnumFenRepresentation& fenRepresentation);
  virtual ~Rook() = default;

  int getValue() const override;

 private:
  constexpr static int value = 5;
};

}  // namespace chess

#endif