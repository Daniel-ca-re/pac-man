#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <array>
#include <iostream>
#include <iterator>
#include "coin.h"
#include <QLCDNumber>
#include <QTimer>

using namespace std;

void MainWindow::pass_second(){
    ui->cronometro->display(30-contador);
    contador++;
    if(contador>30)
    {
        contador=0;
        vidas--;
        ui->numvidas->display(vidas);
        if(vidas==0)
        {
            erraselevel();
            lvl=1;
            level(lvl);
        }
    }

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene= new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1000,800);
    lvl=1;
    level(lvl);





    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(pass_second()));
    timer->start(1000);





}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_A)

    {
        pacman->right();
        for(auto i:muros)
        {
            if(pacman->collidesWithItem(i))
            {
            pacman->left();
            }
        }
        for(int i=0;i<monedas.size();i++)
        {
                if(pacman->collidesWithItem(monedas.at(i)))
                {
                scene->removeItem(monedas.at(i));
                monedas.removeAt(i);
                i--;
                addpoint();

                break;
                }
        }
    }
    else if(evento->key()==Qt::Key_S)
    {
        pacman->down();
        for(auto i:muros)
        {
            if(pacman->collidesWithItem(i))
            {
                pacman->up();
            }
        }
        for(int i=0;i<monedas.size();i++)
        {
                if(pacman->collidesWithItem(monedas.at(i)))
                {
                scene->removeItem(monedas.at(i));
                monedas.removeAt(i);
                i--;
                addpoint();
                break;
                }
        }
    }
    else if(evento->key()==Qt::Key_D)
    {
        pacman->left();
        for(auto i:muros)
        {
            if(pacman->collidesWithItem(i))
            {
                pacman->right();
            }
        }
        for(int i=0;i<monedas.size();i++)
        {
                if(pacman->collidesWithItem(monedas.at(i)))
                {
                scene->removeItem(monedas.at(i));
                monedas.removeAt(i);
                i--;
                addpoint();
                break;
                }
        }
    }
    else if(evento->key()==Qt::Key_W)
    {
        pacman->up();
        for(auto i:muros)
        {
            if(pacman->collidesWithItem(i))
            {
                pacman->down();
            }
        }
    }
    for(int i=0;i<monedas.size();i++)
    {
            if(pacman->collidesWithItem(monedas.at(i)))
            {
            scene->removeItem(monedas.at(i));
            monedas.removeAt(i);
            i--;
            addpoint();
            break;
            }
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::level(int nivel)
{
    if(nivel==1)
    {
        vector <array<int,4>> infMURO = {{440,80,0,-360},{440,80,-560,-360},{120,800,-440,0}};
        for (auto i:infMURO)
        {
            muros.push_back(new muro(i[0],i[1],i[2],i[3]));
            scene->addItem(muros.back());
        }
    }

    else if(nivel==2)
    {
        vector <array<int,4>> infMUROS={{320,200,0,0},{320,200,0,-600},{320,200,-680,-600},{320,200,-680,0},{920,80,-40,-360},{120,320,-440,0},{120,320,-440,-480}};
        for (auto i:infMUROS)
        {
            muros.push_back(new muro(i[0],i[1],i[2],i[3]));
            scene->addItem(muros.back());
        }
    }

    else if(nivel==3)
    {
        vector <array<int,4>> infMUROS={{1000,40,0,-760},{1000,40,0,0},{200,280,0,-40},{200,280,0,-480},{200,280,-800,-40},{200,280,-800,-480},{160,40,-240,-160},{160,40,-600,-160},{120,160,-440,-80},{120,160,-440,-560},
                                        {160,40,-600,-600},{160,40,-240,-600},{520,240,-240,-280}};
        for (auto i:infMUROS)
        {
            muros.push_back(new muro(i[0],i[1],i[2],i[3]));
            scene->addItem(muros.back());
        }
    }



    pacman = new man(20,220,220);

    for (int x=20;x<1000;x+=40)
    {
        for(int y=20;y<800;y+=40)
        {
            monedas.push_back(new coin(5,x,y));
            scene->addItem(monedas.back());
        }
    }
    for(int i=0;i<monedas.size();i++)
    {
        for(auto I:muros)
        {
            if(monedas.at(i)->collidesWithItem(I))
            {
            scene->removeItem(monedas.at(i));
            monedas.removeAt(i);
            i--;
            break;
            }
        }
    }
    scene->addItem(pacman);
    points=0;
    ui->puntaje->display(points);
    contador=0;
    ui->cronometro->display(30-contador);
    vidas=3;
    ui->numvidas->display(vidas);


}

void MainWindow::erraselevel()
{
    while(muros.size()!=0)
    {
        scene->removeItem(muros.at(0));
        muros.removeAt(0);
    }
    while(monedas.size()!=0)
    {
        scene->removeItem(monedas.at(0));
        monedas.removeAt(0);
    }
    scene->removeItem(pacman);
}

void MainWindow::addpoint()
{
    points++;
    ui->puntaje->display(points);
    if(monedas.size()==0)
    {
        lvl++;
        erraselevel();
        level(lvl);
    }
}



