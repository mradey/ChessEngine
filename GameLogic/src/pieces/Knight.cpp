#include "../../include/pieces/Knight.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Knight::Knight(bool iw, square square, pieceId pieceId, pieceType type) : Piece(iw, square, pieceId, type) {}
char Knight::toChar() {
    return getIsWhite() ? 'N' : 'n';
}
std::vector<square> Knight::findValidMoves(Board * board) {
    square currentSquare = getSquare();
    std::vector<square> validMoves;
    //check 2 squares up 1 right and 1 left
    currentSquare.y += 2;  //orig y + 2
    currentSquare.x += 1;  //orig x + 1
    if(squareIsAttackable(board, currentSquare)) validMoves.push_back(currentSquare);
    currentSquare.x -= 2;  //orig x - 1
    if(squareIsAttackable(board, currentSquare)) validMoves.push_back(currentSquare);

    //check 1 square up 2 right and 2 left
    currentSquare.y -= 1;  //orig y + 1
    currentSquare.x -= 1;  //orig x - 2
    if(squareIsAttackable(board, currentSquare)) validMoves.push_back(currentSquare);
    currentSquare.x += 4;  //orig x + 2
    if(squareIsAttackable(board, currentSquare)) validMoves.push_back(currentSquare);

    //check 1 square down 2 right and 2 left
    currentSquare.y -= 2;  //orig y - 1
    if(squareIsAttackable(board, currentSquare)) validMoves.push_back(currentSquare);
    currentSquare.x -= 4;  //orig x - 2
    if(squareIsAttackable(board, currentSquare)) validMoves.push_back(currentSquare);

    //check 2 squares down 1 right and 1 left
    currentSquare.y -= 1;  //orig y - 2
    currentSquare.x += 1;  //orig x - 1
    if(squareIsAttackable(board, currentSquare)) validMoves.push_back(currentSquare);
    currentSquare.x += 2;  //orig x + 1
    if(squareIsAttackable(board, currentSquare)) validMoves.push_back(currentSquare);

    return validMoves;
}
 