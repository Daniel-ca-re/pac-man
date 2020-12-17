#ifndef MAN_H
#define MAN_H
#include <QGraphicsItem>
#include <QPainter>


class man: public QGraphicsItem
{
    int r;
    int posx,posy;
    int velocidad=8;
public:
    man();
    man(int r_, int x ,int y);

    int getR()const;
    void setR(int radio);
    int getPosx()const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget =nullptr);
    void up();
    void down();
    void left();
    void right();
};

#endif // MAN_H
