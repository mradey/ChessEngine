#include "../../include/pieces/Pawn.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Pawn::Pawn(bool iw, int file, int rank) : Piece(iw, file, rank) {}
string Pawn::toString() {
    return "P";
}

int Pawn::findValidMoves(Board * board) {
    square currentSquare = getSquare();
    int advanceableSquares = getAdvanceableSquares(board, currentSquare);
    int attackingSquares   = getAttackingSquares(board, currentSquare);
    cout << "can advance " << advanceableSquares << "squares\n";
    return advanceableSquares + attackingSquares;
}
int Pawn::getAdvanceableSquares(Board * board, square square) {
    //Get pawn direction and if has moved
    int advanceableSquares = 0;
    const int direction = -1 + (getIsWhite() * 2);
    const bool isOnStartingSquare = hasNotMoved();

    //Check 1 square ahead
    square.y += direction;    
    Piece * piece = board->getPiece(square);
    if(piece == NULL) {
        advanceableSquares++;
        setValidMove(square);
        
        //check 2 squares ahead if is on starting square 
        square.y += direction;
        piece = board->getPiece(square);
        if(isOnStartingSquare && piece == NULL) {
            advanceableSquares++;
            setValidMove(square);
        }
    }
    return advanceableSquares;
}

int Pawn::getAttackingSquares(Board * board, square square) {
    //get pawn direction
    int attackingSquares = 0;
    square.y += -1 + (getIsWhite() * 2);
    occupation occ;

    //check if can attack towards a file
    square.x--;

    attackingSquares += squareIsAttackable(board, square) ? 1 : 0;

    //check if can attack towards h file
    square.x += 2;
    attackingSquares += squareIsAttackable(board, square) ? 1 : 0;

    //NEED TO ADD LOGIC FOR EN PASSANT
    return attackingSquares;
}
bool Pawn::hasNotMoved() {
    return (getSquare().y == 6 && !getIsWhite()) || 
           (getSquare().y == 1 &&  getIsWhite());
}