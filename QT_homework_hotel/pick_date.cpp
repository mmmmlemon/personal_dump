#include "pick_date.h"
#include "ui_pick_date.h"

pick_date::pick_date(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pick_date)
{
    ui->setupUi(this);
}

pick_date::~pick_date()
{
    delete ui;
}

void pick_date::on_buttonBox_accepted()
{
    emit sendDate(ui->calendarWidget->selectedDate());
}
