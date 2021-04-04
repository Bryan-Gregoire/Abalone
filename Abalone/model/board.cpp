#include "Board.h"

namespace abalone {


Board::Board():
    hexagones_ {
    {{std::nullopt,std::nullopt,Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),Hexagone(),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),std::nullopt,std::nullopt},
     {std::nullopt,Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),std::nullopt,std::nullopt},
     {std::nullopt, Hexagone(),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),Hexagone(),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),Hexagone(),std::nullopt},
     {Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),std::nullopt},
     {Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone()},
     {Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),std::nullopt },
     {std::nullopt,Hexagone(),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),Hexagone(),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),Hexagone(),std::nullopt },
     {std::nullopt,Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),std::nullopt,std::nullopt },
     {std::nullopt,std::nullopt,Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),Hexagone(),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),std::nullopt,std::nullopt}}
}{}

bool Board::move(std::vector<int> & positions) {
    if(positions.size() == 4) {
        return moveLine(positions);
        hexagones_[positions.at(2)][positions.at(3)].emplace(hexagones_[positions.at(0)][positions.at(1)].value());
        hexagones_[positions.at(0)][positions.at(1)].emplace(Hexagone());
    }
    moveLateral(positions);
    return false;
}

bool Board::moveLine(std::vector<int> & positions) {

}

bool Board::moveLateral(std::vector<int> & positions) {

}
}
