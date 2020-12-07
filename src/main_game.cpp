#include <iostream>
#include <vector>
#include <string>
#include "../include/Board.h"
#include "../include/Piece.h"
#include "../include/pieces/Knight.h"
using namespace std;

int main()
{
    Board * board = new Board();
    Piece * knight = new Knight(true);
    knight->findValidMoves(board);
    cout << endl;
}