#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H

#include <QMenu>
class QAction;

class ContextMenu : public QMenu
{
    Q_OBJECT
public:
    ContextMenu(QWidget* parent = nullptr);

private:
    QAction* hidden;
    QAction* lock;
    void view();
    void controller();

    //test
    void mousePressEvent(QMouseEvent *e) override {
        setAttribute(Qt::WA_NoMouseReplay);
        QMenu::mousePressEvent(e);
    }

signals:
    void isHidden(bool);
    void isLock(bool);
};

#endif // CONTEXTMENU_H
