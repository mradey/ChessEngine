#include <iostream>
using namespace std;
class Bishop : public Piece {
    public:
        using Piece::Piece;
        string toString() {
            return "B";
        }
};