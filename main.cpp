#include "mainwindow.h"
#include <QApplication>
#include <loadmaterial.h>


int main(int argc, char *argv[])
{
    LoadMaterial loca;
    loca.loadObject();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
