#include <iostream>

#include "Square.hpp"
#include "Pawn.hpp"
#include "Piece.hpp"

#include "EnumSquareColors.hpp"
#include "EnumPiecesColors.hpp"
#include "EnumFenRepresentation.hpp"

using namespace chess;

int main(){

    Square *s { new Square{"a","2", EnumSquareColors::LIGHT}};
    
    Pawn p{s, EnumFenRepresentation::BLACK_BISHOP};
    std::vector<std::string> poss = p.possibleMoves();

    for(auto p : poss){
        std::cout << p << " ";
    }
    std::cout << std::endl;

    return 0;
}