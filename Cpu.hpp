#ifndef CPU_HPP
#define CPU_HPP

#include <boost/process.hpp>
#include "EnumPiecesColors.hpp"
#include <string>

namespace bp = boost::process;

namespace chess {

class Cpu {
 public:
  Cpu();
  virtual ~Cpu();

  std::string getMove(std::string fen);
  void setColor(const EnumPiecesColors color);

 private:
  bp::child stockfish;
  bp::opstream toStockfish;
  bp::ipstream fromStockfish;
  constexpr static const char* stockfishPath =
      "stockfish/stockfish-ubuntu-x86-64-avx2";
  EnumPiecesColors color;

  void killStockfish();
};

}  // namespace chess

#endif