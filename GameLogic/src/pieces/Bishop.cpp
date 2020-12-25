#include "../../include/pieces/Bishop.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Bishop::Bishop(bool iw, square square, pieceId pieceId, pieceType type) : Piece(iw, square, pieceId, type) {}
std::string Bishop::toString() {
    return "B";
}
std::vector<square> Bishop::findValidMoves(Board * board) {
    square currentSquare = getSquare();
    std::vector<square> validMoves;
    std::vector<square> squaresOnDiag;
    
    //diag right up
    squaresOnDiag = movesOnDiag(RIGHT, UP, currentSquare, board);
    validMoves.insert(validMoves.end(), squaresOnDiag.begin(), squaresOnDiag.end());

    //diag right down
    squaresOnDiag = movesOnDiag(RIGHT, DOWN, currentSquare, board);
    validMoves.insert(validMoves.end(), squaresOnDiag.begin(), squaresOnDiag.end());

    //diag left up
    squaresOnDiag = movesOnDiag(LEFT, UP, currentSquare, board);
    validMoves.insert(validMoves.end(), squaresOnDiag.begin(), squaresOnDiag.end());

    //diag left down
    squaresOnDiag = movesOnDiag(LEFT, DOWN, currentSquare, board);
    validMoves.insert(validMoves.end(), squaresOnDiag.begin(), squaresOnDiag.end());

    return validMoves;
}

std::vector<square> Bishop::movesOnDiag(int xDir, int yDir, square currentSquare, Board * board) {
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