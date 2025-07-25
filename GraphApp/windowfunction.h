#ifndef WINDOWFUNCTION_H
#define WINDOWFUNCTION_H

#include <QDialog>
#include <QGuiApplication>
#include <QTableWidget>
#include <QHeaderView>
#include <QStack>
#include <QMessageBox>

#include "workspace.h"

namespace Ui {
class WindowFunction;
}

class WindowFunction : public QDialog
{
    Q_OBJECT

public:
    explicit WindowFunction(WorkSpace *workspace_, QWidget *parent = nullptr);
    ~WindowFunction();

private slots:
    void closeWindow();
    void showMatrixAdjVertex();
    void showMatrixAdjEdge();
    void showMatrixIncidence();
    void searchWidth();
    void searchDepth();
    void paintGraph();
    void algDeikstra();
    void showCodeP();
    void algFord();

private:
    Ui::WindowFunction *ui;
    WorkSpace *workspace;

    QVector<QVector<QString>> createMatrixAdjVertex();
    QVector<QVector<QString>> createMatrixAdjEdge();
    QVector<QVector<QString>> createMatrixAdjIncidence();
    void windowMatrix(QStringList label_h, QStringList label_v, QVector<QVector<QString>> matrix) const;
};

#endif // WINDOWFUNCTION_H
