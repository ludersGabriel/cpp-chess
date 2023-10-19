#include "Piece.hpp"

Piece::Piece(const unsigned int color, const unsigned int file, const unsigned int rank)
{
    setColor(color);
    setCurrentSquare(file, rank);
}

Piece::~Piece() {}

unsigned int Piece::getColor() const
{
    return this->color;
}

void Piece::setColor(const unsigned int color)
{
    if (color == 0 or color == 1)
    {
        this->color = color;
    }
    else
    {
        this->color = 0;
    }
}

Square Piece::getCurrentSquare() const
{
    return this->currentSquare;
}

void Piece::setCurrentSquare(const unsigned int file, const unsigned int rank)
{
    Square temp;
    temp.file = file;
    temp.rank = rank;

    std::set<Square>::iterator it{this->availableMoves.begin()};
    it = this->availableMoves.find(temp);

    if (availableMoves.find(temp) != availableMoves.end())
    {
        this->currentSquare.file = file;
        this->currentSquare.rank = rank;
    }
}