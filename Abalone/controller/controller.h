#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view/view.h"
#include "model/Game.h"

namespace abalone {

class Controller {

private:
    View view_;
    Game model_;

public:

    /**
     * @brief constructor Controller
     */
    Controller();

    void start();
};

}

#endif // CONTROLLER_H

