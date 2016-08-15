#ifndef FIND_H
#define FIND_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QClipboard>
#include <QPoint>
#include <windows.h>
#include <QTime>


namespace Ui {
class Find;
}

class Find : public QMainWindow
{
    Q_OBJECT

public:
    explicit Find(QWidget *parent = 0);
    QString findText;
    bool  findExis[17];
    int X,Y;
    int xbutton[17],ybutton[17];
    void setButton();
    void ctrlV();
    void clickButton(int b);
    void sleep(unsigned int msec);

    ~Find();

private slots:
    void on_find_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

private:
    Ui::Find *ui;
};

#endif // FIND_H
