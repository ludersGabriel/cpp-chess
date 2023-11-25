#ifndef GAME_CPP
#define GAME_CPP

#include <memory>

#include "Cpu.hpp"
#include "EnumPiecesColors.hpp"

namespace chess {

class Game {
 public:
  Game();
  virtual ~Game() = default;

  void run();

 private:
  std::unique_ptr<Cpu> cpu;
  EnumPiecesColors playerColor;
  EnumPiecesColors cpuColor = EnumPiecesColors::BLACK;
  EnumPiecesColors turn;
};

}  // namespace chess

#endif