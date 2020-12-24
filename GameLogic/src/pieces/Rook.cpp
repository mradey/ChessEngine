#include "../../include/pieces/Rook.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Rook::Rook(bool iw, square square) : Piece(iw, square) {}
std::string Rook::toString() {
    return "R";
}
std::vector<square> Rook::findValidMoves(Board * board) {
    square currentSquare = getSquare();
    std::vector<square> validMoves;
    std::vector<square> squaresOnLine;
    
    //up
    squaresOnLine = movesOnLine(STAY, UP, currentSquare, board);
    validMoves.insert(validMoves.end(), squaresOnLine.begin(), squaresOnLine.end());

    //down
    squaresOnLine = movesOnLine(STAY, DOWN, currentSquare, board);
    validMoves.insert(validMoves.end(), squaresOnLine.begin(), squaresOnLine.end());

    //left
    squaresOnLine = movesOnLine(LEFT, STAY, currentSquare, board);
    validMoves.insert(validMoves.end(), squaresOnLine.begin(), squaresOnLine.end());

    //right
    squaresOnLine = movesOnLine(RIGHT, STAY, currentSquare, board);
    validMoves.insert(validMoves.end(), squaresOnLine.begin(), squaresOnLine.end());

    return validMoves;
}

std::vector<square> Rook::movesOnLine(int xDir, int yDir, square currentSquare, Board * board) {
    std::vector<square> availableSqures;
    occupation occ = squareIsAttackable(board, currentSquare);
    while(occ == EMPTY_SQUARE) {
        currentSquare.x += xDir;
        currentSquare.y += yDir;
        occ = squareIsAttackable(board, currentSquare);
        if(occ != OCCUPIED_SAME_COLOR) availableSqures.push_back(currentSquare);
    }
    return availableSqures;
}