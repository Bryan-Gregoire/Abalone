#include <iomanip>
#include "view.h"

namespace abalone {

void View::displayBoard(Board hexagones) {
    unsigned int space =1;
    for (unsigned int i = 0;i < hexagones.SIZE ;i++ ) {
        if(space % 2 == 0) {
            std::cout<<" ";
        }
        for (unsigned int j = 0;j < hexagones.SIZE ;j++ ) {
            std::cout<<std::setw(2);
            if(hexagones.isInsideBoard(i,j)) {
                if(hexagones.containMarble(i,j)) {
                    hexagones.getColorMarble(i,j) == Color::BLACK ? std::cout<<"N" : std::cout<<"B";
                } else {
                    std::cout<<"*";
                }
            } else {
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
        space++;
    }
}

}

