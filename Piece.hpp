#ifndef PIECE_HPP
#define PIECE_HPP

#include <vector>
#include <string>
#include <memory>

#include "Square.hpp"
#include "EnumPiecesColors.hpp"
#include "EnumFenRepresentation.hpp"

namespace chess {

class Piece {
 public:
  Piece() = default;
  Piece(std::shared_ptr<Square> square, const EnumFenRepresentation &rep);
  virtual ~Piece() = default;

  EnumPiecesColors getColor() const;
  std::shared_ptr<Square> getLocation() const;
  EnumFenRepresentation getFen() const;

  void setLocation(std::shared_ptr<Square> square);
  bool validateUciLimits(std::string uci) const;

  virtual int getValue() const = 0;
  virtual std::vector<std::string> possibleMoves() const = 0;

  static std::string getWhiteColor();
  static std::string getBlackColor();

 private:
  EnumPiecesColors pieceColor;
  std::weak_ptr<Square> location;

  EnumFenRepresentation fenRep;

  static const std::string whiteColor;
  static const std::string blackColor;
};

}  // namespace chess

#endif