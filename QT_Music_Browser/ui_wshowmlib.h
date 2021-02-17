/********************************************************************************
** Form generated from reading UI file 'wshowmlib.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WSHOWMLIB_H
#define UI_WSHOWMLIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wShowMLib
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *wShowMLib)
    {
        if (wShowMLib->objectName().isEmpty())
            wShowMLib->setObjectName(QStringLiteral("wShowMLib"));
        wShowMLib->resize(330, 352);
        verticalLayout_2 = new QVBoxLayout(wShowMLib);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(wShowMLib);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 16pt \"MS Shell Dlg 2\";"));

        verticalLayout->addWidget(label);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(wShowMLib);

        QMetaObject::connectSlotsByName(wShowMLib);
    } // setupUi

    void retranslateUi(QWidget *wShowMLib)
    {
        wShowMLib->setWindowTitle(QApplication::translate("wShowMLib", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260", 0));
        label->setText(QApplication::translate("wShowMLib", "here's musECH librareh! :^)", 0));
    } // retranslateUi

};

namespace Ui {
    class wShowMLib: public Ui_wShowMLib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WSHOWMLIB_H
