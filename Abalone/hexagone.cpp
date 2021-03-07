#include "hexagone.h"
#include <iostream>

using namespace abalone;

Hexagone::Hexagone() :
    marble_ { std::nullopt }
{}

Hexagone::Hexagone(Marble marble) :
    marble_ { marble }
{
    if(!marble_.has_value()) {
        throw std::invalid_argument("Paramètre ne peut être vide");
    }
}

void Hexagone::setMarble(Marble marble) {
    if(!marble_.has_value()) {
        marble_.emplace(marble);
    } else {
        throw std::invalid_argument("Paramètre ne peut être vide");
    }
}
