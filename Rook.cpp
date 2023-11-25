#include "Rook.hpp"

using namespace chess;

Rook::Rook(Square* square, const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Rook::getValue() const { return Rook::value; }