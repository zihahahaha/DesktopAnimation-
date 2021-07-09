#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
class QMenu;
class QAction;

class MenuBar : public QMenuBar
{
    Q_OBJECT
public:
    MenuBar(QWidget* parent = nullptr);

private:
    void view();

    QMenu* selectMenu;
    QAction* open;
};

#endif // MENUBAR_H
