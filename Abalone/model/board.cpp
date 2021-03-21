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

void Board::move(std::pair<unsigned int, unsigned int> posToMove) {

}

}
