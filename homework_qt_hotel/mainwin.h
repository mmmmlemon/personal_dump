#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QDate>

namespace Ui {
class MainWin;
}

class MainWin : public QWidget
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = 0);
    ~MainWin();

private slots:
    void on_rooms_addButton_clicked();

    void on_rooms_delButton_clicked();

    void on_rooms_saveButton_clicked();

    void show_room_saveButton();

    void show_beds_saveButton();

    void show_clients_saveButton();

    void show_clients_table_saveButton();

    void show_serv_saveButton();

    void show_pay_saveButton();

    void show_units_saveButton();

    void show_staff_saveButton();

    void on_beds_addButton_clicked();

    void on_beds_delButton_clicked();

    void on_beds_saveButton_clicked();

    void on_clients_addButton_clicked();

    void on_clients_delButton_clicked();

    void on_toolButton_clicked();

    void getDate(QDate date);

    void on_clients_saveButton_clicked();

    void on_clientSearch_editTextChanged(const QString &arg1);

    void on_clientServicesView_doubleClicked(const QModelIndex &index);

    void on_servCombo_currentIndexChanged(int index);

    void on_serviceAccept_clicked();

    void on_tabWidget_2_tabBarClicked(int index);

    void on_table_addButton_clicked();

    void on_table_saveButton_clicked();

    void on_clientCombo_2_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_allClientsCheckBox_toggled(bool checked);

    void on_pickDateIn_clicked();

    void getDateIn(QDate date);

    void on_pickDateOut_clicked();

    void getDateOut(QDate date);

    void on_tabWidget_currentChanged(int index);

    void on_serv_addButton_clicked();

    void on_serv_delButton_clicked();

    void on_serv_saveButton_clicked();

    void on_pay_addButton_clicked();

    void on_pay_delButton_clicked();

    void on_pay_saveButton_clicked();

    void on_unit_addButton_clicked();

    void on_staff_delButton_clicked();

    void on_unit_saveButton_clicked();

    void on_unit_delButton_clicked();

    void on_staff_addButton_clicked();

    void on_staff_saveButton_clicked();

    void on_staffDatePick_clicked();

    void getDateForWorker(QDate date);

signals:

    void sendClientInfo(int id, QString name);

private:
    Ui::MainWin *ui;

    //комнаты
    QSqlRelationalTableModel *roomsModel;
    QSqlTableModel* roomCountModel;
    QSqlTableModel* roomBreakfastModel;
    QSqlTableModel* roomStatusModel;

    //кровати
    QSqlTableModel* bedsModel;

    //клиенты
    QSqlTableModel *clientsModel;
    QSqlRelationalTableModel *clientsTotalModel;
    QSqlRelationalTableModel *clientsTableModel;
    QSqlTableModel *servModel;

    //типы платежей
    QSqlTableModel *payModel;

    //доступные комнаты
    QSqlTableModel *avRooms;

    //клиенты проживающие в отеле
    QSqlQueryModel *hotelClients;

    //список услуг
    QSqlTableModel *servicesModel;

    //список способов оплаты
    QSqlTableModel *paymentsModel;

    //список подразделений
    QSqlTableModel *unitsModel;

    //список работников
    QSqlRelationalTableModel *staffModel;







};

#endif // MAINWIN_H
