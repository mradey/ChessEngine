#include <iostream>
#include <vector>
#include <string>
#include "../include/Move.h"
#include "../include/Board.h"
#include "../include/Piece.h"
#include <fstream>
using namespace std;

int main()
{
    char * inp = new char[6];
    ofstream jsonFile;
    Board * board = new Board();
    board->boardToJson(jsonFile);
    while(true) {
        cin.getline(inp, 6);
        Move * move = new Move(inp);
        board->movePiece(move);
        board->boardToJson(jsonFile);
    }
    cout << endl;
}