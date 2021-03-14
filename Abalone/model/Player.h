#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerStatus.h"
#include "Color.h"
#include <iostream>

/*!
 * Namespace of the Abalone project.
 */
namespace  abalone{

/*!
 * Represent a player of the game.
 *
 */
class Player {

private :

    /*!
     * Number of marble he owns in the game.
     *
     */
    int nbMarble_ = 14;

    /*!
     * The state of the player in the game.
     *
     */
    PlayerStatus playerStatus_ = IN_GAME;

    /*!
     * The color of the marbles.
     *
     * One color for all the marbles.
     */
    const Color color_;

public :

    /*!
     * \brief Constructor.
     *
     * \param color color of the marbles.
     *
     * \throw std::invalid_argument if color is null.
     */
    inline Player(Color & color):
        color_ { color }
    {}

    /*!
     * Check if the player has lost.
     *
     */
    inline bool isLost() const {
        return this->nbMarble_ <= 8;
    }

    /*!
     * \brief Read Accessor of the color.
     *
     */
    inline Color getColor() const{
        return this->color_;
    }

    /*!
     * @brief Write accessor of the marble.
     *
     * @param status the given status.
     */
    inline void setPlayerStatus(PlayerStatus  status) {
        this->playerStatus_ = status;
    }

};

}

#endif // PLAYER_H
