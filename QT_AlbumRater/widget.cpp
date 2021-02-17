#include "widget.h"
#include "ui_widget.h"
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QDesktopWidget>
#include <QPropertyAnimation>
#include <QtWidgets/QGraphicsOpacityEffect>
#include <QtWidgets/QGraphicsBlurEffect>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
    //constructor
{
    ui->setupUi(this);

    //showing da stuff from da database
    model = new QSqlTableModel;
    model->setTable("albums");
    model->select();
    ui->tableView->setModel(model);

    //bandlist for main combobox
    mdl = new QSqlQueryModel;
    mdl->setQuery("SELECT DISTINCT(band) FROM albums");
    ui->comboBox->setModel(mdl);

    //bandlist for artists combo
    mdl_art = new QSqlQueryModel;
    mdl_art->setQuery("SELECT DISTINCT(band) FROM albums");
    ui->onlyArtistCombo->setModel(mdl_art);

    //yearlist for tear combo
    mdl_yr = new QSqlQueryModel;
    mdl_yr->setQuery("SELECT DISTINCT(year) FROM albums");
    ui->onlyYearCombo->setModel(mdl_yr);

    //ratinglist for rating combo
    mdl_rt = new QSqlQueryModel;
    mdl_rt->setQuery("SELECT DISTINCT(rating) FROM albums");
    ui->onlyRatingCombo->setModel(mdl_rt);

    //spinbox's max rating
    ui->ratingSpinBox->setMaximum(10);
    ui->ratingSpinBox->setSingleStep(0.5);

    //move window to center of da screen
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center();
    center.setX(center.x() - (this->width()/2));
    center.setY(center.y() - (this->height()/2));
    move(center);

   graf = new QGraphicsOpacityEffect();

    graf->setOpacity(0.3);

    ui->addButton->setGraphicsEffect(graf);

}

//i dunno what is dis
Widget::~Widget()
{
    delete ui;
}

//add new album
void Widget::on_addButton_clicked()
{
    //submit entry
    int row = 0;
    model->insertRows(row, 1);
    QModelIndex artist = model->index(row, 0);
    QModelIndex album = model->index(row, 1);
    QModelIndex year = model->index(row, 2);
    QModelIndex rating = model->index(row, 3);

    model->setData(artist, ui->lineArtist->text());
    model->setData(album, ui->lineAlbum->text());
    model->setData(year, ui->lineYear->text());
    model->setData(rating, ui->ratingSpinBox->text());

    model->submitAll();

    ui->lineArtist->setText("");
    ui->tableView->scrollToBottom();

    mdl = new QSqlQueryModel;
    mdl->setQuery("SELECT DISTINCT(band) FROM albums");
    ui->comboBox->setModel(mdl);
    mdl_art = new QSqlQueryModel;
    mdl_art->setQuery("SELECT DISTINCT(band) FROM albums");
    ui->onlyArtistCombo->setModel(mdl_art);
    mdl_yr = new QSqlQueryModel;
    mdl_yr->setQuery("SELECT DISTINCT(year) FROM albums");
    ui->onlyYearCombo->setModel(mdl_yr);
    mdl_rt = new QSqlQueryModel;
    mdl_rt->setQuery("SELECT DISTINCT(rating) FROM albums");
    ui->onlyRatingCombo->setModel(mdl_rt);


}


//remove album
void Widget::on_removeButton_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
           if (index.isValid())
           {
               int ret = QMessageBox::critical(this, "",
                                               tr("Are you sure?"),
                                               QMessageBox::Yes | QMessageBox::No,
                                               QMessageBox::No);

               if (ret == QMessageBox::Yes)

                   model->removeRow(index.row());
           }

           mdl = new QSqlQueryModel;
           mdl->setQuery("SELECT DISTINCT(band) FROM albums");
           ui->comboBox->setModel(mdl);
           mdl_art = new QSqlQueryModel;
           mdl_art->setQuery("SELECT DISTINCT(band) FROM albums");
           ui->onlyArtistCombo->setModel(mdl_art);
           mdl_yr = new QSqlQueryModel;
           mdl_yr->setQuery("SELECT DISTINCT(year) FROM albums");
           ui->onlyYearCombo->setModel(mdl_yr);
           mdl_rt = new QSqlQueryModel;
           mdl_rt->setQuery("SELECT DISTINCT(rating) FROM albums");
           ui->onlyRatingCombo->setModel(mdl_rt);
}

//find album (sql)
void Widget::on_queryButton_clicked()
{
    QSqlQueryModel *mdl = new QSqlQueryModel;

        mdl->setQuery(ui->queryLine->text());

        ui->tableView->setModel(mdl);

        if(ui->queryLine->text().isEmpty() != false)
        {
            QMessageBox msg;

            msg.setText("The query field is empty");
            msg.setInformativeText("Type something in, you moron");

            msg.setIcon(QMessageBox::Warning);

            msg.show();

            msg.exec();

}

    }


//select band form the list
void Widget::on_comboBox_currentIndexChanged(QString )
{
        ui->lineArtist->setText(ui->comboBox->currentText());
}


//year filter
void Widget::on_showYear_clicked()
{
    QSqlQueryModel *mdl = new QSqlQueryModel;

        mdl->setQuery("SELECT * FROM albums WHERE year = '" + ui->onlyYearCombo->currentText() + "'");

        ui->tableView->setModel(mdl);

}


//rating filter
void Widget::on_showRating_clicked()
{
    QSqlQueryModel *mdl = new QSqlQueryModel;

        mdl->setQuery("SELECT * FROM albums WHERE rating = '" + ui->onlyRatingCombo->currentText() + "'");

        ui->tableView->setModel(mdl);
}


//artists filter
void Widget::on_showArtistsButton_clicked()
{
    QSqlQueryModel *mdl = new QSqlQueryModel;

        mdl->setQuery("SELECT * FROM albums WHERE band = '" + ui->onlyArtistCombo->currentText() + "'");

        ui->tableView->setModel(mdl);
}

void Widget::on_checkBox_clicked()
{
    QPropertyAnimation* animation = new QPropertyAnimation(graf, "opacity");


    animation->setEasingCurve(QEasingCurve::InOutQuad);
     animation->setDuration(500);
     animation->setStartValue(0.01);
     animation->setEndValue(1.0);
     animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void Widget::on_pushButton_clicked()
{


        QPropertyAnimation* animation = new QPropertyAnimation(graf, "opacity");


        animation->setEasingCurve(QEasingCurve::InOutQuad);
         animation->setDuration(500);
         animation->setStartValue(0.01);
         animation->setEndValue(1.0);
         animation->start(QPropertyAnimation::DeleteWhenStopped);


}
