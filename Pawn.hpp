#ifndef PAWN_HPP
#define PAWN_HPP

#include "EnumFenRepresentation.hpp"
#include "Square.hpp"
#include "Piece.hpp"

#include <memory>

namespace chess {

class Pawn : public Piece {
 public:
  Pawn(std::shared_ptr<Square> square,
       const EnumFenRepresentation& fenRepresentation);
  virtual ~Pawn() = default;

  int getValue() const override;

  bool alreadyMove() const;

  std::vector<std::string> possibleMoves() const override;

 private:
  constexpr static int value = 1;
  bool isFirstMove;
};

}  // namespace chess

#endif