#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "EnumSquareColors.hpp"

#include <string>
#include <memory>
#include "EnumFenRepresentation.hpp"

namespace chess {

class Piece;  // Forward Declaration

class Square : public std::enable_shared_from_this<Square> {
 public:
  Square() = default;
  Square(const std::string file, const std::string rank,
         EnumSquareColors color);
  virtual ~Square() = default;

  std::string getFile() const;
  std::string getRank() const;
  const EnumFenRepresentation getFen() const;

  std::unique_ptr<Piece> const& getPiece() const;

  void changePieces(Square& other);
  void initializePiece(const EnumFenRepresentation& fenRepresentation);

  void removePiece();

 private:
  std::string file;  // vertical line of chess   | column
  std::string rank;  // horizontal line of chess | line

  EnumSquareColors squareColor;
  std::unique_ptr<Piece> piece;
};

}  // namespace chess

#endif