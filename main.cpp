#include <QApplication>
#include "SMainWindow/SMainWindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SMainWindow w;
    w.show();


    return a.exec();
}
