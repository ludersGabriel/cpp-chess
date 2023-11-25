#include "Knight.hpp"

using namespace chess;

Knight::Knight(Square* square, const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Knight::getValue() const { return Knight::value; }