#include "titlewindow.h"
#include"titlebar.h"
#include<QtWidgets>

TitleWindow::TitleWindow(QWidget *parent) : QWidget(parent)
{
    view();
    controller();
}

void TitleWindow::view() {
    setWindowFlag(Qt::FramelessWindowHint);

    m_titleBar = new TitleBar;

    m_ui = new QWidget;
    m_ui->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(1,1,1,1);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(m_titleBar);
    mainLayout->addWidget(m_ui);
    QWidget::setLayout(mainLayout);


    setObjectName("main");
    setStyleSheet("#main{border:1px solid black}");

}

void TitleWindow::controller() {
    connect(m_titleBar,SIGNAL(minimize()),this,SLOT(showMinimized()));
    connect(m_titleBar,SIGNAL(close()),this,SLOT(close()));

    connect(m_titleBar,&TitleBar::move,this,[=](QPair<int,int>pos){
        move(pos.first,pos.second);
    });

}

void TitleWindow::setLayout(QLayout * layout) {
    m_ui->setLayout(layout);
}



//debug
void TitleWindow::paintEvent(QPaintEvent *) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
