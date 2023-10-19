#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece
{
public:
    Pawn(const unsigned int color, const unsigned int file, const unsigned int rank, const bool firstMove);
    virtual ~Pawn();

    virtual std::set<Square> getAvailableMoves() const;

private:
    bool firstMove;
};

#endif