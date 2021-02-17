#include "mainwin.h"
#include "ui_mainwin.h"
#include "date_edit.h"
#include "service_details.h"
#include "pick_date.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlRelationalDelegate>
#include <QTime>
#include <QSqlQuery>

//конструктор
MainWin::MainWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWin)
{
    ui->setupUi(this);

    //ставим первую колонку по дефолту
    ui->roomsTabs->setCurrentIndex(0);

    /*//////СПИСОК КОМНАТ////////////////////////////*/
    //модель для комнат
    roomsModel = new QSqlRelationalTableModel;
    //передаем в модель таблицу 'room' из БД
    roomsModel->setTable("room");
    //устанавливаем связи между таблицой 'room' и другими
    roomsModel->setRelation(2, QSqlRelation("room_categories", "id", "category_name"));
    roomsModel->setRelation(3, QSqlRelation("room_types", "id", "name"));
    roomsModel->setRelation(4, QSqlRelation("room_statuses", "id", "status_name"));
    //селектим
    roomsModel->select();
    //передаем модель в виджет roomsView
    ui->roomsView->setModel(roomsModel);
    //устанавливаем заголовки для таблицы
    roomsModel->setHeaderData(0, Qt::Horizontal, "Код");
    roomsModel->setHeaderData(1, Qt::Horizontal, "Номер");
    roomsModel->setHeaderData(2, Qt::Horizontal, "Кровати");
    roomsModel->setHeaderData(3, Qt::Horizontal, "Завтрак");
    roomsModel->setHeaderData(4, Qt::Horizontal, "Статус");
    roomsModel->setHeaderData(5, Qt::Horizontal, "Цена");
    //подогнать размер столбцов в соотв. с содержанием
    ui->roomsView->resizeColumnsToContents();

    //модель для типов комнат
    roomCountModel = new QSqlTableModel;
    roomCountModel->setTable("room_categories");
    roomCountModel->select();
    ui->roomCountCombo->setModel(roomCountModel);
    ui->roomCountCombo->setModelColumn(1);

    //модель для подтипов комнат, с завтраком или без
    roomBreakfastModel = new QSqlTableModel;
    roomBreakfastModel->setTable("room_types");
    roomBreakfastModel->select();
    ui->roomBreakfastCombo->setModel(roomBreakfastModel);
    ui->roomBreakfastCombo->setModelColumn(1);

    //модель для статусов комнат
    roomStatusModel = new QSqlTableModel;
    roomStatusModel->setTable("room_statuses");
    roomStatusModel->select();
    ui->roomStatusCombo->setModel(roomStatusModel);
    ui->roomStatusCombo->setModelColumn(1);

    //сортируем модель с комнатами по первой колонке с id, в порядке возрастания
    roomsModel->sort(0, Qt::AscendingOrder);
    //при выделении будет отмечаться вся строка целиком
    ui->roomsView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //устанавливаем делегата для таблицы
    ui->roomsView->setItemDelegate(new QSqlRelationalDelegate(ui->roomsView));
    /*///////////////////////////////////////////////*/



    /*////СПИСОК ТИПОВ КОМНАТ//////////////////////////*/
    bedsModel = new QSqlTableModel;
    bedsModel->setTable("room_categories");
    bedsModel->select();
    ui->bedsView->setModel(bedsModel);
    bedsModel->setHeaderData(0, Qt::Horizontal, "Код");
    bedsModel->setHeaderData(1,Qt::Horizontal, "Комнаты");
    ui->bedsView->resizeColumnsToContents();
    ui->bedsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    /*////////////////////////////////////////*/


    /*////СПИСОК КЛИЕНТОВ//////////////////////////*/
    clientsModel = new QSqlTableModel;
    clientsModel->setTable("clients");
    clientsModel->select();
    ui->clientView->setModel(clientsModel);
    clientsModel->setHeaderData(0, Qt::Horizontal , "Код");
    clientsModel->setHeaderData(1, Qt::Horizontal, "ФИО");
    clientsModel->setHeaderData(2, Qt::Horizontal, "Дата рождения");
    clientsModel->setHeaderData(3, Qt::Horizontal, "Паспорт");
    ui->clientView->resizeColumnsToContents();
    ui->clientView->setSelectionBehavior(QAbstractItemView::SelectRows);
    /*////////////////////////////////////*/


    /*/////ОБЩАЯ ТАБЛИЦА УСЛУГ//////*/
    clientsTotalModel = new QSqlRelationalTableModel;
    clientsTotalModel->setTable("clients_services_total");
    clientsTotalModel->setRelation(1,QSqlRelation("clients","id","fio"));
    clientsTotalModel->select();
    ui->clientServicesView->setModel(clientsTotalModel);
    clientsTotalModel->setHeaderData(0, Qt::Horizontal, "Код");
    clientsTotalModel->setHeaderData(1, Qt::Horizontal, "ФИО");
    clientsTotalModel->setHeaderData(2, Qt::Horizontal, "К оплате (руб.)");
    ui->clientServicesView->resizeColumnsToContents();
    ui->clientSearch->setModel(clientsModel);
    ui->clientSearch->setModelColumn(1);
    ui->clientSearch->setCurrentText("");
    //clientsTotalModel->setFilter("");
    clientsTotalModel->setFilter("payed = 'false'");
    ui->clientServicesView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->clientServicesView->hideColumn(3);
    /*////////////////////////////////////*/


    /*//////ТАБЛИЦА ПРОЖИВАЮЩИХ///////*/
    ui->clientCombo->setModel(clientsModel);
    ui->clientCombo->setModelColumn(1);
    //доступные комнаты
    avRooms = new QSqlTableModel;
    avRooms->setTable("room");
    avRooms->setFilter("status_id = '2'");
    avRooms->select();
    ui->roomCombo->setModel(avRooms);
    ui->roomCombo->setModelColumn(1);
    ui->dateIn->setDate(QDate::currentDate());
    ui->dateOut->setDate(QDate::currentDate().addDays(1));

    //типы платежей
    payModel = new QSqlTableModel;
    payModel->setTable("types_of_pay");
    payModel->select();
    ui->payCombo->setModel(payModel);
    ui->payCombo->setModelColumn(1);


    //клиенты
    clientsTableModel = new QSqlRelationalTableModel;

    clientsTableModel->setTable("clients_table");
    clientsTableModel->setRelation(1, QSqlRelation("clients","id","fio"));
    clientsTableModel->setRelation(2, QSqlRelation("room","id", "number"));
    clientsTableModel->setRelation(5, QSqlRelation("types_of_pay","id", "type"));
    clientsTableModel->setRelation(7, QSqlRelation("clients_services_total","id", "to_pay"));
    clientsTableModel->select();
    ui->clientsTableView->setModel(clientsTableModel);
    clientsTableModel->setHeaderData(0, Qt::Horizontal, "Код");
    clientsTableModel->setHeaderData(1, Qt::Horizontal, "Клиент");
    clientsTableModel->setHeaderData(2, Qt::Horizontal, "Комната");
    clientsTableModel->setHeaderData(3, Qt::Horizontal, "Заселение");
    clientsTableModel->setHeaderData(4, Qt::Horizontal, "Выезд");
    clientsTableModel->setHeaderData(5, Qt::Horizontal, "Способ оплаты");
    clientsTableModel->setHeaderData(6, Qt::Horizontal, "Комната (руб.)");
    clientsTableModel->setHeaderData(7, Qt::Horizontal, "Доп. услуги (руб.)");
    clientsTableModel->setHeaderData(8, Qt::Horizontal, "Итого (руб.)");
    clientsTableModel->setHeaderData(9, Qt::Horizontal, "Статус оплаты");


    //прячем клиентов у которых статус оплаты true
    int rows = clientsTableModel->rowCount();
    for (int i = 0; i < rows; i++)
    {
        QString data = clientsTableModel->data(clientsTableModel->index(i, 9)).toString();

        if (data == "true")
        {
            ui->clientsTableView->hideRow(i);
        }
    }

    ui->clientsTableView->resizeColumnsToContents();

    /*//////ОПЛАТА УСЛУГ И ПРОЖИВАНИЯ//////*/
    //проживающие клиенты
    hotelClients = new QSqlQueryModel;
    hotelClients->setQuery("SELECT client_id, fio FROM clients_table "
                          "JOIN clients ON clients_table.client_id = clients.id"
                           " WHERE payed = 'false'");

    ui->clientCombo_2->setModel(hotelClients);
    ui->clientCombo_2->setModelColumn(1);

    servModel = new QSqlTableModel;
    servModel->setTable("services");
    servModel->select();
    ui->servCombo->setModel(servModel);
    ui->servCombo->setModelColumn(1);
    /*////////////////////////////////////////*/


    //*СПИСОК УСЛУГ*///////////////////////////////
    servicesModel = new QSqlTableModel;
    servicesModel->setTable("services");
    servicesModel->select();
    servicesModel->setHeaderData(0, Qt::Horizontal, "Код");
    servicesModel->setHeaderData(1, Qt::Horizontal, "Наименование");
    servicesModel->setHeaderData(2, Qt::Horizontal, "Цена (руб.)");
    ui->servsView->setModel(servicesModel);
    ui->servsView->resizeColumnsToContents();


    //*СПИСОК СПОСОБ ОПЛАТЫ///////////////////////
    paymentsModel = new QSqlTableModel;
    paymentsModel->setTable("types_of_pay");
    paymentsModel->setHeaderData(0, Qt::Horizontal, "Код");
    paymentsModel->setHeaderData(1, Qt::Horizontal, "Наименование");
    paymentsModel->select();
    ui->payView->setModel(paymentsModel);
    ui->payView->resizeColumnsToContents();

    //*СПИСОК ПОДРАЗДЕЛЕНИЙ/////////////////
    unitsModel = new QSqlTableModel;
    unitsModel->setTable("units");
    unitsModel->select();
    unitsModel->setHeaderData(0, Qt::Horizontal, "Код");
    unitsModel->setHeaderData(1, Qt::Horizontal, "Наименование");
    ui->unitsView->setModel(unitsModel);
    ui->unitsView->resizeColumnsToContents();
    ui->unitCombo->setModel(unitsModel);
    ui->unitCombo->setModelColumn(1);


    //*РАБОТНИКИ///////////////////////
    staffModel = new QSqlRelationalTableModel;
    staffModel->setTable("staff");

    staffModel->setRelation(2, QSqlRelation("units","id","name"));
    staffModel->select();
    staffModel->setHeaderData(0, Qt::Horizontal, "Код");
    staffModel->setHeaderData(1, Qt::Horizontal, "ФИО");
    staffModel->setHeaderData(2, Qt::Horizontal, "Подразделение");
    staffModel->setHeaderData(3, Qt::Horizontal, "Паспорт");
    staffModel->setHeaderData(4, Qt::Horizontal, "Дата рождения");
    ui->staffView->setModel(staffModel);
    ui->staffView->resizeColumnsToContents();
    staffModel->sort(0, Qt::AscendingOrder);
    //устанавливаем делегата для таблицы
    ui->staffView->setItemDelegate(new QSqlRelationalDelegate(ui->staffView));

    //*ПРОЧЕЕ*//////////////////////
    //прячем кнопку сохранения, т.к она пока не нужна
    ui->rooms_saveButton->hide();
    ui->beds_saveButton->hide();
    ui->clients_saveButton->hide();
    ui->table_saveButton->hide();
    ui->serv_saveButton->hide();
    ui->pay_saveButton->hide();
    ui->unit_saveButton->hide();
    ui->staff_saveButton->hide();

    ui->servsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->payView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->unitsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->staffView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->clientsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //показать кнопку сохранения, когда данные в таблице изменятся
    connect(roomsModel,SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)),this, SLOT(show_room_saveButton()));
    connect(bedsModel,SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), this, SLOT(show_beds_saveButton()));
    connect(clientsModel,SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), this, SLOT(show_clients_saveButton()));
    connect(clientsTableModel,SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), this, SLOT(show_clients_table_saveButton()));
    connect(servicesModel,SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), this, SLOT(show_serv_saveButton()));
    connect(paymentsModel, SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), this, SLOT(show_pay_saveButton()));
    connect(unitsModel, SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), this, SLOT(show_units_saveButton()));
    connect(staffModel, SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), this, SLOT(show_staff_saveButton()));

    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setCurrentIndex(0);
}


//деструктор
MainWin::~MainWin()
{
    //при закрытии программы

    //если в модели есть несохраненные изменения
    if(roomsModel->isDirty())
    {

        //показываем месседжбокс
    int ret = QMessageBox::warning(this, "Внимание", tr("В базе есть насохраненные изменения. Хотите их сохранить?"),
                                    QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        // Если ответ диалога "Да"
        if (ret == QMessageBox::Yes)
            // то сохраняем изменения
        {roomsModel->submitAll();}

        }

    delete ui;

}

//при нажатии кнопки "Добавить" КОМНАТЫ
void MainWin::on_rooms_addButton_clicked()
{
    //если не заполнены поля "Номер комнаты" и "Цена"
    if(ui->roomNumEdit->text().isEmpty() && ui->priceEdit->text().isEmpty())
    {
        //показать месседжбокс
        QMessageBox::warning(this, "Внимание", "Не заполнены поля \"Номер комнаты\" и \"Цена\"");
        //переместить фокус на номер комнаты
        ui->roomNumEdit->setFocus();
       }
    //если не заполнена только цена
    else if(ui->priceEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Не заполнено поле \"Цена\"");
        ui->priceEdit->setFocus();
    }
    //если не заполнен только номер комнаты
    else if(ui->roomNumEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Внимание",
                        "Не заполнено поле \"Номер комнаты\"");
        ui->roomNumEdit->setFocus();

    }
    //если все заполнено
    else
    {
      //забиваем номер строки куда будем добавлять запись
      int row = roomsModel->rowCount();
      //добавляем запись в модель
      roomsModel->insertRows(row, 1);

      //забиваем запись данными
      //Номер комнаты
      QModelIndex roomNumberIndex = roomsModel->index(row, 1);
      roomsModel->setData(roomNumberIndex, ui->roomNumEdit->text());

      //Кол-во комнат
      //Выдергиваем ID из модельки, сначала берем индекс, потом по нему дергаем сам id
      QModelIndex indexRoomCount = ui->roomCountCombo->model()->index(ui->roomCountCombo->currentIndex(),0);
      QString roomCountId = ui->roomCountCombo->model()->data(indexRoomCount).toString();
      QModelIndex roomCountIndex = roomsModel->index(row, 2);
      roomsModel->setData(roomCountIndex, roomCountId);

      //Завтрак
      //Выдергиваем ID из модельки, сначала берем индекс, потом по нему дергаем сам id
      QModelIndex indexBreakfast = ui->roomBreakfastCombo->model()->index(ui->roomBreakfastCombo->currentIndex(),0);
      QString roomBreakfastId = ui->roomBreakfastCombo->model()->data(indexBreakfast).toString();
      QModelIndex roomBreakfastIndex = roomsModel->index(row, 3);
      roomsModel->setData(roomBreakfastIndex, roomBreakfastId);

      //Статус
      //Выдергиваем ID из модельки, сначала берем индекс, потом по нему дергаем сам id
      QModelIndex indexStatus = ui->roomStatusCombo->model()->index(ui->roomStatusCombo->currentIndex(),0);
      QString roomStatusId = ui->roomStatusCombo->model()->data(indexStatus).toString();
      QModelIndex roomStatusIndex = roomsModel->index(row, 4);
      roomsModel->setData(roomStatusIndex, roomStatusId);

      //Цена
      QModelIndex priceIndex = roomsModel->index(row, 5);
      roomsModel->setData(priceIndex, ui->priceEdit->text());



      //если что-то пошло не так и какие-то данные не добавились,
      //такое может быть только если где-то совпал номер комнаты
      if (roomsModel->submitAll() == false)
      {
          roomsModel->select();
          QMessageBox::critical(this, "Ошибка",
                          "Комната с таким номером уже существует");

      }
      //если все ок
      else {
      //убираем везде введенный текст
      ui->roomNumEdit->setText("");
      ui->priceEdit->setText("");
      ui->roomsView->scrollToBottom();
      ui->roomsView->resizeColumnsToContents();
      //добавляем запись в логи
      ui->logs->append("<p>Добавлена запись в справочник \"Комнаты\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
                }
       }

    //прячем кнопку сейва
    ui->rooms_saveButton->hide();

    //обновляем список комнат в проживании
    avRooms->select();
    ui->roomCombo->setCurrentIndex(0);
}

//при нажатии "Удалить" КОМНАТЫ
void MainWin::on_rooms_delButton_clicked()
{

    //берем индекс выделенной записи
    QModelIndex index = ui->roomsView->currentIndex();
            //если индекс существует
            if (index.isValid())
            {
                // Вызываем диалог с вопросом
                int ret = QMessageBox::critical(this, "",
                                                tr("Вы действительно хотите удалить запись?"),
                                                QMessageBox::Yes | QMessageBox::No,
                                                QMessageBox::No);
                // Если ответ диалога "Да"
                if (ret == QMessageBox::Yes)
                    // то удаляем строку из модели
                    roomsModel->removeRow(index.row());
                       }
            //селектим, чтобы модель обновилась
            roomsModel->select();

            //обновляем список комнат в проживании
            avRooms->select();
            ui->roomCombo->setCurrentIndex(0);

            //запись в лог
            ui->logs->append("<p>Удалена запись из справочника \"Комнаты\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}

//при нажатии "Сохранить" КОМНАТЫ
void MainWin::on_rooms_saveButton_clicked()
{
    //записываем изменения модели в БД
    roomsModel->submitAll();
    //логи
    ui->logs->append("<p>Изменены записи в справочнике \"Комнаты\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
    //прячем кнопку сохранения
    ui->rooms_saveButton->hide();

    //обновляем список комнат в проживании
    avRooms->select();
    ui->roomCombo->setCurrentIndex(0);
}

//слоты для отображения кнопки сохранения
void MainWin::show_room_saveButton()
{
    ui->rooms_saveButton->show();
    //обновляем список комнат в проживании
    avRooms->select();
    ui->roomCombo->setCurrentIndex(0);
}

void MainWin::show_beds_saveButton()
{
    ui->beds_saveButton->show();
    roomCountModel->select();
    ui->roomCountCombo->setCurrentIndex(0);
}

void MainWin::show_clients_saveButton()
{
    ui->clients_saveButton->show();

}

void MainWin::show_clients_table_saveButton()
{
    ui->table_saveButton->show();
}

void MainWin::show_serv_saveButton()
{
    ui->serv_saveButton->show();
}

void MainWin::show_pay_saveButton()
{
    ui->pay_saveButton->show();
}

void MainWin::show_units_saveButton()
{
    ui->unit_saveButton->show();
}

void MainWin::show_staff_saveButton()
{
    ui->staff_saveButton->show();
}

//при нажатии "Добавить" ТИПЫ КОМНАТ
void MainWin::on_beds_addButton_clicked()
{
    if(ui->bedsEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не заполнено поле \"Кол-во комнат");
        ui->bedsEdit->setFocus();
    }
    else
    {
        int row = bedsModel->rowCount();
        //добавляем запись в модель
        bedsModel->insertRows(row, 1);

        QModelIndex bedsIndex = bedsModel->index(row, 1);
        bedsModel->setData(bedsIndex, ui->bedsEdit->text());

        bedsModel->submitAll();

        ui->logs->append("<p>Добавлена запись в справочник \"Кол-во кроватей\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
    }

    ui->beds_saveButton->hide();
    ui->bedsEdit->clear();
    roomCountModel->select();
    ui->roomCountCombo->setCurrentIndex(0);
}

//при нажатии "Удалить" ТИПЫ КОМНАТ
void MainWin::on_beds_delButton_clicked()
{
    //берем индекс выделенной записи
    QModelIndex index = ui->bedsView->currentIndex();
            //если индекс существует
            if (index.isValid())
            {
                // Вызываем диалог с вопросом
                int ret = QMessageBox::critical(this, "",
                                                tr("Вы действительно хотите удалить запись?"),
                                                QMessageBox::Yes | QMessageBox::No,
                                                QMessageBox::No);
                // Если ответ диалога "Да"
                if (ret == QMessageBox::Yes)
                    // то удаляем строку из модели
                    bedsModel->removeRow(index.row());
                       }
            //селектим, чтобы модель обновилась
            bedsModel->select();
            roomCountModel->select();
            ui->roomCountCombo->setModel(roomCountModel);

            roomCountModel->select();
            ui->roomCountCombo->setCurrentIndex(0);

            //запись в лог
            ui->logs->append("<p>Удалена запись из справочника \"Комнаты\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}

//при нажатии "Сохранить" ТИПЫ КОМНАТ
void MainWin::on_beds_saveButton_clicked()
{
    bedsModel->submitAll();
    ui->logs->append("<p>Изменены записи в справочнике \"Типы комнат\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
    ui->beds_saveButton->hide();

    roomCountModel->select();
    ui->roomCountCombo->setCurrentIndex(0);
}

//при нажатии "Добавить" КЛИЕНТЫ
void MainWin::on_clients_addButton_clicked()
{

    if(ui->clientFioEdit->text().isEmpty() && ui->clientPassportEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не заполнены поля \"ФИО\" и \"Паспорт");
        ui->clientFioEdit->setFocus();
    }

    else if (ui->clientPassportEdit->text().isEmpty())
    {
       QMessageBox::warning(this, "Внимание", "Не заполнено поле \"Паспорт");
       ui->clientPassportEdit->setFocus();
    }

    else if (ui->clientFioEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не заполнено поле \"ФИО");
        ui->clientFioEdit->setFocus();
    }

    else
    {
        int row = clientsModel->rowCount();
        //добавляем запись в модель
        clientsModel->insertRows(row, 1);

        QModelIndex fioIndex = clientsModel->index(row, 1);
        clientsModel->setData(fioIndex, ui->clientFioEdit->text());

        QModelIndex dateIndex = clientsModel->index(row, 2);
        clientsModel->setData(dateIndex, ui->clientDateEdit->date().toString("yyyy-MM-dd"));

        QModelIndex passportIndex = clientsModel->index(row, 3);
        clientsModel->setData(passportIndex, ui->clientPassportEdit->text());


        clientsModel->submitAll();

        clientsModel->select();

        ui->logs->append("<p>Добавлена запись в справочник \"Клиенты\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");

    }

    ui->clients_saveButton->hide();
    ui->clientFioEdit->clear();
    ui->clientPassportEdit->clear();

    clientsModel->select();
    ui->clientCombo->setCurrentIndex(0);

}

//при нажатии "Удалить" КЛИЕНТЫ
void MainWin::on_clients_delButton_clicked()
{
    //берем индекс выделенной записи
    QModelIndex index = ui->clientView->currentIndex();
            //если индекс существует
            if (index.isValid())
            {
                // Вызываем диалог с вопросом
                int ret = QMessageBox::critical(this, "",
                                                tr("Вы действительно хотите удалить запись?"),
                                                QMessageBox::Yes | QMessageBox::No,
                                                QMessageBox::No);
                // Если ответ диалога "Да"
                if (ret == QMessageBox::Yes)
                    // то удаляем строку из модели
                    clientsModel->removeRow(index.row());
                       }
            //селектим, чтобы модель обновилась
            clientsModel->select();

            clientsModel->select();
            ui->clientCombo->setCurrentIndex(0);

            //запись в лог
            ui->logs->append("<p>Удалена запись из справочника \"Клиенты\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}

//Выбрать дату КЛИЕНТЫ
void MainWin::on_toolButton_clicked()
{
    date_edit *date_win = new date_edit;
    date_win->show();
    connect(date_win,SIGNAL(sendDate(QDate)),this,SLOT(getDate(QDate)));
}

//Слот, получить дату КЛИЕНТЫ
void MainWin::getDate(QDate date)
{
    ui->clientDateEdit->setDate(date);
}

//при нажатии "Сохранить" КЛИЕНТЫ
void MainWin::on_clients_saveButton_clicked()
{
    clientsModel->submitAll();
    ui->logs->append("<p>Изменены записи в справочнике \"Клиенты\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
    ui->clients_saveButton->hide();

    clientsModel->select();
    ui->clientCombo->setCurrentIndex(0);

    clientsTableModel->select();
    hotelClients->setQuery("SELECT client_id, fio FROM clients_table "
                           "JOIN clients ON clients_table.client_id = clients.id"
                           " WHERE payed = 'false'");
    ui->clientCombo_2->setModel(hotelClients);
    ui->clientCombo_2->setCurrentIndex(0);
}

//поиск клиента в УСЛУГАХ
void MainWin::on_clientSearch_editTextChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
       clientsTotalModel->setFilter("payed = 'false'");
    }
    else
    {
    clientsTotalModel->setFilter("client_id = (SELECT id FROM clients WHERE fio = '" + arg1 + "' and payed = 'false')");
    }
}

//переход в подробной таблице с УСЛУГАМИ
void MainWin::on_clientServicesView_doubleClicked(const QModelIndex &index)
{

    int client_id = clientsTotalModel->data(clientsTotalModel->
                                            index(index.row(), 0)).toInt();

    QString client_name = clientsTotalModel->data(clientsTotalModel->
                                                  index(index.row(), 1)).toString();

    service_details *serv_det = new service_details;
    serv_det->show();
    connect(this,SIGNAL(sendClientInfo(int,QString)),serv_det,SLOT(getClientInfo(int,QString)));
    emit sendClientInfo(client_id, client_name);

}

//ОПЛАТА при изменении услуги подставить цену
void MainWin::on_servCombo_currentIndexChanged(int index)
{
    QModelIndex servPriceIndex = ui->servCombo->model()->index(index, 2);
    QString price = ui->servCombo->model()->data(servPriceIndex).toString();
    ui->servPriceEdit->setText(price);
}

//ОПЛАТА подствредить платеж за услугу
void MainWin::on_serviceAccept_clicked()
{
    if(ui->servPriceEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не заполнено поле \"Цена\"");
        ui->servPriceEdit->setFocus();
    }
    else
    {
        QModelIndex clientIdIndex = ui->clientCombo_2->model()->index(ui->clientCombo_2->currentIndex(),0);
        QString clientId = ui->clientCombo_2->model()->data(clientIdIndex).toString();

        QModelIndex servIdIndex = ui->servCombo->model()->index(ui->servCombo->currentIndex(), 0);
        QString servId = ui->servCombo->model()->data(servIdIndex).toString();

        QString price = ui->servPriceEdit->text();

        QSqlQuery query;

        query.prepare("INSERT INTO clients_services (client_id, service_id, date) "
                      "VALUES (:client_id, :service_id, :date)");
        query.bindValue(":client_id", clientId);
        query.bindValue(":service_id", servId);
        query.bindValue(":date", QDate::currentDate().toString("yyyy-MM-dd"));
        query.exec();

         ui->logs->append("<p>Проведен платеж за услугу " + ui->servCombo->currentText() +
                          " для клиента " + ui->clientCombo_2->currentText() + " " + QTime::currentTime().toString("hh:mm:ss") + "</p>");


         QSqlQuery findId;
         findId.exec("SELECT * FROM clients_services_total WHERE client_id = '" + clientId + "'");
         findId.next();
         if (findId.value(1).isNull())
         {
             QSqlQuery add;
             add.prepare("INSERT INTO clients_services_total (client_id, to_pay)"
                         "VALUES (:id, :pay)");
             add.bindValue(":id",clientId);
             add.bindValue(":pay",price);
             add.exec();

             clientsTotalModel->select();
         }
         else
         {
             int old_price = findId.value(2).toInt();
             int new_price = old_price + price.toInt();

             QSqlQuery add;
             add.prepare("UPDATE clients_services_total SET to_pay = :pay WHERE client_id = :id");
             add.bindValue(":id",clientId);
             add.bindValue(":pay",QString::number(new_price));
             add.exec();

             QSqlQuery addTable;
             addTable.prepare("SELECT pay_for_room FROM clients_table WHERE client_id = :id");
             addTable.bindValue(":id",clientId);
             addTable.exec();
             addTable.next();
             QString total_pay = addTable.value(0).toString();

             QSqlQuery buba;
             buba.prepare("UPDATE clients_table SET total_pay = :pay WHERE client_id = :id");
             buba.bindValue(":pay", total_pay.toInt() + new_price);
             buba.bindValue(":id", clientId);
             buba.exec();

             clientsTableModel->select();
             ui->clientsTableView->resizeColumnsToContents();

             clientsTotalModel->select();
         }



         QSqlQuery getPay;
         getPay.prepare("SELECT total_pay FROM clients_table WHERE client_id = :id and payed = 'false'");
         getPay.bindValue(":id", clientId);
         getPay.exec();
         getPay.next();

         ui->totalPayEdit->setText(getPay.value(0).toString());

    }
}

//при переходе на вкладку "Пользование услугами" ресайзнуть таблицу
void MainWin::on_tabWidget_2_tabBarClicked(int index)
{
    if (index == 1)
    {
        ui->clientServicesView->resizeColumnsToContents();
    }
}

//Добавить запись ПРОЖИВАНИЕ
void MainWin::on_table_addButton_clicked()
{
    int row = clientsTableModel->rowCount();

    clientsTableModel->insertRows(row, 1);

    //добавляем id клиента
    QModelIndex clientIdIndex = ui->clientCombo->model()->index(ui->clientCombo->currentIndex(), 0);
    QString clientId = ui->clientCombo->model()->data(clientIdIndex).toString();
    QModelIndex cIdIndex = clientsTableModel->index(row, 1);
    clientsTableModel->setData(cIdIndex, clientId);

    //проверяем есть ли запись о клиенте в таблице доп. услуг
    QSqlQuery searchClient;
    searchClient.prepare("SELECT id FROM clients_services_total WHERE client_id = :id");
    searchClient.bindValue(":id", clientId);
    searchClient.exec();
    searchClient.next();

    searchClient.value(0).toString();

    if(searchClient.value(0).isValid())
    {
        QSqlQuery addServInfo;
        addServInfo.prepare("UPDATE clients_services_total SET payed = 'false', to_pay = '0' WHERE id = :id");
        addServInfo.bindValue(":id", clientId);
        addServInfo.exec();
        addServInfo.finish();
    }

    else
    {
        //добавляем запись о доп. услугах в соотв. таблицу
        QSqlQuery addServInfo;
        addServInfo.prepare("INSERT INTO clients_services_total (id, client_id, to_pay, payed)"
                            "VALUES (:id, :client_id, :to_pay, 'false')");
        addServInfo.bindValue(":id", clientId);
        addServInfo.bindValue(":client_id", clientId);
        addServInfo.bindValue(":to_pay", "0");
        addServInfo.exec();
        addServInfo.finish();
    }

    //добавляем id комнаты
    QModelIndex roomIdIndex = ui->roomCombo->model()->index(ui->roomCombo->currentIndex(), 0);
    QString roomId = ui->roomCombo->model()->data(roomIdIndex).toString();
    QModelIndex rIdIndex = clientsTableModel->index(row, 2);
    clientsTableModel->setData(rIdIndex, roomId);

    //дата въезда
    QModelIndex dateInIndex = clientsTableModel->index(row, 3);
    clientsTableModel->setData(dateInIndex, ui->dateIn->date().toString("yyyy-MM-dd"));

    //дата выезда
    QModelIndex dateOutIndex = clientsTableModel->index(row, 4);
    clientsTableModel->setData(dateOutIndex, ui->dateOut->date().toString("yyyy-MM-dd"));

    //добавить id вида оплаты
    QModelIndex payIdIndex = ui->payCombo->model()->index(ui->payCombo->currentIndex(), 0);
    QString payId = ui->payCombo->model()->data(payIdIndex).toString();
    QModelIndex pIdIndex = clientsTableModel->index(row, 5);
    clientsTableModel->setData(pIdIndex, payId);

    //оплата за комнату
    QModelIndex payForRoomIndex = avRooms->index(ui->roomCombo->currentIndex(), 5);
    QString payForRoom = avRooms->data(payForRoomIndex).toString();
    QModelIndex pfrIndex = clientsTableModel->index(row, 6);
    clientsTableModel->setData(pfrIndex, payForRoom);

    //id оплаты за доп. услуги
//    QModelIndex servIdIndex = clientsTableModel->index(row, 7);
//    qInfo() << "setData " << clientId << " " << clientsTableModel->setData(servIdIndex, clientId);

    //оплата за всё (комната + услуги, т.к услуги на момент добавления равны нулю, то просто
    //добавляем цену за комнату)
    QModelIndex payTotalIndex = clientsTableModel->index(row, 8);
    clientsTableModel->setData(payTotalIndex, payForRoom);

    //статус оплаты
    QModelIndex statusIndex = clientsTableModel->index(row, 9);
    clientsTableModel->setData(statusIndex, "false");

    clientsTableModel->submitAll();

    QSqlQuery wtf;
    wtf.prepare("UPDATE clients_table SET pay_for_services_id = :id WHERE client_id = :cid and payed = 'false'");
    wtf.bindValue(":id",clientId);
    wtf.bindValue(":cid",clientId);
    wtf.exec();

    clientsTableModel->select();

    //обновляем таблицу услуг
    clientsTotalModel->select();

    //обновить информацию о комнатах
    QSqlQuery updateRooms;
    updateRooms.prepare("UPDATE room SET status_id = '1' WHERE id = :id");
    updateRooms.bindValue(":id",roomId);
    updateRooms.exec();

    roomsModel->select();
    avRooms->select();
    ui->roomCombo->setCurrentIndex(0);

    //обновить информацию о проживающих
    hotelClients->setQuery("SELECT client_id, fio FROM clients_table "
                           "JOIN clients ON clients_table.client_id = clients.id"
                           " WHERE payed = 'false'");
    ui->clientCombo_2->setModel(hotelClients);
    ui->clientCombo_2->setCurrentIndex(0);

    ui->clientsTableView->resizeColumnsToContents();
    ui->table_saveButton->hide();
    ui->logs->append("<p>Ура! Поселился новый клиент! :^) " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}
//сохранить изменения в ТАБЛИЦЕ
void MainWin::on_table_saveButton_clicked()
{
    clientsTableModel->submitAll();
     ui->logs->append("<p>Изменены записи в справочнике \"Проживание\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
    ui->table_saveButton->hide();
}


void MainWin::on_clientCombo_2_currentIndexChanged(int index)
{
    QSqlQuery getPay;
    getPay.prepare("SELECT total_pay FROM clients_table WHERE client_id = :id and payed = 'false'");
    QModelIndex clientIdIndex = ui->clientCombo_2->model()->index(index,0);
    QString clientId = ui->clientCombo_2->model()->data(clientIdIndex).toString();
    getPay.bindValue(":id", clientId);
    getPay.exec();
    getPay.next();

    ui->totalPayEdit->setText(getPay.value(0).toString());
}

void MainWin::on_pushButton_2_clicked()
{

   if(ui->clientCombo_2->currentText().isEmpty())
   {
     QMessageBox::warning(this, "Внимание", "Не заполнено поле \"Клиент\"");
   }

    else
   {
    QModelIndex clientIdIndex = ui->clientCombo_2->model()->index(ui->clientCombo_2->currentIndex(),0);
    QString clientId = ui->clientCombo_2->model()->data(clientIdIndex).toString();

    QSqlQuery getRoom;
    getRoom.prepare("SELECT room_id FROM clients_table WHERE client_id = :id AND payed = 'false'");
    getRoom.bindValue(":id", clientId);
    getRoom.exec();
    getRoom.next();
    QString roomId = getRoom.value(0).toString();
    qInfo() << roomId;

    QSqlQuery updateRoom;
    updateRoom.prepare("UPDATE room SET status_id = '2' WHERE id = :id");
    updateRoom.bindValue(":id",roomId);
    qInfo() << updateRoom.exec();

    QSqlQuery acceptTotal;
    acceptTotal.prepare("UPDATE clients_table SET payed = 'true' WHERE client_id = :id and payed = 'false'");
    acceptTotal.bindValue(":id", clientId);
    acceptTotal.exec();

    clientsTableModel->select();
    roomsModel->select();
    avRooms->select();
    ui->roomCombo->setCurrentIndex(0);

    QSqlQuery delTotal;
    delTotal.prepare("UPDATE clients_services_total SET payed = 'true' WHERE client_id = :id");
    delTotal.bindValue(":id", clientId);
    delTotal.exec();

    QSqlQuery delServs;
    delServs.prepare("DELETE FROM clients_services WHERE client_id = :id");
    delServs.bindValue(":id", clientId);
    delServs.exec();

    clientsTotalModel->select();
    clientsTotalModel->setFilter("payed = 'false'");
    hotelClients->setQuery("SELECT client_id, fio FROM clients_table "
                           "JOIN clients ON clients_table.client_id = clients.id"
                           " WHERE payed = 'false'");
    clientsTableModel->select();

    if (ui->allClientsCheckBox->isChecked() == false)
    {

    int rows = clientsTableModel->rowCount();
    for (int i = 0; i < rows; i++)
    {
        QString data = clientsTableModel->data(clientsTableModel->index(i, 9)).toString();

        if (data == "true")
        {
            ui->clientsTableView->hideRow(i);
        }
    }

    }

    ui->clientCombo_2->setModel(hotelClients);
    ui->clientCombo_2->setCurrentIndex(0);

    ui->logs->append("<p>Проведена оплата за проживание. Клиент уехал. :^( " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}
}

void MainWin::on_allClientsCheckBox_toggled(bool checked)
{

     int rows = clientsTableModel->rowCount();

    if(checked)
    {
        for(int i = 0; i < rows; i++)
        {
            ui->clientsTableView->showRow(i);
        }
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            QString data = clientsTableModel->data(clientsTableModel->index(i, 9)).toString();

            if (data == "true")
            {
                ui->clientsTableView->hideRow(i);
            }
        }
    }
}


void MainWin::on_pickDateIn_clicked()
{
    pick_date *date_picker = new pick_date;
    date_picker->show();
    connect(date_picker, SIGNAL(sendDate(QDate)), this, SLOT(getDateIn(QDate)));

}

void MainWin::getDateIn(QDate date)
{
    ui->dateIn->setDate(date);
}

void MainWin::on_pickDateOut_clicked()
{
    pick_date *date_picker = new pick_date;
    date_picker->show();
    connect(date_picker, SIGNAL(sendDate(QDate)), this, SLOT(getDateOut(QDate)));
}

void MainWin::getDateOut(QDate date)
{
    ui->dateOut->setDate(date);
}

void MainWin::on_tabWidget_currentChanged(int index)
{
    if (index == 0)
    {
        QSqlQuery clientsNow;
        clientsNow.exec("SELECT COUNT(*) FROM clients_table WHERE payed = 'false'");
        clientsNow.next();
        ui->clientsNow->setText(clientsNow.value(0).toString());

        QSqlQuery clientsAllTime;
        clientsAllTime.exec("SELECT COUNT(*) FROM clients_table");
        clientsAllTime.next();
        ui->clientsAllTime->setText(clientsAllTime.value(0).toString());

        QSqlQuery staff;
        staff.exec("SELECT COUNT(*) FROM staff");
        staff.next();
        ui->staff->setText(staff.value(0).toString());

        QSqlQuery rooms;
        rooms.exec("SELECT COUNT(*) FROM room");
        rooms.next();
        ui->rooms->setText(rooms.value(0).toString());

        QSqlQuery profitRooms;
        profitRooms.exec("SELECT SUM(pay_for_room) FROM clients_table WHERE payed = 'true'");
        profitRooms.next();
        ui->profitRooms->setText(profitRooms.value(0).toString() + " руб.");

        QSqlQuery profitTotal;
        profitTotal.exec("SELECT SUM(total_pay) FROM clients_table  WHERE payed = 'true'");
        profitTotal.next();
        ui->profitTotal->setText(profitTotal.value(0).toString() + " руб.");

        int profitServes = profitTotal.value(0).toInt() - profitRooms.value(0).toInt();
        ui->profitServs->setText(QString::number(profitServes) + " руб.");



    }
}

void MainWin::on_serv_addButton_clicked()
{

    if(ui->servNameEdit->text().isEmpty() && ui->servPriceEdit_2->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не заполнены поля \"Наименование\" и \"Цена\"");
        ui->servNameEdit->setFocus();
    }

    else if (ui->servNameEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не заполнено поле \"Наименование\"");
        ui->servNameEdit->setFocus();
    }

    else if (ui->servPriceEdit_2->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не заполнено поле \"Цена\"");
        ui->servPriceEdit->setFocus();
    }

    else
   {
    int row = servicesModel->rowCount();

    servicesModel->insertRows(row, 1);

    QModelIndex nameIndex = servicesModel->index(row, 1);
    servicesModel->setData(nameIndex, ui->servNameEdit->text());

    QModelIndex priceIndex = servicesModel->index(row, 2);
    servicesModel->setData(priceIndex, ui->servPriceEdit_2->text());

    servicesModel->submitAll();
    servicesModel->select();
    servModel->select();
    ui->servCombo->setCurrentIndex(0);
    ui->servsView->resizeColumnsToContents();

    }

    ui->serv_saveButton->hide();
    ui->servNameEdit->clear();
    ui->servPriceEdit_2->clear();
}

void MainWin::on_serv_delButton_clicked()
{

    //берем индекс выделенной записи
    QModelIndex index = ui->servsView->currentIndex();
            //если индекс существует
            if (index.isValid())
            {
                // Вызываем диалог с вопросом
                int ret = QMessageBox::critical(this, "",
                                                tr("Вы действительно хотите удалить запись?"),
                                                QMessageBox::Yes | QMessageBox::No,
                                                QMessageBox::No);
                // Если ответ диалога "Да"
                if (ret == QMessageBox::Yes)
                    // то удаляем строку из модели
                    servicesModel->removeRow(index.row());
                       }
            //селектим, чтобы модель обновилась
            servicesModel->select();

            servModel->select();
            ui->servCombo->setCurrentIndex(0);

            ui->serv_saveButton->hide();

            //запись в лог
            ui->logs->append("<p>Удалена запись из справочника \"Услуги\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}

void MainWin::on_serv_saveButton_clicked()
{
    servicesModel->submitAll();
    servModel->select();
    ui->servCombo->setCurrentIndex(0);
    ui->serv_saveButton->hide();

    ui->logs->append("<p>Изменены записи в справочнике \"Услуги\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}


void MainWin::on_pay_addButton_clicked()
{
    if(ui->payEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не заполнено поле \"Наименование\"");
        ui->payEdit->setFocus();
    }

    else
    {
        int row = paymentsModel->rowCount();
        paymentsModel->insertRows(row, 1);

        QModelIndex nameIndex = paymentsModel->index(row, 1);
        paymentsModel->setData(nameIndex, ui->payEdit->text());

        paymentsModel->submitAll();
        paymentsModel->select();
        ui->payView->resizeColumnsToContents();

        payModel->select();
        ui->payCombo->setCurrentIndex(0);
        ui->pay_saveButton->hide();
        ui->logs->append("<p>Добавлена запись в справочник \"Способы оплаты\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");

    }
        ui->payEdit->clear();

}

void MainWin::on_pay_delButton_clicked()
{

    //берем индекс выделенной записи
    QModelIndex index = ui->payView->currentIndex();
            //если индекс существует
            if (index.isValid())
            {
                // Вызываем диалог с вопросом
                int ret = QMessageBox::critical(this, "",
                                                tr("Вы действительно хотите удалить запись?"),
                                                QMessageBox::Yes | QMessageBox::No,
                                                QMessageBox::No);
                // Если ответ диалога "Да"
                if (ret == QMessageBox::Yes)
                    // то удаляем строку из модели
                    paymentsModel->removeRow(index.row());
                       }
            //селектим, чтобы модель обновилась
            paymentsModel->select();

            payModel->select();
            ui->payCombo->setCurrentIndex(0);

            ui->pay_saveButton->hide();

            //запись в лог
            ui->logs->append("<p>Удалена запись из справочника \"Способы оплаты\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}

void MainWin::on_pay_saveButton_clicked()
{

    paymentsModel->submitAll();
    payModel->select();
    ui->payCombo->setCurrentIndex(0);
    ui->pay_saveButton->hide();
    ui->logs->append("<p>Изменены записи в справочнике \"Способы оплаты\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}

void MainWin::on_unit_addButton_clicked()
{
    if(ui->unitEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не заполнено поле \"Наименование\"");
        ui->unitEdit->setFocus();
    }

    else
    {
        int row = unitsModel->rowCount();
        unitsModel->insertRows(row, 1);

        QModelIndex nameIndex = unitsModel->index(row, 1);
        unitsModel->setData(nameIndex, ui->unitEdit->text());

        unitsModel->submitAll();
        unitsModel->select();
        ui->unitsView->resizeColumnsToContents();

        unitsModel->select();
        ui->unitCombo->setCurrentIndex(0);
        ui->unit_saveButton->hide();
        ui->logs->append("<p>Добавлена запись в справочник \"Подразделения\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");

    }

    ui->unitEdit->clear();
}

void MainWin::on_staff_delButton_clicked()
{
    //берем индекс выделенной записи
    QModelIndex index = ui->staffView->currentIndex();
            //если индекс существует
            if (index.isValid())
            {
                // Вызываем диалог с вопросом
                int ret = QMessageBox::critical(this, "",
                                                tr("Вы действительно хотите удалить запись?"),
                                                QMessageBox::Yes | QMessageBox::No,
                                                QMessageBox::No);
                // Если ответ диалога "Да"
                if (ret == QMessageBox::Yes)
                    // то удаляем строку из модели
                    staffModel->removeRow(index.row());
                       }
            //селектим, чтобы модель обновилась
            staffModel->select();


            ui->staff_saveButton->hide();

            //запись в лог
            ui->logs->append("<p>Удалена запись из справочника \"Работники\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}


void MainWin::on_unit_saveButton_clicked()
{

    unitsModel->submitAll();
    unitsModel->select();
    ui->unitCombo->setCurrentIndex(0);
    ui->unit_saveButton->hide();
    ui->logs->append("<p>Изменены записи в справочнике \"Подразделения\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}

void MainWin::on_unit_delButton_clicked()
{
    //берем индекс выделенной записи
    QModelIndex index = ui->unitsView->currentIndex();
            //если индекс существует
            if (index.isValid())
            {
                // Вызываем диалог с вопросом
                int ret = QMessageBox::critical(this, "",
                                                tr("Вы действительно хотите удалить запись?"),
                                                QMessageBox::Yes | QMessageBox::No,
                                                QMessageBox::No);
                // Если ответ диалога "Да"
                if (ret == QMessageBox::Yes)
                    // то удаляем строку из модели
                    unitsModel->removeRow(index.row());
                       }
            //селектим, чтобы модель обновилась
            unitsModel->select();


            ui->unitCombo->setCurrentIndex(0);

            ui->unit_saveButton->hide();

            //запись в лог
            ui->logs->append("<p>Удалена запись из справочника \"Подразделения\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}

void MainWin::on_staff_addButton_clicked()
{
    if (ui->staffFioEdit->text().isEmpty() && ui->staffPasportEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не заполнено поле \"ФИО\" и \"Паспорт\"");
        ui->staffFioEdit->setFocus();
    }

    else if (ui->staffFioEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не заполнено поле \"ФИО\"");
        ui->staffFioEdit->setFocus();
    }

    else if (ui->staffPasportEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Внимание", "Не заполнено поле \"Паспорт\"");
        ui->staffPasportEdit->setFocus();
    }

    else {

        int row = staffModel->rowCount();
        staffModel->insertRows(row, 1);

        QModelIndex fioIndex = staffModel->index(row, 1);
        staffModel->setData(fioIndex, ui->staffFioEdit->text());

        QModelIndex unitIndex = ui->unitCombo->model()->index(ui->unitCombo->currentIndex(), 0);
        QString unitId = ui->unitCombo->model()->data(unitIndex).toString();
        QModelIndex uIndex = staffModel->index(row, 2);
        staffModel->setData(uIndex, unitId);

        QModelIndex passportIndex = staffModel->index(row, 3);
        staffModel->setData(passportIndex, ui->staffPasportEdit->text());

        QModelIndex dateIndex = staffModel->index(row, 4);
        staffModel->setData(dateIndex, ui->staffDateEdit->date().toString("yyyy-MM-dd"));

        staffModel->submitAll();
        staffModel->select();
        ui->staffView->resizeColumnsToContents();

        ui->staff_saveButton->hide();
        ui->staffFioEdit->clear();
        ui->staffPasportEdit->clear();
        ui->logs->append("<p>Добавлена запись в справочник \"Работники\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
   }
    }


void MainWin::on_staff_saveButton_clicked()
{
    staffModel->submitAll();
    staffModel->select();
    ui->staff_saveButton->hide();
     ui->logs->append("<p>Изменены записи в справочнике \"Работники\" " + QTime::currentTime().toString("hh:mm:ss") + "</p>");
}

void MainWin::on_staffDatePick_clicked()
{
    date_edit *date_editor = new date_edit;
    date_editor->show();

    connect(date_editor,SIGNAL(sendDate(QDate)), this, SLOT(getDateForWorker(QDate)));
}

void MainWin::getDateForWorker(QDate date)
{
    ui->staffDateEdit->setDate(date);
}
