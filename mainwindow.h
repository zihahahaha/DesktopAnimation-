#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"titlewindow.h"
#include"animationwidget.h"
class MenuBar;

class MainWindow
        : public TitleWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void addAnimation(QString buttonText, QString filename,int w,int h) {
        m_ui->addAnimation(buttonText,filename,w,h);
    }
    void addNormalAnimation(QString buttonText,QString filename,int w,int h) {
        m_ui->addNormalAnimation(buttonText,filename,w,h);
    }
    void addPickAnimation(QString buttonText,QString filename,int w,int h) {
        m_ui->addPickAnimation(buttonText,filename,w,h);
    }
    void addDropAnimation(QString buttonText,QString filename, int w, int h) {
        m_ui->addDropAnimation(buttonText,filename,w,h);
    }
private:
    AnimationWidget* m_ui;
    MenuBar* m_menubar;

    void view();
    void controller();

};

#endif // MAINWINDOW_H
