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
enum Color{ BLACK,WHITE };

inline std::ostream & operator<<(std::ostream & out, const Color color) {
    return out<<(color == BLACK ? "Black" : "White");
}

}
#endif // COLOR_H
