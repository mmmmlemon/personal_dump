/********************************************************************************
** Form generated from reading UI file 'service_details.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICE_DETAILS_H
#define UI_SERVICE_DETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_service_details
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *details;

    void setupUi(QWidget *service_details)
    {
        if (service_details->objectName().isEmpty())
            service_details->setObjectName(QStringLiteral("service_details"));
        service_details->resize(497, 171);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/food.png"), QSize(), QIcon::Normal, QIcon::Off);
        service_details->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(service_details);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        details = new QTableView(service_details);
        details->setObjectName(QStringLiteral("details"));
        details->setEnabled(true);
        details->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(details);


        retranslateUi(service_details);

        QMetaObject::connectSlotsByName(service_details);
    } // setupUi

    void retranslateUi(QWidget *service_details)
    {
        service_details->setWindowTitle(QApplication::translate("service_details", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class service_details: public Ui_service_details {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICE_DETAILS_H
