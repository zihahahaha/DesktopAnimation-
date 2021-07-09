/*承保对动画播放的所有职责*/

#ifndef ANIMATIONLABEL_H
#define ANIMATIONLABEL_H

#include <QLabel>
#include<QMovie>
#include<QVector>

class ContextMenu;

class AnimationLabel : public QLabel
{
    Q_OBJECT
public:
    AnimationLabel(QWidget* parent = nullptr);
    int addAnimation(QString filename,int w,int h);
    void addNormalAnimation(QString filename,int w,int h);
    void addPickAnimation(QString filename,int w,int h);
    void addDropAnimation(QString filename,int w,int h);
    void AnimationStart(int i);
    void startNext();
    void normalAnimationStart();
    void pickAnimationStart();
    void dropAnimationStart();
    int animationSize() {
        return animationList.size();
    }
private:
    int nowAnimation = 0;


    QVector<QMovie*> animationList;
    QMovie* normalAnimation = nullptr;
    QMovie* pickAnimation = nullptr;
    QMovie* dropAnimation = nullptr;

    void controller();
};

#endif // ANIMATIONLABEL_H
