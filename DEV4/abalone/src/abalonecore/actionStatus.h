#ifndef ACTIONSTATUS_H
#define ACTIONSTATUS_H

namespace abalone {
/**
* @brief The ActionStatus enum represents the status of the movement made.
*/

enum class ActionStatus {
    MOVED, FALLEN, SELF_FALLEN, PUSHED, BLOCKED, NOT_STARTED
};

}

#endif // ACTIONSTATUS_H
