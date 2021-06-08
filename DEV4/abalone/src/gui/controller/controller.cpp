#include "controller.h"

namespace abalone {

void Controller::start() {
    view_.show();
    view_.controller(this);
}

void Controller::makeAction(std::vector<std::string> &positionsClicked) {
    std::vector<abalone::Position> ABACoords;
    abalone::ActionStatus resultMove;
    std::string coords{};

    for (const auto &value : positionsClicked) {
        coords.append(value);
    }

    if (coords.size() != 4 && coords.size() != 6) {
        view_.defineLabel(NOT_POSSIBLE_DISPLACMENT);
        return;
    }

    for (size_t i = 0; i < coords.size(); i += 2) {
        std::string currentMove = coords.substr(i, 2);
        ABACoords.push_back(game_.convertABAToCoord(currentMove));
    }

    try {
        resultMove = game_.move(ABACoords);
        if (resultMove == abalone::ActionStatus::BLOCKED) {
            view_.defineLabel(BLOCKED);
            view_.updateEnd(game_.isEnd());
            return;
        }
    } catch (const std::exception &e) {
        view_.defineLabel(NOT_DISPLACEMENT_CHECK_COORD);
        return;
    }

    if (resultMove == abalone::ActionStatus::SELF_FALLEN) {
        game_.currentPlayer().decreaseNbBall();
    }
    game_.togglePlayer();

    if (resultMove == abalone::ActionStatus::FALLEN) {
        game_.currentPlayer().decreaseNbBall();
    }
    game_.addMoves();

    view_.updateInfoPlayer(game_.players().at(0),
                           game_.nbMaxBall() - game_.players().at(1).nbBall());
    view_.updateInfoPlayer(game_.players().at(1),
                           game_.nbMaxBall() - game_.players().at(0).nbBall());
    view_.selectCurrentPlayer(game_.currentPlayer().id());

    view_.updateEnd(game_.isEnd());
}
}
