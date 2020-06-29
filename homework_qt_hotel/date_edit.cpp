#include "date_edit.h"
#include "ui_date_edit.h"
#include "mainwin.h"
#include <QDebug>
#include <QMessageBox>

date_edit::date_edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::date_edit)
{
    ui->setupUi(this);
}

date_edit::~date_edit()
{
    delete ui;
}

void date_edit::on_buttonBox_accepted()
{

    QDate date;

    if (date.setDate(ui->year->text().toInt(),
                 ui->month->currentIndex() + 1,
                 ui->day->text().toInt()))
    {
        emit sendDate(date);
    }

    else
    {
         QMessageBox::warning(this, "Внимание", "Не корректная дата");
    }

}



void date_edit::on_month_currentIndexChanged(int index)
{
    QDate month;
    month.setDate(ui->year->text().toInt(),index+1,1);
    ui->day->setMaximum(month.daysInMonth());
}

void date_edit::on_year_valueChanged(int arg1)
{
    QDate month;
    month.setDate(ui->year->text().toInt(),ui->month->currentIndex()+1,1);
    ui->day->setMaximum(month.daysInMonth());
}
