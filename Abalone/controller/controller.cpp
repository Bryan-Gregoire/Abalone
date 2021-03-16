#include "controller/controller.h"

namespace abalone {

void Controller::start() {
    model_.setGameStatus(IN_PROGRESS);
    view_.displayMessage("Player 1");
    model_.setCurrentPlayerName(view_.askName());
    view_.displayMessage("Player 2");
    model_.setCurrentPlayerName(view_.askName());
    view_.displayCurrentPlayer(model_.getCurrentPlayer());
    view_.displayBoard(model_.getBoard());
    view_.askPosition();
}
}
