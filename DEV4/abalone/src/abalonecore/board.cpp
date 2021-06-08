#include "board.h"
#include <optional>
#include <stdexcept>
#include <string>

namespace abalone {
Board::Board() :
    board_{{
{std::nullopt, std::nullopt, std::nullopt, std::nullopt, Hexagon(Ball{2, Color::WHITE}), Hexagon(Ball{2, Color::WHITE}), Hexagon(), Hexagon(Ball{1, Color::BLACK}), Hexagon(Ball{1, Color::BLACK})},
{std::nullopt, std::nullopt, std::nullopt, Hexagon(Ball{2, Color::WHITE}), Hexagon(Ball{2, Color::WHITE}), Hexagon(Ball{2, Color::WHITE}), Hexagon(Ball{1, Color::BLACK}), Hexagon(Ball{1, Color::BLACK}), Hexagon(Ball{1, Color::BLACK})},
{std::nullopt, std::nullopt, Hexagon(), Hexagon(Ball{2, Color::WHITE}), Hexagon(Ball{2, Color::WHITE}), Hexagon(), Hexagon(Ball{1, Color::BLACK}), Hexagon(Ball{1, Color::BLACK}), Hexagon()},
{std::nullopt, Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon()},
{Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon()},
{Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon(), Hexagon(), std::nullopt},
{Hexagon(), Hexagon(Ball{1, Color::BLACK}), Hexagon(Ball{1, Color::BLACK}), Hexagon(), Hexagon(Ball{2, Color::WHITE}), Hexagon(Ball{2, Color::WHITE}), Hexagon(), std::nullopt, std::nullopt},
{Hexagon(Ball{1, Color::BLACK}), Hexagon(Ball{1, Color::BLACK}), Hexagon(Ball{1, Color::BLACK}), Hexagon(Ball{2, Color::WHITE}), Hexagon(Ball{2, Color::WHITE}), Hexagon(Ball{2, Color::WHITE}), std::nullopt, std::nullopt, std::nullopt},
{Hexagon(Ball{1, Color::BLACK}), Hexagon(Ball{1, Color::BLACK}), Hexagon(), Hexagon(Ball{2, Color::WHITE}), Hexagon(Ball{2, Color::WHITE}), std::nullopt, std::nullopt, std::nullopt, std::nullopt}}}
{}

ActionStatus Board::moveLateral(Position posStarted,
                                Position posDestination,
                                Position posLateral) {
    if (!at(posStarted)->ball()) {
        throw std::invalid_argument("Any ball on the started position.");
    }

    // WEST | EST
    std::array<Position, 8> directions{Position{1, 0}, Position{-1, 0},
                                       Position{0, -1}, Position{0, 1},
                                       Position{-1, -1}, Position{-1, 1},
                                       Position{1, 1}, Position{1, -1}};

    Position posDirectionLine{0, 0};
    // Defines the direction of movement or returns the error
    // if the given positions are not valid
    for (unsigned i = 0; i < (int) directions.size(); i++) {
        // Copy to advance without touching the given actual position
        Position posStartedCheck{posStarted};
        posStartedCheck.next(directions.at(i));
        if (posStartedCheck != posDestination) {
            posStartedCheck.next(directions.at(i));
            if (posStartedCheck != posDestination) {
                if (i != directions.size() - 1) {
                    continue;
                }
                throw std::invalid_argument("The coordinate between the two ball"
                                            " to lateral move is not valid.");
            }
        }
        posDirectionLine = directions.at(i);
        break;
    }

    // Checks the lateral coordinate is valid.
    Position posDirectionLateral = direction(posStarted, posLateral);
    if (posDirectionLateral != Position{-1, 0} // NORTH
            && posDirectionLateral != Position{-1, 1} // NORTH EST
            && posDirectionLateral != Position{-1, -1} // NORTH WEST
            && posDirectionLateral != Position{1, 0} // SOUTH
            && posDirectionLateral != Position{1, -1} // SOUTH WEST
            && posDirectionLateral != Position{1, 1}) { // SOUTH EST

        throw std::invalid_argument("The ABA-PRO coordinate for lateral "
                                    "movement is not valid.");
    }

    Position posStartedCheck{posStarted};
    Position posStartedCheckLateral{posStartedCheck};
    Position lateralEnd{posDestination};
    lateralEnd.next(posDirectionLateral);
    // Checks that there were no enemy balls in the next positions,
    // in the line position or that the lateral position is not out.
    while (lateralEnd != posStartedCheckLateral) {
        posStartedCheckLateral = posStartedCheck;
        posStartedCheckLateral.next(posDirectionLateral);

        if (!(isInside(posStartedCheck) && isInside(posStartedCheckLateral)
              && at(posStartedCheck)->ball()
              && at(posStartedCheck)->ball()->color() == at(posStarted)->ball()->color()
              && !at(posStartedCheckLateral)->ball())) {
            return ActionStatus::BLOCKED;
        }
        posStartedCheck.next(posDirectionLine);
    }

    posStartedCheck = posStarted;
    posStartedCheckLateral = posStartedCheck;
    lateralEnd = posDestination;
    lateralEnd.next(posDirectionLateral);
    // Makes the moves
    std::optional <Ball> nullBall = std::nullopt;
    while (lateralEnd != posStartedCheckLateral) {
        posStartedCheckLateral = posStartedCheck;
        posStartedCheckLateral.next(posDirectionLateral);
        editBall(at(posStartedCheckLateral), at(posStartedCheck)->ball());
        editBall(at(posStartedCheck), nullBall);
        posStartedCheck.next(posDirectionLine);
    }
    return ActionStatus::MOVED;
}

ActionStatus Board::moveLine(Position posStarted, Position posAdjacent) {
    if (!at(posStarted)->ball()) {
        throw std::invalid_argument("Any ball on the started position.");
    }
    Position posDirection = direction(posStarted, posAdjacent);
    Color colorStarted = at(posStarted)->ball()->color();
    Position posNext{posStarted};
    int sameColor = 1;
    int otherColor = 0;
    while (at(posNext)->ball()) {
        posNext.next(posDirection);
        if (!isInside(posNext)) {
            break;
        }
        if (at(posNext)->ball()) {
            if (colorStarted == at(posNext)->ball()->color() && otherColor != 0) {
                return ActionStatus::BLOCKED;
            } else if (colorStarted == at(posNext)->ball()->color() && otherColor == 0) {
                sameColor++;
            } else {
                otherColor++;
            }
        } else {
            break;
        }
    }
    if (sameColor > 3 || sameColor <= otherColor) {
        return ActionStatus::BLOCKED;
    }

    std::optional <Ball> nullBall = std::nullopt;
    if (otherColor == 0) {
        if (!isInside(posNext)) {
            editBall(at(posStarted), nullBall);
            return ActionStatus::SELF_FALLEN;
        }

        editBall(at(posNext), at(posStarted)->ball());
        editBall(at(posStarted), nullBall);
        return ActionStatus::MOVED;

    } else {
        Position adversePos{posStarted};
        for (int i = 0; i < sameColor; i++) {
            adversePos.next(posDirection);
        }

        if (!isInside(posNext)) {
            editBall(at(adversePos), at(posStarted)->ball());
            editBall(at(posStarted), nullBall);
            return ActionStatus::FALLEN;
        } else {
            Position posNextNext{posNext};
            posNextNext.next(posDirection);
            if (isInside(posNextNext) && at(posNextNext)->ball()
                    && at(posNextNext)->ball()->color() == colorStarted
                    && sameColor < otherColor) {
                return ActionStatus::BLOCKED;
            } else {
                editBall(at(posNext), at(adversePos)->ball());
                editBall(at(adversePos), at(posStarted)->ball());
                editBall(at(posStarted), nullBall);
            }
        }
        return ActionStatus::PUSHED;
    }
}


Position Board::convertABAToCoord(const std::string &ABACoord) {
    if (ABACoord.size() > 2) {
        throw std::invalid_argument(
                    "The ABA-PRO coordinate cannot be greater than 2.");
    }
    char letter{ABACoord[0]};
    int digit{std::stoi(std::string(1, ABACoord[1]))};
    if (isNotValidAbaPro(ABACoord)
            || isNotValidFirstLetter(letter)
            || digit == 0) {
        throw std::invalid_argument("The ABA-PRO coordinate is not valid.");
    }
    digit -= 1;
    switch (letter) {
    case 'I':
        return Position{0, digit};
    case 'H':
        return Position{1, digit};
    case 'G':
        return Position{2, digit};
    case 'F':
        return Position{3, digit};
    case 'E':
        return Position{4, digit};
    case 'D':
        return Position{5, digit};
    case 'C':
        return Position{6, digit};
    case 'B':
        return Position{7, digit};
    case 'A':
        return Position{8, digit};
    default:
        throw std::invalid_argument("ABA-PRO invalid coordinate");
    }
}

bool Board::isNotValidFirstLetter(const char &firstLetter) {
    return firstLetter != 'A'
            && firstLetter != 'B'
            && firstLetter != 'C'
            && firstLetter != 'D'
            && firstLetter != 'E'
            && firstLetter != 'F'
            && firstLetter != 'G'
            && firstLetter != 'I'
            && firstLetter != 'H';
}

bool Board::isNotValidAbaPro(const std::string &ABACoord) {
    return ABACoord == "I1" || ABACoord == "I2" || ABACoord == "I3" || ABACoord == "I4"
            || ABACoord == "H1" || ABACoord == "H2" || ABACoord == "H3"
            || ABACoord == "G1" || ABACoord == "G2"
            || ABACoord == "D9"
            || ABACoord == "C8" || ABACoord == "C9"
            || ABACoord == "F1"
            || ABACoord == "B7" || ABACoord == "B8" || ABACoord == "B9"
            || ABACoord == "A6" || ABACoord == "A7" || ABACoord == "A8" || ABACoord == "A9";
}

Position Board::direction(Position &firstCoord, Position &secondCoord) {
    if ((firstCoord.x() + 1 == secondCoord.x()) && (firstCoord.y() == secondCoord.y())) {
        return Position{1, 0}; // SOUTH
    } else if ((firstCoord.x() - 1 == secondCoord.x()) && (firstCoord.y() == secondCoord.y())) {
        return Position{-1, 0}; // NORTH
    } else if ((firstCoord.x() == secondCoord.x()) && (firstCoord.y() - 1 == secondCoord.y())) {
        return Position{0, -1}; // WEST
    } else if ((firstCoord.x() == secondCoord.x()) && (firstCoord.y() + 1 == secondCoord.y())) {
        return Position{0, 1}; // EST
    } else if ((firstCoord.x() - 1 == secondCoord.x()) && (firstCoord.y() - 1 == secondCoord.y())) {
        return Position{-1, -1}; // NORTH WEST
    } else if ((firstCoord.x() - 1 == secondCoord.x()) && (firstCoord.y() + 1 == secondCoord.y())) {
        return Position{-1, 1}; // NORTH EST
    } else if ((firstCoord.x() + 1 == secondCoord.x()) && (firstCoord.y() + 1 == secondCoord.y())) {
        return Position{1, 1}; // SOUTH EST
    } else if ((firstCoord.x() + 1 == secondCoord.x()) && (firstCoord.y() - 1 == secondCoord.y())) {
        return Position{1, -1}; // SOUTH WEST
    }
    throw std::invalid_argument("Bad movement to make displacement.");
}
}

