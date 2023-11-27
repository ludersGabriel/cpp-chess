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

  std::cout << "Received uciok." << std::endl;

  // Set the skill level to 20, which is the maximum level
  command = "setoption name Skill Level value 20\n";
  this->toStockfish << command;
  this->toStockfish.flush();

  // Optionally, you can also disable any learning mechanisms of Stockfish
  // by setting the "UCI_LimitStrength" option to false
  command = "setoption name UCI_LimitStrength value false\n";
  this->toStockfish << command;
  this->toStockfish.flush();

  // Make sure the engine has processed the options
  command = "isready\n";
  this->toStockfish << command;
  this->toStockfish.flush();

  while (std::getline(this->fromStockfish, response) && response != "readyok")
    ;

  std::cout << "Stockfish difficulty set to max. Sotckfish is ready"
            << std::endl;
}

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

bool Cpu::lookForCheckmate(std::string fen) {
  if (!this->stockfish.running()) {
    std::cout << "Stockfish is not running, probably crashed" << std::endl;
    std::cout << "Something terrible happened, forcing exit" << std::endl;
    exit(1);
  }

  this->toStockfish << "position fen " + fen + "\n";
  this->toStockfish << "d"
                    << "\n";
  this->toStockfish.flush();

  std::string response;

  while (std::getline(this->fromStockfish, response) &&
         response.substr(0, 8) != "Checkers")
    ;

  // response = Checkers: f2
  std::string checker = response.substr(10, response.length() - 10);

  // std::cout << "Received checkers: " << checker << std::endl;

  bool hasCheckers = checker.length() > 0;
  this->toStockfish.flush();

  this->toStockfish << "go perft 1\n";
  this->toStockfish.flush();
  // Nodes searched: 0

  while (std::getline(this->fromStockfish, response) &&
         response.substr(0, 14) != "Nodes searched")
    ;

  int nodesSearched = std::stoi(response.substr(15, response.length() - 15));

  // std::cout << "Received nodes searched: " << nodesSearched << std::endl;

  bool hasCheckmate = nodesSearched == 0 && hasCheckers;

  return hasCheckmate;
}