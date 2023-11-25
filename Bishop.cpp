#include "Bishop.hpp"

using namespace chess;

Bishop::Bishop(Square* square, const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Bishop::getValue() const { return Bishop::value; }