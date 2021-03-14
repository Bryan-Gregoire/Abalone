#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "model/Player.h"
#include "model/Board.h"

namespace abalone {

class View {

public:

    View();

    void displayBoard(Board hexagones);

    inline void displayMessage(std::string message) const {
        std::cout<<message<<std::endl;
    }

    inline void displayPlayer(Player player) const;
};

}


#endif // VIEW_H

