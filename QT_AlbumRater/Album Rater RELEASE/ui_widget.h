/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Wed 4. Feb 19:33:23 2015
**      by: Qt User Interface Compiler version 4.6.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineArtist;
    QLabel *label_6;
    QComboBox *comboBox;
    QLabel *label_2;
    QLineEdit *lineAlbum;
    QLabel *label_3;
    QLineEdit *lineYear;
    QLabel *label_4;
    QDoubleSpinBox *ratingSpinBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addButton;
    QPushButton *removeButton;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLineEdit *queryLine;
    QPushButton *queryButton;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QComboBox *onlyYearCombo;
    QPushButton *showYear;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_7;
    QComboBox *onlyRatingCombo;
    QPushButton *showRating;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QComboBox *onlyArtistCombo;
    QPushButton *showArtistsButton;
    QTableView *tableView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(598, 947);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/vinyl.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        verticalLayout_10 = new QVBoxLayout(Widget);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineArtist = new QLineEdit(groupBox);
        lineArtist->setObjectName(QString::fromUtf8("lineArtist"));

        verticalLayout->addWidget(lineArtist);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineAlbum = new QLineEdit(groupBox);
        lineAlbum->setObjectName(QString::fromUtf8("lineAlbum"));

        verticalLayout->addWidget(lineAlbum);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        lineYear = new QLineEdit(groupBox);
        lineYear->setObjectName(QString::fromUtf8("lineYear"));

        verticalLayout->addWidget(lineYear);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        ratingSpinBox = new QDoubleSpinBox(groupBox);
        ratingSpinBox->setObjectName(QString::fromUtf8("ratingSpinBox"));

        verticalLayout->addWidget(ratingSpinBox);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        addButton = new QPushButton(groupBox);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon1);

        verticalLayout_2->addWidget(addButton);

        removeButton = new QPushButton(groupBox);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeButton->setIcon(icon2);
        removeButton->setIconSize(QSize(16, 16));
        removeButton->setAutoRepeat(false);

        verticalLayout_2->addWidget(removeButton);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout->addWidget(groupBox);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        queryLine = new QLineEdit(groupBox_2);
        queryLine->setObjectName(QString::fromUtf8("queryLine"));

        verticalLayout_4->addWidget(queryLine);

        queryButton = new QPushButton(groupBox_2);
        queryButton->setObjectName(QString::fromUtf8("queryButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        queryButton->setIcon(icon3);

        verticalLayout_4->addWidget(queryButton);


        verticalLayout_9->addWidget(groupBox_2);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        onlyYearCombo = new QComboBox(groupBox_4);
        onlyYearCombo->setObjectName(QString::fromUtf8("onlyYearCombo"));

        verticalLayout_6->addWidget(onlyYearCombo);

        showYear = new QPushButton(groupBox_4);
        showYear->setObjectName(QString::fromUtf8("showYear"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/show.png"), QSize(), QIcon::Normal, QIcon::Off);
        showYear->setIcon(icon4);

        verticalLayout_6->addWidget(showYear);


        verticalLayout_8->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(Widget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_7 = new QVBoxLayout(groupBox_5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        onlyRatingCombo = new QComboBox(groupBox_5);
        onlyRatingCombo->setObjectName(QString::fromUtf8("onlyRatingCombo"));

        verticalLayout_7->addWidget(onlyRatingCombo);

        showRating = new QPushButton(groupBox_5);
        showRating->setObjectName(QString::fromUtf8("showRating"));
        showRating->setIcon(icon4);

        verticalLayout_7->addWidget(showRating);


        verticalLayout_8->addWidget(groupBox_5);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        onlyArtistCombo = new QComboBox(groupBox_3);
        onlyArtistCombo->setObjectName(QString::fromUtf8("onlyArtistCombo"));

        verticalLayout_5->addWidget(onlyArtistCombo);

        showArtistsButton = new QPushButton(groupBox_3);
        showArtistsButton->setObjectName(QString::fromUtf8("showArtistsButton"));
        showArtistsButton->setIcon(icon4);

        verticalLayout_5->addWidget(showArtistsButton);


        verticalLayout_8->addWidget(groupBox_3);


        verticalLayout_9->addLayout(verticalLayout_8);


        horizontalLayout_2->addLayout(verticalLayout_9);


        verticalLayout_10->addLayout(horizontalLayout_2);

        tableView = new QTableView(Widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_10->addWidget(tableView);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Album List", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Widget", "Edit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "Artist/Band", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "Artist/Band from the current list", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "Album", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "Year", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "Rating", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("Widget", "Add", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("Widget", "Remove selected", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Widget", "Filter", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "Sql Query", 0, QApplication::UnicodeUTF8));
        queryButton->setText(QApplication::translate("Widget", "Send", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Widget", "Show only [year]", 0, QApplication::UnicodeUTF8));
        showYear->setText(QApplication::translate("Widget", "Show", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("Widget", "Show only [rating]", 0, QApplication::UnicodeUTF8));
        showRating->setText(QApplication::translate("Widget", "Show", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Widget", "Show only [artist]", 0, QApplication::UnicodeUTF8));
        showArtistsButton->setText(QApplication::translate("Widget", "Show", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
