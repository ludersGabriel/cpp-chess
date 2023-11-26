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

void Cpu::killStockfish() {}

Cpu::~Cpu() {
  if (this->stockfish.running()) {
    std::cout << "Sending quit command to Stockfish..." << std::endl;
    this->toStockfish << "quit\n";
    this->toStockfish.flush();

    // Wait for a limited time for Stockfish to quit
    if (!this->stockfish.wait_for(std::chrono::seconds(2))) {
      // Stockfish didn't respond to quit within the time limit
      std::cerr << "Stockfish did not quit in time, terminating forcefully."
                << std::endl;
      this->stockfish.terminate();  // Forcefully terminate Stockfish
    } else {
      std::cout << "Stockfish has quit gracefully." << std::endl;
    }
  } else {
    std::cerr << "Stockfish is not running." << std::endl;
  }

  // Here you would also ensure that all the pipes are closed properly
  this->toStockfish.close();
  this->fromStockfish.close();

  // Any additional cleanup if necessary
}

void Cpu::setColor(const EnumPiecesColors color) { this->color = color; }

std::string Cpu::getMove(std::string fen) {
  if (!this->stockfish.running()) {
    std::cout << "Stockfish is not running, probably crashed" << std::endl;
    std::cout << "Something terrible happened, forcing exit" << std::endl;
    exit(1);
  }

  this->toStockfish << "position fen " + fen + "\n";
  this->toStockfish << "go movetime 500\n";
  this->toStockfish.flush();

  std::string response;

  while (std::getline(this->fromStockfish, response) &&
         response.substr(0, 8) != "bestmove")
    ;

  // std::cout << "Received bestmove: " << response << std::endl;

  if (!response.length()) {
    return "none";
  }

  return response.substr(9, 4);
}