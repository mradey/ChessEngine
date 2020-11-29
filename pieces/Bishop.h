#include "../Piece.h"
#include <iostream>
using namespace std;
class Bishop : public Piece {
    public:
        void toString() {
            cout << "B";
        }
};