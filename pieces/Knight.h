#include <iostream>
using namespace std;
class Knight : public Piece {
    public:
        using Piece::Piece;
        string toString() {
            return "N";
        }
};