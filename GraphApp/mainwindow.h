#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGuiApplication>
#include <QMessageBox>

#include "workspace.h"
#include <windowfunction.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void closeApp();
    void clearWorkSpace();
    void openWindowFunc();
    void getInfoApp();

private:
    Ui::MainWindow *ui;
    WorkSpace *workspace;
    WindowFunction *windowfunc;
};

#endif // MAINWINDOW_H
