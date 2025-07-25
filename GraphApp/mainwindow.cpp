#include "mainwindow.h"
#include "ui_mainwindow.h"

static QSize main_window_size = {600, 600};
static Qt::GlobalColor color_workspace = Qt::white;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , workspace(new WorkSpace(new QGraphicsScene(this)))
{
    this->setFixedSize(main_window_size);
    ui->setupUi(this);

    workspace->setBackgroundBrush(color_workspace);
    workspace->setSceneRect(ui->graphicsView->rect());

    ui->centralwidget->setStyleSheet("QWidget { background: transparent; border: none; }");

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(workspace);
    ui->graphicsView->setMouseTracking(true);

    connect(ui->pushButtonExit,&QPushButton::clicked, this, &MainWindow::closeApp);
    connect(ui->pushButtonClear,&QPushButton::clicked, this, &MainWindow::clearWorkSpace);
    connect(ui->pushButtonFunction,&QPushButton::clicked, this, &MainWindow::openWindowFunc);
    connect(ui->pushButtonRules,&QPushButton::clicked, this, &MainWindow::getInfoApp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeApp()
{
    QCoreApplication::instance()->quit();
}

void MainWindow::clearWorkSpace()
{
    workspace->clearSpace();
}

void MainWindow::openWindowFunc()
{
    windowfunc = new WindowFunction(this->workspace);
    windowfunc ->setModal(false);
    windowfunc ->show();
}

void MainWindow::getInfoApp()
{
    QMessageBox information(this);
    information.setWindowTitle(tr("Инструкция по работе"));
    information.setFont(QFont("Arial", 16, QFont::Bold));

    information.setStyleSheet(
        "QMessageBox {"
        "   background-color: #f5f7fa;"
        "}"
        "QMessageBox QWidget {"
        "   background-color: #f5f7fa;"
        "   border: none;"
        "}"
        "QMessageBox QLabel {"
        "   color: #2c3e50;"
        "   min-width: 500px;"
        "}"
        "QMessageBox QPushButton {"
        "   background-color: #4a90e2;"
        "   color: white;"
        "   border-radius: 4px;"
        "   padding: 8px 16px;"
        "   font-weight: bold;"
        "   min-width: 80px;"
        "}"
        "QMessageBox QPushButton:hover {"
        "   background-color: #3a7bc8;"
        "}"
        "QMessageBox QPushButton:pressed {"
        "   background-color: #2a5b9e;"
        "}"
        );

    information.setText(tr(
                            "<h2 style='color:#e74c3c; margin-bottom:10px;'>Добро пожаловать!</h2>"
                            "<p style='margin-bottom:10px;'><b>Основные функции:</b></p>"
                            "<ul style='margin-left:15px; margin-bottom:15px;'>"
                            "<li style='margin-bottom:5px;'><b><u>Добавление вершины:</u></b> ЛКМ на пустой области сцены</li>"
                            "<li style='margin-bottom:5px;'><b><u>Добавление ребра:</u></b> ПКМ на вершину + перетаскивание</li>"
                            "<li style='margin-bottom:5px;'><b><u>Удаление:</u></b> Кнопка \"Очистить\" удаляет все элементы</li>"
                            "<li style='margin-bottom:5px;'><b><u>Изменение веса:</u></b> ЛКМ на LineEdit (диапазон 1-99)</li>"
                            "</ul>"
                            "<hr style='margin:10px 0; border:1px solid #ddd;'>"
                            "<p style='font-size:small; color:#7f8c8d;'>Версия: %1</p>"
                            "<p style='font-size:small; color:#7f8c8d;'>© NameInit, 2025</p>"
                            ).arg(QApplication::applicationVersion()));

    QPushButton *okButton = information.addButton(QMessageBox::Ok);
    okButton->setText(tr("Понятно"));
    okButton->setCursor(Qt::PointingHandCursor);

    information.setIcon(QMessageBox::NoIcon);

    information.exec();
}
/*
"<p><b>Горячие клавиши:</b></p>"
"<table border='1' cellpadding='4'>"
"<tr><td>Ctrl+N</td><td>Новый проект</td></tr>"
"<tr><td>Ctrl+S</td><td>Сохранить</td></tr>"
"<tr><td>Ctrl+Z</td><td>Отменить</td></tr>"
"<tr><td>F1</td><td>Справка</td></tr>"
"</table>"
*/


















