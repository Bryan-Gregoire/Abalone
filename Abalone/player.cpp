#include "Player.h"
#include <iostream>


using namespace abalone;

Player::Player(Color & color) :
    color_ { color }
{}

void Player::setPlayerStatus(PlayerStatus & status) {
        if(status == NULL) {
            throw std::invalid_argument("Paramètre ne peut être vide");
        }
        this->playerStatus_ = status;
}

