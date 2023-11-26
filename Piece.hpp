#ifndef PIECE_HPP
#define PIECE_HPP

#include <vector>
#include <string>
#include <memory>
#include <array>

#include "EnumPiecesColors.hpp"
#include "EnumFenRepresentation.hpp"

namespace chess {
class Square;
class Piece {
 public:
  Piece() = default;
  Piece(std::shared_ptr<Square> square, const EnumFenRepresentation& rep);
  virtual ~Piece() = default;

  EnumPiecesColors getColor() const;
  std::shared_ptr<Square> getLocation() const;
  EnumFenRepresentation getFen() const;

  void setLocation(std::shared_ptr<Square> square);

  virtual int getValue() const = 0;
  virtual std::vector<std::string> possibleMoves(
      std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState)
      const = 0;

  bool validateUciLimits(std::string uci) const;

 private:
  EnumPiecesColors pieceColor;
  std::weak_ptr<Square> location;

  EnumFenRepresentation fenRep;
};

}  // namespace chess

#endif