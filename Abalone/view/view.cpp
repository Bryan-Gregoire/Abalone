#include <iomanip>
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
    char letter[9] = {'I','H','G','F','E','D','C','B','A'};

    for (unsigned int i = 0;i < hexagones.SIZE ;i++ ) {
        if(space % 2 == 0) {
            std::cout<<"     ";
        }
        else
            std::cout<<"    ";
        for (unsigned int j = 0;j < hexagones.SIZE ;j++ ) {
            std::cout<<std::setw(2);
            if(hexagones.isInsideBoard(i,j)) {
                if(j == 0) {
                    std::cout<<std::setw(1);
                    std::cout<<"\b";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITE_PEN);
                    std::cout<<letter[i];
                    std::cout<<std::setw(2);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                }

                if(hexagones.containMarble(i,j)) {
                    if(hexagones.getColorMarble(i,j) == Color::BLACK) {
                         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
                         std::cout<<"B";
                         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITEONBLACK);
                    } else{
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                        std::cout<<"W";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITEONBLACK);
                    }
                } else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    std::cout<<"*";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITEONBLACK);
                }
            } else {
                if(hexagones.isInsideBoard(i,j+1) && j < hexagones.SIZE / 2)
                   {

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITE_PEN); //Type of yellow
                    std::cout<<letter[i];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITEONBLACK); //15 for white
                }
                else
                    std::cout<<" ";
            }
        }
        std::cout<<std::endl;
        space++;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7); //7 for Light grey (color of terminal text)
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
    std::cout<< player.getNbMarbles() << " Marbles " << player.getColor() << std::endl;
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


