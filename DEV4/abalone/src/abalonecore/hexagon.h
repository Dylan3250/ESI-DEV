#ifndef HEXAGON_H
#define HEXAGON_H

#include "ball.h"
#include <memory>
#include <optional>
#include <iostream>

namespace abalone {
/**
* @brief The Hexagon class represents the hexagon box of the game.
* In the game there are 61 hexagons. A hexagon can have a ball or not.
*/
class Hexagon {
    std::optional <Ball> ball_;

public:
    /**
    * @brief Empty constructor of Hexagon.
    */
    Hexagon() : ball_{std::nullopt} {}
    /**
     * @brief Constructor of Hexagon.
     * @param ball contained in the hexagon
     */
    Hexagon(Ball ball) : ball_{ball} {}

    /**
    * @brief Getter of Hexagon.
    * @return the ball contained in the hexagon
    */
    constexpr std::optional <Ball> &ball() {
        return ball_;
    }

    /**
    * @brief Setter of Hexagon.
    * @param the given ball
    */
    constexpr void ball(std::optional <Ball> &ball) {
        ball_ = ball;
    }
};

}
#endif // HEXAGON_H
