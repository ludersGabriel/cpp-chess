#include <boost/process.hpp>
#include <iostream>
#include <string>
#include <array>

namespace bp = boost::process;

using ChessBoard = std::array<std::array<char, 8>, 8>;

std::string convertMatrixToFen(const ChessBoard& board, char turn) {
  std::string fen;
  for (const auto& row : board) {
    int emptyCount = 0;
    for (char piece : row) {
      if (piece == ' ') {
        ++emptyCount;
      } else {
        if (emptyCount != 0) {
          fen += std::to_string(emptyCount);
          emptyCount = 0;
        }
        fen += piece;
      }
    }
    if (emptyCount != 0) {
      fen += std::to_string(emptyCount);
    }
    fen += '/';
  }
  fen.pop_back();  // Remove the last '/'
  fen += ' ';
  fen += turn;  // Add whose turn it is

  // ! REDO, ITS FIXED RIGHT NOW
  fen += " KQkq - 0 1";  // Adding some defaults for the remaining FEN sections
  return fen;
}

int main() {
  ChessBoard board = {{{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                       {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                       {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}}};
  char turn = 'w';  // White to move

  // Convert the board to a FEN string
  std::string fen = convertMatrixToFen(board, turn);
  std::cout << "FEN: " << fen << std::endl;

  // Set up pipes for the child process's stdin and stdout
  bp::opstream in;   // sending to stockfish
  bp::ipstream out;  // receiving from stockfish
  std::string line;

  // Start the Stockfish process
  bp::child c("../stockfish/stockfish-ubuntu-x86-64-avx2",
              bp::std_in<in, bp::std_out> out);

  // Send "uci" command to Stockfish to initialize it
  in << "uci\n";
  in.flush();

  // Read the output from Stockfish
  while (std::getline(out, line) && line != "uciok") {
    std::cout << line << std::endl;
  }
  std::cout << "Received uciok, Stockfish is ready." << std::endl;

  // Set up the position and ask Stockfish to make a move within 1000
  // milliseconds (1 second)
  in << "position fen " << fen << "\n";
  in << "go movetime 1000\n";  // Stockfish will search for 1 second
  in.flush();

  // Read the output from Stockfish
  while (std::getline(out, line)) {
    if (line.find("bestmove") != std::string::npos) {
      // Extract the best move from the line
      std::string bestMove = line.substr(9, line.find(' ', 9) - 9);
      std::cout << "Best move: " << bestMove << std::endl;
      break;
    }
  }

  // Stop the Stockfish engine
  in << "quit\n";
  in.flush();
  c.wait();  // Wait for the child process to exit

  return 0;
}
