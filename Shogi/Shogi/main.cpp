#include "MainWindow.h"
#include "Board.h"

#include <QApplication>

void runTests();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    runTests();


    Board b(nullptr);
    b.show();
    return a.exec();
}
