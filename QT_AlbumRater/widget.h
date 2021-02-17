#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include <QSqlTableModel>
#include <QStateMachine>


namespace Ui {
    class Widget;
}


//class desc
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();



private:
    Ui::Widget *ui;

    QSqlTableModel *model;
    QSqlQueryModel *mdl;
    QSqlQueryModel *mdl_art;
    QSqlQueryModel *mdl_yr;
    QSqlQueryModel *mdl_rt;

     //QGraphicsOpacityEffect *graf;



private slots:
    void on_pushButton_clicked();
    void on_checkBox_clicked();
    void on_showArtistsButton_clicked();
    void on_showRating_clicked();
    void on_showYear_clicked();
    void on_comboBox_currentIndexChanged(QString );
    void on_queryButton_clicked();
    void on_removeButton_clicked();
    void on_addButton_clicked();

};

#endif // WIDGET_H
