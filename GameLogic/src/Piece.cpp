#include "../include/Piece.h"
#include "../include/Board.h"
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iostream>

Piece::Piece(bool iw, int myFile, int myRank) {
    isWhite = iw;
    isOnBoard = true;
    rank = myRank;
    file = myFile;
}

bool Piece::getIsWhite() { return isWhite; };

bool Piece::getIsOnBoard() { return isOnBoard; };

bitset<64> Piece::getValidMoves() { return validMoves; }

/*A1 = 0, B1 = 1, ... H1 = 7
    A2 = 8, B2 = 9, ... H2 = 15
*/
void Piece::setValidMove(square square) {
    int idx = convertChessSquareToBitSetIdx(square.y, square.x); 
    validMoves.set(idx);
    validMovesList.push_back(arr.at(idx));
}

bool Piece::isValidMove(square square) {
    return validMoves.test(convertChessSquareToBitSetIdx(square.y, square.x));
}

void Piece::noValidMoves() { validMoves.reset(); }

string Piece::toString() { return "piece"; }

int Piece::findValidMoves(Board * board) {return 0;}

square Piece::getSquare() {
    square s1;
    s1.x = file;
    s1.y = rank;
    return s1;
}

bool Piece::isSameColor(Piece * piece) {
    return piece->getIsWhite() == isWhite;
}


std::string Piece::getValidMovesAsString(){
    std::ostringstream oss;
    oss << "['";
    if (!validMovesList.empty())
    {
    // Convert all but the last element to avoid a trailing ","
    std::copy(validMovesList.begin(), validMovesList.end()-1,
        std::ostream_iterator<std::string>(oss, "','"));

    // Now add the last element with no delimiter
    oss << validMovesList.back();
    }
    oss << "']";
    return oss.str();

}

void Piece::setNewSquare(square square) {
    file = square.x;
    rank = square.y;
}

occupation Piece::squareIsAttackable(Board * board, square square) {
    Piece * piece = board->getPiece(square);
    board->isOnBoard(square);

    if(board->isOnBoard(square) && (piece == NULL || !isSameColor(piece))){
        setValidMove(square);
        return piece == NULL ? EMPTY_SQUARE : OCCUPIED_DIFFERENT_COLOR;
    } 
    return OCCUPIED_SAME_COLOR;
}

void Piece::pieceMoved() {
    hasMoved = true;
}