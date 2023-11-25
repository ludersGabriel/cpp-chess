#include "Piece.hpp"

namespace chess{

Piece::Piece(Square *square, const int value, const EnumPiecesColors color)
    : location{square}, value{value}, pieceColor{color}  {}

EnumPiecesColors Piece::getColor() const{
    return this->pieceColor;
}

int Piece::getValue() const{
    return this->value;
}

Square* Piece::getLocation() const{
    return this->location;
}

void Piece::setLocation(Square *square){
    this->location = square;
}
    
}