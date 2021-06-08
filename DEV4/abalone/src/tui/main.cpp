// #include "ball.h"
// #include "hexagon.h"
#include "controller/controller.h"

/**
 * @mainpage Abalone game
 *
 * @section intro_sec Introduction
 *
 * Project "Abalone" developed during the dev4 course by Akeche Chahed and
 * Bricar Dylan with Mr Bettens.
 *
 * @section rules_sec Rules of the game
 *
 * One player plays with white balls, the other with black balls. The object of
 * the game is to be the first to push 6 opposing balls out of the playing area
 * by pushing them with his own balls.<br>
 * Constraint : to be able to push opposing balls, the player's balls must
 * be larger than the opposing player's balls.<br>
 *
 * - Player 1 pushes with his two balls, a ball of the opposing player.
 * The movement will be OK
 * - Player 1 pushes with his two balls, two balls of the opposing player.
 * The movement will not be OK.
 **/

int main() {
    abalone::Game game{};
    abalone::View view{game};
    abalone::Controller controller{game, view};
    controller.start();
    return 0;
}
