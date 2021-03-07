#include "marble.h"
#include <iostream>

using namespace abalone;

Marble::Marble(Color color) :
    color_ {color}
{
    if(color == NULL) {
        throw std::invalid_argument("Paramètre ne peut être vide");
    }
}
