#include <string>
using namespace std;
class Piece {
    private: 
        bool isWhite;
        bool isOnBoard;
    public:
        Piece(bool iw) {
            isWhite = iw;
            isOnBoard = true;
        }

        bool getIsWhite() {
            return isWhite;
        };
        
        bool getIsOnBoard() {
            return isOnBoard;
        };

        //virtual bool canMove();

        virtual string toString() {
            return "piece";
        }
};