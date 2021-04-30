#ifndef MARBLE_H
#define MARBLE_H
#include "Color.h"
#include <string>


/*!
 * Namespace of the Abalone project.
 */
namespace  abalone
{

/*!
 * Marble of a color belonging to a player, placed on the game board.
 *
 */
class Marble
{

  private :

    /*!
     * Color of the marble.
     *
     */
    const Color color_ ;

  public :

    /*!
     * \brief Constructor.
     */
    inline Marble();

    /*!
     * \brief Constructor.
     *
     * \param color color of the marble.
     *
     * \throw std::invalid_argument if color is null.
     */
    inline Marble(Color color);

    /*!
     * \brief Read accessor of the color.
     *
     */
    inline Color getColor() const
    {
        return this->color_;
    }

};

/*
 * @pbt be more consistent when writing code.
 * either you write inline method after bloc or you write in
 * class bloc. don't mix.
 * */

Marble::Marble(Color color) :
    color_ {color}
{}

}


#endif // MARBLE_H
