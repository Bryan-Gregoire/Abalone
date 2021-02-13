#ifndef HEXAGONE_H
#define HEXAGONE_H
#include"Position.h"
namespace  abalone{
class Hexagone{
private :
    bool isfree ;
    Position positionOnBoard;

public :
    Hexagone(Position positionOnBoard, bool isFree);
    inline bool getisFree();
    inline bool setisFree(bool isFree);
    inline Position getPositionOnBoard();


};
}
#endif // HEXAGONE_H
