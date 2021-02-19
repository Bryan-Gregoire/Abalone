#ifndef MARBLE_H
#define MARBLE_H
#include "color.h"

/*!
 * Namespace of the Abalone project.
 */
namespace  abalone{

/*!
 * Marble of a color belonging to a player, placed on the game board.
 *
 */
class Marble{

private :

    /*!
     * Color of the marble.
     *
     */
    const Color color ;

public :

    /*!
     * \brief Constructor.
     *
     * \param color color of the marble.
     *
     * \throw std::invalid_argument if color is null.
     */
    Marble(Color color);

    /*!
     * \brief Read accessor of the color.
     *
     */
    inline Color getColor() const;

    Color getColor() {
        return this->color;
    }
};

}


#endif // MARBLE_H
