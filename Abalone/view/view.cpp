#include <iomanip>
#include "view.h"
#include <array>
#include <string>
#include <conio.h>
#include <iostream>
#include <sstream>
namespace abalone {

void View::displayBoard(Board& hexagones) {
    unsigned int space =1;
    unsigned int beginLetter=1;
    unsigned int incre =1;
    std::array<std::string,9>letter={"I","H","G","F","E","D","C","B","A"};
    for (unsigned int i = 0;i < hexagones.SIZE ;i++ ) {
        for (unsigned int j = 0;j < hexagones.SIZE ;j++ ) {
            if( beginLetter % incre ==0){
                std::cout<<letter[incre-1];
                if(space % 2 == 0) {
                    std::cout<<" ";
                }
            }
            std::cout<<std::setw(2);
            if(hexagones.isInsideBoard(i,j)) {
                if(hexagones.containMarble(i,j)) {
                    hexagones.getColorMarble(i,j) == Color::BLACK ? std::cout<<"B" : std::cout<<"W";
                } else {
                    std::cout<<"*";
                }
            } else {
                std::cout<<" ";
            }
            incre++;
        }
        if(beginLetter%2==1){
            std::cout<<" ";

        }
        std::cout<<beginLetter;
        std::cout<<std::endl;
        beginLetter++;
        incre = i+2;
        space++;
    }
}

void View::askPosition()  {
    std::cout << "Enter the Position of the marble you want to move : ";
    std::string pos {};
    std::cin >> pos;
    while(pos.length()!=2){
       std::cout << "Enter a good Position : ";
       std::cin.clear();
       std::cin>>pos;
    }
    std::cout << "the choosen position is " << pos << std::endl;
}


//int readInteger(std::string message) {
//    cin>>
//    std::cout<<message;
//    std::cout<<"-->";
//    while (!keyboard.hasNextInt()) {
//        keyboard.next();
//        std::cout<<"the number is not a integer";
//       std::cout<<(message);
//    }

//    return keyboard.nextInt();
//}


}


