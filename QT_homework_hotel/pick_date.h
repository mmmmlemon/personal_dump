#ifndef PICK_DATE_H
#define PICK_DATE_H

#include <QDialog>
#include <QDate>

namespace Ui {
class pick_date;
}

class pick_date : public QDialog
{
    Q_OBJECT

public:
    explicit pick_date(QWidget *parent = 0);
    ~pick_date();

private:
    Ui::pick_date *ui;


signals:
    void sendDate(QDate date);
private slots:
    void on_buttonBox_accepted();
};

#endif // PICK_DATE_H
