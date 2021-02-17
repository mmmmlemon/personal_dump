#ifndef DATE_EDIT_H
#define DATE_EDIT_H

#include <QDialog>
#include <QDate>

namespace Ui {
class date_edit;
}

class date_edit : public QDialog
{
    Q_OBJECT

public:
    explicit date_edit(QWidget *parent = 0);
    ~date_edit();

private slots:
    void on_buttonBox_accepted();

    void on_month_currentIndexChanged(int index);

    void on_year_valueChanged(int arg1);

private:
    Ui::date_edit *ui;

signals:
    void sendDate(QDate date);

};

#endif // DATE_EDIT_H
