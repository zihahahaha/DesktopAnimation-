#ifndef TITLEWINDOW_H
#define TITLEWINDOW_H

#include <QWidget>
#include "titlebar.h"
class QVBoxLayout;

class TitleWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TitleWindow(QWidget *parent = nullptr);
    void setLayout(QLayout*);
    void setTitle(QString title) {
        m_titleBar->setTitle(title);
    }
    void hideTitle() {
        m_titleBar->hide();
        setStyleSheet("");
    }
    void showTitle() {
        m_titleBar->show();
        setStyleSheet("#main{border:1px solid black}");
    }

    int getTitleBarHeight() {
        return m_titleBar->height();
    }
    TitleBar* titleBar() const{
        return m_titleBar;
    }
private:
    TitleBar* m_titleBar;
    QWidget* m_ui;

    void view();
    void controller();


    //如果QWidget子类要支持Q_OBJECT的同时支持setStyleSheet的话就要加这个
    void paintEvent(QPaintEvent *);
};


#endif // TITLEWINDOW_H
