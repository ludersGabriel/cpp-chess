#include "Board.hpp"

namespace chess {

const std::array<std::array<std::string, 8>, 8> Board::initialBoard = {
    {{"r", "n", "b", "q", "k", "b", "n", "r"},
     {"p", "p", "p", "p", "p", "p", "p", "p"},
     {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
     {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
     {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
     {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
     {"P", "P", "P", "P", "P", "P", "P", "P"},
     {"R", "N", "B", "Q", "K", "B", "N", "R"}}};

const std::unordered_map<std::string, int> Board::fileToIndex = {
    {"a", 0}, {"b", 1}, {"c", 2}, {"d", 3},
    {"e", 4}, {"f", 5}, {"g", 6}, {"h", 7}};

const std::unordered_map<std::string, int> Board::rankToIndex = {
    {"1", 7}, {"2", 6}, {"3", 5}, {"4", 4},
    {"5", 3}, {"6", 2}, {"7", 1}, {"8", 0}};

Board::Board() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      std::string file = "";
      std::string rank = "";
      for (const auto& [key, value] : fileToIndex) {
        if (value == j) {
          file = key;
          break;
        }
      }
      for (const auto& [key, value] : rankToIndex) {
        if (value == i) {
          rank = key;
          break;
        }
      }
      EnumSquareColors color = EnumSquareColors::LIGHT;
      if ((i + j) % 2 != 0) {
        color = EnumSquareColors::DARK;
      }

      this->squares[i][j] = std::make_shared<Square>(file, rank, color);
    }
  }
}

}  // namespace chess