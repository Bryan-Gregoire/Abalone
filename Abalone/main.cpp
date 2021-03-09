#include <iostream>
#include "board.h"

using namespace abalone;

int main()
{
    Color black = BLACK;
    Marble BMarble = Marble(black);
    std::optional<Hexagone> hexagones_[9][9] = {
        { {std::nullopt},{std::nullopt},{Hexagone(BMarble)},{Hexagone(BMarble)},{Hexagone(BMarble)},{Hexagone(BMarble)},{Hexagone(BMarble)},{std::nullopt},{std::nullopt} },
        { {std::nullopt},{Hexagone(Marble(Color::BLACK))},{Hexagone(Marble(Color::BLACK))},{Hexagone(Marble(Color::BLACK))},{Hexagone(Marble(Color::BLACK))},{Hexagone(Marble(Color::BLACK))},{Hexagone(Marble(Color::BLACK))},{std::nullopt},{std::nullopt} },
        { {std::nullopt},{Hexagone()},{Hexagone()},{Hexagone(Marble(Color::BLACK))},{Hexagone(Marble(Color::BLACK))},{Hexagone(Marble(Color::BLACK))},{Hexagone()},{Hexagone()},{std::nullopt} },
        { {Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{std::nullopt} },
        { {Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()} },
        { {Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{Hexagone()},{std::nullopt} },
        { {std::nullopt},{Hexagone()},{Hexagone()},{Hexagone(Marble(Color::WHITE))},{Hexagone(Marble(Color::WHITE))},{Hexagone(Marble(Color::WHITE))},{Hexagone()},{Hexagone()},{std::nullopt} },
        { {std::nullopt},{Hexagone(Marble(Color::WHITE))},{Hexagone(Marble(Color::WHITE))},{Hexagone(Marble(Color::WHITE))},{Hexagone(Marble(Color::WHITE))},{Hexagone(Marble(Color::WHITE))},{Hexagone(Marble(Color::WHITE))},{std::nullopt},{std::nullopt} },
        { {std::nullopt},{std::nullopt},{Hexagone(Marble(Color::WHITE))},{Hexagone(Marble(Color::WHITE))},{Hexagone(Marble(Color::WHITE))},{Hexagone(Marble(Color::WHITE))},{Hexagone(Marble(Color::WHITE))},{std::nullopt},{std::nullopt} }
                };
    std::cout << "Test du board : " << std::endl;
    for (unsigned int i = 0;i < 9 ;i++ ) {
        for (unsigned int j = 0;j < 9 ;j++ ) {
            if(hexagones_[i][j].has_value()) {
                if(hexagones_[i][j].value().getMarble().getColor() == Color::BLACK) {
                    std::cout<< "N";
                } else {
                    std::cout<<"B";
                }
            } else {
                std::cout<<" ";
            }
        }
        std::cout<<" "<<std::endl;
    }

    return 0;
}
