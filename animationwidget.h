/*拥有Animationabel的窗体，增添了左右按钮栏*/

#ifndef ANIMATIONWIDGET_H
#define ANIMATIONWIDGET_H

#include <QWidget>
#include"animationlabel.h"

class QVBoxLayout;
class QPushButton;
class AnimationLabel;

class AnimationWidget : public QWidget
{
    Q_OBJECT
public:
    AnimationWidget(QWidget *parent = nullptr);
    void addAnimation(QString buttonText,QString filename,int w,int h);
    void addNormalAnimation(QString buttonText,QString filename,int w,int h);
    void addPickAnimation(QString buttonText,QString filename,int w,int h);
    void addDropAnimation(QString buttonText,QString filename, int w, int h);
private:
    void view();
    void controller();
    void m_hide();
    void m_show();

    AnimationLabel* animation;
    QWidget* left;
    QWidget* right;

    ContextMenu* m_contextMenu;
    QMovie* normalAnimation;


    bool pressState = false;
    bool moveState = false;
    bool lockState = false;
    bool hiddenState = false;
    QPair<int,int> pressPoint;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void contextMenuEvent(QContextMenuEvent *e) override;
    void paintEvent(QPaintEvent*) override;
signals:
    void isHidden(bool);
    void move(QPair<int,int>);


};

#endif // ANIMATIONWIDGET_H
