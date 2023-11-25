#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <memory>
#include <unordered_map>
#include <string>

#include "Square.hpp"
#include "EnumSquareColors.hpp"

namespace chess {

class Board {
 public:
  Board();
  virtual ~Board() = default;

  std::string getFen() const;

 private:
  std::array<std::array<std::shared_ptr<Square>, 8>, 8> squares;

  static const std::array<std::array<std::string, 8>, 8> initialBoard;
  static const std::unordered_map<std::string, int> fileToIndex;
  static const std::unordered_map<std::string, int> rankToIndex;
};

}  // namespace chess

#endif