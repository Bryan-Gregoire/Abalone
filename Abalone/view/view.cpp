#include <iomanip>
#include "view.h"
#include <array>
#include <string>
#include <conio.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <windows.h>


namespace abalone {

void View::displayBoard(Board const& hexagones) {
    unsigned int space =1;
    char letter[9] = {'I','H','G','F','E','D','C','B','A'};
    int number[9] = {9,8,7,6,5,4,3,2,1};
    unsigned idxNumber = 0;

    for (unsigned int i = 0;i < hexagones.SIZE ;i++ ) {
        if(space % 2 == 0) {
            std::cout<<"     ";
        }
        else {
            std::cout<<"    ";
        }
        for (unsigned int j = 0;j < hexagones.SIZE ;j++ ) {
            std::cout<<std::setw(2);
            if(hexagones.isInsideBoard(i,j)) {
                if(j == 0) {
                    std::cout<<std::setw(1);
                    std::cout<<"\b";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
                    std::cout<<letter[i];
                    std::cout<<std::setw(2);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                }
                if(hexagones.containMarble(i,j)) {
                    if(hexagones.getColorMarble(i,j) == Color::BLACK) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8); // 8 for DARKGREY
                        std::cout<<"B";
                    } else{
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); // 15 for WHITE
                        std::cout<<"W";
                    }
                } else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);  // 12 for RED, for hexagones
                    std::cout<<"*";
                }
            } else {
                if(hexagones.isInsideBoard(i,j+1) && j < hexagones.SIZE / 2) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); //Type of Yellow
                    std::cout<<letter[i];
                } else {
                    std::cout<<" ";
                }
                if( i > (hexagones.SIZE / 2 ) && j > hexagones.SIZE / 2 && hexagones.isInsideBoard(i, j-1)) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); //Type of GREEN
                    std::cout<<"\b"<<number[idxNumber];
                    idxNumber++;
                }
            }
        }
        std::cout<<std::endl;
        if(i == hexagones.SIZE -1) {
            std::cout<<"         ";
            for (unsigned int k = hexagones.SIZE-1;k > idxNumber -1;k-- ) {
                std::cout<<std::setw(2);
                std::cout<<number[k];
            }
            std::cout<<std::endl;
        }
        space++;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7); //7 for Light grey (default color of terminal text)
}

std::vector<int> View::askPosition(std::string message)  {
    std::cout <<message;
    std::string pos {};
    std::cin >> pos;
    std::transform(pos.begin(), pos.end(), pos.begin(), ::toupper);
    bool goodPos = false;
    while(!goodPos) {
        std::cout<<pos<<std::endl;
        if(pos.length() == 4) {
            if(goodRow(pos[0]) && checkGoodCol(pos[0],pos[1]) && goodRow(pos[2])
                    && checkGoodCol(pos[2], pos[3])) {
                goodPos = true;
            }
        } else if(pos.length() == 6) {
            if(goodRow(pos[0]) && checkGoodCol(pos[0],pos[1]) && goodRow(pos[2]) && checkGoodCol(pos[2], pos[3])
                    && goodRow(pos[4]) && checkGoodCol(pos[4], pos[5]))
                goodPos = true;
        }
        if(!goodPos) {
            std::cout << "Wrong Position(s), try again : ";
            std::cin.clear();
            std::cin>>pos;
            std::transform(pos.begin(), pos.end(), pos.begin(), ::toupper);
        }
    }
    if(pos.length() == 4) {
        int initialRow = convertRow(pos[0]);
        int initialCol = convertColumn(initialRow,pos[1]);
        int moveRow = convertRow(pos[2]);
        int moveCol = convertColumn(moveRow,pos[3]);
        std::vector<int> positions {initialRow,initialCol,moveRow,moveCol};
        return positions;
    }
    int firstMarbleRow = convertRow(pos[0]);
    int firstMarbleCol = convertColumn(firstMarbleRow,pos[1]);
    int twiceMarbleRow = convertRow(pos[2]);
    int twiceMarbleCol = convertColumn(twiceMarbleRow,pos[3]);
    int moveRow = convertRow(pos[4]);
    int moveCol = convertColumn(moveRow,pos[5]);
    std::vector<int> positions {firstMarbleRow,firstMarbleCol,twiceMarbleRow,twiceMarbleCol,moveRow,moveCol};
    return positions;
}

bool View::goodRow(char row) const {
    return row >= 'A' && row <= 'I';
}

const std::string View::askName() {
    std::cout << "Enter your name : ";
    std::string name {};
    std::cin >> name;
    std::cout << "Hello " << name << std::endl;
    return name;
}

void View::displayCurrentPlayer(Player const& player, unsigned int idxPlayer) const {
    std::cout<< "Player " << idxPlayer+1 << " "<<player.getName() << " you have : ";
    std::cout<< player.getNbMarbles() << " Marbles " << player.getColor() << std::endl;
}

int View::convertRow(char row) const {
    switch(row) {
    case 'A':
        return 8;
    case 'B':
        return 7;
    case 'C':
        return 6;
    case 'D':
        return 5;
    case 'E':
        return 4;
    case 'F':
        return 3;
    case 'G':
        return 2;
    case 'H':
        return 1;
    case 'I':
        return 0;
    }
    return -1;
}

int View::convertColumn(unsigned int row, unsigned int col) const {
    col = col - 48; // -48 for ASCII.
    switch(row) {
    case 0:
    case 1:
        return col - 3;
    case 2:
    case 3:
        return col - 2;
    case 4:
    case 5:
        return col - 1;
    case 6:
    case 7:
        return col;
    case 8:
        return col +1;
    }
    return col;
}

bool View::checkGoodCol(unsigned int row, unsigned int col) {
    row = convertRow(row);
    col = col - 48;
    switch(row) {
    case 0:
        return col >= 5;
    case 1:
        return col >= 4;
    case 2:
        return col >= 3;
    case 3:
        return col >= 2;
    case 5:
        return col < 9;
    case 6:
        return col < 8;
    case 7:
        return col < 7;
    case 8:
        return col < 6;
    }
    return true;
}

}
