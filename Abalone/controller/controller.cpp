#include "controller/controller.h"

namespace abalone {

void Controller::start() {
   view_.displayMessage("Player 1 ");
   view_.askName();
   view_.displayMessage("Player 2 ");
   view_.askName();
   view_.askPosition();
   view_.displayBoard(model_.getBoard());
}
}
