#include <QApplication>
#include<QtWidgets>
#include "mainwindow.h"
#include "titleWindow.h"
#include"animationlabel.h"






int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //AnimationWidget_test();
    //TitleBar_test();
    MainWindow a;
    a.titleBar()->setTitle("hello world!");
    a.titleBar()->setIcon("../title.png");
    a.resize(640,480);
    a.addAnimation("等待","../wait_withGun.gif",400,400);
    a.addAnimation("攻击","../attack.gif",400,400);
    a.addAnimation("胜利","../victory.gif",400,400);
    a.addNormalAnimation("常驻","../wait.gif",400,400);
    a.addPickAnimation("捡起","../pick.gif",400,400);
    a.show();

    return app.exec();
}

