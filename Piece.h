#include <string.h>
class Piece {
    private: 
        bool isWhite;
        bool isOnBoard;
    public:
        bool isWhite() {
            return isWhite;
        };
        
        bool isOnBoard() {
            return isOnBoard;
        };

        virtual bool canMove();
};