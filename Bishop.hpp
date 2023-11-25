#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "EnumFenRepresentation.hpp"
#include "Square.hpp"
#include "Piece.hpp"

namespace chess {

class Bishop : public Piece {
 public:
  Bishop(Square* square, const EnumFenRepresentation& fenRepresentation);
  virtual ~Bishop() = default;

 private:
  constexpr static int value = 3;
};

}  // namespace chess

#endif