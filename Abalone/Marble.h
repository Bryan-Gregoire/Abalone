#ifndef MARBLE_H
#define MARBLE_H
#include "color.h"
namespace  abalone{

class Marble{

private :
    Color color ;

public :
    Marble(Color color);
    inline Color getColor() const;

    Color getColor() {
        return this->color;
    }
};

}


#endif // MARBLE_H
