#include "mycalculator.h"
#include <QApplication>
#include <QtWidgets>
#include <QMap>
#include <map>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyCaclulator sd;
    sd.show();
    return a.exec();
}
