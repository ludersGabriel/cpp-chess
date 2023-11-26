#ifndef KING_HPP
#define KING_HPP

#include "EnumFenRepresentation.hpp"
#include "Square.hpp"
#include "Piece.hpp"

#include <memory>

namespace chess {

class King : public Piece {
 public:
  King(std::shared_ptr<Square> square,
       const EnumFenRepresentation& fenRepresentation);
  virtual ~King() = default;

  int getValue() const override;

  std::vector<std::string> possibleMoves() const override;
  bool alreadyMove() const;

 private:
  constexpr static int value = 1000;
};

}  // namespace chess

#endif