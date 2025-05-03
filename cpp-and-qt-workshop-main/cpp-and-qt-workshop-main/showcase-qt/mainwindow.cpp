#include "mainwindow.h"

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QRect>
#include <QPen>
#include <QBrush>

#include <iostream>
#include <algorithm>

void someFunctionCall() {
    std::cout << "Clicked!" << std::endl;
}

bool collideTest(QRect one, QList<QRect> &collection)
{
    std::remove_if(std::begin(collection), std::end(collection),
       [&one](const QRect &test){
            return one.intersects(test);
        }
    );
}

MainWindow::MainWindow()
: m_SquarePoint(0, 0)
, m_snake(0, 0, 0, 0)
{
    show();

    connect(&m_loopTimer, &QTimer::timeout, this, [&]{
        m_SquarePoint.setX(m_SquarePoint.x() + m_moveDelta.x());
        m_SquarePoint.setY(m_SquarePoint.y() + m_moveDelta.y());

        QRect geom = geometry();

        if (m_SquarePoint.y() > geom.height()) {
            m_SquarePoint.setY(0);
        }
        if (m_SquarePoint.x() > geom.width()) {
            m_SquarePoint.setX(0);
        }

        m_snake = QRect(m_SquarePoint.x(), m_SquarePoint.y(), 100, 100);

        // collideTest(m_snake, m_fruits);

        update();
    });

    for (int i = 0; i < 5; i++) {
        auto x = rand() % 400;
        auto y = rand() % 400;

        m_fruits.push_back(QRect(x, y, 50, 50));
    }

    m_loopTimer.start(24);
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
    QWidget::paintEvent(ev);

    QPainter painter(this);

    QPen pen(QBrush(Qt::red), 2);
    QBrush brush(Qt::gray);

    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRoundRect(m_snake);

    for (auto rect : m_fruits) {
        painter.drawRoundRect(rect);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);

}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    switch(ev->key()) {
        case Qt::Key_Up:
            m_moveDelta.setY(-10);
            m_moveDelta.setX(0);
        break;
        case Qt::Key_Down:
            m_moveDelta.setY(10);
            m_moveDelta.setX(0);
        break;
        case Qt::Key_Left:
            m_moveDelta.setX(-10);
            m_moveDelta.setY(0);
            break;
        case Qt::Key_Right:
            m_moveDelta.setX(10);
            m_moveDelta.setY(0);
        break;
        case Qt::Key_Space:
            m_SquarePoint.setX(0);
            m_SquarePoint.setY(0);
            m_moveDelta.setX(0);
            m_moveDelta.setY(0);
        break;
        default: break;
    }
    QWidget::keyPressEvent(ev);
}
