#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
class QLabel;
class QPushButton;

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);
    void setTitle(QString title);
    void setIcon(QString filename);

private:
    QLabel* m_titleIcon;
    QLabel* m_title;
    QPushButton* m_minBtn;
    QPushButton* m_closeBtn;

    bool pressState = false;
    QPair<int,int> pressPoint;

    void view();
    void controller();

    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;

signals:
    void close();
    void minimize();

    void move(QPair<int,int>);
};

#endif // TITLEBAR_H
