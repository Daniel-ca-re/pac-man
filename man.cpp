#include "man.h"

man::man()
{

}

man::man(int r_, int x, int y)
{
    r=r_;
    posx=x;
    posy=y;
    setPos(posx,posy);
}

int man::getR() const
{

}

void man::setR(int radio)
{
    r=radio;
}

int man::getPosx() const
{

}

void man::setPosx(int px)
{
    posx=px;
}

int man::getPosy() const
{

}

void man::setPosy(int py)
{
    posy=py;
}

QRectF man::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void man::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());

}

void man::up()
{
    posy -= 5*velocidad;
    if(posy<-40)
    {
        posy=840;
    }
    setPos(posx,posy);

}

void man::down()
{
    posy += 5*velocidad;
    if(posy>840)
    {
        posy=-40;
    }
    setPos(posx,posy);
}

void man::left()
{
    posx += 5*velocidad;
    if(posx>1040)
    {
        posx=-40;
    }

    setPos(posx,posy);
}

void man::right()
{
    posx -= 5*velocidad;
    if(posx<-40)
    {
        posx=1040;
    }
    setPos(posx,posy);
}
