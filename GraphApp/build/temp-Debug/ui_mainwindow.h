/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QPushButton *pushButtonFunction;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonRules;
    QPushButton *pushButtonExit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(600, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: rgba(200, 200, 200, 0.95);\n"
"    border: 1px solid #e0e0e0;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 581, 521));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(graphicsView, 0, 0, 4, 1);

        pushButtonFunction = new QPushButton(widget);
        pushButtonFunction->setObjectName("pushButtonFunction");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonFunction->sizePolicy().hasHeightForWidth());
        pushButtonFunction->setSizePolicy(sizePolicy);
        pushButtonFunction->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout->addWidget(pushButtonFunction, 2, 1, 1, 1);

        pushButtonClear = new QPushButton(widget);
        pushButtonClear->setObjectName("pushButtonClear");
        sizePolicy.setHeightForWidth(pushButtonClear->sizePolicy().hasHeightForWidth());
        pushButtonClear->setSizePolicy(sizePolicy);
        pushButtonClear->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout->addWidget(pushButtonClear, 1, 1, 1, 1);

        pushButtonRules = new QPushButton(widget);
        pushButtonRules->setObjectName("pushButtonRules");
        sizePolicy.setHeightForWidth(pushButtonRules->sizePolicy().hasHeightForWidth());
        pushButtonRules->setSizePolicy(sizePolicy);
        pushButtonRules->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout->addWidget(pushButtonRules, 3, 1, 1, 1);

        pushButtonExit = new QPushButton(widget);
        pushButtonExit->setObjectName("pushButtonExit");
        sizePolicy.setHeightForWidth(pushButtonExit->sizePolicy().hasHeightForWidth());
        pushButtonExit->setSizePolicy(sizePolicy);
        pushButtonExit->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout->addWidget(pushButtonExit, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "GraphApp", nullptr));
        pushButtonFunction->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214\n"
"\320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButtonRules->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\272\n"
"\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214\321\201\321\217?", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
