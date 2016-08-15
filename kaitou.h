#ifndef KAITOU_H
#define KAITOU_H

#include <QMainWindow>
#include <QAxWidget>
#include <QTime>
#include <QDir>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>

namespace Ui {
class Kaitou;
}

class Kaitou : public QMainWindow
{
    Q_OBJECT

public:
    explicit Kaitou(QWidget *parent = 0);
    void tuichu();
    void sleep(unsigned int msec);
    QAxWidget *IEwidget;
    void keyPressEvent(QKeyEvent  *event);
    void mousePressEvent(QMouseEvent *e);
    int  tuichuFlag;
    ~Kaitou();
//    void sleep(unsigned int msec);

private:
    Ui::Kaitou *ui;
};

#endif // KAITOU_H
