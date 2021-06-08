#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "hexagon.h"
#include "position.h"
#include "actionStatus.h"
#include <vector>
#include <array>
#include <optional>

namespace abalone {
/**
* @brief The Board class represents the game board which has a specific length
* and is a board of 61 hexagons.
*/
class Board {
    std::array<std::array<std::optional < abalone::Hexagon>, 9>, 9>
    board_;

    /**
     * @brief Checks if the given position are inside of the board.
     * @param pos the given position
     * @return true if the given position are inside of the board, false otherwise.
     */
    inline bool isInside(Position &pos) {
        auto x = static_cast<size_t>(pos.x());
        auto y = static_cast<size_t>(pos.y());

        return y < board_.size()
                && pos.y() >= 0
                && x < board_.size()
                && pos.x() >= 0
                && board_[x][y] != std::nullopt;
    }

    /**
    * @brief Checks if the first letter of the ABA-PRO coordinate given
    * in parameter is valid.
    * @return true if the first letter of the ABA-PRO coordinate is valid,
    * false otherwise.
    */
    bool isNotValidFirstLetter(const char &);

    /**
    * @brief Checks if the ABA-PRO coordinate given as a parameter is exists.
    * @return true if the ABA-PRO coordinate is exists, false otherwise
    */
    bool isNotValidAbaPro(const std::string &);

public:
    /**
    * @brief Empty constructor of Board.
    */
    Board();

    /**
    * @brief The getter of board.
    * @return the board of hexagon
    */
    constexpr std::array<std::array<std::optional < Hexagon>, 9>, 9> &
    /**
     * Getter of board.
     */
    board() {
        return board_;
    }

    /**
    * @brief The getter hexagon with coordinates of board.
    * @return the hexagon on given coordinates
    */
    constexpr std::optional <Hexagon> &at(size_t x, size_t y) {
        return board_.at(x).at(y);
    }
    /**
     * @brief Gives the hexagon with coordinate of the position.
     * @param the given position
     * @return the hexagon with coordinate of the position
     */
    inline std::optional <Hexagon> &at(Position &pos) {
        return board_.at(pos.x()).at(pos.y());
    }

    /**
    * @brief Edits the ball in a hexagon.
    * @param hex the hexagon box of board
    * @param ball the ball contained in the hexagon
    */
    inline void editBall(std::optional <Hexagon> &hex,
                         std::optional <Ball> &ballToEdit) {
        hex->ball(ballToEdit);
    }

    /**
    * @brief Literally moves the ball according to the starting position of the given
    * and the destination position of the given.
    * @param posStarted the starting position of the ball
    * @param posDestination the destination position of the ball
    * @param posLateral the lateral position you want to move
    * @return the actionStatus of the movement
    */
    ActionStatus moveLateral(Position, Position, Position);

    /**
    * @brief Moves the ball linearly according to the starting position of the given ball
    * and the destination position of the given ball.
    * @param PosDepart the starting position of the ball
    * @param PosDestination the destination position of the ball
    * @return the actionStatus of the movement
    */
    ActionStatus moveLine(Position, Position);

    /**
    * @brief Converts ABA-PRO notation to array position (x,y).
    * @param ABACoord ABA-PRO notation
    * @return the array position converted
    */
    Position convertABAToCoord(const std::string &);

    /**
    * Gives the position of the movement given as a parameter.
    * @param represents the coordinates in ABA-PRO
    * @return the position of the movement given as a parameter
    */
    Position direction(Position &, Position &);
};

}
#endif // BOARD_H
