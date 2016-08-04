#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <QAxWidget>
#include <QString>


#define malieN 65
#define dangshiN 75
#define guoxueN 113

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     int malie_cnt,dangshi_cnt,guoxue_cnt;
     QString moshi;
     QAxWidget *IEwidget;

     void xibutton(bool flag);


private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_xi2_clicked();

    void on_xi1_clicked();

    void on_xi3_clicked();

    void on_xi4_clicked();

    void on_xi5_clicked();

    void on_xi6_clicked();

    void on_xi7_clicked();

    void on_xi8_clicked();

    void on_xi9_clicked();

    void on_xi10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
