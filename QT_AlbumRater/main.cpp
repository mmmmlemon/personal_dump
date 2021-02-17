#include <QtWidgets/QApplication>
#include "widget.h"
#include <QtSql/QSqlDatabase>
#include <QtWidgets/QMessageBox>


//connect to database
bool connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("albums");

    return db.open();
}


//main function
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!connect())
        {
           QMessageBox::critical(0, "Whoops...", "Error connecting to database");
           return 1;
              }

    Widget w;
    w.show();

    return a.exec();
}
