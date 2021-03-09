#include <iostream>
#include "Board.h"
#include <iostream>
#include <iomanip>

using namespace abalone;

int main()
{
    Board b= Board();
    std::cout << "Est-ce-qu'il y a une bille en (4,4) : " << std::endl;
    std::cout <<std::boolalpha<<b.getHexagones().at(4).at(4).has_value()<< std::endl;
    std::cout<<"Le board :: "<<std::endl;;
    unsigned int space = 3;
    for (unsigned int i = 0;i < b.SIZE ;i++ ) {
        for (unsigned int j = 0;j < b.SIZE ;j++ ) {
            if(space < 5 ) {
                std::cout<<std::setw(space);
            } else {
                --space;
                std::cout<<std::setw(space);
            }
            if(b.getHexagones()[i][j].has_value()) {
                if(b.getHexagones()[i][j].value().getMarble().has_value()) {
                    if(b.getHexagones()[i][j].value().getMarble().value().getColor() == Color::BLACK) {
                        std::cout<< "N";
                    } else {
                        std::cout<<"B";
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
