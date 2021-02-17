/********************************************************************************
** Form generated from reading UI file 'wgenmuslib.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGENMUSLIB_H
#define UI_WGENMUSLIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wGenMusLib
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *wGenMusLib)
    {
        if (wGenMusLib->objectName().isEmpty())
            wGenMusLib->setObjectName(QStringLiteral("wGenMusLib"));
        wGenMusLib->resize(398, 383);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/debug/icons/genmuslib_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        wGenMusLib->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(wGenMusLib);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scrollArea = new QScrollArea(wGenMusLib);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 378, 363));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout->addLayout(gridLayout);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);


        retranslateUi(wGenMusLib);

        QMetaObject::connectSlotsByName(wGenMusLib);
    } // setupUi

    void retranslateUi(QWidget *wGenMusLib)
    {
        wGenMusLib->setWindowTitle(QApplication::translate("wGenMusLib", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260", 0));
        pushButton->setText(QApplication::translate("wGenMusLib", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class wGenMusLib: public Ui_wGenMusLib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGENMUSLIB_H
