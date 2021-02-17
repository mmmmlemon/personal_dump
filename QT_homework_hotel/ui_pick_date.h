/********************************************************************************
** Form generated from reading UI file 'pick_date.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICK_DATE_H
#define UI_PICK_DATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_pick_date
{
public:
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *pick_date)
    {
        if (pick_date->objectName().isEmpty())
            pick_date->setObjectName(QStringLiteral("pick_date"));
        pick_date->resize(330, 230);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/date.png"), QSize(), QIcon::Normal, QIcon::Off);
        pick_date->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(pick_date);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        calendarWidget = new QCalendarWidget(pick_date);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGridVisible(true);
        calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);

        verticalLayout->addWidget(calendarWidget);

        buttonBox = new QDialogButtonBox(pick_date);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(pick_date);
        QObject::connect(buttonBox, SIGNAL(accepted()), pick_date, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), pick_date, SLOT(reject()));

        QMetaObject::connectSlotsByName(pick_date);
    } // setupUi

    void retranslateUi(QDialog *pick_date)
    {
        pick_date->setWindowTitle(QApplication::translate("pick_date", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\264\320\260\321\202\321\203", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pick_date: public Ui_pick_date {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICK_DATE_H
