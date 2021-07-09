#include "titlebar.h"
#include<QtWidgets>


TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
{
    view();
    controller();
}

void TitleBar::view() {
    QPalette pal;
    QColor color;


    m_titleIcon = new QLabel;
    m_titleIcon->setFixedHeight(30);

    m_title = new QLabel;
    m_title->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    pal = m_title->palette();
    pal.setColor(QPalette::WindowText,Qt::white);
    m_title->setPalette(pal);

    m_minBtn = new QPushButton;
    m_minBtn->setFixedSize(30,30);
    m_minBtn->setIcon(QIcon("../min.png"));
    m_minBtn->setToolTip("最小化");


    m_closeBtn = new QPushButton;
    m_closeBtn->setFixedSize(30,30);
    m_closeBtn->setIcon(QIcon("../close.png"));
    m_closeBtn->setToolTip("关闭");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(m_titleIcon);
    layout->addWidget(m_title);
    layout->addWidget(m_minBtn);
    layout->addWidget(m_closeBtn);
    setLayout(layout);

    pal = palette();
    color.setRgb(76,74,72);
    pal.setColor(QPalette::Background, color); //设置背景黑色
    setAutoFillBackground(true);
    setPalette(pal);

    m_closeBtn->setStyleSheet("background-color:rgb(76,74,72);border:none;color:white");
    m_minBtn->setStyleSheet("background-color:rgb(76,74,72);border:none;color:white");

    QSizePolicy policy = sizePolicy();
    policy.setRetainSizeWhenHidden(true);
    policy.setHorizontalPolicy(QSizePolicy::Expanding);
    policy.setVerticalPolicy(QSizePolicy::Fixed);
    setSizePolicy(policy);

}


void TitleBar::controller(){
    connect(m_minBtn,SIGNAL(clicked()),this,SIGNAL(minimize()));
    connect(m_closeBtn,SIGNAL(clicked()),this,SIGNAL(close()));
}

void TitleBar::setTitle(QString title) {
    m_title->setText(title);
}

void TitleBar::setIcon(QString filename) {
    QPixmap icon(filename);
    m_titleIcon->setPixmap(icon.scaledToHeight(m_titleIcon->height()));
}

//event
void TitleBar::mousePressEvent(QMouseEvent* e) {
    if(e->button() == Qt::LeftButton) {
        pressPoint = {e->x(),e->y()};
        pressState = true;
    }
}

void TitleBar::mouseReleaseEvent(QMouseEvent* e) {
    pressState = false;
}

void TitleBar::mouseMoveEvent(QMouseEvent* e) {
    if(pressState) {
        emit move({e->globalX() - pressPoint.first,e->globalY()-pressPoint.second});
    }
}
