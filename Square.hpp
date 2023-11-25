#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "EnumSquareColors.hpp"
class Piece; //Forward Declaration

namespace chess {

class Square{
    public:
        Square() = default;
        Square(const int file, const int rank, EnumSquareColors color);
        virtual ~Square() = default;

        int getFile() const;
        int getRank() const;

        bool isOccupied() const;
        void setOccupant(Piece *p);
        Piece* getOccupant();

    private:
        int file; // vertical line of chess
        int rank; // horizontal line of chess
        EnumSquareColors squareColor;
        Piece *piece;
};

}

#endif