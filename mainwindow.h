#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <find.h>
#include <login.h>
#include <QApplication>
#include <QObject>
#include <QMainWindow>
#include <QPushButton>
#include <QRect>
#include <QPixmap>
#include <QMouseEvent>
#include <QDebug>
#include <QIcon>
#include <pushbutton.h>
#include <QTime>
#include <QAxWidget>
#include <QDir>
#include <QFontDatabase>
#include <QPalette>
#include <QPalette>
#include <QFont>
#include <QMessagebox>
#include <QPalette>
#include <QTextStream>
#include <QUrl>
#include <QDesktopServices>
#include <QDesktopWidget>

#include <windows.h>
#include <Shlobj.h>
#include <mmsystem.h>

#include <QPoint>
#include <QMap>
#include <QKeyEvent>
#include <QToolButton>
#include <QEvent>
#include <QFontDatabase>
#include <QStringList>
#include <QSound>
#include <QMovie>
#include <QDateTime>
#include <QTimer>

#define abcN 100 //abc题目总数
#define abcdN 30
#define yongdianN 10
#define shichaN 12
#define newsN 11
#define liangxueN 5



#define happyN 12


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void buttonHidden(bool flag);
    void buttonFlat();
    void sleep(unsigned int msec);
    void loadDemo();
    void setCurrentIndex(int cnt);
    void setVideoCurrentIndex(int cnt);
    void jieMian(int index);
    void chuTiABC(int t);
    void chuTiABCD(int t);
    void initVis();
    void judge(QString yourans);
    void jianliZhanghu();
    void setWeizhi();
    void changeEvent(QEvent* e);
    void setFilter();
    void setTiShu(int tiN);
    void setAdjustSize();
    void changeValume(int value);
//    QString loadFontFamilyFromTTF();

    bool eventFilter(QObject *target, QEvent *e);

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);


    QPixmap tongyongpix,shouyepix,ranktoppix,exampix;
    QAxWidget *IEwidget;
    QAxWidget *happyIEwidget;
    QAxWidget *speechIEwidget;
    QAxWidget *rankIEwidget;
    QPixmap temp_pix;
    QMap<QString,int>map; //跟着计数
    QPalette pa,pa2;
    QPalette pared,pablack;
    QDateTime lastTime,curTime;
    QTimer *timer;
    QString moshi;
    QString videoMoshi;

    QMap<QString,QString>name;
    QMap<QString,QString>password;

    QPoint last;

    int genzheCnt;
    int happyCnt;
    int happyflag;
    int videoflag;
    int moveFlag;
    int changeflag;
    int minFlag;
    int videoSoundFlag;
    int timeFlag;
    int happyPlayFlag;
    int videoPlayFlag;
    int duicnt,zuoticnt;
    int abcVis[abcN+1],abcdVis[abcdN+1];
    int bugXielieX,bugXielieY;
    int bugLabelW,bugLabelH;
    int oldx,oldy;
    int lastValue,curValue;
    double beishu;
    int tiN;
    int jiShi;
    int videoCnt;
    int bugValume;

    QString dangqianans;
    QString id;

    Find find;

    ~MainWindow();

private slots:
    void timerUpDate();

    void on_video_clicked();

    void on_video_pressed();
    void on_video_released();
    void on_shouye_pressed();
    void on_shouye_released();
    void on_xilie_pressed();
    void on_xilie_released();
    void on_genzhe_pressed();
    void on_genzhe_released();
    void on_exam_pressed();
    void on_exam_released();
    void on_rank_pressed();
    void on_rank_released();
    void on_happy_pressed();
    void on_happy_released();
    void on_bbs_pressed();
    void on_bbs_released();
    void on_exit_pressed();
    void on_exit_released();


    void on_exit_clicked();

    void on_shouye_clicked();

    void on_genzhe_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_dangshi_activated(const QString &arg1);

    void on_junshi_activated(const QString &arg1);

    void on_malie_activated(const QString &arg1);

    void on_guoxue_activated(const QString &arg1);

    void on_next_clicked();

    void on_next_pressed();

    void on_next_released();

    void on_last_pressed();

    void on_last_released();

    void on_exam_clicked();

    void on_examnext_clicked();

    void on_examnext_pressed();

    void on_examnext_released();

    void on_pushButton_clicked();

    void on_xilie_clicked();

    void on_rank_clicked();

    void on_happy_clicked();

    void on_bbs_clicked();

    void on_happylast_pressed();

    void on_happylast_released();

    void on_happynext_pressed();

    void on_happynext_released();

    void on_speech_17_clicked();

    void on_speechDangnei_clicked();

    void on_speechQiangjun_clicked();

    void on_speechGaige_clicked();

    void on_speechQiangguo_clicked();

    void on_speechWaijiao_clicked();

    void on_speechXibu_clicked();

    void on_speechFind1_clicked();

    void on_speechFind1_released();

    void on_speechFind2_pressed();

    void on_speechFind2_released();

    void on_speechFind1_pressed();

    void on_speech1_clicked();

    void on_speech2_clicked();

    void on_speech3_clicked();

    void on_speech4_clicked();

    void on_speech5_clicked();

    void on_speech6_clicked();

    void on_speech7_clicked();

    void on_speech8_clicked();

    void on_speech9_clicked();

    void on_speech10_clicked();

    void on_videoyongdian_activated(const QString &arg1);

    void on_videoyongdian_activated(int index);

    void on_guoxue_activated(int index);

    void on_videoliangxue_activated(int index);

    void on_videoshicha_activated(int index);

    void on_videonews_activated(int index);

    void on_dangshi_activated(int index);

    void on_last_clicked();

    void on_junshi_activated(int index);

    void on_malie_activated(int index);

    void on_happynext_clicked();

    void on_happylast_clicked();

    void on_add_pressed();

    void on_add_released();

    void on_up_pressed();

    void on_up_released();

    void on_jian_pressed();

    void on_jian_released();

    void on_down_pressed();

    void on_down_released();

    void on_speechPrint_pressed();

    void on_speechPrint_released();

    void on_add_clicked();

    void on_jian_clicked();

    void on_up_clicked();

    void on_down_clicked();

    void on_speechPrint_clicked();

    void on_speechFind2_clicked();

    void on_videoPlay_pressed();

    void on_videoPlay_released();

    void on_videoLast_pressed();

    void on_videoLast_released();

    void on_videoNext_pressed();

    void on_videoNext_released();

    void on_videoSound_pressed();

    void on_videoSound_released();

    void on_videoSound_clicked();

    void on_videoSlider_actionTriggered(int action);

    void on_videoSlider_sliderMoved(int position);

    void on_videoSlider_rangeChanged(int min, int max);

    void on_videoSlider_valueChanged(int value);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_happyPlay_pressed();

    void on_happyPlay_released();

    void on_happySound_pressed();

    void on_happySound_released();

    void on_happyPlay_clicked();

    void on_happySound_clicked();

    void on_happy_1_clicked();

    void on_happy_2_clicked();

    void on_happy_3_clicked();

    void on_happy_4_clicked();

    void on_happy_5_clicked();

    void on_happy_6_clicked();

    void on_happy_7_clicked();

    void on_happy_8_clicked();

    void on_happy_9_clicked();

    void on_happy_10_clicked();

    void on_happy_11_clicked();

    void on_happy_12_clicked();

    void on_videoPlay_clicked();

    void on_videoNext_clicked();

    void on_videoLast_clicked();

    void on_happySlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
