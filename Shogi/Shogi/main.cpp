#include "MainWindow.h"
#include "Board.h"

#include <QApplication>

void runTests();

int main(int argc, char *argv[])
{
    runTests();

    QApplication a(argc, argv);
    Board b(nullptr);
    b.show();
    return a.exec();
}
