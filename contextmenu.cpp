#include "contextmenu.h"
#include<QAction>
#include<QDebug>

ContextMenu::ContextMenu(QWidget* parent)
    :QMenu(parent)
{
    view();
    controller();
}

void ContextMenu::view() {

    hidden = addAction(tr("隐藏"));
    hidden->setCheckable(true);
    hidden->setChecked(false);

    lock = addAction(tr("锁定"));
    lock->setCheckable(true);
    lock->setChecked(false);
    lock->setVisible(false);
}

void ContextMenu::controller() {
    connect(hidden,&QAction::triggered,this,[=](bool hidden) {
        lock->setVisible(hidden);
        emit isHidden(hidden);
    });
    connect(lock,SIGNAL(triggered(bool)),this,SIGNAL(isLock(bool)));
}

