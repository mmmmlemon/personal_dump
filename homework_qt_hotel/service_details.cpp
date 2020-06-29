#include "service_details.h"
#include "ui_service_details.h"
#include <QSqlQueryModel>
#include <QDebug>

service_details::service_details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::service_details)
{
    ui->setupUi(this);
}

service_details::~service_details()
{
    delete ui;
}

void service_details::getClientInfo(int id, QString name)
{
    this->setWindowTitle("Детали по клиенту " + name);

    QSqlQueryModel *details = new QSqlQueryModel;
    details->setQuery("SELECT  name, price, date FROM clients_services "
                      "JOIN services ON clients_services.service_id = services.id "
                      "WHERE client_id = '" + QString::number(id)+ "'");
    details->setHeaderData(0, Qt::Horizontal, "Услуга");
    details->setHeaderData(1, Qt::Horizontal, "Цена (руб.)");
    details->setHeaderData(2,Qt::Horizontal, "Дата");
    ui->details->setModel(details);



}
