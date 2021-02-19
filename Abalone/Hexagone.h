#ifndef HEXAGONE_H
#define HEXAGONE_H
#include "marble.h"
namespace  abalone{

class Hexagone{

private :
    bool isFree ;
    Marble * marble;

public :
    Hexagone() = default;
    Hexagone(Marble * marble);
    inline bool getIsFree() const;
    inline Marble * getMarble() const;
    void setIsFree(bool isFree);
    void setMarble(Marble * marble);
    void deleteMarble();

public:
    bool getIsFree() {
        return this->isFree;
    }

    Marble * getMarble() {
        return this->marble;
    }
};

}
#endif // HEXAGONE_H
