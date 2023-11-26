#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "EnumFenRepresentation.hpp"
#include "Square.hpp"
#include "Piece.hpp"

#include <memory>

namespace chess {
class Bishop : public Piece {
 public:
  Bishop(std::shared_ptr<Square> square,
         const EnumFenRepresentation& fenRepresentation);
  virtual ~Bishop() = default;

  int getValue() const override;

  std::vector<std::string> possibleMoves() const override;

 private:
  constexpr static int value = 3;
};

}  // namespace chess

#endif