#include "../Piece.h"
#include <iostream>
using namespace std;
class King : public Piece {
    public:
        void toString() {
            cout << "K";
        }
};