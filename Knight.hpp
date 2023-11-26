#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "EnumFenRepresentation.hpp"
#include "Square.hpp"
#include "Piece.hpp"

#include <memory>

namespace chess {

class Knight : public Piece {
 public:
  Knight(std::shared_ptr<Square> square,
         const EnumFenRepresentation& fenRepresentation);
  virtual ~Knight() = default;

  int getValue() const override;

  std::vector<std::string> possibleMoves() const override;

 private:
  constexpr static int value = 3;
};

}  // namespace chess

#endif