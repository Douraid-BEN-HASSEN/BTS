#include "ccharlyrobot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CCharlyrobot w;
    w.show();

    return a.exec();
}
