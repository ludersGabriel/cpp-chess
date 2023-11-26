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

  std::vector<std::string> possibleMoves(
      std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState)
      const override;

 private:
  constexpr static int value = 9;
  bool checkMove(int file, int rank, std::string uci,
                 std::array<std::array<std::shared_ptr<Square>, 8>, 8> const&
                     boardState) const;
};

}  // namespace chess

#endif