/********************************************************************************
** Form generated from reading UI file 'date_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATE_EDIT_H
#define UI_DATE_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_date_edit
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *day;
    QSpinBox *year;
    QComboBox *month;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *date_edit)
    {
        if (date_edit->objectName().isEmpty())
            date_edit->setObjectName(QStringLiteral("date_edit"));
        date_edit->resize(453, 88);
        date_edit->setMaximumSize(QSize(16777215, 88));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/date.png"), QSize(), QIcon::Normal, QIcon::Off);
        date_edit->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(date_edit);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(date_edit);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(date_edit);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(date_edit);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        day = new QSpinBox(date_edit);
        day->setObjectName(QStringLiteral("day"));
        day->setWrapping(false);
        day->setFrame(true);
        day->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        day->setAccelerated(true);
        day->setProperty("showGroupSeparator", QVariant(false));
        day->setMinimum(1);
        day->setMaximum(31);
        day->setSingleStep(1);

        gridLayout->addWidget(day, 1, 2, 1, 1);

        year = new QSpinBox(date_edit);
        year->setObjectName(QStringLiteral("year"));
        year->setMinimum(1900);
        year->setMaximum(3000);
        year->setValue(2000);

        gridLayout->addWidget(year, 1, 0, 1, 1);

        month = new QComboBox(date_edit);
        month->setObjectName(QStringLiteral("month"));

        gridLayout->addWidget(month, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(date_edit);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(date_edit);
        QObject::connect(buttonBox, SIGNAL(accepted()), date_edit, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), date_edit, SLOT(reject()));

        QMetaObject::connectSlotsByName(date_edit);
    } // setupUi

    void retranslateUi(QDialog *date_edit)
    {
        date_edit->setWindowTitle(QApplication::translate("date_edit", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\321\202\321\203", Q_NULLPTR));
        label->setText(QApplication::translate("date_edit", "\320\223\320\276\320\264", Q_NULLPTR));
        label_2->setText(QApplication::translate("date_edit", "\320\234\320\265\321\201\321\217\321\206", Q_NULLPTR));
        label_3->setText(QApplication::translate("date_edit", "\320\224\320\265\320\275\321\214", Q_NULLPTR));
        day->setPrefix(QString());
        month->clear();
        month->insertItems(0, QStringList()
         << QApplication::translate("date_edit", "\320\257\320\275\320\262\320\260\321\200\321\214", Q_NULLPTR)
         << QApplication::translate("date_edit", "\320\244\320\265\320\262\321\200\320\260\320\273\321\214", Q_NULLPTR)
         << QApplication::translate("date_edit", "\320\234\320\260\321\200\321\202", Q_NULLPTR)
         << QApplication::translate("date_edit", "\320\220\320\277\321\200\320\265\320\273\321\214", Q_NULLPTR)
         << QApplication::translate("date_edit", "\320\234\320\260\320\271", Q_NULLPTR)
         << QApplication::translate("date_edit", "\320\230\321\216\320\275\321\214", Q_NULLPTR)
         << QApplication::translate("date_edit", "\320\230\321\216\320\273\321\214", Q_NULLPTR)
         << QApplication::translate("date_edit", "\320\220\320\262\320\263\321\203\321\201\321\202", Q_NULLPTR)
         << QApplication::translate("date_edit", "\320\241\320\265\320\275\321\202\321\217\320\261\321\200\321\214", Q_NULLPTR)
         << QApplication::translate("date_edit", "\320\236\320\272\321\202\321\217\320\261\321\200\321\214", Q_NULLPTR)
         << QApplication::translate("date_edit", "\320\235\320\276\321\217\320\261\321\200\321\214", Q_NULLPTR)
         << QApplication::translate("date_edit", "\320\224\320\265\320\272\320\260\320\261\321\200\321\214", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class date_edit: public Ui_date_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATE_EDIT_H
