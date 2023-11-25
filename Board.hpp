#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <memory>

#include "Square.hpp"
#include "EnumSquareColors.hpp"

namespace chess {

class Board {
 public:
  Board();
  virtual ~Board() = default;

  std::array<std::array<std::string, 8>, 8> getCharBoard() const;
  std::string getFen() const;

 private:
  std::array<std::array<std::shared_ptr<Square>, 8>, 8> squares;
};

}  // namespace chess

#endif