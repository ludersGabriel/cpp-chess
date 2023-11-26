#include "Pawn.hpp"
#include "iostream"

using namespace chess;

Pawn::Pawn(std::shared_ptr<Square> square,
           const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation), isFirstMove{true} {}

int Pawn::getValue() const { return Pawn::value; }

int Pawn::getValue() const { return Pawn::value; }

bool Pawn::alreadyMove() const{
  return isFirstMove;
}

std::vector<std::string> Pawn::possibleMoves() const {
  std::shared_ptr<Square> location = getLocation();
  std::vector<std::string> possibleMoves;

  if (location == nullptr) {
    return possibleMoves;
  }

  // constroi uci
  std::string uci = location->getFile() + location->getRank();

  // checa orientação baseado na cor da peça
  int mod;
  if(this->getColor() == EnumPiecesColors::WHITE){
    mod = 1;
  }
  else{
    mod = -1;
  }

  // peão move uma vez para frente
  uci[1]+=mod;
  possibleMoves.push_back(uci);

  // se é o primeiro movimento, pode se mover duas vezes
  if(alreadyMove()){
    uci[1]+=mod;
    possibleMoves.push_back(uci);
    uci[1]-=mod;
  }

  //captura à esquerda
  uci[0]--;
  possibleMoves.push_back(uci);

  //captura à esquerda
  uci[0]+=2;
  possibleMoves.push_back(uci);

  //captura à esquerda
  std::vector<std::string>::iterator movit{possibleMoves.begin()};
  for (; movit != possibleMoves.end();) {
    if (!validateUciLimits(*movit)) {
      movit = possibleMoves.erase(movit);
      } else {
        ++movit;
      }
  }

  return possibleMoves;
}