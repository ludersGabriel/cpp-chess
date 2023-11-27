#ifndef ENUM_FEN_REPRESENTATION_HPP
#define ENUM_FEN_REPRESENTATION_HPP

namespace chess {

enum class EnumFenRepresentation : char {
  EMPTY = ' ',
  WHITE_BISHOP = 'B',
  WHITE_KING = 'K',
  WHITE_KNIGHT = 'N',
  WHITE_PAWN = 'P',
  WHITE_QUEEN = 'Q',
  WHITE_ROOK = 'R',
  BLACK_BISHOP = 'b',
  BLACK_KING = 'k',
  BLACK_KNIGHT = 'n',
  BLACK_PAWN = 'p',
  BLACK_QUEEN = 'q',
  BLACK_ROOK = 'r'
};

}

#endif