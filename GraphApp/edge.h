#ifndef EDGE_H
#define EDGE_H

#include <QString>
#include <QLineEdit>
#include <QGraphicsLineItem>

#include "vertex.h"

class Edge
{
private:
    QLineEdit *line_edit;
    QGraphicsLineItem *line_item;
    Vertex *vertex1;
    Vertex *vertex2;

public:
    Edge();
    Edge(QLineEdit *new_line_edit, QGraphicsLineItem *new_line_item, Vertex *new_vertex1, Vertex *new_vertex2);

    QString getWeight() const noexcept;
    void swap_vertex();
    Vertex* get_vertex1() const noexcept;
    Vertex* get_vertex2() const noexcept;
};

#endif // EDGE_H
