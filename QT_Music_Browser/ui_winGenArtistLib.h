/********************************************************************************
** Form generated from reading UI file 'winGenArtistLib.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINGENARTISTLIB_H
#define UI_WINGENARTISTLIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_winGenArtistLib
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;

    void setupUi(QWidget *winGenArtistLib)
    {
        if (winGenArtistLib->objectName().isEmpty())
            winGenArtistLib->setObjectName(QStringLiteral("winGenArtistLib"));
        winGenArtistLib->resize(594, 419);
        winGenArtistLib->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(winGenArtistLib);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scrollArea = new QScrollArea(winGenArtistLib);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 574, 399));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(winGenArtistLib);

        QMetaObject::connectSlotsByName(winGenArtistLib);
    } // setupUi

    void retranslateUi(QWidget *winGenArtistLib)
    {
        winGenArtistLib->setWindowTitle(QApplication::translate("winGenArtistLib", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class winGenArtistLib: public Ui_winGenArtistLib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINGENARTISTLIB_H
