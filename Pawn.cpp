#include "Pawn.hpp"

using namespace chess;

Pawn::Pawn(Square* square, const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Pawn::getValue() const { return Pawn::value; }