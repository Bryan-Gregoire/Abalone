#ifndef HEXAGONE_H
#define HEXAGONE_H
#include"Position.h"
namespace  abalone{

class Hexagone{

private :
    bool isFree ;

public :
    Hexagone(Position positionOnBoard, bool isFree);
    inline bool getisFree() const;
    inline bool setIsFree(bool isFree);

};

}
#endif // HEXAGONE_H
