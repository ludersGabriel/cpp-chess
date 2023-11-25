#include "Queen.hpp"

using namespace chess;

Queen::Queen(Square* square, const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int Queen::getValue() const { return Queen::value; }