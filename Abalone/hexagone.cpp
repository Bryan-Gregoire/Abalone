#include "Hexagone.h"
#include <iostream>

using namespace abalone;

void Hexagone::setMarble(Marble & marble) {
    if(!marble_.has_value()) {
        marble_.emplace(marble);
    } else {
        throw std::invalid_argument("Paramètre ne peut être vide");
    }
}
