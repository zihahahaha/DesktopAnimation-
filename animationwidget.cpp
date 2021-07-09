#include "animationwidget.h"
#include"contextmenu.h"
#include"animationlabel.h"
#include<QtWidgets>

AnimationWidget::AnimationWidget(QWidget *parent)
    :QWidget(parent)
{
    view();
    controller();
}

void AnimationWidget::view() {
    m_contextMenu = new ContextMenu(this);

    animation = new AnimationLabel;

    QHBoxLayout* mainLayout = new QHBoxLayout;

    left = new QWidget;
    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->setContentsMargins(20,10,20,10);
    left->setLayout(leftLayout);
    QSizePolicy leftPolicy = left->sizePolicy();
    leftPolicy.setRetainSizeWhenHidden(true);
    left->setSizePolicy(leftPolicy);
    right = new QWidget;
    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->setContentsMargins(20,10,20,10);
    right->setLayout(rightLayout);
    QSizePolicy rightPolicy = right->sizePolicy();
    rightPolicy.setRetainSizeWhenHidden(true);
    right->setSizePolicy(rightPolicy);

    mainLayout->addWidget(left);
    mainLayout->addWidget(animation);
    mainLayout->addWidget(right);

    setLayout(mainLayout);

    setObjectName("animation");
    setStyleSheet("#animation{background-color:rgb(0,255,0)}");

}

void AnimationWidget::controller() {
    connect(m_contextMenu,&ContextMenu::isHidden,this,[=](bool hidden){
        hiddenState = hidden;
        if(hidden) {
            m_hide();
        }
        else {
            m_show();
        }
        emit isHidden(hidden);
    });
    connect(m_contextMenu,&ContextMenu::isLock,this,[=](bool lock){
        lockState = lock;
    });
}


void AnimationWidget::m_hide() {
    setStyleSheet("#animation{background-color:rgba(0,0,0,0)}");
    left->hide();
    right->hide();
}

void AnimationWidget::m_show() {
    setStyleSheet("#animation{background-color:rgb(0,255,0)}");
    left->show();
    right->show();
}


//interface
void AnimationWidget::addAnimation(QString buttonText, QString filename,int w,int h) {
    int num = animation->addAnimation(filename,w,h);
    QPushButton* btn = new QPushButton(buttonText);
    if(num % 2 == 0) {
        left->layout()->addWidget(btn);
    }
    else {
        right->layout()->addWidget(btn);
    }
    connect(btn,&QPushButton::clicked,animation,[=]{
        animation->AnimationStart(num);
    });
}


//test
void AnimationWidget::addNormalAnimation(QString buttonText, QString filename, int w, int h) {
    animation->addNormalAnimation(filename,w,h);
}

void AnimationWidget::addDropAnimation(QString buttonText, QString filename, int w, int h) {
    animation->addDropAnimation(filename,w,h);
}

void AnimationWidget::addPickAnimation(QString buttonText, QString filename, int w, int h) {
    animation->addPickAnimation(filename,w,h);
}

//event
void AnimationWidget::contextMenuEvent(QContextMenuEvent*) {
    m_contextMenu->exec(QCursor::pos());
}

void AnimationWidget::mousePressEvent(QMouseEvent* e) {
    if(e->button() == Qt::LeftButton&& hiddenState) {
        if(!lockState) {
            pressPoint = {e->x(),e->y()};
            pressState = true;
        }
        animation->startNext();
    }
}

void AnimationWidget::mouseReleaseEvent(QMouseEvent*) {
    if(pressState == true) {
        pressState = false;
        if(moveState) {
            moveState = false;
            animation->normalAnimationStart();
        }
    }
}

void AnimationWidget::mouseMoveEvent(QMouseEvent* e) {
    if(pressState && !lockState && hiddenState) {
        if(moveState == false) {
            moveState = true;
            animation->pickAnimationStart();
        }
        emit move({e->globalX() - pressPoint.first,e->globalY()-pressPoint.second});
    }
}


//debug
void AnimationWidget::paintEvent(QPaintEvent *) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
