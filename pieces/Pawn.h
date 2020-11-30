#include <iostream>
using namespace std;
class Pawn : public Piece {
    public:
        using Piece::Piece;
        string toString() {
            return "P";
        }
};