#include <QApplication>
#include "SMainWindow/SMainWindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SMainWindow w;
    w.show();

    //QNChatMessage m;
    //QString msg = "hello wrold888888888jkk8888888888888888888";
    //m.setText(msg, "12:30", QSize(120, 50), QNChatMessage::User_Type::User_Me);
    //m.fontRect(msg);
    //m.show();

    //QNChatMessage m1;
    //QString msg1 = "hello wrold888888888jkk8888888888888888888";
    //m1.setText(msg1, "12:30", QSize(120, 50), QNChatMessage::User_Type::User_Time);
    //m1.fontRect(msg1);
    //m1.show();


    return a.exec();
}
