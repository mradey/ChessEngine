#include "../Piece.h"
#include <iostream>
using namespace std;
class Queen : public Piece {
    public:
        void toString() {
            cout << "Q";
        }
};