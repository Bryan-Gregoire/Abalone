#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "model/Player.h"

namespace abalone {

class View {

public:
    View();
    inline void displayBoard() const;
    inline void displayMessage(std::string message) const;
    inline void displayPlayer(Player player) const;
};

}


#endif // VIEW_H

