#ifndef COIN_H
#define COIN_H
#include <QGraphicsItem>
#include <QPainter>

class coin: public QGraphicsItem
{
    int r;
    int posx,posy;
public:
    coin();
    coin(int r_, int x ,int y);

    int getR()const;
    void setR(int radio);
    int getPosx()const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget =nullptr);
};

#endif // COIN_H
