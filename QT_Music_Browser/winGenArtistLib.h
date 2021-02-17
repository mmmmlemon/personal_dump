#ifndef WINGENARTISTLIB_H
#define WINGENARTISTLIB_H

#include <QWidget>
#include <QStringList>
#include <QDir>

namespace Ui {
class winGenArtistLib;
}

class winGenArtistLib : public QWidget
{
    Q_OBJECT

public:
    explicit winGenArtistLib(QWidget *parent = 0);
    ~winGenArtistLib();

    //FIELDS


    //METHODS
    //генерит список всех исполнителей
    void generateArtistList();

    //отрисовывает библиотеку с артистами в виде виджетов
    void generateArtistLib();

    //устанавливает папку с музыкой, mainDir
    void setMainDir(QString mainDir_path);

    //возвращает папку с музыкой, mainDir
    QString getMainDir();

private:
    Ui::winGenArtistLib *ui;

    //FIELDS
    //список всех файлов песен, на основе которого составляется библиотека
    QStringList songList;
    //список всех исполнителей и жанров, относящихся к исполнителю
    QStringList libList;

    //главный каталог с музыкой
    QDir mainDir;

    //METHODS
    //просканировать все папки и подпапки в каталоге с музыкой и составить список файлов
    void getAllFilesFromMainDir(QDir dir);

};

#endif // WINGENARTISTLIB_H
