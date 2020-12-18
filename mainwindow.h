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
#include <QMediaPlayer>

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
    void level(int);
    void erraselevel();
    void addpoint();

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
    QTimer * timers;
    int points;
    int contador;
    int lvl;
    int vidas;
    QList <muro *> muros;
    QList <coin *> monedas;
    QMediaPlayer * losesound;
    QMediaPlayer * wakawaka;
    QMediaPlayer * theme;
};
#endif // MAINWINDOW_H
