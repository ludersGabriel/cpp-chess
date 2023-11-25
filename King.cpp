#include "King.hpp"

using namespace chess;

King::King(Square* square, const EnumFenRepresentation& fenRepresentation)
    : Piece(square, fenRepresentation) {}

int King::getValue() const { return King::value; }