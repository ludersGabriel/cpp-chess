#include "Square.hpp"
#include "EnumSquareColors.hpp"

namespace chess {

Square::Square(const int file, const int rank, EnumSquareColors color)
    : file{file}, rank{rank}, squareColor{color} {}

int Square::getFile() const{
    return this->file;
}

int Square::getRank() const{
    return this->rank;
}

bool Square::isOccupied() const{
    return (this->piece != nullptr);
}

void Square::setOccupant(Piece *p){
    this->piece = p;
}

Piece* Square::getOccupant() {
    return this->piece;
}

}