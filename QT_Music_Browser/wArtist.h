#ifndef WARTIST_H
#define WARTIST_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

class wArtist : public QWidget
{
    Q_OBJECT
public:
    explicit wArtist(QWidget *parent = 0);

    //METHODS
    //задать имя исполнителя
    void setArtistName(QString name);
    //получить имя исполнителя
    QString getArtistName();

    //добавить жанр к исполнителю
    void addGenre(QStringList genres);

private:
    //FIELDS
    QWidget *weegee;
    //QLabel с именем исполинеля
    QLabel *artistName;
    //QLabel со списком жанров
    QLabel *genreListView;
    //список жанров
    QStringList *genreList;
};

#endif // WARTIST_H
