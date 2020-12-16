#ifndef MURO_H
#define MURO_H
#include <QGraphicsItem>
#include <QPainter>


class muro: public QGraphicsItem
{

    int w,h;
    int posx , posy;
public:
    muro();
    muro(int w_,int h_, int x,int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget =nullptr);
};

#endif // MURO_H
