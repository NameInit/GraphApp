#include "edge.h"

Edge::Edge() : line_edit(nullptr), line_item(nullptr), vertex1(nullptr), vertex2(nullptr) {}

Edge::Edge(QLineEdit *new_line_edit, QGraphicsLineItem *new_line_item, Vertex *new_vertex1, Vertex *new_vertex2)
{
    this->line_edit=new_line_edit;
    this->line_item = new_line_item;
    this->vertex1 = new_vertex1;
    this->vertex2 = new_vertex2;
}

QString Edge::getWeight() const noexcept
{
    return this->line_edit->text();
}

void Edge::swap_vertex()
{
    std::swap(vertex1,vertex2);
}

Vertex *Edge::get_vertex1() const noexcept
{
    return this->vertex1;
}

Vertex *Edge::get_vertex2() const noexcept
{
    return this->vertex2;
}
