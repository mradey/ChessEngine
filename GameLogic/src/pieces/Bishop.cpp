#include "../../include/pieces/Bishop.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Bishop::Bishop(bool iw, int file, int rank) : Piece(iw, file, rank) {}
string Bishop::toString() {
    return "B";
}
int Bishop::findValidMoves(Board * board) {
    square currentSquare = getSquare();
    int availableSquares = 0;
    
    //diag right up
    availableSquares += movesOnDiag(RIGHT, UP, currentSquare, board);

    //diag right down
    availableSquares += movesOnDiag(RIGHT, DOWN, currentSquare, board);

    //diag left up
    availableSquares += movesOnDiag(LEFT, UP, currentSquare, board);

    //diag left down
    availableSquares += movesOnDiag(LEFT, DOWN, currentSquare, board);

    return availableSquares;
}

int Bishop::movesOnDiag(int xDir, int yDir, square square, Board * board) {
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