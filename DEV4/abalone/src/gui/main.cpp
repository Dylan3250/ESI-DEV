#include <QApplication>
#include "controller/controller.h"

int main(int argc, char * argv[]) {
    QApplication a(argc, argv);
    abalone::Game game{};
    View view{};
    abalone::Controller controller{game, view};
    controller.start();
    return a.exec();
}
