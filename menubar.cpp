#include "menubar.h"

MenuBar::MenuBar(QWidget* parent)
    :QMenuBar(parent)
{
    view();
}


void MenuBar::view() {
    setStyleSheet("border-bottom:1px solid rgb(242,242,242);background-color:white");

    selectMenu = new QMenu(tr("选择(&s)"));
    addMenu(selectMenu);
    QAction* open = new QAction(tr("打开(&o)"));
    selectMenu->addAction(open);

    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
}
