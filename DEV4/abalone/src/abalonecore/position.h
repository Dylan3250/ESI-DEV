#ifndef POSITION_H
#define POSITION_H

#include <string>
#include <stdexcept>

namespace abalone {
/**
* @brief The position class represents the coordinates of a hexagon box.
*/
class Position {
    int x_;
    int y_;

public:
    /**
    * @brief Constructor of Position.
    * @param the given position x
    * @param the given position y
    */
    Position(int x, int y) : x_{x}, y_{y} {
        if (x < -1 || y < -1 || x > 9 || y > 9) {
            throw std::invalid_argument(
                        "Position is out of array : x "
                        + std::to_string(x) + " y " + std::to_string(y));
        }
    }

    /**
    * @brief Getter of X.
    * @return the position x
    */
    constexpr int x() const {
        return x_;
    }

    /**
    * @brief Getter of Y.
    * @return the position y
    */
    constexpr int y() const {
        return y_;
    }

    /**
     * @brief Gives the next Position according to direction.
     * @param posDelta the given position
     */
    inline void next(Position &posDelta) {
        y_ += posDelta.y();
        x_ += posDelta.x();
    }
};

/**
 * @brief operator == Defines the equality operator between two positions.
 * @param pos1 first given position
 * @param pos2 second given position
 * @return true if two position are same, false otherwise.
 */
constexpr bool operator==(const Position &pos1, const Position &pos2) {
    return pos1.x() == pos2.x() && pos1.y() == pos2.y();
}

/**
 * @brief operator != Defines the different operator between two positions.
 * @param pos1 first given position
 * @param pos2 second given position
 * @return true if two positions are not same, false otherwise.
 */
constexpr bool operator!=(const Position &pos1, const Position &pos2) {
    return pos1.x() != pos2.x() || pos1.y() != pos2.y();
}

}
#endif // POSITION_H
