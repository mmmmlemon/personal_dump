#include "winGenArtistLib.h"
#include "ui_winGenArtistLib.h"

//TagLib
#include <tag.h>
#include <fileref.h>

//MusBrowser
#include "wArtist.h"

//Qt
#include <QLabel>
#include <QtDebug>

winGenArtistLib::winGenArtistLib(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winGenArtistLib)
{
    ui->setupUi(this);
}

winGenArtistLib::~winGenArtistLib()
{
    delete ui;
}

void winGenArtistLib::generateArtistLib()
{
    //songList = mainDir.entryList(QStringList("*.mp3"),QDir::Files);

    getAllFilesFromMainDir(mainDir);

    for (int i = 0; i < songList.size(); i++)
    {
        QString fileName = songList.value(i);

        TagLib::FileRef song(fileName.toStdString().c_str());

        std::string artistName = song.tag()->artist().toCString(true);

        libList.append(QString::fromStdString(artistName));

    }

    libList.removeDuplicates();
    libList.sort();

    for(int i = 0 ; i < libList.size(); i++)
    {
        QString currArtistName = libList.value(i);

        std::string genre;
        QStringList genres;

        for(int i = 0; i < songList.size(); i++)
        {
            QString fileName = songList.value(i);
            TagLib::FileRef currSong(fileName.toStdString().c_str());
            std::string artistName = currSong.tag()->artist().toCString();

            if (currArtistName.toStdString().c_str() == artistName)
            {
                genre = currSong.tag()->genre().toCString();
                genres.append(QString::fromStdString(genre));
            }

            else
            {
                //do nothing
            }
        }
        wArtist *art = new wArtist();
        art->setArtistName(currArtistName);
        art->addGenre(genres);
        ui->gridLayout->addWidget(art);
    }
}

void winGenArtistLib::setMainDir(QString mainDir_path)
{
    mainDir.setPath(mainDir_path);
}

QString winGenArtistLib::getMainDir()
{
    return mainDir.path();
}

void winGenArtistLib::getAllFilesFromMainDir(QDir dir)
{
    QApplication::processEvents();

    QStringList listFiles =
            dir.entryList(QStringList("*.mp3"),QDir::Files);

    foreach (QString file, listFiles) {
        songList.append(dir.absoluteFilePath(file));
    }

    QStringList listDir = dir.entryList(QDir::Dirs);
    foreach (QString subdir, listDir) {
        if (subdir == "." || subdir == "..") {
            continue;
        }

        getAllFilesFromMainDir(QDir(dir.absoluteFilePath(subdir)));
    }
}
