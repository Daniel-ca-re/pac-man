#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "man.h"
#include "muro.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <vector>
#include <iostream>
#include "coin.h"
#include <QTimer>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void pass_second();

private:
    Ui::MainWindow *ui;
    man *pacman;
    muro *muro1;
    QGraphicsScene *scene;
    void keyPressEvent(QKeyEvent *evento);
    void fTimer();
    QTimer * timer;
    int points;
    int contador;
    QList <muro *> muros;
    QList <coin *> monedas;
};
#endif // MAINWINDOW_H
