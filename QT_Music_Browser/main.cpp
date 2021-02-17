#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <locale>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();

    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
     QTextCodec::codecForUtfText("UTF-8");

       //setlocale(LC_ALL,"");

    w->show();

    return a.exec();
}
