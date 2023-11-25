#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "EnumFenRepresentation.hpp"
#include "Square.hpp"
#include "Piece.hpp"

namespace chess {

class Knight : public Piece {
 public:
  Knight(Square* square, const EnumFenRepresentation& fenRepresentation);
  virtual ~Knight() = default;

  int getValue() const override;

 private:
  constexpr static int value = 3;
};

}  // namespace chess

#endif