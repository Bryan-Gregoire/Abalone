#include <iostream>
#include "Board.h"

using namespace abalone;

int main()
{
    Board b= Board();
    std::cout << "Test du board : " << std::endl;
    std::cout << b.getHexagones().at(4).at(4).has_value()<< std::endl;
//    for (unsigned int i = 0;i < 9 ;i++ ) {
//        for (unsigned int j = 0;j < 9 ;j++ ) {
//            if(b.getHexagones()[i][j]) {
//                if(hexagones_[i][j].value().getMarble().getColor() == Color::BLACK) {
//                    std::cout<< "N";
//                } else {
//                    std::cout<<"B";
//                }
//            } else {
//                std::cout<<" ";
//            }
//        }
//        std::cout<<" "<<std::endl;
//    }

    return 0;
}
