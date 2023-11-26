#include "King.hpp"
#include <iostream>

using namespace chess;

King::King(std::shared_ptr<Square> square,
           const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation), isFirstMove{true} {}

int King::getValue() const { return King::value; }

bool King::notMovedYet() const { return isFirstMove; }

bool King::isIncheck(std::string uci, std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState) const {

  std::shared_ptr<Square> square;

  int i, j;

  for(i=0;i<8;++i){
    for(j=0;j<8;++j){
      // for each square of the board
      square = boardState[i][j];
      std::vector<std::string> possibleMoves;

      // não chama para o Rei inimigo
      char fenrepr = static_cast<char>(square->getFen());
      if(!(fenrepr != 'k' && fenrepr != 'K')){
        continue;
      }

      possibleMoves = square->possibleMoves(boardState);

      std::unique_ptr<Piece>const& piece = square->getPiece();
      // if a piece of the opossite color exists
      if( piece != nullptr && piece->getColor() != this->getColor()){

        std::cout << "Piece: " << static_cast<char>(square->getFen()) << std::endl << "Movements: ";

        // and there is a possible move equal to the move you want
        for( auto mv : possibleMoves ){
          std::cout << mv << " ";
          if(uci == mv)
            return true;
        }

        std::cout << "TERMINEI" << std::endl;

      }
    }
  }

  return false;
}


std::vector<std::string> King::possibleMoves(
    std::array<std::array<std::shared_ptr<Square>, 8>, 8> const& boardState)
    const {
  std::shared_ptr<Square> location = getLocation();
  std::vector<std::string> possibleMoves;

  if (location == nullptr) {
    return possibleMoves;
  }

  // constroi uci
  std::string uci = location->getFile() + location->getRank();

  // castle
  if (notMovedYet()) {
    uci[0] -= 2;
    possibleMoves.push_back(uci);
    uci[0] += 4;
    possibleMoves.push_back(uci);
    uci[0] -= 2;
  }

  // cima
  uci[1]++;
  possibleMoves.push_back(uci);

  // cima esquerda
  uci[0]--;
  possibleMoves.push_back(uci);

  // esquerda
  uci[1]--;
  possibleMoves.push_back(uci);

  // esquerda/baixo
  uci[1]--;
  possibleMoves.push_back(uci);

  // baixo
  uci[0]++;
  possibleMoves.push_back(uci);

  // baixo/direita
  uci[0]++;
  possibleMoves.push_back(uci);

  // direita
  uci[1]++;
  possibleMoves.push_back(uci);

  // direita/cima
  uci[1]++;
  possibleMoves.push_back(uci);

  // captura à esquerda
  std::vector<std::string>::iterator movit{possibleMoves.begin()};
  for (; movit != possibleMoves.end();) {
    if (!validateUciLimits(*movit, boardState)) {
      movit = possibleMoves.erase(movit);
    }
    else if(isIncheck(*movit, boardState)){

      movit = possibleMoves.erase(movit);
    }
     else {
      ++movit;
    }
  }

  return possibleMoves;
}