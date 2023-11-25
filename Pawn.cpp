#include "Pawn.hpp"

using namespace chess;

Pawn::Pawn(Square* square, const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Pawn::getValue() const { return Pawn::value; }

std::vector<std::string> const & Pawn::possibleMoves() const{

    std::string baseFile = (getLocation())->getFile();
    std::string baseRank = (getLocation())->getFile();

}
