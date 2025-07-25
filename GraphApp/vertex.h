#ifndef VERTEX_H
#define VERTEX_H

#include <QString>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>

class Vertex
{
private:
    QGraphicsTextItem *text;
    QGraphicsEllipseItem *ellipse;

public:
    Vertex();
    Vertex(QGraphicsTextItem *new_text, QGraphicsEllipseItem *new_ellipse);

    QString getNum() const noexcept;
    bool operator==(QGraphicsEllipseItem *other_ellipse) const noexcept;
};

#endif // VERTEX_H
