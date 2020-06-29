#include "mainwin.h"
#include <QApplication>
#include <QMessageBox>
#include <QSplashScreen>
#include "connect.h"


int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    QApplication::setStyle("Fusion");

    if(!connect()) {

        QMessageBox::critical(0, "ААААААААААА", "ААААААААААААА");

        return 1;

    }





    MainWin w;

    w.show();

    return a.exec();
}
