#include "muro.h"

muro::muro()
{

}

muro::muro(int w_, int h_, int x, int y)
{
    w=w_;
    h=h_;
    posx=x;
    posy=y;
}
QRectF muro::boundingRect() const
{
    return QRectF(-posx,-posy,w,h);
}

void muro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());

}
