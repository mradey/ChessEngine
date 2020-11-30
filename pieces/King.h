#include <iostream>
using namespace std;
class King : public Piece {
    public:
        using Piece::Piece;
        string toString() {
            return "K";
        }
};