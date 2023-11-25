#include "Square.hpp"
#include "EnumSquareColors.hpp"

namespace chess {

Square::Square(const std::string file, const std::string rank, EnumSquareColors color)
    : file{file}, rank{rank}, squareColor{color} {}

std::string Square::getFile() const{
    return this->file;
}

std::string Square::getRank() const{
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