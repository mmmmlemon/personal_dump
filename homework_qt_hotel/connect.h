#ifndef CONNECT_H
#define CONNECT_H

#include <QSqlDatabase>

bool connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setPort(3307);

    db.setUserName("root");
    db.setPassword("usbw");
    db.setDatabaseName("hotel");
    db.setDatabaseName("zhuravskiy_egor");

//сервер
//    db.setHostName("localhost");
//    db.setPort(3306);

//    db.setUserName("zhuravskiy_egor");
//    db.setPassword("bababuba");
//    db.setDatabaseName("zhuravskiy_egor");


    return db.open();
}

#endif // CONNECT_H
