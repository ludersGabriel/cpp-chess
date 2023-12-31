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

  std::vector<std::string> possibleMoves(
      std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState)
      const override;

 private:
  constexpr static int value = 1;
};

}  // namespace chess

#endif