#include "../../include/pieces/Knight.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Knight::Knight(bool iw, int file, int rank) : Piece(iw, file, rank) {}
string Knight::toString() {
    return "N";
}
int Knight::findValidMoves(Board * board) {
    square currentSquare = getSquare();
    int numberAvailableSquares = 0;
    //check 2 squares up 1 right and 1 left
    currentSquare.y += 2;  //orig y + 2
    currentSquare.x += 1;  //orig x + 1
    numberAvailableSquares += squareIsAttackable(board, currentSquare) ? 1 : 0;
    currentSquare.x -= 2;  //orig x - 1
    numberAvailableSquares += squareIsAttackable(board, currentSquare) ? 1 : 0;

    //check 1 square up 2 right and 2 left
    currentSquare.y -= 1;  //orig y + 1
    currentSquare.x -= 1;  //orig x - 2
    numberAvailableSquares += squareIsAttackable(board, currentSquare) ? 1 : 0;
    currentSquare.x += 4;  //orig x + 2
    numberAvailableSquares += squareIsAttackable(board, currentSquare) ? 1 : 0;

    //check 1 square down 2 right and 2 left
    currentSquare.y -= 2;  //orig y - 1
    numberAvailableSquares += squareIsAttackable(board, currentSquare) ? 1 : 0;
    currentSquare.x -= 4;  //orig x - 2
    numberAvailableSquares += squareIsAttackable(board, currentSquare) ? 1 : 0;

    //check 2 squares down 1 right and 1 left
    currentSquare.y -= 1;  //orig y - 2
    currentSquare.x += 1;  //orig x - 1
    numberAvailableSquares += squareIsAttackable(board, currentSquare) ? 1 : 0;
    currentSquare.x += 2;  //orig x + 1
    numberAvailableSquares += squareIsAttackable(board, currentSquare) ? 1 : 0;

    return numberAvailableSquares;
}
 