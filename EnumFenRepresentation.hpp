#ifndef ENUM_FEN_REPRESENTATION_HPP
#define ENUM_FEN_REPRESENTATION_HPP

namespace chess {

enum class EnumFenRepresentation : char {
  WHITE_PAWN = 'P',
  WHITE_KNIGHT = 'N',
  WHITE_BISHOP = 'B',
  WHITE_ROOK = 'R',
  WHITE_QUEEN = 'Q',
  WHITE_KING = 'K',
  BLACK_PAWN = 'p',
  BLACK_KNIGHT = 'n',
  BLACK_BISHOP = 'b',
  BLACK_ROOK = 'r',
  BLACK_QUEEN = 'q',
  BLACK_KING = 'k',
  EMPTY = ' '
};

}

#endif