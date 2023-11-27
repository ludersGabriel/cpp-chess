#include "iostream"

#include "Game.hpp"
#include "memory"

int main() {
  std::unique_ptr<chess::Game> game = std::make_unique<chess::Game>();

  game->run();

  return 0;
}