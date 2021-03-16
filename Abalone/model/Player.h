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
    int nbMarble_;

    /*!
     * The state of the player in the game.
     *
     */
    PlayerStatus playerStatus_;

    /*!
     * The color of the marbles.
     *
     * One color for all the marbles.
     */
    const Color color_;

    std::string name_;

public :

    Player();

    /*!
     * \brief Constructor.
     *
     * \param color color of the marbles.
     *
     * \throw std::invalid_argument if color is null.
     */
    inline Player(Color  color):
        nbMarble_{14},
        playerStatus_{IN_GAME},
        color_ { color }
    {}

    inline int getNbMarbles() const{
        return this->nbMarble_;
    }

    inline PlayerStatus getPlayerStatus() const {
        return this->playerStatus_;
    }
    /*!
     * \brief Read Accessor of the color.
     *
     */
    inline Color getColor() const{
        return this->color_;
    }

    inline std::string getName() const{
        return this->name_;
    }

    /*!
     * @brief Write accessor of the marble.
     *
     * @param status the given status.
     */
    inline void setPlayerStatus(PlayerStatus  status) {
        this->playerStatus_ = status;
    }

    inline void setNbMarble(int nbMarbles){
        this->nbMarble_=nbMarbles;
    }

    /*!
     * @brief Write accessor of the name of the player.
     *
     * @param status the given name.
     */
    inline void setName(std::string name) {
        this->name_ = name;
    }

    /*!
     * Check if the player has lost.
     *
     */
    inline bool isLost() const {
        return this->nbMarble_ <= 8;
    }
};

}

#endif // PLAYER_H
