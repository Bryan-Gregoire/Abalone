#ifndef HEXAGONE_H
#define HEXAGONE_H
#include <optional>
#include "Marble.h"

/*!
 * Namespace of the Abalone project.
 */
namespace  abalone{

/*!
 * Hexagone on the board.
 *
 */
class Hexagone{

private :

    /*!
     * One marble of one color.
     *
     */
    std::optional<Marble> marble_;

public :

    /*!
     * \brief Constructor.
     *
     * Does not contain a marble.
     *
     */
    inline Hexagone();

    /*!
     * \brief Constructor.
     *
     * Contains a marble.
     *
     * \param marble cannot be null and represents only one marble.
     */
    inline Hexagone(Marble marble);

    /*!
     * \brief Read accessor of the marble.
     *
     */
    inline  std::optional<Marble> &getMarble() const;


    /*!
     * \brief Write accessor of the marble.
     *
     */
    void setMarble(Marble & marble){
            if(!marble_.has_value()) {
                marble_.emplace(marble);
            } else {
                throw std::invalid_argument("Paramètre ne peut être vide");
            }
        }
    std::optional<Marble> &getMarble() {
        return marble_;
    }
};

Hexagone::Hexagone(Marble marble) :
    marble_ { marble }
{
    if(!marble_.has_value()) {
        throw std::invalid_argument("Paramètre ne peut être vide");
    }
}

Hexagone::Hexagone() :
    marble_ { std::nullopt }
{}


}
#endif // HEXAGONE_H
