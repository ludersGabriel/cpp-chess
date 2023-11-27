#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <string>
#include <memory>
#include <vector>
#include <array>
#include <unordered_map>

#include "EnumSquareColors.hpp"
#include "EnumFenRepresentation.hpp"
#include "Piece.hpp"

namespace chess {

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

  void movePieceTo(Square& destination);
  void undoMovePieceTo(Square& destination);

  void initializePiece(const EnumFenRepresentation& fenRepresentation);

  std::vector<std::string> possibleMoves(
      std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState)
      const;

  bool validateIfMyKinCheck(std::string uci,
                            std::array<std::array<std::shared_ptr<Square>, 8>,
                                       8> const& boardState) const;

  void removePiece();

  void resetOldFen();

  static const std::unordered_map<std::string, int> fileToIndex;
  static const std::unordered_map<std::string, int> rankToIndex;
  static const std::unordered_map<int, std::string> indexToFile;
  static const std::unordered_map<int, std::string> indexToRank;

 private:
  std::string file;  // vertical line of chess   | column
  std::string rank;  // horizontal line of chess | line

  EnumSquareColors squareColor;
  std::unique_ptr<Piece> piece;
  EnumFenRepresentation oldFen;
};

}  // namespace chess

#endif