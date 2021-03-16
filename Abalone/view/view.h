#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "model/Player.h"
#include "model/Board.h"
#include "model/Position.h"
namespace abalone {

class View {

public:

    View() = default;

    void displayBoard(Board const& hexagones);

    inline void displayMessage(const std::string message) const {
        std::cout<<message<<std::endl;
    }

    void displayCurrentPlayer(Player const& player) const;

    void askPosition();

    const std::string askName();


};
}


#endif // VIEW_H

