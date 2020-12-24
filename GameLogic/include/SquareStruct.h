#ifndef SQURE_STRUCT_INCLUDED
#define SQURE_STRUCT_INCLUDED

//OCCUPIED_SAME_COLOR is value if square not on board
enum occupation { OCCUPIED_SAME_COLOR, OCCUPIED_DIFFERENT_COLOR, EMPTY_SQUARE };

enum pieceType {PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};

struct square
{
    int x;
    int y;
};
#endif