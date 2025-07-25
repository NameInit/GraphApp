/********************************************************************************
** Form generated from reading UI file 'windowfunction.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWFUNCTION_H
#define UI_WINDOWFUNCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowFunction
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonPaint;
    QPushButton *pushButtonSearchWidth;
    QPushButton *pushButtonAdjVertex;
    QPushButton *pushButtonAdjEdge;
    QPushButton *pushButtonDeikstra;
    QPushButton *pushButtonIncidence;
    QPushButton *pushButtonFord;
    QPushButton *pushButtonExit;
    QPushButton *pushButtonSearchDepth;
    QPushButton *pushButtonCodeP;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *WindowFunction)
    {
        if (WindowFunction->objectName().isEmpty())
            WindowFunction->setObjectName("WindowFunction");
        WindowFunction->resize(563, 477);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WindowFunction->sizePolicy().hasHeightForWidth());
        WindowFunction->setSizePolicy(sizePolicy);
        WindowFunction->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: rgba(200, 200, 200, 0.95);\n"
"    border: none;\n"
"}"));
        layoutWidget = new QWidget(WindowFunction);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 541, 461));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonPaint = new QPushButton(layoutWidget);
        pushButtonPaint->setObjectName("pushButtonPaint");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonPaint->sizePolicy().hasHeightForWidth());
        pushButtonPaint->setSizePolicy(sizePolicy1);
        pushButtonPaint->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout_2->addWidget(pushButtonPaint, 1, 2, 1, 1);

        pushButtonSearchWidth = new QPushButton(layoutWidget);
        pushButtonSearchWidth->setObjectName("pushButtonSearchWidth");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonSearchWidth->sizePolicy().hasHeightForWidth());
        pushButtonSearchWidth->setSizePolicy(sizePolicy2);
        pushButtonSearchWidth->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout_2->addWidget(pushButtonSearchWidth, 1, 0, 1, 1);

        pushButtonAdjVertex = new QPushButton(layoutWidget);
        pushButtonAdjVertex->setObjectName("pushButtonAdjVertex");
        sizePolicy1.setHeightForWidth(pushButtonAdjVertex->sizePolicy().hasHeightForWidth());
        pushButtonAdjVertex->setSizePolicy(sizePolicy1);
        pushButtonAdjVertex->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout_2->addWidget(pushButtonAdjVertex, 0, 0, 1, 1);

        pushButtonAdjEdge = new QPushButton(layoutWidget);
        pushButtonAdjEdge->setObjectName("pushButtonAdjEdge");
        sizePolicy1.setHeightForWidth(pushButtonAdjEdge->sizePolicy().hasHeightForWidth());
        pushButtonAdjEdge->setSizePolicy(sizePolicy1);
        pushButtonAdjEdge->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout_2->addWidget(pushButtonAdjEdge, 0, 1, 1, 1);

        pushButtonDeikstra = new QPushButton(layoutWidget);
        pushButtonDeikstra->setObjectName("pushButtonDeikstra");
        sizePolicy2.setHeightForWidth(pushButtonDeikstra->sizePolicy().hasHeightForWidth());
        pushButtonDeikstra->setSizePolicy(sizePolicy2);
        pushButtonDeikstra->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout_2->addWidget(pushButtonDeikstra, 2, 0, 1, 1);

        pushButtonIncidence = new QPushButton(layoutWidget);
        pushButtonIncidence->setObjectName("pushButtonIncidence");
        sizePolicy2.setHeightForWidth(pushButtonIncidence->sizePolicy().hasHeightForWidth());
        pushButtonIncidence->setSizePolicy(sizePolicy2);
        pushButtonIncidence->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout_2->addWidget(pushButtonIncidence, 0, 2, 1, 1);

        pushButtonFord = new QPushButton(layoutWidget);
        pushButtonFord->setObjectName("pushButtonFord");
        sizePolicy1.setHeightForWidth(pushButtonFord->sizePolicy().hasHeightForWidth());
        pushButtonFord->setSizePolicy(sizePolicy1);
        pushButtonFord->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout_2->addWidget(pushButtonFord, 2, 2, 1, 1);

        pushButtonExit = new QPushButton(layoutWidget);
        pushButtonExit->setObjectName("pushButtonExit");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButtonExit->sizePolicy().hasHeightForWidth());
        pushButtonExit->setSizePolicy(sizePolicy3);
        pushButtonExit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ff5555;\n"
"    color: #000000;          \n"
"    border: 2px solid #cc0000;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px;\n"
"    font: bold 14px 'Arial';\n"
"    min-width: 100px;\n"
"    outline: none;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #ff7777;\n"
"    border-color: #dd2222;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #dd2222;\n"
"    border-color: #bb1111;\n"
"    color: #111111;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #aa9999;\n"
"    color: #555555;\n"
"    border-color: #998888;\n"
"}"));

        gridLayout_2->addWidget(pushButtonExit, 4, 1, 1, 1);

        pushButtonSearchDepth = new QPushButton(layoutWidget);
        pushButtonSearchDepth->setObjectName("pushButtonSearchDepth");
        sizePolicy1.setHeightForWidth(pushButtonSearchDepth->sizePolicy().hasHeightForWidth());
        pushButtonSearchDepth->setSizePolicy(sizePolicy1);
        pushButtonSearchDepth->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout_2->addWidget(pushButtonSearchDepth, 1, 1, 1, 1);

        pushButtonCodeP = new QPushButton(layoutWidget);
        pushButtonCodeP->setObjectName("pushButtonCodeP");
        sizePolicy1.setHeightForWidth(pushButtonCodeP->sizePolicy().hasHeightForWidth());
        pushButtonCodeP->setSizePolicy(sizePolicy1);
        pushButtonCodeP->setStyleSheet(QString::fromUtf8("QPushButton { background: #00b4d8; color: #222222; border: 1px solid #0096c7; border-bottom: 3px solid #0096c7; border-radius: 8px; padding: 10px 20px; font: bold 14px; } QPushButton:hover { background: #48cae4; border-bottom: 3px solid #00a8e8; } QPushButton:pressed { background: #0096c7; border-bottom: 1px solid #0077b6; margin-top: 2px; }"));

        gridLayout_2->addWidget(pushButtonCodeP, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 3, 1, 1, 1);


        retranslateUi(WindowFunction);

        QMetaObject::connectSlotsByName(WindowFunction);
    } // setupUi

    void retranslateUi(QDialog *WindowFunction)
    {
        WindowFunction->setWindowTitle(QCoreApplication::translate("WindowFunction", "Function", nullptr));
        pushButtonPaint->setText(QCoreApplication::translate("WindowFunction", "\320\227\320\260\320\272\321\200\320\260\321\201\320\272\320\260", nullptr));
        pushButtonSearchWidth->setText(QCoreApplication::translate("WindowFunction", "\320\237\320\276\320\270\321\201\320\272 \320\262\n"
"\321\210\320\270\321\200\320\270\320\275\321\203", nullptr));
        pushButtonAdjVertex->setText(QCoreApplication::translate("WindowFunction", "\320\234\320\260\321\202\321\200\320\270\321\206\320\260\n"
"\321\201\320\274\320\265\320\266\320\275\320\276\321\201\321\202\320\270\n"
"\320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        pushButtonAdjEdge->setText(QCoreApplication::translate("WindowFunction", "\320\234\320\260\321\202\321\200\320\270\321\206\320\260\n"
"\321\201\320\274\320\265\320\266\320\275\320\276\321\201\321\202\320\270\n"
"\321\200\321\221\320\261\320\265\321\200", nullptr));
        pushButtonDeikstra->setText(QCoreApplication::translate("WindowFunction", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274\n"
"\320\224\320\265\320\271\320\272\321\201\321\202\321\200\321\213", nullptr));
        pushButtonIncidence->setText(QCoreApplication::translate("WindowFunction", "\320\234\320\260\321\202\321\200\320\270\321\206\320\260\n"
"\320\270\320\275\321\206\320\270\320\264\320\265\320\275-\n"
"\321\202\320\275\320\276\321\201\321\202\320\270", nullptr));
        pushButtonFord->setText(QCoreApplication::translate("WindowFunction", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274\n"
"\320\244\320\276\321\200\320\264\320\260", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("WindowFunction", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        pushButtonSearchDepth->setText(QCoreApplication::translate("WindowFunction", "\320\237\320\276\320\270\321\201\320\272 \320\262\n"
"\320\263\320\273\321\203\320\261\320\270\320\275\321\203", nullptr));
        pushButtonCodeP->setText(QCoreApplication::translate("WindowFunction", "\320\232\320\276\320\264\n"
"\320\237\321\200\321\216\321\204\320\265\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowFunction: public Ui_WindowFunction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWFUNCTION_H
