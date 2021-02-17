#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "winGenArtistLib.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
    ui->actionShowLib->activate(QAction::Trigger);
    ui->mainToolBar->hide();


    firstLaunch = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionShowLib_triggered()
{
    winGenArtistLib *winArtistLib = new winGenArtistLib();
    winArtistLib->setMainDir("test");

//    if(firstLaunch == true)
//    {
//        firstLaunch = false;
        winArtistLib->generateArtistLib();

//    }
//    else
//    {
//        //parse from xml(???)
//    }

    ui->mdiArea->addSubWindow(winArtistLib);
    winArtistLib->showMaximized();

}
