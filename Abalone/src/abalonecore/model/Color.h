#ifndef COLOR_H
#define COLOR_H

#include <ostream>

/*!
 * Namespace of the Abalone project.
 */
namespace abalone {

/*!
 * Enum which represent the color of a marble.
 *
 */
enum Color{ BLACK,WHITE, NONE};


/*!
 * \brief Operator to inject a color into an output stream.
 *
 * The name of the color is injected in the flow.
 *
 * \param out flow in which the color is injected.
 * \param color color to be injected.
 *
 * \return flow after injection.
 */
inline std::ostream & operator<<(std::ostream & out, const Color color) {
    return out<<(color == BLACK ? "Black" : "White");
}

}
#endif // COLOR_H
