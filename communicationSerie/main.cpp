#include "cportserie.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CPortSerie w;
    w.show();

    return a.exec();
}
