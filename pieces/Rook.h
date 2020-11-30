#include <iostream>
using namespace std;
class Rook : public Piece {
    public:
        using Piece::Piece;
        string toString() {
            return "R";
        }
};