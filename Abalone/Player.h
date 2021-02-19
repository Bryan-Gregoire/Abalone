#ifndef PLAYER_H
#define PLAYER_H
#include"playerStatus.h"
#include"color.h"

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
    int nbMarble =14;

    /*!
     * The state of the player in the game.
     *
     */
    PlayerStatus playerStatus = IN_GAME;

    /*!
     * The color of the marbles.
     *
     * One color for all the marbles.
     */
    const Color color;

public :

    /*!
     * \brief Constructor.
     *
     * \param color color of the marbles.
     *
     * \throw std::invalid_argument if color is null.
     */
    Player(Color color);

    /*!
     * Check if the player has lost.
     *
     */
    inline bool isLost();

    /*!
     * \brief Read Accessor of the color.
     *
     */
    inline Color getColor() const;

    Color getColor() {
        return this->color;
    }
};

}
#endif // PLAYER_H
