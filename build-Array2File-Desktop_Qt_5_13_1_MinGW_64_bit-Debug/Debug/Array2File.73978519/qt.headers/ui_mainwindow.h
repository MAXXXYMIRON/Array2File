/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ButtonStart;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *spinBoxRow;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSpinBox *spinBoxCol;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QTableWidget *TWFileArr;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableWidget *TWFirstArr;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTableWidget *TWSecondArr;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(794, 444);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ButtonStart = new QPushButton(centralwidget);
        ButtonStart->setObjectName(QString::fromUtf8("ButtonStart"));
        ButtonStart->setGeometry(QRect(110, 380, 611, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Mistral"));
        font.setPointSize(14);
        ButtonStart->setFont(font);
        ButtonStart->setCursor(QCursor(Qt::PointingHandCursor));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 330, 611, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        spinBoxRow = new QSpinBox(layoutWidget);
        spinBoxRow->setObjectName(QString::fromUtf8("spinBoxRow"));

        horizontalLayout_3->addWidget(spinBoxRow);


        horizontalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        spinBoxCol = new QSpinBox(layoutWidget);
        spinBoxCol->setObjectName(QString::fromUtf8("spinBoxCol"));

        horizontalLayout->addWidget(spinBoxCol);


        horizontalLayout_2->addLayout(horizontalLayout);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(270, 50, 258, 213));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        TWFileArr = new QTableWidget(layoutWidget1);
        TWFileArr->setObjectName(QString::fromUtf8("TWFileArr"));
        TWFileArr->horizontalHeader()->setMinimumSectionSize(20);
        TWFileArr->horizontalHeader()->setDefaultSectionSize(20);
        TWFileArr->verticalHeader()->setMinimumSectionSize(20);
        TWFileArr->verticalHeader()->setDefaultSectionSize(20);

        verticalLayout->addWidget(TWFileArr);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 0, 258, 213));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        TWFirstArr = new QTableWidget(layoutWidget2);
        TWFirstArr->setObjectName(QString::fromUtf8("TWFirstArr"));
        TWFirstArr->horizontalHeader()->setMinimumSectionSize(20);
        TWFirstArr->horizontalHeader()->setDefaultSectionSize(20);
        TWFirstArr->verticalHeader()->setMinimumSectionSize(20);
        TWFirstArr->verticalHeader()->setDefaultSectionSize(20);

        verticalLayout_2->addWidget(TWFirstArr);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(530, 0, 258, 213));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        TWSecondArr = new QTableWidget(layoutWidget3);
        TWSecondArr->setObjectName(QString::fromUtf8("TWSecondArr"));
        TWSecondArr->horizontalHeader()->setMinimumSectionSize(20);
        TWSecondArr->horizontalHeader()->setDefaultSectionSize(20);
        TWSecondArr->verticalHeader()->setMinimumSectionSize(20);
        TWSecondArr->verticalHeader()->setDefaultSectionSize(20);

        verticalLayout_3->addWidget(TWSecondArr);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\2602\320\23219\320\222\320\265\320\272\320\260", nullptr));
        ButtonStart->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\320\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \321\201\321\202\321\200\320\276\320\272 -", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273 - \320\262\320\276 \321\201\321\202\320\276\320\273\320\261\321\206\320\276\320\262 -", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262\321\213\320\271 \320\274\320\260\321\201\321\201\320\270\320\262 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262\321\213\320\271 \320\274\320\260\321\201\321\201\320\270\320\262  ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\202\320\276\321\200\320\276\320\271 \320\274\320\260\321\201\321\201\320\270\320\262  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
