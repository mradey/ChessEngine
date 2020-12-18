#include "../../include/pieces/Rook.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Rook::Rook(bool iw, int file, int rank) : Piece(iw, file, rank) {}
string Rook::toString() {
    return "R";
}
int Rook::findValidMoves(Board * board) {
    square currentSquare = getSquare();
    int availableSquares = 0;
    
    //up
    availableSquares += movesOnLine(0, UP, currentSquare, board);

    //down
    availableSquares += movesOnLine(0, DOWN, currentSquare, board);

    //left
    availableSquares += movesOnLine(LEFT, 0, currentSquare, board);

    //right
    availableSquares += movesOnLine(RIGHT, 0, currentSquare, board);

    return availableSquares;
}

int Rook::movesOnLine(int xDir, int yDir, square square, Board * board) {
    int availableSqures = 0;
    occupation occ = squareIsAttackable(board, square);
    while(occ == EMPTY_SQUARE) {
        availableSqures++;
        square.x += xDir;
        square.y += yDir;
        occ = squareIsAttackable(board, square);
    }
    return availableSqures;
}