#include "wArtist.h"

#include <QVBoxLayout>
#include <QLabel>

wArtist::wArtist(QWidget *parent) : QWidget(parent)
{
  QVBoxLayout *mainLayout =  new QVBoxLayout();
  QVBoxLayout *weegeeLayout =  new QVBoxLayout();
  QHBoxLayout *artist_img_lay = new QHBoxLayout();
  QHBoxLayout *genre_lay = new QHBoxLayout();

  weegee = new QWidget();
  mainLayout->addWidget(weegee);
  weegee->setLayout(weegeeLayout);


  artistName = new QLabel("artistName");
  artistName->setStyleSheet("font-size: 13pt;");
  genreListView = new QLabel("");
  genreList = new QStringList();

  weegeeLayout->addLayout(artist_img_lay);
  weegeeLayout->addLayout(genre_lay);
  artist_img_lay->addWidget(artistName);
  //addWidget(image)
  genre_lay->addWidget(genreListView);
  genre_lay->setAlignment(Qt::AlignRight);

  this->setLayout(mainLayout);
  weegee->show();

}

void wArtist::setArtistName(QString name)
{
    artistName->setText(name);
}

QString wArtist::getArtistName()
{
    return artistName->text();
}

void wArtist::addGenre(QStringList genres)
{
    genres.removeDuplicates();
    QString allGenres;
    allGenres.clear();

    for(int i = 0; i < genres.size(); i++)
    {
        allGenres += genres.value(i) + ", ";
    }

   allGenres.remove(allGenres.size()-2,2);

    genreListView->clear();
    genreListView->setText(allGenres);
}
