#ifndef SQURE_STRUCT_INCLUDED
#define SQURE_STRUCT_INCLUDED

//OCCUPIED_SAME_COLOR = not a square on board
enum occupation { OCCUPIED_SAME_COLOR, OCCUPIED_DIFFERENT_COLOR, EMPTY_SQUARE };

struct square
{
    int x;
    int y;
};
#endif