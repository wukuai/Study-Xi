#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMap>
#include <QString>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    int execflag;
    QString id;
    QString passwords;
    void sleep(unsigned int msec);



private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
