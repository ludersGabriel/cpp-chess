#ifndef ENUM_FEN_REPRESENTATION_HPP
#define ENUM_FEN_REPRESENTATION_HPP

namespace chess {

enum class EnumFenRepresentation : char {
  EMPTY = ' ',
  BLACK_PAWN = 'p',
  BLACK_KNIGHT = 'n',
  BLACK_BISHOP = 'b',
  BLACK_ROOK = 'r',
  BLACK_QUEEN = 'q',
  BLACK_KING = 'k',
  WHITE_BISHOP = 'B',
  WHITE_KING = 'K',
  WHITE_KNIGHT = 'N',
  WHITE_PAWN = 'P',
  WHITE_QUEEN = 'Q',
  WHITE_ROOK = 'R'
};

}

#endif