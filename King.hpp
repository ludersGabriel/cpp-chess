#ifndef KING_HPP
#define KING_HPP

#include "EnumFenRepresentation.hpp"
#include "Square.hpp"
#include "Piece.hpp"

namespace chess {

class King : public Piece {
 public:
  King(Square* square, const EnumFenRepresentation& fenRepresentation);
  virtual ~King() = default;

  int getValue() const override;

 private:
  constexpr static int value = 1000;
};

}  // namespace chess

#endif