#include "Cpu.hpp"
#include "iostream"

using namespace chess;

Cpu::Cpu() {
  try {
    this->stockfish = bp::child(
        this->stockfishPath,
        bp::std_in<this->toStockfish, bp::std_out> this->fromStockfish);
  } catch (const bp::process_error& e) {
    std::cout << "Error initializing Stockfish: " << e.what() << std::endl;
    std::cout << "Make sure you are running this program from the root "
                 "directory of the project."
              << std::endl;
    exit(1);
  }

  std::string command = "uci\n";
  this->toStockfish << command;
  this->toStockfish.flush();

  std::string response;

  while (std::getline(this->fromStockfish, response) && response != "uciok")
    ;

  std::cout << "Received uciok, Stockfish is ready." << std::endl;
}

Cpu::~Cpu() {
  std::string command = "quit\n";

  this->toStockfish << command;
  this->toStockfish.flush();

  this->stockfish.wait();
}

void Cpu::setColor(const EnumPiecesColors color) { this->color = color; }

std::string Cpu::getMove(std::string fen) {
  this->toStockfish << "position fen " + fen + "\n";
  this->toStockfish << "go movetime 1000\n";
  this->toStockfish.flush();

  std::string response;

  while (std::getline(this->fromStockfish, response) &&
         response.substr(0, 8) != "bestmove")
    ;

  std::cout << "Received bestmove: " << response << std::endl;

  return response.substr(9, 4);
}