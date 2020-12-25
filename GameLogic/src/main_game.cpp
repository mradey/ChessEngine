#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>
#include "../include/Move.h"
#include "../include/Board.h"
#include "../include/Piece.h"
#include <fstream>
using namespace std;

void printHexToBinary(uint64_t x);
uint64_t getRookAttackSquares(int space, uint64_t board);

int main()
{
    char * inp = new char[6];
    ofstream jsonFile;
    inp = "e7 b3";
    Move * move = new Move(inp);

    Board * board = new Board();
    board->movePiece(move);
    board->printBoardWhiteTurn();
    square s;
    s.x = 2;
    s.y = 1;

    Piece * p = board->getPiece(s);
    s.x++;
    p->setValidMoves(p->findValidMoves(board));
    printHexToBinary(p->getValidMoves().to_ullong());
    cout << "\n\n" << p->getValidMovesAsString();
   
    
    board->boardToJson(jsonFile);
    // while(true) {
    //     cin.getline(inp, 6);
    //     Move * move = new Move(inp);
    //     board->movePiece(move);
    //     board->boardToJson(jsonFile);
    // }


    cout << endl;
}

void printHexToBinary(uint64_t board) {
    int mask = 0xFF;
    cout << "8 " << bitset<8>(board >> 8*7) << "\n";
    cout << "7 " << bitset<8>(board >> 8*6) << "\n";
    cout << "6 " << bitset<8>(board >> 8*5) << "\n";
    cout << "5 " << bitset<8>(board >> 8*4) << "\n";
    cout << "4 " << bitset<8>(board >> 8*3) << "\n";
    cout << "3 " << bitset<8>(board >> 8*2) << "\n";
    cout << "2 " << bitset<8>(board >> 8*1) << "\n";
    cout << "1 " << bitset<8>(board >> 8*0) << "\n";
    cout << "  " << "ABCDEFGH\n\n";
}