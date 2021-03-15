#include "controller/controller.h"

namespace abalone {

void Controller::start() {
   view_.askPosition();
   view_.displayBoard(model_.getBoard());
}
}
