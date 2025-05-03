#pragma once

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QKeyEvent>

#include <QPoint>
#include <QTimer>

#include <QList>
#include <QRect>

class MainWindow : public QWidget {
    Q_OBJECT
public:
    MainWindow();

protected:
    void paintEvent(QPaintEvent *ev) override ;
    void mousePressEvent(QMouseEvent *ev) override ;
    void mouseReleaseEvent(QMouseEvent *ev) override ;
    void keyPressEvent(QKeyEvent *ev) override ;
private:
    QPoint m_SquarePoint;
    QPoint m_moveDelta;
    QTimer m_loopTimer;
    QRect m_snake;
    QList<QRect> m_fruits;

};
