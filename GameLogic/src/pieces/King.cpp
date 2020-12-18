#include "../../include/pieces/King.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

King::King(bool iw, int file, int rank) : Piece(iw, file, rank) {}
string King::toString() {
    return "K";
}
int King::findValidMoves(Board * board) {
    square currentSquare = getSquare();
    int numberAvailableSquares = 0;


    return 0;
}