#include "maincalc.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainCalc w;
    w.show();
    return a.exec();
}
