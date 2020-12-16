#include "coin.h"

coin::coin()
{

}

coin::coin(int r_, int x, int y)
{
    r=r_;
    posx=x;
    posy=y;
    setPos(posx,posy);
}

int coin::getR() const
{

}

void coin::setR(int radio)
{
    r=radio;
}

int coin::getPosx() const
{

}

void coin::setPosx(int px)
{
    posx=px;
}

int coin::getPosy() const
{

}

void coin::setPosy(int py)
{
    posy=py;
}

QRectF coin::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(boundingRect());

}
