﻿#include <iomanip>
#include "view.h"
#include <array>
#include <string>
#include <conio.h>
#include <iostream>
#include <sstream>
#include <algorithm>


namespace abalone {

void View::displayBoard(Board const& hexagones) {
    unsigned int space =1;
    for (unsigned int i = 0;i < hexagones.SIZE ;i++ ) {
        if(space % 2 == 0) {
            std::cout<<" ";
        }
        for (unsigned int j = 0;j < hexagones.SIZE ;j++ ) {
            std::cout<<std::setw(3);
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

std::pair<unsigned int,unsigned int> View::askPosition()  {
    std::cout << "Enter the Position of the marble you want to move : ";
    std::string pos {};
    std::cin >> pos;
    std::transform(pos.begin(), pos.end(), pos.begin(), ::toupper);
    while(pos.length() != 2 || pos[0] < 'A' || pos[0] > 'I' || pos[1] < 49 || pos[1] > 57) {
        std::cout << "Enter a good Position : ";
        std::cin.clear();
        std::cin>>pos;
        std::transform(pos.begin(), pos.end(), pos.begin(), ::toupper);
    }
    std::cout << "the choosen position is " << pos << std::endl;
    return std::pair(convertRow(pos[0]),pos[1] - 49);

}

const std::string View::askName() {
    std::cout << "Enter your name : ";
    std::string name {};
    std::cin >> name;
    std::cout << "Hello " << name << std::endl;
    return name;
}

void View::displayCurrentPlayer(Player const& player, unsigned int idxPlayer) const {
    std::cout<< "Player " << idxPlayer+1 << " : "<<player.getName() << " it's your turn , you have : ";
    std::cout<< player.getNbMarbles() << " Marbles, color of marble : " << player.getColor() << std::endl;
}

unsigned int View::convertRow(char row) const {
    switch(row) {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
     case 'E':
        return 4;
    case 'F':
        return 5;
    case 'G':
        return 6;
    case 'H':
        return 7;
    case 'I':
        return 8;
    }
    return -1;
}

}


