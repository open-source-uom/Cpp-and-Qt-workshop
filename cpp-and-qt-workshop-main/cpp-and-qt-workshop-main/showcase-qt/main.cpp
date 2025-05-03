#include <iostream>
#include <QApplication>

#include "mainwindow.h"


int main(int argc, char *argv[]) {
    qsrand(time(0));

    QApplication app(argc, argv);

    MainWindow window;

    app.exec();
}

