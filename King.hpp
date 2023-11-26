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

  std::vector<std::string> possibleMoves(
      std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState)
      const override;
  bool notMovedYet() const;

 private:
  bool isIncheck(std::string uci, std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState) const;
  constexpr static int value = 1000;
  bool isFirstMove;
};

}  // namespace chess

#endif