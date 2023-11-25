#include "Bishop.hpp"

using namespace chess;

Bishop::Bishop(Square* square, const EnumFenRepresentation& fenRepresentation)
    : Piece(square, this->value, fenRepresentation) {}