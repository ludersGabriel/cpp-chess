#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <array>

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
  fen += turn;           // Add whose turn it is
  fen += " KQkq - 0 1";  // Adding some defaults for the remaining FEN sections
  return fen;
}

// Function to execute commands and get response from Stockfish
std::string execCommand(int toStockfish[2], int fromStockfish[2],
                        const std::string& command) {
  write(toStockfish[1], command.c_str(),
        command.size());           // Send command to Stockfish
  write(toStockfish[1], "\n", 1);  // End of command

  // Read from Stockfish
  std::string output;
  char buffer[256];
  ssize_t nbytes;
  while ((nbytes = read(fromStockfish[0], buffer, sizeof(buffer) - 1)) > 0) {
    buffer[nbytes] = '\0';  // null-terminate the string
    output += buffer;

    // If the last line of the output is "readyok" or contains "bestmove", we
    // can stop reading
    if (output.find("readyok") != std::string::npos ||
        output.find("bestmove") != std::string::npos) {
      break;
    }
  }

  return output;
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

  int toStockfish[2], fromStockfish[2];
  pid_t pid;

  // Create the pipes
  if (pipe(toStockfish) < 0 || pipe(fromStockfish) < 0) {
    std::cerr << "Failed to create pipes." << std::endl;
    return 1;
  }

  // Fork the process
  pid = fork();
  if (pid < 0) {
    std::cerr << "Failed to fork." << std::endl;
    return 1;
  }

  if (pid == 0) {  // Child process
    // Redirect standard input to the read end of the pipe to Stockfish
    dup2(toStockfish[0], STDIN_FILENO);
    close(toStockfish[0]);
    close(toStockfish[1]);  // No longer need this end of the pipe

    // Redirect standard output to the write end of the pipe from Stockfish
    dup2(fromStockfish[1], STDOUT_FILENO);
    close(fromStockfish[0]);  // No longer need this end of the pipe
    close(fromStockfish[1]);

    // Execute Stockfish
    execlp("../stockfish/stockfish-ubuntu-x86-64-avx2",
           "stockfish-ubuntu-x86-64-avx2", (char*)NULL);

    // execlp only returns if there is an error
    std::cerr << "Failed to execute Stockfish." << std::endl;
    exit(1);
  } else {                    // Parent process
    close(toStockfish[0]);    // Close the read end of the pipe to Stockfish
    close(fromStockfish[1]);  // Close the write end of the pipe from Stockfish

    // Send "uci" command to Stockfish to initialize it
    execCommand(toStockfish, fromStockfish, "uci");

    // Main game loop - For demonstration, we'll just do one iteration
    std::string fen = convertMatrixToFen(board, turn);
    std::string stockfishCommand = "position fen " + fen;
    execCommand(toStockfish, fromStockfish, stockfishCommand);

    // Get the best move
    std::string bestMove = execCommand(toStockfish, fromStockfish, "go");
    std::cout << "Best move: " << bestMove << std::endl;

    // Tell Stockfish to quit and close the pipes
    execCommand(toStockfish, fromStockfish, "quit");
    close(toStockfish[1]);
    close(fromStockfish[0]);

    // Wait for the Stockfish process to exit
    waitpid(pid, NULL, 0);
  }

  return 0;
}
