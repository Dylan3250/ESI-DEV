#ifndef MODEL_H
#define MODEL_H

#include "player.h"
#include "board.h"
#include "player.h"
#include "gameStatus.h"
#include "utils/observable.h"

namespace abalone {
/**
* @brief The Model class is an interface for the Game class and is
* used like an Observable object.
*/
class Model : public pbt::utils::Observable {

public:
    inline static const std::string PROPERTY_ACTIONSTATUS{"ActionStatus"};
    inline static const std::string PROPERTY_BOARD{"Board"};
    inline static const std::string PROPERTY_ENDGAME{"End"};

    /**
    * @brief Empty constructor of game.
    */
    virtual ~Model() = default;

    /**
    * @brief Getter of current player.
    * @return the current player
    */
    virtual Player &currentPlayer() = 0;

    /**
     * @brief Getter of nbMaxBall.
     * @return max ball in the game
     */
    virtual int nbMaxBall() const = 0;

    /**
    * @brief Switches the Player to play.
    */
    virtual void togglePlayer() = 0;

    /**
    * @brief Getter of board.
    * @return the board of the game
    */

    virtual Board &board() = 0;
    /**
     * @brief Getter of players.
     * @return the players of the game
     */
    virtual std::array<Player, 2> &players() = 0;

    /**
    * @brief Getter of gameStatus.
    * @return gameStatus of the game
    */
    virtual GameStatus gameStatus() const = 0;

    /**
     * @brief Getter of lastActionStatus.
     * @return lastActionStatus of the game
     */
    virtual ActionStatus lastActionStatus() const = 0;

    /**
    * @brief Setter of gameStatus.
    * @param gameStatus the given gameStatus
    */
    virtual void gameStatus(GameStatus gameStatus) = 0;

    /**
    * @brief Getter the total number of movements.
    * @return the total number of movements
    */
    virtual unsigned totalMoves() const = 0;

    /**
    * @brief Adds a movement.
    */
    virtual void addMoves() = 0;

    /**
    * @brief Checks if the game is over. The game is over when a player
    * has successfully pushed 6 balls
    * from the opposing player and if the gameStatus is finish.
    * @return true if the game is over, false otherwise
    */
    virtual bool isEnd() = 0;

    /**
    * @brief Moves the ball according to the starting position of the given ball
    * and the destination position of the given ball.
    * @param Positions list of position, if 3 it will be lateral movement,
    * 2 line movement and throws exception otherwise
    * @return the actionStatus of the movement
    */
    virtual ActionStatus move(std::vector <Position> positions) = 0;

    /**
    * @brief Converts ABA-PRO notation to array position (x,y).
    * @param ABACoord ABA-PRO notation
    * @return the array position converted
    */
    virtual Position convertABAToCoord(std::string ABACoord) = 0;
};

}

#endif // MODEL_H
