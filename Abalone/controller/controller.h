#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view/view.h"
#include "model/Game.h"

/*!
 * Namespace of the Abalone project.
 *
 */
namespace abalone {

/*!
 * The Controller represents the dynamics of the game and the
 * update of the View as you go along.
 *
 */
class Controller {

private:
    View view_; /**<The view of the game */
    Game model_; /**<Represent the model of the game */

public:

    /*!
     * \brief Constructor.
     *
    */
    Controller() = default;

    /*!
     * \brief start the game.
     */
    void start();

private :

    /*!
     * \brief The game is on. Display the game header.
     */
    void printGame();

    /*!
     * \brief ask for the names of the players.
     */
    void askNames();

    /*!
     * Check if among the given positions, there are some that are equal.
     *
     * \param position the given positions.
     * \return true if there are two equal positions otherwise false.
     */
    bool checkIfIsSamePos(std::vector<int> const& position) const;

    /*!
     * \brief Displays the name of the loser and the winner.
     */
    void printWinnerLoser();
};

}

#endif // CONTROLLER_Hs
