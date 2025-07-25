#include "vertex.h"

Vertex::Vertex() : text(nullptr), ellipse(nullptr) {}

Vertex::Vertex(QGraphicsTextItem *new_text, QGraphicsEllipseItem *new_ellipse)
{
    this->text=new_text;
    this->ellipse=new_ellipse;
}

QString Vertex::getNum() const noexcept
{
    return this->text->toPlainText();
}

bool Vertex::operator==(QGraphicsEllipseItem *other_ellipse) const noexcept
{
    return this->ellipse==other_ellipse;
}
