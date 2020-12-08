#include <iostream>
#include <vector>
#include <string>
#include "../include/Move.h"
#include "../include/Board.h"
#include "../include/Piece.h"
using namespace std;

int main()
{
    char * inp = new char[6];
    Board * board = new Board();
    board->printBoardWhiteTurn();
    while(true) {
        cin.getline(inp, 6);
        Move * move = new Move(inp);
        board->movePiece(move);
    }
    cout << endl;
}