#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "EnumFenRepresentation.hpp"
#include "Square.hpp"
#include "Piece.hpp"

#include <memory>

namespace chess {

class Queen : public Piece {
 public:
  Queen(std::shared_ptr<Square> square,
        const EnumFenRepresentation& fenRepresentation);
  virtual ~Queen() = default;

  int getValue() const override;

  std::vector<std::string> possibleMoves() const override;

 private:
  constexpr static int value = 9;
};

}  // namespace chess

#endif