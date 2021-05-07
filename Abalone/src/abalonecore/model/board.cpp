#include "Board.h"
#include "iostream"

namespace abalone {


Board::Board():
    hexagones_ {
{{std::nullopt,std::nullopt,std::nullopt, std::nullopt, Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),Hexagone(),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK))},
{std::nullopt,std::nullopt, std::nullopt, Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK))},
{std::nullopt,std::nullopt, Hexagone(),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),Hexagone(),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),Hexagone()},
{std::nullopt,Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone()},
{Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone()},
{Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),Hexagone(),std::nullopt },
{Hexagone(),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),Hexagone(),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),Hexagone(),std::nullopt, std::nullopt },
{Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),std::nullopt,std::nullopt,std::nullopt },
{Hexagone(Marble(Color::BLACK)),Hexagone(Marble(Color::BLACK)),Hexagone(),Hexagone(Marble(Color::WHITE)),Hexagone(Marble(Color::WHITE)),std::nullopt,std::nullopt,std::nullopt,std::nullopt}}
}{}

int Board::move(std::vector<int> & positions) {
    if(positions.size() == 4) {
        return moveLine(positions);
    } else if(positions.size() == 6) {
        moveLateral(positions);
    } else {
        throw std::invalid_argument("size of vector not correct");
    }
    return 10; // lateral movement
}


int Board::convertPositionBound(int i ) const {
    if(i < -1) {
        return -1;
    } else if(i > 1){
        return 1;
    }
    return i;
}

int Board::moveLine(std::vector<int> & positions) {
    std::pair<int, int> directionLine {(positions.at(2) - positions.at(0)),(positions.at(3) - positions.at(1))};
    unsigned countSame = 0;
    unsigned countOther = 0;
    std::pair<int, int> selectedMarble {positions.at(0), positions.at(1)};

    while(countSame < 4 || countOther < 4) {
        if(!containMarble(selectedMarble.first, selectedMarble.second)) {
            break;
        }
        if(hexagones_.at(selectedMarble.first).at(selectedMarble.second)->getMarble()->getColor()
                == hexagones_.at(positions.at(0)).at(positions.at(1))->getMarble()->getColor()) {
            if(countOther != 0) {
                return 0; //nothing fall, blocked
            }
            countSame++;
        } else {
            countOther++;
        }
        selectedMarble.first += directionLine.first;
        selectedMarble.second += directionLine.second;
    }
    if(countSame >= 4 ) {
        return 0;
    }
    if (countOther == 0) {
        if(!isInsideBoard(selectedMarble.first, selectedMarble.second)) {
            hexagones_[selectedMarble.first - directionLine.first]
                    [selectedMarble.second - directionLine.second]
                    .emplace(hexagones_[positions.at(0)][positions.at(1)].value());
            hexagones_[positions.at(0)][positions.at(1)].emplace(Hexagone());
            return 1; // self marble fall
        }
        hexagones_[selectedMarble.first][selectedMarble.second]
                .emplace(hexagones_[positions.at(0)][positions.at(1)].value());
        hexagones_[positions.at(0)][positions.at(1)].emplace(Hexagone());

    } else if(countOther < countSame){
        std::pair<int, int> firstMarbleOther {positions.at(0), positions.at(1)};

        for(unsigned i = 0; i < countSame; i++) {
            firstMarbleOther.first += directionLine.first;
            firstMarbleOther.second += directionLine.second;
        }
        if(!isInsideBoard(selectedMarble.first, selectedMarble.second)) {
            hexagones_[selectedMarble.first - directionLine.first][selectedMarble.second - directionLine.second]
                    .emplace(hexagones_[firstMarbleOther.first][firstMarbleOther.second].value());
            hexagones_[firstMarbleOther.first][firstMarbleOther.second]
                    .emplace(hexagones_[positions.at(0)][positions.at(1)].value());
            hexagones_[positions.at(0)][positions.at(1)].emplace(Hexagone());
            return 2; // enemy marble fallen
        }
        hexagones_[selectedMarble.first][selectedMarble.second]
                .emplace(hexagones_[firstMarbleOther.first][firstMarbleOther.second].value());
        hexagones_[firstMarbleOther.first][firstMarbleOther.second]
                .emplace(hexagones_[positions.at(0)][positions.at(1)].value());
        hexagones_[positions.at(0)][positions.at(1)].emplace(Hexagone());
    } else {
        return 0; //nothing fall, blocked
    }
    return -1; // nothing fall
}


void Board::moveLateral(std::vector<int> & positions) {
    std::pair<int, int> directionLateral {convertPositionBound((positions.at(4) - positions.at(0))),
                (convertPositionBound(positions.at(5) - positions.at(1)))};
    std::pair<int, int> directionLine {convertPositionBound((positions.at(2) - positions.at(0))),
                convertPositionBound((positions.at(3) - positions.at(1)))};
    std::pair<int, int> selectedMarble {positions.at(0), positions.at(1)};
    while(selectedMarble.first != positions.at(2) || selectedMarble.second != positions.at(3)) {
        if(!containMarble(selectedMarble.first, selectedMarble.second)
                || hexagones_.at(selectedMarble.first).at(selectedMarble.second)->getMarble()->getColor()
                != hexagones_.at(positions.at(0)).at(positions.at(1))->getMarble()->getColor()
                || containMarble(selectedMarble.first + directionLateral.first, selectedMarble.second + directionLateral.second)){
            return;
        }
        selectedMarble.first = selectedMarble.first + directionLine.first;
        selectedMarble.second = selectedMarble.second + directionLine.second;
    }

    selectedMarble.first = positions.at(0);
    selectedMarble.second = positions.at(1);

    while(selectedMarble.first != (positions.at(2) +directionLine.first) || selectedMarble.second != (positions.at(3) + directionLine.second)) {
        if(!isInsideBoard(positions.at(2) +directionLine.first, positions.at(3) + directionLine.second)) {
            return;
        }
        hexagones_[selectedMarble.first + directionLateral.first][selectedMarble.second + directionLateral.second]
                .emplace(hexagones_[selectedMarble.first][selectedMarble.second].value());
        hexagones_[selectedMarble.first][selectedMarble.second].emplace(Hexagone());
        selectedMarble.first = selectedMarble.first + directionLine.first;
        selectedMarble.second = selectedMarble.second + directionLine.second;
    }
    return;
}

}
