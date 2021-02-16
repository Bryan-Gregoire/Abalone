#ifndef HEXAGONE_H
#define HEXAGONE_H
#include"Position.h"
namespace  abalone{

class Hexagone{

private :

    bool isFree ;
    Position positionOnBoard;

public :
    Hexagone(Position positionOnBoard, bool isFree);
    inline bool getisFree() const;
    inline bool setIsFree(bool isFree);
    inline Position getPositionOnBoard() const;

};

}
#endif // HEXAGONE_H
