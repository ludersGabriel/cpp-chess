#include "Pawn.hpp"

#include <set> // std::set

Pawn::Pawn(const unsigned int color, const unsigned int file, const unsigned int rank, const bool firstMove)
    : Piece{color, file, rank}, firstMove{true} {}

Pawn::~Pawn()
{
}

std::set<Square> Pawn::getAvailableMoves() const
{
    std::set<Square> tempSet;
    Square tempSquare = getCurrentSquare();

    // peão vai para frente
    tempSquare.rank++;
    tempSet.insert(tempSquare);

    // se é o primeiro movimento, pode ir pra frente novamente
    if (firstMove)
    {
        tempSquare.rank++;
        tempSet.insert(tempSquare);
        tempSquare.rank--;
    }

    // captura à esquerda
    if (tempSquare.file > 97)
    {
        tempSquare.file--;
        tempSet.insert(tempSquare);
        tempSquare.file++;
    }

    // captura à esquerda
    if (tempSquare.file < 104)
    {
        tempSquare.file++;
        tempSet.insert(tempSquare);
    }

    // checkBoard()
}
