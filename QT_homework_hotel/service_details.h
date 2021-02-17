#ifndef SERVICE_DETAILS_H
#define SERVICE_DETAILS_H

#include <QWidget>

namespace Ui {
class service_details;
}

class service_details : public QWidget
{
    Q_OBJECT

public:
    explicit service_details(QWidget *parent = 0);
    ~service_details();

private:
    Ui::service_details *ui;


private slots:
    void getClientInfo(int id, QString name);
};

#endif // SERVICE_DETAILS_H
