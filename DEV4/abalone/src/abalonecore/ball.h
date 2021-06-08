#ifndef BALL_H
#define BALL_H

#include <stdexcept>

namespace abalone {
/**
* @brief The Color enum represents the color of the ball.
* The ball can be black (color of player 1) or white (color of opposing player)
*/
enum class Color {
    WHITE, BLACK
};

/**
* @brief The Ball class represents the player's ball.
* The ball is characterized by a color (black or white) and by the player's id.
*/
class Ball {
    unsigned playerId_;
    Color color_;

public:
    /**
    * @brief The constructor of Ball.
    * @param playerId the id of player's ball
    * @param color the color of player's ball
    */
    Ball(unsigned playerId, Color color) :
        playerId_{playerId}, color_{color} {
        if (playerId != 1 && playerId != 2) {
            throw std::invalid_argument("Invalid player Id (1 - 2)");
        }
    }

    /**
    * @brief Getter of ball Color.
    * @return the color of the player's ball
    */
    constexpr Color color() const {
        return color_;
    }

    /**
    * @brief Getter of Player id.
    */
    constexpr unsigned playerId() const {
        return playerId_;
    }
};

}

#endif // BALL_H
