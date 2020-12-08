#ifndef SQUARE_INCLUDED
#define SQUARE_INCLUDED
class Piece;
class Square {
    private:
        Piece * piece;
        int rank;
        int col;
    public:
        Square(int x, int y, Piece * p) {
            col = x;
            rank = y;
            piece = p;
        }
        Piece * getPiece() {
            return piece;
        }
        void setPiece(Piece * p) {
            piece = p;
        }
};

#endif