#include <iostream>

#include "Square.hpp"
#include "Pawn.hpp"
#include "Piece.hpp"
#include "Knight.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"

#include "EnumSquareColors.hpp"
#include "EnumPiecesColors.hpp"
#include "EnumFenRepresentation.hpp"
#include <memory>

using namespace chess;

int main(){

    std::shared_ptr<Square> sa1{ new Square{"d","5", EnumSquareColors::LIGHT}};
    
    Rook rook{sa1, EnumFenRepresentation::BLACK_KING};
    std::vector<std::string> poss = rook.possibleMoves();
    std::cout << "Rook: ";
    for(auto pm : poss){
        std::cout << pm << " ";
    }
    std::cout << std::endl;

    Bishop bishop{sa1, EnumFenRepresentation::BLACK_KING};
    std::vector<std::string> poss2 = bishop.possibleMoves();
    std::cout << "Bishop: ";
    for(auto pm : poss2){
        std::cout << pm << " ";
    }
    std::cout << std::endl;

    Queen queen{sa1, EnumFenRepresentation::BLACK_KING};
    std::vector<std::string> poss3 = queen.possibleMoves();
    std::cout << "Queen: ";
    for(auto pm : poss3){
        std::cout << pm << " ";
    }
    std::cout << std::endl;

    return 0;
}