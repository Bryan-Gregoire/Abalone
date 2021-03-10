#include <iostream>
#include "model/Board.h"
#include <iostream>
#include <iomanip>

using namespace abalone;

int main()
{
    Board b= Board();
    std::cout << "Est-ce-qu'il y a une bille en (4,4) : " << std::endl;
    std::cout <<std::boolalpha<<b.getHexagones().at(4).at(4).has_value()<< std::endl;
    std::cout<<"Le board :: "<<std::endl;
    unsigned int space = 1;
    for (unsigned int i = 0;i < b.SIZE ;i++ ) {
        for (unsigned int j = 0;j < b.SIZE ;j++ ) {
            if(space%2==0 && space < 2) {
                std::cout<<std::setw(space);
            } else {
                --space;
                std::cout<<std::setw(space+2);
            }
            if(b.getHexagones()[i][j].has_value()) {
                if(b.getHexagones()[i][j]->getMarble().has_value()) {
                    if(b.getHexagones()[i][j]->getMarble()->getColor() == Color::BLACK) {
                        std::cout<<"*";
                    } else {
                        std::cout<<"*";
                    }
                }else {
                    std::cout<<"*";
                }
            } else {
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
        space++;
    }
    return 0;
}
