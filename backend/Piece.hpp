#ifndef PIECE_HPP
#define PIECE_HPP

// Classe abstrata

#include <set> // std::set

struct Square
{
    unsigned int file; // vertical line of chess
    unsigned int rank; // horizontal line of chess
};

class Piece
{

public:
    Piece(const unsigned int color, const unsigned int file, const unsigned int rank);
    virtual ~Piece();

    unsigned int getColor() const;
    void setColor(const unsigned int color);

    Square getCurrentSquare() const;
    void setCurrentSquare(const unsigned int file, const unsigned int rank);

    // Cada classe derivada deve implementar sua função
    virtual std::set<Square> getAvailableMoves() const = 0;

private:
    Square currentSquare;
    unsigned int color;
    std::set<Square> availableMoves;
};

#endif