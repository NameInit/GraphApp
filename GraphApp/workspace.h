#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsSceneMouseEvent>
#include <QLineEdit>
#include <QApplication>
#include <QRegularExpressionValidator>

#include "vertex.h"
#include "edge.h"


class WorkSpace : public QGraphicsScene
{
    Q_OBJECT
public:
    WorkSpace(QObject *parent = nullptr);
    void clearSpace();
    void sortEdges();
    QVector<Edge>& getAllEdge();
    QVector<Vertex>& getAllVertex();
    void updateWorkSpace();
    Qt::GlobalColor getBaseColorVertex();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QVector<Vertex> vertexes;
    QVector<Edge> edges;
};

#endif // WORKSPACE_H
