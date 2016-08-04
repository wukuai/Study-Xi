#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap shouye(":/shouye.png");
    shouye=shouye.scaled(ui->label->width(),ui->label->height());
    ui->label->setPixmap(shouye);

    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);

    ui->label_2->setVisible(false);
    ui->comboBox->setVisible(false);

    malie_cnt=0;
    dangshi_cnt=0;
    guoxue_cnt=0;
   //qDebug()<<this->objectName();

    QAxWidget *tempie= new QAxWidget(this);
    IEwidget=tempie;


    IEwidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}")); //设置插件为IE
    IEwidget->setVisible(false);

   qDebug() << QDir::currentPath();

   //习讲话内容按钮透明
   xibutton(false);



//   ui->xi1->setFlat(true);
//   ui->xi2->setFlat(true);
//   ui->xi3->setFlat(true);


//    ui->label->setText("<a href=\"http://www.baidu.com\">BaiDu</a>");
//    ui->label->setOpenExternalLinks(true);
//    ui->label->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()//马列
{
    ui->label_2->setVisible(false);
    ui->comboBox->setVisible(false);

    xibutton(false);

    IEwidget->setVisible(false);
    ui->label->setVisible(true);

    moshi="malie";
    malie_cnt=0;
    QString file1=":/1/malie/1/malie1-(";
    QString file2=QString::number(malie_cnt);
    QString file3=").JPG";
    QString file=file1+file2+file3;
    QPixmap temp_pix(file);
    temp_pix=temp_pix.scaled(ui->label->width(),ui->label->height());
    ui->label->setPixmap(temp_pix);

    ui->pushButton_9->setVisible(true);
    ui->pushButton_10->setVisible(true);
}

void MainWindow::on_pushButton_10_clicked() //下一张
{
    if(moshi=="malie"){
        malie_cnt++;
        if(malie_cnt==malieN){
            QMessageBox *wanle=new QMessageBox();
            wanle->setText("恭喜你完成了马列内容的学习！\n"
                           "快看看其它内容吧");
            wanle->setWindowTitle("提示");
            wanle->exec();
            malie_cnt--;
        }
        else {
            QString file1=":/1/malie/1/malie1-(";
            QString file2=QString::number(malie_cnt);
            QString file3=").JPG";
            QString file=file1+file2+file3;
            QPixmap temp_pix(file);
            temp_pix=temp_pix.scaled(ui->label->width(),ui->label->height());
            ui->label->setPixmap(temp_pix);
        }
    }
    else if(moshi=="dangshi"){
        dangshi_cnt++;
        if(dangshi_cnt==dangshiN){
            QMessageBox *wanle=new QMessageBox();
            wanle->setText("恭喜你完成了党史内容的学习！\n"
                           "快看看其它内容吧");
            wanle->setWindowTitle("提示");
            wanle->exec();
            malie_cnt--;
        }
        else {
            QString file1="./dangshi/1/dangshi1-(";
            QString file2=QString::number(dangshi_cnt);
            QString file3=").JPG";
            QString file=file1+file2+file3;
            QPixmap temp_pix(file);
            temp_pix=temp_pix.scaled(ui->label->width(),ui->label->height());
            ui->label->setPixmap(temp_pix);
        }
    }
    else if(moshi=="guoxue"){
        guoxue_cnt++;
        if(guoxue_cnt==guoxueN){
            QMessageBox *wanle=new QMessageBox();
            wanle->setText("恭喜你完成了国学内容的学习！\n"
                           "快看看其它内容吧");
            wanle->setWindowTitle("提示");
            wanle->exec();
            guoxue_cnt--;
        }
        else {
            QString file1="./guoxue/1/guoxue1-(";
            QString file2=QString::number(guoxue_cnt);
            QString file3=").JPG";
            QString file=file1+file2+file3;
            QPixmap temp_pix(file);
            temp_pix=temp_pix.scaled(ui->label->width(),ui->label->height());
            ui->label->setPixmap(temp_pix);
        }
    }
}

void MainWindow::on_pushButton_9_clicked()//上一张
{
    if(moshi=="malie"){
        malie_cnt--;
        if(malie_cnt<0){
            QMessageBox *wanle=new QMessageBox();
            wanle->setText("已经是第一张了");
            wanle->setWindowTitle("提示");
            wanle->exec();
            malie_cnt++;
        }
        else {
            QString file1=":/1/malie/1/malie1-(";
            QString file2=QString::number(malie_cnt);
            QString file3=").JPG";
            QString file=file1+file2+file3;
            QPixmap temp_pix(file);
            temp_pix=temp_pix.scaled(ui->label->width(),ui->label->height());
            ui->label->setPixmap(temp_pix);
        }
    }
    else if(moshi=="dangshi"){
        dangshi_cnt--;
        if(dangshi_cnt<0){
            QMessageBox *wanle=new QMessageBox();
            wanle->setText("已经是第一张了");
            wanle->setWindowTitle("提示");
            wanle->exec();
            malie_cnt++;
        }
        else {
            QString file1="./dangshi/1/dangshi1-(";
            QString file2=QString::number(dangshi_cnt);
            QString file3=").JPG";
            QString file=file1+file2+file3;
            QPixmap temp_pix(file);
            temp_pix=temp_pix.scaled(ui->label->width(),ui->label->height());
            ui->label->setPixmap(temp_pix);
        }
    }
    else if(moshi=="guoxue"){
        guoxue_cnt--;
        if(guoxue_cnt<0){
            QMessageBox *wanle=new QMessageBox();
            wanle->setText("已经是第一张了");
            wanle->setWindowTitle("提示");
            wanle->exec();
           guoxue_cnt++;
        }
        else {
            QString file1="./guoxue/1/guoxue1-(";
            QString file2=QString::number(guoxue_cnt);
            QString file3=").JPG";
            QString file=file1+file2+file3;
            QPixmap temp_pix(file);
            temp_pix=temp_pix.scaled(ui->label->width(),ui->label->height());
            ui->label->setPixmap(temp_pix);
        }
    }

}

void MainWindow::on_pushButton_5_clicked()//党史
{
    ui->label_2->setVisible(false);
    ui->comboBox->setVisible(false);

    xibutton(false);


    IEwidget->setVisible(false);
    ui->label->setVisible(true);

    moshi="dangshi";
    dangshi_cnt=0;
    QString file1="./dangshi/1/dangshi1-(";
    QString file2=QString::number(dangshi_cnt);
    QString file3=").JPG";
    QString file=file1+file2+file3;
    QPixmap temp_pix(file);
    temp_pix=temp_pix.scaled(ui->label->width(),ui->label->height());
    ui->label->setPixmap(temp_pix);

    ui->pushButton_9->setVisible(true);
    ui->pushButton_10->setVisible(true);
}

void MainWindow::on_pushButton_6_clicked()//国学
{
    ui->label_2->setVisible(false);
    ui->comboBox->setVisible(false);

    xibutton(false);

    IEwidget->setVisible(false);
    ui->label->setVisible(true);

    moshi="guoxue";
    guoxue_cnt=0;
    QString file1="./guoxue/1/guoxue1-(";
    QString file2=QString::number(guoxue_cnt);
    QString file3=").JPG";
    QString file=file1+file2+file3;
    QPixmap temp_pix(file);
    temp_pix=temp_pix.scaled(ui->label->width(),ui->label->height());
    ui->label->setPixmap(temp_pix);

    ui->pushButton_9->setVisible(true);
    ui->pushButton_10->setVisible(true);
}

void MainWindow::on_pushButton_clicked() //习讲话
{
    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);

    ui->label->setVisible(false);
    IEwidget->setVisible(true);


    //ui->label->setAttribute(Qt::WA_TranslucentBackground, false);
//    QAxWidget *tempie=new QAxWidget(Ui::MainWindow);
    //tempie->setParent(MainWindow);
   // IEwidget=tempie;
   // *IEwidget= new QAxWidget(this);
   // ui->label->layout()->addWidget(IEwidget); //布局

    IEwidget->setGeometry(ui->label->x()+220,ui->label->y()+4,ui->label->width()-260,ui->label->height()+120);
//    IEwidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}")); //设置插件为IE
    //qDebug() << QDir::currentPath();
   // IEwidget->dynamicCall("Navigate(const QString&)", "F:/html/1.html"); //调用参数
    IEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/1.html"); //调用参数
   // IEwidget->dynamicCall("./htm/2.htm"); //调用参数

//    //习讲话内容按钮恢复
   xibutton(true);
}

void MainWindow::on_xi2_clicked()
{
     IEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/2.html"); //调用参数
}

 void MainWindow::xibutton(bool flag){//习讲话是否透明
     ui->xi1->setVisible(flag);
     ui->xi2->setVisible(flag);
     ui->xi3->setVisible(flag);
     ui->xi4->setVisible(flag);
     ui->xi5->setVisible(flag);
     ui->xi6->setVisible(flag);
     ui->xi7->setVisible(flag);
     ui->xi8->setVisible(flag);
     ui->xi9->setVisible(flag);
     ui->xi10->setVisible(flag);
 }

void MainWindow::on_xi1_clicked()
{
    IEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/1.html");
}

void MainWindow::on_xi3_clicked()
{
    IEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/3.html");
}

void MainWindow::on_xi4_clicked()
{
    IEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/4.html");
}

void MainWindow::on_xi5_clicked()
{
    IEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/5.html");
}

void MainWindow::on_xi6_clicked()
{
    IEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/6.html");
}

void MainWindow::on_xi7_clicked()
{
    IEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/7.html");
}

void MainWindow::on_xi8_clicked()
{
    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("基础版，资料待补充");
    tishi->setWindowTitle("提示");
    tishi->exec();
//    IEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/8.html");
}

void MainWindow::on_xi9_clicked()
{
    IEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/9.html");
}

void MainWindow::on_xi10_clicked()
{
    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("基础版，资料待补充");
    tishi->setWindowTitle("提示");
    tishi->exec();
//    IEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/10.html");
}

void MainWindow::on_pushButton_7_clicked()
{
    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("用于连接内网论坛\n"
                   "链接待提供");
    tishi->setWindowTitle("提示");
    tishi->exec();
}

void MainWindow::on_pushButton_8_clicked()//视频学习
{
    ui->label_2->setVisible(true);
    ui->comboBox->setVisible(true);

    ui->label->setVisible(false);
    IEwidget->setVisible(true);

    xibutton(false);

    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);

    xibutton(false);
    IEwidget->setGeometry(ui->label->x(),ui->label->y(),ui->label->width(),ui->label->height());
    IEwidget->dynamicCall("Navigate(const QString&)", "http://tvplayer.people.com.cn/player.php/xml/L3B2c2VydmljZS94bWwvLzIwMTYvNC82LzAyMmIwNmJiLWNiMWUtNDdiYy1iZjkyLTIxODUxZTMxZjhhYi54bWw=/playerByOsmf.swf");

    //视频地址

    //习近平对开展“两学一做”学习教育作出重要指示强调
    //http://tvplayer.people.com.cn/player.php/xml/L3B2c2VydmljZS94bWwvLzIwMTYvNC82LzAyMmIwNmJiLWNiMWUtNDdiYy1iZjkyLTIxODUxZTMxZjhhYi54bWw=/playerByOsmf.swf

    //习近平就政法队伍建设作出重要指示强调...
   //http://tvplayer.people.com.cn/player.php/xml/L3B2c2VydmljZS94bWwvLzIwMTYvNC8yNS8wODdhOWVkMS01NzA0LTQ5M2YtYTNiZS0zNmViNmM1YzlmYjYueG1s/playerByOsmf.swf

   //习近平在军委联合作战指挥中心视察时强调...
  //http://tvplayer.people.com.cn/player.php/xml/L3B2c2VydmljZS94bWwvLzIwMTYvNC8yMC83NTBlNGU5ZC0yOTA4LTRkNGQtYjJmNy00YjI3MDg1OTgwNmMueG1s/playerByOsmf.swf

   //习近平在出席解放军代表团全体会议时强调
  //http://tvplayer.people.com.cn/player.php/xml/L3B2c2VydmljZS94bWwvLzIwMTYvMy8xMy9lZDk2Mzc1ZS0yMTY3LTQyOWEtYmM2OS00ZmM2MmYzODA1MmUueG1s/playerByOsmf.swf

 //习近平主持召开网络安全和信息化工作座谈会
 //http://tvplayer.people.com.cn/player.php/xml/L3B2c2VydmljZS94bWwvLzIwMTYvNC8xOS8zY2NmNzdkNC0wMTIxLTQ3NTYtOWM1Mi1jYzhkZDBjZDRlMTUueG1s/playerByOsmf.swf
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    if(arg1=="习近平对开展“两学一做”学习教育作出重要指示强调...")
        IEwidget->dynamicCall("Navigate(const QString&)", "http://tvplayer.people.com.cn/player.php/xml/L3B2c2VydmljZS94bWwvLzIwMTYvNC82LzAyMmIwNmJiLWNiMWUtNDdiYy1iZjkyLTIxODUxZTMxZjhhYi54bWw=/playerByOsmf.swf");
    else if(arg1=="习近平就政法队伍建设作出重要指示强调...")
        IEwidget->dynamicCall("Navigate(const QString&)", "http://tvplayer.people.com.cn/player.php/xml/L3B2c2VydmljZS94bWwvLzIwMTYvNC8yNS8wODdhOWVkMS01NzA0LTQ5M2YtYTNiZS0zNmViNmM1YzlmYjYueG1s/playerByOsmf.swf");
    else if(arg1=="习近平在军委联合作战指挥中心视察时强调...")
        IEwidget->dynamicCall("Navigate(const QString&)", "http://tvplayer.people.com.cn/player.php/xml/L3B2c2VydmljZS94bWwvLzIwMTYvNC8yMC83NTBlNGU5ZC0yOTA4LTRkNGQtYjJmNy00YjI3MDg1OTgwNmMueG1s/playerByOsmf.swf");
    else if(arg1=="习近平在出席解放军代表团全体会议时强调...")
        IEwidget->dynamicCall("Navigate(const QString&)", "http://tvplayer.people.com.cn/player.php/xml/L3B2c2VydmljZS94bWwvLzIwMTYvMy8xMy9lZDk2Mzc1ZS0yMTY3LTQyOWEtYmM2OS00ZmM2MmYzODA1MmUueG1s/playerByOsmf.swf");
    else if(arg1=="习近平主持召开网络安全和信息化工作座谈会...")
        IEwidget->dynamicCall("Navigate(const QString&)", "http://tvplayer.people.com.cn/player.php/xml/L3B2c2VydmljZS94bWwvLzIwMTYvNC8xOS8zY2NmNzdkNC0wMTIxLTQ3NTYtOWM1Mi1jYzhkZDBjZDRlMTUueG1s/playerByOsmf.swf");
}

void MainWindow::on_pushButton_2_clicked()//开始考试
{
    xibutton(false);

    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);

    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("考试样题待提供\n");
    tishi->setWindowTitle("提示");
    tishi->exec();
}

void MainWindow::on_pushButton_3_clicked()//龙虎榜
{

    xibutton(false);


    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);

    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("考试后的排名，暂无数据\n");
    tishi->setWindowTitle("提示");
    tishi->exec();

}

void MainWindow::on_pushButton_11_clicked()
{
    ui->label_2->setVisible(false);
    ui->comboBox->setVisible(false);

    xibutton(false);

    IEwidget->setVisible(true);
    ui->label->setVisible(false);

    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);

    IEwidget->setGeometry(ui->label->x(),ui->label->y(),ui->label->width(),ui->label->height());
    IEwidget->dynamicCall("Navigate(const QString&)", "http://up.51xxs.com/users/public/1470008912_961415.swf"); //调用参数

    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("按键：上、下、左、右控制方向\n"
                   "A:射击 S:出刀 D:跳跃");
    tishi->setWindowTitle("提示");
    tishi->exec();
}
