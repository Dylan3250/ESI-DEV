#ifndef PLAYER_H
#define PLAYER_H

#include <string>

namespace abalone {
/**
* @brief The Player class represents the players of the game.
* The player is characterized by his unique id,
* his name and the number of balls he owns.
*/
class Player {
    const unsigned id_;
    std::string name_;
    int nbBall_;

public:
    /**
    * @brief Constructor of Player.
    * @param id of Player
    * @param name of Player
    */
    Player(unsigned id) :
        id_{id}, name_{}, nbBall_{14} {}

    /**
     * @brief Constructor of Player.
     * @param player of the game
     */
    Player(Player &player) :
        id_{player.id()}, name_{player.name()}, nbBall_{player.nbBall()} {}

    /**
    * @brief Getter of Player's id.
    * @return id of Player
    */
    constexpr unsigned id() const {
        return id_;
    }

    /**
    * @brief Setter of Player's name.
    * @return name of Player
    */
    inline void name(std::string name) {
        name_ = name;
    }

    /**
    * @brief Getter of Player's name.
    * @return name of Player
    */
    constexpr std::string &name() {
        return name_;
    }

    /**
    * @brief Getter of the number of ball of Player.
    * @return the number of balls he owns
    */
    constexpr int nbBall() const {
        return nbBall_;
    }

    /**
    * @brief Decreases the balls the player has.
    */
    constexpr void decreaseNbBall() {
        nbBall_--;
    }
};

}

#endif // PLAYER_H
