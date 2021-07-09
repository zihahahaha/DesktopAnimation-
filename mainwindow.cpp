#include "mainwindow.h"
#include"titlebar.h"
#include"menubar.h"
#include"animationwidget.h"
#include"contextmenu.h"
#include<QtWidgets>


MainWindow::MainWindow(QWidget *parent)
    : TitleWindow(parent)
{
    view();
    controller();
}

void MainWindow::view() {

    m_menubar = new MenuBar();
    QSizePolicy policyMenu = m_menubar->sizePolicy();
    policyMenu.setRetainSizeWhenHidden(true);
    m_menubar->setSizePolicy(policyMenu);

    m_ui = new AnimationWidget;
    m_ui->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(m_menubar);
    mainLayout->addWidget(m_ui);

    setLayout(mainLayout);

    setAttribute(Qt::WA_TranslucentBackground);
}

void MainWindow::controller() {
    connect(m_ui,&AnimationWidget::isHidden,this,[=](bool hidden){
        if(hidden) {
            hideTitle();
            m_menubar->hide();
            setWindowFlag(Qt::WindowStaysOnTopHint);
            show();

        }
        else {
            showTitle();
            m_menubar->show();
            setWindowFlag(Qt::WindowStaysOnTopHint,false);
            show();
        }
    });

    connect(m_ui,&AnimationWidget::move,this,[=](QPair<int,int>pos){
        move(pos.first,pos.second - getTitleBarHeight() - m_menubar->height());
    });
}
