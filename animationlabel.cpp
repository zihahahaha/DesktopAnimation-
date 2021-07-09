#include "animationlabel.h"
#include"contextmenu.h"
#include<QtWidgets>

AnimationLabel::AnimationLabel(QWidget *parent)
    :QLabel(parent)
{
    controller();
}

void AnimationLabel::controller() {

}

int AnimationLabel::addAnimation(QString filename,int w,int h) {
    QMovie* animation = new QMovie(filename);
    animation->setScaledSize({w,h});
    animationList.push_back(animation);
    return animationList.size() - 1;
}

void AnimationLabel::addNormalAnimation(QString filename, int w, int h) {
    normalAnimation = new QMovie(filename);
    normalAnimation->setScaledSize({w,h});
    if(movie()) {
        movie()->stop();
    }
    setMovie(normalAnimation);
    normalAnimation->start();
}

void AnimationLabel::addPickAnimation(QString filename, int w, int h) {
    pickAnimation = new QMovie(filename);
    pickAnimation->setScaledSize({w,h});
}

void AnimationLabel::addDropAnimation(QString filename, int w, int h) {
    dropAnimation = new QMovie(filename);
    dropAnimation->setScaledSize({w,h});
}

void AnimationLabel::AnimationStart(int i) {
    nowAnimation = i;
    if(movie()) {
        movie()->stop();
    }
    setMovie(animationList[i]);
    animationList[i]->start();
}

void AnimationLabel::startNext() {
   nowAnimation++;
   if(nowAnimation < animationList.size()) {
        AnimationStart(nowAnimation);
   }
   else {
       nowAnimation = 0;
       AnimationStart(nowAnimation);
   }
}

void AnimationLabel::normalAnimationStart() {
    if(normalAnimation && movie()) {
        movie()->stop();
        setMovie(normalAnimation);
        normalAnimation->start();
    }
}

void AnimationLabel::pickAnimationStart() {
    if(pickAnimation && movie()) {
        movie()->stop();
        setMovie(pickAnimation);
        pickAnimation->start();
    }
}

void AnimationLabel::dropAnimationStart() {
    if(dropAnimation && movie()) {
        movie()->stop();
        setMovie(dropAnimation);
        dropAnimation->start();
    }
}




