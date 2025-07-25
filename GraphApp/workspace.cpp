#include <QDebug>

#include "workspace.h"

constexpr static auto getCustomPen=[](){ return QPen(Qt::black, 2); };
constexpr static quint16 radius_vertex = 20;
constexpr static Qt::GlobalColor color_vertex = Qt::red;
constexpr static quint16 max_count_vertex = 20;
static QGraphicsItem *first_click_vertex=nullptr;
static bool right_mouse_is_active = false;
static QGraphicsLineItem *new_edge = nullptr;
static quint16 count_vertex=0;
static QLineEdit *last_edit_line = nullptr;

WorkSpace::WorkSpace(QObject *parent) : QGraphicsScene(parent) { }

void WorkSpace::clearSpace()
{
    this->blockSignals(true);
    this->clear();
    this->edges.clear();
    this->edges.shrink_to_fit();
    this->vertexes.clear();
    this->vertexes.shrink_to_fit();
    this->blockSignals(false);
    count_vertex=0;
}

void WorkSpace::sortEdges()
{
    for(auto &edge : this->edges){
        if(edge.get_vertex1()->getNum().toInt()>edge.get_vertex2()->getNum().toInt()){
            edge.swap_vertex();
        }
    }
    std::sort(this->edges.begin(), this->edges.end(), [](const Edge &e1, const Edge &e2){
        return e1.get_vertex1()->getNum().toInt()!=e2.get_vertex1()->getNum().toInt() ?
                   e1.get_vertex1()->getNum().toInt()<e2.get_vertex1()->getNum().toInt() :
                   e1.get_vertex2()->getNum().toInt()<e2.get_vertex2()->getNum().toInt();
    });
}

QVector<Edge>& WorkSpace::getAllEdge()
{
    return this->edges;
}

QVector<Vertex>& WorkSpace::getAllVertex()
{
    return this->vertexes;
}

void WorkSpace::updateWorkSpace()
{
    this->update();
}

Qt::GlobalColor WorkSpace::getBaseColorVertex()
{
    return color_vertex;
}

void WorkSpace::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    // qDebug()<<"Vertexes:";
    // for(auto &i : this->vertexes){
    //     qDebug()<<&i << ' ' << i.getNum();
    // }
    // qDebug()<<"Edges:";
    // for(auto &i : this->edges){
    //     qDebug()<<i.get_vertex1();
    //     qDebug() << i.get_vertex1()->getNum();
    //     qDebug() << i.get_vertex2();
    //     qDebug() << i.get_vertex2()->getNum();
    // }
    if(this->itemAt(event->scenePos(), QTransform())&&
        (this->itemAt(event->scenePos(), QTransform())->type()==QGraphicsProxyWidget::Type)){
        last_edit_line=qobject_cast<QLineEdit*>(qgraphicsitem_cast<QGraphicsProxyWidget*>(this->itemAt(event->scenePos(), QTransform()))->widget());
    }

    if(last_edit_line&&(last_edit_line->text().size()==0)){
        last_edit_line->setText("1");
    }

    if((event->button()==Qt::LeftButton)&&
        ((this->itemAt(event->scenePos(), QTransform()))==nullptr)&&
        (count_vertex<max_count_vertex)){

        QGraphicsEllipseItem *new_ellipse = new QGraphicsEllipseItem(event->scenePos().x()-radius_vertex,
                                                            event->scenePos().y()-radius_vertex,
                                                            radius_vertex*2,
                                                            radius_vertex*2);

        new_ellipse->setBrush(color_vertex);
        new_ellipse->setPen(getCustomPen());

        bool correct_item = true;
        for(auto &item : this->items()){
            if((item->type()==QGraphicsEllipseItem::Type)&&((new_ellipse->boundingRect().intersects(item->boundingRect())))){
                correct_item=false;
                delete new_ellipse;
                break;
            }
        }

        if(correct_item){
            QGraphicsTextItem *num_vertex = new QGraphicsTextItem();
            num_vertex->setPlainText(QString::number(count_vertex++));
            num_vertex->setPos(new_ellipse->boundingRect().x()+2,new_ellipse->boundingRect().y()+2);
            num_vertex->setDefaultTextColor(Qt::black);
            num_vertex->setFont(QFont("Arial", 20, QFont::Black));
            this->addItem(new_ellipse);
            this->addItem(num_vertex);
            this->vertexes.push_back(Vertex(num_vertex, new_ellipse));
        }
    }
    else if(event->button() == Qt::RightButton){
        for(auto &item : this->items()){
            if((item->type() == QGraphicsEllipseItem::Type)&&(item->contains(event->scenePos()))){
                first_click_vertex=item;
                break;
            }
        }

        if(first_click_vertex){
            new_edge = new QGraphicsLineItem(event->scenePos().x(),event->scenePos().y(),event->scenePos().x(),event->scenePos().y());
            new_edge->setPen(getCustomPen());
            this->addItem(new_edge);
        }

        right_mouse_is_active=true;
    }
    QGraphicsScene::mousePressEvent(event);
}

void WorkSpace::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if(right_mouse_is_active){
        if(new_edge){
            double temp_dx = (event->scenePos().x() - (first_click_vertex->boundingRect().x()+first_click_vertex->boundingRect().height()/2));
            double temp_dy = (event->scenePos().y() - (first_click_vertex->boundingRect().y()+first_click_vertex->boundingRect().width()/2));
            double len_new_edge = qSqrt(temp_dx*temp_dx+temp_dy*temp_dy);
            double dx=temp_dx/len_new_edge;
            double dy=temp_dy/len_new_edge;
            new_edge->setLine(first_click_vertex->boundingRect().x()+first_click_vertex->boundingRect().height()/2+dx*radius_vertex,
                              first_click_vertex->boundingRect().y()+first_click_vertex->boundingRect().width()/2+dy*radius_vertex,
                              event->scenePos().x(), event->scenePos().y());
            this->update();
        }
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void WorkSpace::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if(event->button() == Qt::RightButton){
        QGraphicsItem *second_click_vertex = nullptr;
        for(auto &item : this->items()){
            if((item->type() == QGraphicsEllipseItem::Type)&&(item->contains(event->scenePos()))){
                second_click_vertex = item;
                break;
            }
        }

        if(first_click_vertex){
            if(this->items().contains(new_edge)){
                this->removeItem(new_edge);
            }
        }

        if(second_click_vertex&&first_click_vertex&&(first_click_vertex->boundingRect()!=second_click_vertex->boundingRect())){
            double temp_dx = ((second_click_vertex->boundingRect().x()+second_click_vertex->boundingRect().height()/2) - (first_click_vertex->boundingRect().x()+first_click_vertex->boundingRect().height()/2));
            double temp_dy = ((second_click_vertex->boundingRect().y()+second_click_vertex->boundingRect().width()/2) - (first_click_vertex->boundingRect().y()+first_click_vertex->boundingRect().width()/2));
            double len_new_edge = qSqrt(temp_dx*temp_dx+temp_dy*temp_dy);
            double dx=temp_dx/len_new_edge;
            double dy=temp_dy/len_new_edge;
            new_edge->setLine(first_click_vertex->boundingRect().x()+first_click_vertex->boundingRect().height()/2+dx*radius_vertex,
                              first_click_vertex->boundingRect().y()+first_click_vertex->boundingRect().width()/2+dy*radius_vertex,
                              second_click_vertex->boundingRect().x()+second_click_vertex->boundingRect().height()/2-dx*radius_vertex,
                              second_click_vertex->boundingRect().y()+second_click_vertex->boundingRect().width()/2-dy*radius_vertex);

            bool is_not_copy_edge = true;
            for(auto &item : this->items()){
                if(item->boundingRect()==new_edge->boundingRect()){
                    is_not_copy_edge=false;
                    break;
                }
            }

            if(is_not_copy_edge){
                this->addItem(new_edge);
                QLineEdit *weight_edge = new QLineEdit("1");
                weight_edge->setMaximumWidth(30);
                weight_edge->setStyleSheet("background: transparent; color: black; border: none;");
                weight_edge->setFont(QFont("Arial", 18, QFont::Black));
                weight_edge->setValidator(new QRegularExpressionValidator(QRegularExpression("[1-9][0-9]?")));
                QGraphicsProxyWidget *proxy = this->addWidget(weight_edge);
                proxy->setPos(new_edge->line().x1()+new_edge->line().dx()/2,new_edge->line().y1()+new_edge->line().dy()/2);
                QObject::connect(weight_edge, &QLineEdit::returnPressed, [weight_edge](){
                    weight_edge->deselect();
                    weight_edge->clearFocus();
                    QGuiApplication::inputMethod()->reset();
                    QCoreApplication::sendEvent(weight_edge, new QFocusEvent(QEvent::FocusOut));
                });

                Vertex *v1=nullptr, *v2=nullptr;
                for(auto &item : vertexes){
                    if((item == qgraphicsitem_cast<QGraphicsEllipseItem*>(first_click_vertex)) ||
                        (item == qgraphicsitem_cast<QGraphicsEllipseItem*>(second_click_vertex))){
                        v1 ? v2 = &item : v1=&item;
                    }
                    if(v2){
                        break;
                    }
                }
                edges.push_back(Edge(weight_edge,new_edge,v1,v2));
            }
        }

        new_edge = nullptr;
        first_click_vertex=nullptr;
        right_mouse_is_active=false;
    }
    QGraphicsScene::mouseReleaseEvent(event);
}
