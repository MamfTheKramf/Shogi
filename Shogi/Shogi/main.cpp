#include "MainWindow.h"

#include <QApplication>

void runTests();

int main(int argc, char *argv[])
{
    runTests();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
