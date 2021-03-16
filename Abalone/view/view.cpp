#include <iomanip>
#include "view.h"
#include <array>
#include <string>
#include <conio.h>
#include <iostream>
#include <sstream>
#include <algorithm>


namespace abalone {

void View::displayBoard(Board& hexagones) {
    unsigned int space =1;
    for (unsigned int i = 0;i < hexagones.SIZE ;i++ ) {
        if(space % 2 == 0) {
            std::cout<<" ";
        }
        for (unsigned int j = 0;j < hexagones.SIZE ;j++ ) {
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
        }
        std::cout<<std::endl;
        space++;
    }
}

void View::askPosition()  {
    std::cout << "Enter the Position of the marble you want to move : ";
    std::string pos {};
    std::cin >> pos;
    std::transform(pos.begin(), pos.end(), pos.begin(), ::toupper);
    while(pos.length() != 2 || pos[0] < 'A' || pos[0] > 'I' || pos[1] < 49 || pos[1] >= 57) {
        std::cout << "Enter a good Position : ";
        std::cin.clear();
        std::cin>>pos;
        std::transform(pos.begin(), pos.end(), pos.begin(), ::toupper);
    }
    std::cout << "the choosen position is " << pos << std::endl;
}

std::string View::askName() {
    std::cout << "Enter your name : ";
    std::string name {};
    std::cin >> name;
    std::cout << "Hello " << name << std::endl;
    return name;
}
void View::displayCurrentPlayer(Player const& player) const {
    std::cout<<"Player : " + player.getName() + " it's your turn , you have : " << player.getNbMarbles()<< " Marbles" << std::endl;
}
}


