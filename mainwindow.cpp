#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bugValume=0;

    qDebug()<<"asdfasdfsdfsadf";

    setAdjustSize();

    beishu=1.3;
    changeflag=0;
    minFlag=0;
    videoSoundFlag=1;
    timeFlag=0;

    ui->label->setGeometry(ui->label->x(),ui->label->y(),ui->label->width()*beishu,ui->label->height()*beishu);
    bugLabelW=ui->label->width(),bugLabelH=ui->label->height();

    this->setFixedSize(ui->label->width(),ui->label->height()); //设置窗体固定大小

    setWeizhi();

    ui->pushButton->setVisible(false);

    ui->exame->setVisible(false);

    ui->comboBox->setVisible(false);
    ui->examz->setVisible(false);
    ui->speechLabel->setVisible(false);
    ui->rankLabel->setVisible(false);

    ui->happylabel->setVisible(false);

    ui->speechFind2->setVisible(false);

    ui->pushButton->setFocusPolicy(Qt::NoFocus);//?
    ui->down->setFocusPolicy(Qt::NoFocus);//?

    setWindowTitle("习主席系列重要讲话精神学习系统 V2.0");

     setWindowIcon(QIcon(":/tubiao.ico"));

    QAxWidget *tempie=new QAxWidget(ui->label);
    QAxWidget *tempie2=new QAxWidget(ui->label);
    QAxWidget *tempie3=new QAxWidget(ui->label);
    QAxWidget *tempie4=new QAxWidget(ui->label);
//    QAxWidget *tempie5=new QAxWidget(ui->label);

    IEwidget= tempie;
    happyIEwidget=tempie2;
    speechIEwidget=tempie3;
    rankIEwidget=tempie4;


    QPixmap temp(":/shouye.jpg");
    temp=temp.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(temp);
    shouyepix=temp;

    setWindowFlags(Qt::FramelessWindowHint); //取消边框 最大小化按钮



    buttonFlat();

    loadDemo();

    videoflag=0;
    happyflag=0;

//    //设置label字体大小
//    QFont ft;
//    ft.setPointSize(12);
//    ui.label_4->setFont(ft);

    //设置label颜色
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    ui->examwelcome->setPalette(pa);
    ui->examwelcome2->setPalette(pa);

    jieMian(1);

    QPixmap temp2(":/tongyong.jpg");
    temp2=temp2.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    tongyongpix=temp2;

    map["dangshi1"]=89;
    map["dangshi2"]=41;
    map["dangshi3"]=48;
    map["dangshi4"]=88;

    map["junshi1"]=21;
    map["junshi2"]=30;
    map["junshi3"]=28;
    map["junshi4"]=10;

    map["malie1"]=59;
    map["malie2"]=27;
    map["malie3"]=47;
    map["malie4"]=100;
    map["malie5"]=12;

    map["guoxue1"]=112;
    map["guoxue2"]=41;
    map["guoxue3"]=43;
    map["guoxue4"]=46;
    map["guoxue5"]=126;

     moveFlag=0;

    bugXielieX=ui->xilie->x();
    bugXielieY=ui->xilie->y();

    jianliZhanghu();

//   connect(speechIEwidget,SIGNAL(moved()),this,SLOT(mousePressEvent(QMouseEvent *e)));

//    ui->textEdit->setContextMenuPolicy (Qt::NoContextMenu);
//    speechIEwidget->setContextMenuPolicy(Qt::NoContextMenu);


     this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);//无边框、允许最小化、还原
//    this->setWindowFlags(Qt::FramelessWindowHint);//无边框、允许最小化、还原

//     int width = width();
     int width=ui->label->width();

     //构建最小化、最大化、关闭按钮
     QToolButton *minButton = new QToolButton(this);
     QToolButton *closeButton= new QToolButton(this);



     //获取最小化、关闭按钮图标
     QPixmap minPix  = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
     QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);

     //设置最小化、关闭按钮图标
     minButton->setIcon(minPix);
     closeButton->setIcon(closePix);
     //设置最小化、关闭按钮在界面的位置
     minButton->setGeometry(width-46,5,20,20);
     closeButton->setGeometry(width-25,5,20,20);


     //设置鼠标移至按钮上的提示信息
     minButton->setToolTip(tr("最小化"));
     closeButton->setToolTip(tr("关闭"));
     //设置最小化、关闭按钮的样式
     minButton->setStyleSheet("background-color:transparent;");
     closeButton->setStyleSheet("background-color:transparent;");

     connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
     connect(minButton,SIGNAL(clicked()),this,SLOT(showMinimized()));


     ui->shouye->setMouseTracking(true);

     setMouseTracking(true);
     centralWidget()->setMouseTracking(true);//设置不点击就监听鼠标事件

     ui->label->setMouseTracking(true);

     setFilter(); //设置注册事件

     oldx=mapToGlobal(ui->label->pos()).x(),oldy=mapToGlobal(ui->label->pos()).y();

     pared.setColor(QPalette::ButtonText,Qt::red);
     pablack.setColor(QPalette::ButtonText,Qt::black);

     ui->videoSlider->setValue(10);
     ui->videoSlider->setValue(10);
     lastValue=10;

//      QString selfFont = loadFontFamilyFromTTF();
//      QFont f(selfFont);
//      f.setPixelSize(30);
////      ui->genzhe->setText("学习");
//      ui->genzhe->setFont(f);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::buttonHidden(bool flag){

    ui->shouye->setHidden(flag);
    ui->xilie->setHidden(flag);
    ui->video->setHidden(flag);
    ui->genzhe->setHidden(flag);
    ui->exam->setHidden(flag);
    ui->rank->setHidden(flag);
    ui->happy->setHidden(flag);
    ui->bbs->setHidden(flag);
    ui->exit->setHidden(flag);

}
void MainWindow::buttonFlat(){
    ui->shouye->setFlat(true);
    ui->xilie->setFlat(true);
    ui->video->setFlat(true);
    ui->genzhe->setFlat(true);
    ui->exam->setFlat(true);
    ui->rank->setFlat(true);
    ui->happy->setFlat(true);
    ui->bbs->setFlat(true);
    ui->exit->setFlat(true);
}

void MainWindow::on_video_clicked()//视频学习
{
    jieMian(3);
     ui->videoSlider->setValue(lastValue);
    if(videoflag==0){
        videoMoshi="yongdian";
        videoCnt=1;

        videoPlayFlag=0;
        ui->videoPlay->setStyleSheet("QPushButton{border-image: url(:/pause.png);}");

//        IEwidget->setParent(ui->label);
        IEwidget->setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}")); //设定控制器(flash)
        IEwidget->setGeometry(ui->genzhelabel->x(),ui->genzhelabel->y(),ui->genzhelabel->width(),ui->genzhelabel->height());
//        IEwidget->setGeometry(IEwidget->x()*beishu,IEwidget->y()*beishu,IEwidget->width()*beishu,IEwidget->height()*beishu);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\yongdian\\yongdian(1).swf");
        IEwidget->show();
        videoflag=1;
    }

}
void MainWindow::sleep(unsigned int msec){
    QTime reachTime =QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

void MainWindow::on_video_pressed()
{
  ui->video->setGeometry(ui->video->x(),ui->video->y()+3,ui->video->width(),ui->video->height());
}
void MainWindow::on_video_released()
{
    ui->video->setGeometry(ui->video->x(),ui->video->y()-3,ui->video->width(),ui->video->height());
    sleep(1);
}

void MainWindow::on_shouye_pressed()
{
  ui->shouye->setGeometry(ui->shouye->x(),ui->shouye->y()+3,ui->shouye->width(),ui->shouye->height());
}
void MainWindow::on_shouye_released()
{
    ui->shouye->setGeometry(ui->shouye->x(),ui->shouye->y()-3,ui->shouye->width(),ui->shouye->height());
    sleep(1);
}

void MainWindow::on_xilie_pressed()
{
    ui->xilie->setGeometry(ui->xilie->x(),ui->xilie->y()+3,ui->xilie->width(),ui->xilie->height());
}
void MainWindow::on_xilie_released()
{
    ui->xilie->setGeometry(ui->xilie->x(),ui->xilie->y()-3,ui->xilie->width(),ui->xilie->height());
    sleep(1);
}

void MainWindow::on_genzhe_pressed()
{
  ui->genzhe->setGeometry(ui->genzhe->x(),ui->genzhe->y()+3,ui->genzhe->width(),ui->genzhe->height());
}
void MainWindow::on_genzhe_released()
{
    ui->genzhe->setGeometry(ui->genzhe->x(),ui->genzhe->y()-3,ui->genzhe->width(),ui->genzhe->height());
    sleep(1);
}

void MainWindow::on_exam_pressed()
{
  ui->exam->setGeometry(ui->exam->x(),ui->exam->y()+3,ui->exam->width(),ui->exam->height());
}
void MainWindow::on_exam_released()
{
    ui->exam->setGeometry(ui->exam->x(),ui->exam->y()-3,ui->exam->width(),ui->exam->height());
    sleep(1);
}

void MainWindow::on_rank_pressed()
{
  ui->rank->setGeometry(ui->rank->x(),ui->rank->y()+3,ui->rank->width(),ui->rank->height());
}
void MainWindow::on_rank_released()
{
    ui->rank->setGeometry(ui->rank->x(),ui->rank->y()-3,ui->rank->width(),ui->rank->height());
    sleep(1);
}

void MainWindow::on_happy_pressed()
{
  ui->happy->setGeometry(ui->happy->x(),ui->happy->y()+3,ui->happy->width(),ui->happy->height());
}
void MainWindow::on_happy_released()
{
    ui->happy->setGeometry(ui->happy->x(),ui->happy->y()-3,ui->happy->width(),ui->happy->height());
    sleep(1);
}

void MainWindow::on_bbs_pressed()
{
  ui->bbs->setGeometry(ui->bbs->x(),ui->bbs->y()+3,ui->bbs->width(),ui->bbs->height());
}
void MainWindow::on_bbs_released()
{
    ui->bbs->setGeometry(ui->bbs->x(),ui->bbs->y()-3,ui->bbs->width(),ui->bbs->height());
    sleep(1);
}

void MainWindow::on_exit_pressed()
{
  ui->exit->setGeometry(ui->exit->x(),ui->exit->y()+3,ui->exit->width(),ui->exit->height());
}
void MainWindow::on_exit_released()
{
    ui->exit->setGeometry(ui->exit->x(),ui->exit->y()-3,ui->exit->width(),ui->exit->height());
    sleep(1);
}


void MainWindow::on_exit_clicked()
{
    close();
}

void MainWindow::loadDemo(){

    QPixmap temp(":/shouye.jpg");
    shouyepix=temp;
    shouyepix=shouyepix.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    temp.load(":/tongyong.jpg");
    tongyongpix=temp;
    tongyongpix=tongyongpix.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    ranktoppix.load(":/longhurank.png");
    ranktoppix=ranktoppix.scaled(ui->ranktopLabel->width(),ui->ranktopLabel->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    exampix.load(":/exampix.jpg");
    exampix=exampix.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

}

void MainWindow::on_shouye_clicked()
{
    jieMian(1);

//   if(videoflag==1)
//        delete IEwidget;
    ui->label->setPixmap(shouyepix);
    videoflag=0;
}

void MainWindow::on_genzhe_clicked()
{
    jieMian(4);
    setCurrentIndex(-1);//初始化combox

    moshi="dangshi1";
    genzheCnt=1;

    //    QString file1="./guoxue/1/guoxue1-(";
    //    QString file2=QString::number(guoxue_cnt);
    //    QString file3=").JPG";
    //    QString file=file1+file2+file3;
    //    QPixmap temp_pix(file);

    ui->label->setPixmap(tongyongpix);

    temp_pix.load("./follow/dangshi/dangshi1/(1).JPG");
    temp_pix=temp_pix.scaled(ui->genzhelabel->width(),ui->genzhelabel->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->genzhelabel->setPixmap(temp_pix);

}



void MainWindow::on_dangshi_activated(const QString &arg1)
{

}

void MainWindow::on_junshi_activated(const QString &arg1)
{

}

void MainWindow::on_malie_activated(const QString &arg1)
{

}

void MainWindow::on_guoxue_activated(const QString &arg1)
{

}

void MainWindow::setCurrentIndex(int cnt){ //跟着
    if(cnt!=1)
    ui->dangshi->setCurrentIndex(0);
    if(cnt!=2)
    ui->junshi->setCurrentIndex(0);
    if(cnt!=3)
    ui->malie->setCurrentIndex(0);
    if(cnt!=4)
    ui->guoxue->setCurrentIndex(0);
}


void MainWindow::on_next_clicked()
{
        if(genzheCnt==map[moshi]){
            QMessageBox *tishi=new QMessageBox(this);
            tishi->setWindowTitle("提示");
            tishi->setText("浏览完毕\n");
            tishi->exec();
            return;
        }
        else{
            genzheCnt++;
            temp_pix.load("./follow/"+moshi.left(moshi.length() - 1)+"/"+moshi+"/("+QString::number(genzheCnt)+").JPG");
            temp_pix=temp_pix.scaled(ui->genzhelabel->width(),ui->genzhelabel->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            ui->genzhelabel->setPixmap(temp_pix);
        }

}

void MainWindow::on_next_pressed()
{
    ui->next->setGeometry(ui->next->x(),ui->next->y()+3,ui->next->width(),ui->next->height());
}

void MainWindow::on_next_released()
{
    ui->next->setGeometry(ui->next->x(),ui->next->y()-3,ui->next->width(),ui->next->height());
    sleep(1);
}

void MainWindow::on_last_pressed()
{
    ui->last->setGeometry(ui->last->x(),ui->last->y()+3,ui->last->width(),ui->last->height());
}

void MainWindow::on_last_released()
{
    ui->last->setGeometry(ui->last->x(),ui->last->y()-3,ui->last->width(),ui->last->height());
    sleep(1);
}

void MainWindow::jieMian(int index){
    bool flag;

    if(index!=7)
        happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\yongdian().swf");

    if(index==1)
        ui->label->setPixmap(shouyepix);
    else if(index==8){
    }
    else if(index==5){
        ui->label->setPixmap(exampix);
    }
    else
        ui->label->setPixmap(tongyongpix);

    if(index==2) flag=true;
    else if(index!=2) {flag=false;}
    speechIEwidget->setVisible(flag);
    ui->speech1->setVisible(flag);
    ui->speech2->setVisible(flag);
    ui->speech3->setVisible(flag);
    ui->speech4->setVisible(flag);
    ui->speech5->setVisible(flag);
    ui->speech6->setVisible(flag);
    ui->speech7->setVisible(flag);
    ui->speech8->setVisible(flag);
    ui->speech9->setVisible(flag);
    ui->speech10->setVisible(flag);
    ui->speechDangnei->setVisible(flag);
    ui->speechQiangguo->setVisible(flag);
    ui->speechFind1->setVisible(flag);
    ui->speechFind2->setVisible(flag);
    ui->speechPrint->setVisible(flag);
    ui->speechGaige->setVisible(flag);
    ui->speechQiangjun->setVisible(flag);
    ui->speechWaijiao->setVisible(flag);
    ui->speechXibu->setVisible(flag);
    ui->add->setVisible(flag);
    ui->jian->setVisible(flag);
    ui->up->setVisible(flag);
    ui->down->setVisible(flag);
    ui->speechFind1Label->setVisible(flag);
    ui->speechFind2Label->setVisible(flag);
    ui->speechPrintLabel->setVisible(flag);


    if(index==3) flag=true;
    else if(index!=3) {flag=false;videoflag=0;}
    ui->videoliangxue->setVisible(flag);
    ui->videonews->setVisible(flag);
    ui->videoshicha->setVisible(flag);
    ui->videoyongdian->setVisible(flag);
    ui->videoSlider->setVisible(flag);
    ui->videoSound->setVisible(flag);
    ui->videoNext->setVisible(flag);
    ui->videoLast->setVisible(flag);
    ui->videoPlay->setVisible(flag);
    IEwidget->setVisible(flag);

    if(index!=3)
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\yongdian().swf");

    //跟着 4
    if(index==4) flag=true;
    else if(index!=4) flag=false;
        ui->genzhelabel->setVisible(flag);
        ui->dangshi->setVisible(flag);
        ui->junshi->setVisible(flag);
        ui->malie->setVisible(flag);
        ui->guoxue->setVisible(flag);
        ui->next->setVisible(flag);
        ui->last->setVisible(flag);


    //测试 5
    if(index==5) flag=true;
    else if(index!=5) flag=false;
    ui->examlabel->setVisible(flag);
    ui->exama->setVisible(flag);
    ui->examb->setVisible(flag);
    ui->examc->setVisible(flag);
    ui->examd->setVisible(flag);
    ui->examnext->setVisible(flag);
    ui->examjindu->setVisible(flag);
    ui->examwelcome->setVisible(flag);
    ui->examwelcome2->setVisible(flag);
    //2 3 5 6 = 20 40 80 100
    ui->pushButton_2->setVisible(flag);
    ui->pushButton_3->setVisible(flag);
    ui->pushButton_5->setVisible(flag);
    ui->pushButton_6->setVisible(flag);
    ui->examshalou->setVisible(flag);
    ui->examJishi->setVisible(flag);
    ui->examXuanze->setVisible(flag);

    if(index==6) flag=true;
    else if(index!=6) flag=false;
    ui->ranktopLabel->setVisible(flag);
    rankIEwidget->setVisible(flag);


    if(index==7) flag=true;
    else if(index!=7) {flag=false;happyflag=0;}
    ui->happylast->setVisible(flag);
    ui->happynext->setVisible(flag);
    happyIEwidget->setVisible(flag);
    ui->happyPlay->setVisible(flag);
    ui->happySound->setVisible(flag);
    ui->happySlider->setVisible(flag);
    ui->happy_1->setVisible(flag);
    ui->happy_2->setVisible(flag);
    ui->happy_3->setVisible(flag);
    ui->happy_4->setVisible(flag);
    ui->happy_5->setVisible(flag);
    ui->happy_6->setVisible(flag);
    ui->happy_7->setVisible(flag);
    ui->happy_8->setVisible(flag);
    ui->happy_9->setVisible(flag);
    ui->happy_10->setVisible(flag);
    ui->happy_11->setVisible(flag);
    ui->happy_12->setVisible(flag);
}


void MainWindow::on_exam_clicked()
{

    jieMian(5);
    tiN=20;
    ui->examd->setCheckable(false);
    ui->examd->setVisible(false);

    QMovie*movie=new QMovie(":/shalou.gif");
    movie->scaledSize();
    ui->examshalou->setMovie(movie);
    movie->start();

//   ui->examnext->setText("下一题");

    ui->examwelcome->setText("欢迎 "+name[id]+" 的到来");

    QMessageBox *tishi=new QMessageBox(this);
    tishi->setWindowTitle("提示");
    tishi->setText("测试即将开始，请注意：\n"
                   "测试过程中选择答案后不能返回修改\n"
                   "每题你将有10秒的答题时间，否则将会跳至下一题\n"
                   "题目总数默认为20个，完成后提交可查看分数");
    tishi->exec();


    jiShi=0;


    if(timeFlag==0){
        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
        timer->start(1000);
        timeFlag=1;
    }


    ui->examjindu->setText("测试进度：1/20");


    ui->examnext->setStyleSheet("QPushButton{border-image: url(:/next.png);}");

    duicnt=0;
    zuoticnt=1;

    QFont textsize;//字体大小
    textsize.setPointSize(12);
    ui->examlabel->setFont(textsize);

    QPalette textcolor;
    textcolor.setColor(QPalette::WindowText,Qt::red);
    ui->examlabel->setPalette(textcolor);

    int examwidth=ui->examlabel->width();
    int examheight=ui->examlabel->height();

    ui->examlabel->adjustSize();//设置自动换行
    ui->examlabel->setGeometry(QRect(ui->examlabel->x(), ui->examlabel->y(),examwidth,examheight));  //四倍行距
    ui->examlabel->setWordWrap(true);
//    ui->examlabel->setAlignment(Qt::AlignTop);
//    ui->examlabel->setAlignment(Qt::AlignCenter);

    ui->examlabel->setAlignment(Qt::AlignLeft);



//    ui->examlabel->setText("当代中国价值观念，就是（  ）价值观，代表了中国先进文化的前进方向。"); //测试，待注释

    initVis();

    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int xxx=qrand()%abcN;

    abcVis[xxx]=1;

   chuTiABC(xxx);
}

void MainWindow::on_examnext_clicked()
{
//    ui->examnext->setIcon(QIcon(":/checked.png"));

   if(zuoticnt>=tiN+1){
         QMessageBox *tishi=new QMessageBox(this);
         tishi->setWindowTitle("提示");
         tishi->setText("你已经完成测试！\n"
                        "你一共答对了 "+QString::number(duicnt)+" 道题\n"
                         "你的分数为 "+QString::number(100*1.0/(tiN*1.0)*duicnt*1.0)+" 分");
         tishi->exec();
         return;
     }

    QString yourans;
    if(ui->exama->isChecked()){
        yourans="A";
    }
    else if(ui->examb->isChecked())
    {
        yourans="B";
    }
    else if(ui->examc->isChecked())
    {
        yourans="C";
    }
    else if(ui->examd->isChecked())
    {
        yourans="D";
    }
    else if(ui->exame->isChecked()){
        yourans="E";
    }
    else {
        yourans="Z";  //没选择答案
    }

     //如果没有选择答案，强制选择
    if(yourans=="Z"){
        QMessageBox *tishi=new QMessageBox(this);
        tishi->setWindowTitle("提示");
        tishi->setText("你还没有选择任何答案哦\n");
        tishi->exec();
        return;
    }

    if(zuoticnt>=1&&zuoticnt<=tiN)
         judge(yourans);

    ui->examz->setChecked(true);

    zuoticnt++;

    if(zuoticnt==tiN)
        ui->examnext->setStyleSheet("QPushButton{border-image: url(:/checked.png);}");

    if(zuoticnt==tiN+1){
         QMessageBox *tishi=new QMessageBox(this);
         tishi->setWindowTitle("提示");
         tishi->setText("正在计算分数，请稍候\n");
         tishi->show();
         sleep(1000);
         tishi->close();
         sleep(500);
         tishi->setText("你一共答对了 "+QString::number(duicnt)+" 道题\n"
                         "你的分数为 "+QString::number(100*1.0/(tiN*1.0)*duicnt*1.0)+" 分");
         tishi->exec();
      }

    if(zuoticnt<=(tiN/10+6)){
       ui->examd->setCheckable(false);
       ui->examd->setVisible(false);

       while(1){
            QTime time;
            time= QTime::currentTime();
            qsrand(time.msec()+time.second()*1000);
            int t=qrand()%abcN;
            if(abcVis[t]==1) continue;
            chuTiABC(t);
            break;
        }
    }

    else if(zuoticnt>(tiN/10+6)&&zuoticnt<=tiN){
        ui->examd->setCheckable(true);
        ui->examd->setVisible(true);
        while(1){
            QTime time;
            time= QTime::currentTime();
            qsrand(time.msec()+time.second()*1000);
            int t=qrand()%abcdN;
            if(abcdVis[t]==1) continue;
            chuTiABCD(t);
            break;
        }
     }

     if(zuoticnt<=tiN)
        ui->examjindu->setText("测试进度："+QString::number(zuoticnt)+"/"+QString::number(tiN));

    jiShi=0;
}

void MainWindow::on_examnext_pressed()
{
    ui->examnext->setGeometry(ui->examnext->x(),ui->examnext->y()+3,ui->examnext->width(),ui->examnext->height());
}

void MainWindow::on_examnext_released()
{
    ui->examnext->setGeometry(ui->examnext->x(),ui->examnext->y()-3,ui->examnext->width(),ui->examnext->height());
    sleep(1);
}
void MainWindow::chuTiABC(int t){

    int lineNo=t*5+1;

    QFile file(":/abctiku.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
         qDebug()<<"Can't open the file!"<<endl;
     }

    QTextStream in(&file);
    int i=0;
    QString line="";
    while (!in.atEnd() && ++i<=lineNo ){
    line=in.readLine();
//    qDebug()<<line;
    }

    ui->examlabel->setText(line);

    line=in.readLine();
    ui->exama->setText(line);

    line=in.readLine();
    ui->examb->setText(line);

    line=in.readLine();
    ui->examc->setText(line);

    line=in.readLine();
    dangqianans=line;
}

void MainWindow::on_comboBox_activated(const QString &arg1) //待删除
{

}

void MainWindow::initVis(){
    for(int i=0;i<abcN+1;i++)
        abcVis[i]=0;
    for(int i=0;i<abcdN+1;i++)
        abcdVis[i]=0;
}

void MainWindow::chuTiABCD(int t){
//:/abcdtiku.txt
            int lineNo=t*6+1;

            QFile file(":/abcdtiku.txt");
            if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                 qDebug()<<"Can't open the file!"<<endl;
             }
            QTextStream in(&file);
            int i=0;
            QString line="";
            while (!in.atEnd() && ++i<=lineNo ){
            line=in.readLine();
        //    qDebug()<<line;
            }
            ui->examlabel->setText(line);

            line=in.readLine();
            ui->exama->setText(line);

            line=in.readLine();
            ui->examb->setText(line);

            line=in.readLine();
            ui->examc->setText(line);

            line=in.readLine();
            ui->examd->setText(line);

            line=in.readLine();
            dangqianans=line;
}

void MainWindow::judge(QString yourans){

    if(dangqianans.contains(yourans)){
        duicnt++;
        qDebug()<<"da dui le";
    }

    else{
        QMessageBox *tishi=new QMessageBox(this);
        tishi->setWindowTitle("提示");
        if(zuoticnt<=(tiN/10+6)&&zuoticnt>=1)
            tishi->setText("真遗憾，你答错了哦\n"
                        +dangqianans);
        else if(zuoticnt>=(tiN/10+6+1)&&zuoticnt<=tiN)
            tishi->setText("真遗憾，你答错了哦\n"
                        "参考答案："+dangqianans);
        tishi->exec();
    }
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_xilie_clicked()
{

        jieMian(2);
        ui->xilie->setGeometry(bugXielieX,bugXielieY,ui->xilie->width(),ui->xilie->height());
//      speechIEwidget->setParent(ui->label);
//      speechIEwidget->setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}")); //设定控制器(flash)
       speechIEwidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}")); //设置插件为IE
       speechIEwidget->setGeometry(ui->speechLabel->x(),ui->speechLabel->y(),ui->speechLabel->width(),ui->speechLabel->height());
       speechIEwidget->setGeometry(speechIEwidget->x()*beishu,speechIEwidget->y()*beishu,speechIEwidget->width()*beishu,speechIEwidget->height()*beishu);

//        speechIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\html\\1.html");

        speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/qiangjun.htm");

        speechIEwidget->show();
//      E:\QT\build-StudyXiDemo-Desktop_Qt_5_6_0_MinGW_32bit-Debug\html\1.html
}

void MainWindow::on_rank_clicked()
{
    jieMian(6);
    ui->ranktopLabel->setPixmap(ranktoppix);
    rankIEwidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}")); //设置插件为IE，加载网页
    rankIEwidget->setGeometry(ui->rankLabel->x(),ui->rankLabel->y(),ui->rankLabel->width(),ui->rankLabel->height());
    rankIEwidget->setGeometry(rankIEwidget->x()*beishu,rankIEwidget->y()*beishu,rankIEwidget->width()*beishu,rankIEwidget->height()*beishu);
    rankIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/rank.htm");
    rankIEwidget->show();
}

void MainWindow::on_happy_clicked()
{
    jieMian(7);
    ui->happySlider->setValue(lastValue);

    if(happyflag==0){
//        ui->label->setPixmap(video);
        happyPlayFlag=0;
        ui->happyPlay->setStyleSheet("QPushButton{border-image: url(:/pause.png);}");

        happyCnt=1;
        happyIEwidget->setParent(ui->label);
        happyIEwidget->setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}")); //设定控制器(flash)
        happyIEwidget->setGeometry(ui->happylabel->x(),ui->happylabel->y(),ui->happylabel->width(),ui->happylabel->height());

        happyIEwidget->setGeometry(happyIEwidget->x()*beishu,happyIEwidget->y()*beishu,happyIEwidget->width()*beishu,happyIEwidget->height()*beishu);

        happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\1.swf");
        happyIEwidget->show();
        happyflag=1;
    }

}

void MainWindow::on_bbs_clicked()
{
  const QUrl url("http://lt.cjdby.net/");
  QDesktopServices::openUrl(url);
}

void MainWindow::on_happylast_pressed()
{
    ui->happylast->setGeometry(ui->happylast->x(),ui->happylast->y()+3,ui->happylast->width(),ui->happylast->height());
}

void MainWindow::on_happylast_released()
{
    ui->happylast->setGeometry(ui->happylast->x(),ui->happylast->y()-3,ui->happylast->width(),ui->happylast->height());
    sleep(1);
}

void MainWindow::on_happynext_pressed()
{
    ui->happynext->setGeometry(ui->happynext->x(),ui->happynext->y()+3,ui->happynext->width(),ui->happynext->height());
}

void MainWindow::on_happynext_released()
{
    ui->happynext->setGeometry(ui->happynext->x(),ui->happynext->y()-3,ui->happynext->width(),ui->happynext->height());
    sleep(1);

}

void MainWindow::on_speech_17_clicked()
{
    Find *find=new Find();
    find->show();
}

void MainWindow::on_speechDangnei_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/dangnei.htm");

}

void MainWindow::on_speechQiangjun_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/qiangjun.htm");

}

void MainWindow::on_speechGaige_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/gaige.htm");

}

void MainWindow::on_speechQiangguo_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/qiangguo.htm");

}

void MainWindow::on_speechWaijiao_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/waijiao.htm");

}

void MainWindow::on_speechXibu_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/xibu.htm");

}

void MainWindow::on_speechFind1_clicked()
{
    QPoint pc=cursor().pos();//获取当前鼠标位置

    QPoint p=speechIEwidget->pos();

    p=mapToGlobal(p);

    SetCursorPos(p.x()+3,p.y()+3);

    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

    keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),0,0); //按下CTRL键。
    keybd_event(0x46,MapVirtualKey(0x46,0),0,0);//键下F键。
    keybd_event(0x46,MapVirtualKey(0x46,0), KEYEVENTF_KEYUP,0);//放开F键。
    keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),KEYEVENTF_KEYUP,0);//放开CTRL键
    SetCursorPos(pc.x(),pc.y());
}


void MainWindow::on_speechFind1_released()
{
    ui->speechFind1->setGeometry(ui->speechFind1->x(),ui->speechFind1->y()-3,ui->speechFind1->width(),ui->speechFind1->height());
    sleep(1);
}

void MainWindow::on_speechFind2_pressed()
{
    ui->speechFind2->setGeometry(ui->speechFind2->x(),ui->speechFind2->y()+3,ui->speechFind2->width(),ui->speechFind2->height());

}

void MainWindow::on_speechFind2_released()
{
    ui->speechFind2->setGeometry(ui->speechFind2->x(),ui->speechFind2->y()-3,ui->speechFind2->width(),ui->speechFind2->height());
    sleep(1);
}

void MainWindow::on_speechFind1_pressed()
{
    ui->speechFind1->setGeometry(ui->speechFind1->x(),ui->speechFind1->y()+3,ui->speechFind1->width(),ui->speechFind1->height());

}

void MainWindow::on_speech1_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/1.htm");
}

void MainWindow::on_speech2_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/2.htm");

}

void MainWindow::on_speech3_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/3.htm");

}

void MainWindow::on_speech4_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/4.htm");

}

void MainWindow::on_speech5_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/5.htm");

}

void MainWindow::on_speech6_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/6.htm");

}

void MainWindow::on_speech7_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/7.htm");

}

void MainWindow::on_speech8_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/8.htm");

}

void MainWindow::on_speech9_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/9.htm");

}

void MainWindow::on_speech10_clicked()
{
    speechIEwidget->dynamicCall("Navigate(const QString&)", QDir::currentPath()+"/html/10.htm");

}

void MainWindow::on_videoyongdian_activated(const QString &arg1)
{

}

void MainWindow::on_videoyongdian_activated(int index)
{
    if(index!=0){
        videoMoshi="yongdian";
        videoCnt=index;
        setVideoCurrentIndex(1);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\yongdian\\yongdian("+QString::number(index)+").swf");
    }

}
void MainWindow::setVideoCurrentIndex(int cnt){
    if(cnt!=1)
    ui->videoyongdian->setCurrentIndex(0);
    if(cnt!=2)
    ui->videoliangxue->setCurrentIndex(0);
    if(cnt!=3)
    ui->videoshicha->setCurrentIndex(0);
    if(cnt!=4)
    ui->videonews->setCurrentIndex(0);
}

void MainWindow::on_guoxue_activated(int index)
{
    if(index!=0) {
        setCurrentIndex(3);
        moshi="guoxue"+QString::number(index);
        genzheCnt=1;
        temp_pix.load("./follow/guoxue/"+moshi+"/(1).JPG");
        temp_pix=temp_pix.scaled(ui->genzhelabel->width(),ui->genzhelabel->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->genzhelabel->setPixmap(temp_pix);
    }
}

void MainWindow::on_videoliangxue_activated(int index)
{
    if(index!=0){
        videoCnt=index;
        videoMoshi="liangxue";
        setVideoCurrentIndex(2);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\liangxue\\liangxue("+QString::number(index)+").swf");
    }
}

void MainWindow::on_videoshicha_activated(int index)
{
    if(index!=0){
        videoMoshi="shicha";
        videoCnt=index;
        setVideoCurrentIndex(3);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\shichajundui\\("+QString::number(index)+").swf");
    }
}

void MainWindow::on_videonews_activated(int index)
{
    if(index!=0){
        videoMoshi="news";
        videoCnt=index;
        setVideoCurrentIndex(4);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\news\\("+QString::number(index)+").swf");
    }
}

void MainWindow::on_dangshi_activated(int index)
{
    if(index!=0) {
        setCurrentIndex(1);
        moshi="dangshi"+QString::number(index);
        genzheCnt=1;
        temp_pix.load("./follow/dangshi/"+moshi+"/(1).JPG");
        temp_pix=temp_pix.scaled(ui->genzhelabel->width(),ui->genzhelabel->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->genzhelabel->setPixmap(temp_pix);
    }
}

void MainWindow::on_last_clicked()
{
    if(genzheCnt==1){
        QMessageBox *tishi=new QMessageBox(this);
        tishi->setWindowTitle("提示");
        tishi->setText("已经是第一张了！\n");
        tishi->exec();
        return;
    }
    else {
    genzheCnt--;
    temp_pix.load("./follow/"+ moshi.left(moshi.length() - 1)+"/"+moshi+"/("+QString::number(genzheCnt)+").JPG");
    temp_pix=temp_pix.scaled(ui->genzhelabel->width(),ui->genzhelabel->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->genzhelabel->setPixmap(temp_pix);

   }

}

void MainWindow::on_junshi_activated(int index)
{
    if(index!=0) {
        setCurrentIndex(2);
        moshi="junshi"+QString::number(index);
        genzheCnt=1;
        temp_pix.load("./follow/junshi/"+moshi+"/(1).JPG");
        temp_pix=temp_pix.scaled(ui->genzhelabel->width(),ui->genzhelabel->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->genzhelabel->setPixmap(temp_pix);
    }
}

void MainWindow::on_malie_activated(int index)
{
    if(index!=0) {
        setCurrentIndex(3);
        moshi="malie"+QString::number(index);
        genzheCnt=1;
        temp_pix.load("./follow/malie/"+moshi+"/(1).JPG");
        temp_pix=temp_pix.scaled(ui->genzhelabel->width(),ui->genzhelabel->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->genzhelabel->setPixmap(temp_pix);
    }
}

void MainWindow::on_happynext_clicked()
{
    ui->happyPlay->setStyleSheet("QPushButton{border-image: url(:/pause.png);}");
    happyCnt++;
    if(happyCnt>happyN)
        happyCnt=1;
    happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\"+QString::number(happyCnt)+".swf");
}

void MainWindow::on_happylast_clicked()
{
    ui->happyPlay->setStyleSheet("QPushButton{border-image: url(:/pause.png);}");
    happyCnt--;
    if(happyCnt<=0)
        happyCnt=happyN;
    happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\"+QString::number(happyCnt)+".swf");
}

void MainWindow::jianliZhanghu(){
        name["1601"]="黄华",password["1601"]="4003";
        name["1602"]="朱櫆",password["1602"]="4348";
        name["1603"]="罗洋",password["1603"]="4692";
        name["1604"]="李志峰",password["1604"]="5037";
        name["1605"]="郑超越",password["1605"]="5382";
        name["1606"]="吴余",password["1606"]="5727";
        name["1607"]="仁庆江村",password["1607"]="3312";
        name["1608"]="蒙荣伟",password["1608"]="3657";
        name["1609"]="文岭",password["1609"]="4003";
        name["1610"]="雷庆",password["1610"]="4348";
        name["1611"]="张越",password["1611"]="4694";
        name["1612"]="左建强",password["1612"]="5039";
        name["1613"]="刘洋",password["1613"]="5385";
        name["1614"]="袁张松",password["1614"]="5730";
        name["1615"]="刘克江",password["1615"]="6076";
        name["1616"]="刘虎",password["1616"]="6421";
        name["1617"]="廖永生",password["1617"]="6767";
        name["1618"]="彭力",password["1618"]="7112";
        name["1619"]="谢鑫",password["1619"]="7458";
        name["1620"]="王道建",password["1620"]="7803";
        name["1621"]="赖东豪",password["1621"]="8149";
        name["1622"]="蒋金佐",password["1622"]="8494";
        name["1623"]="王虎",password["1623"]="8840";
        name["1624"]="吕浩浩",password["1624"]="9185";
        name["1625"]="罗长城",password["1625"]="9531";
        name["1626"]="陈光照",password["1626"]="9876";
        name["1627"]="陈湘",password["1627"]="3658";
        name["1628"]="董淑贵",password["1628"]="1265";
        name["1629"]="杨润",password["1629"]="1532";
        name["1630"]="赵宪吉",password["1630"]="1956";
        name["1631"]="晋美朗杰",password["1631"]="2275";
        name["1632"]="尤升辉",password["1632"]="2621";
        name["1633"]="胡敬茂",password["1633"]="2966";
        name["1634"]="李游知",password["1634"]="6072";
        name["1635"]="浦智力",password["1635"]="6417";
        name["1636"]="蒋亚洲",password["1636"]="6761";
        name["1637"]="刘光富",password["1637"]="7106";
        name["1638"]="强巴吹批",password["1638"]="7451";
        name["1639"]="牟毅",password["1639"]="7796";
        name["test01"]="王鹏飞",password["test01"]="test01";
        name["test02"]="王鹏飞",password["test02"]="test02";
        name["test03"]="王鹏飞",password["test03"]="test03";
        name["test04"]="王鹏飞",password["test04"]="test04";
        name["test05"]="王鹏飞",password["test05"]="test05";
}

void MainWindow::on_add_pressed()
{
    ui->add->setGeometry(ui->add->x(),ui->add->y()+3,ui->add->width(),ui->add->height());
}

void MainWindow::on_add_released()
{
    ui->add->setGeometry(ui->add->x(),ui->add->y()-3,ui->add->width(),ui->add->height());
    sleep(1);

}

void MainWindow::on_up_pressed()
{
    ui->up->setGeometry(ui->up->x(),ui->up->y()+3,ui->up->width(),ui->up->height());

}

void MainWindow::on_up_released()
{
    ui->up->setGeometry(ui->up->x(),ui->up->y()-3,ui->up->width(),ui->up->height());
    sleep(1);

}

void MainWindow::on_jian_pressed()
{
    ui->jian->setGeometry(ui->jian->x(),ui->jian->y()+3,ui->jian->width(),ui->jian->height());

}

void MainWindow::on_jian_released()
{
    ui->jian->setGeometry(ui->jian->x(),ui->jian->y()-3,ui->jian->width(),ui->jian->height());
    sleep(1);
}

void MainWindow::on_down_pressed()
{
    ui->down->setGeometry(ui->down->x(),ui->down->y()+3,ui->down->width(),ui->down->height());
}

void MainWindow::on_down_released()
{
    ui->down->setGeometry(ui->down->x(),ui->down->y()-3,ui->down->width(),ui->down->height());
    sleep(1);
}

void MainWindow::on_speechPrint_pressed()
{
    ui->speechPrint->setGeometry(ui->speechPrint->x(),ui->speechPrint->y()+3,ui->speechPrint->width(),ui->speechPrint->height());
}

void MainWindow::on_speechPrint_released()
{
    ui->speechPrint->setGeometry(ui->speechPrint->x(),ui->speechPrint->y()-3,ui->speechPrint->width(),ui->speechPrint->height());
    sleep(1);
}

void MainWindow::on_add_clicked()
{
    QPoint pc=cursor().pos();//获取当前鼠标位置
    QPoint p=speechIEwidget->pos();
    p=mapToGlobal(p);
    SetCursorPos(p.x()+3,p.y()+3);
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

    keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),0,0); //按下CTRL键。
    keybd_event(107,MapVirtualKey(107,0),0,0);//键下+键。
    keybd_event(107,MapVirtualKey(107,0), KEYEVENTF_KEYUP,0);//放开+键。
    keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),KEYEVENTF_KEYUP,0);//放开CTRL键

    SetCursorPos(pc.x(),pc.y());
}

void MainWindow::on_jian_clicked()
{
    QPoint pc=cursor().pos();//获取当前鼠标位置
    QPoint p=speechIEwidget->pos();
    p=mapToGlobal(p);
    SetCursorPos(p.x()+3,p.y()+3);
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

    keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),0,0); //按下CTRL键。
    keybd_event(109,MapVirtualKey(109,0),0,0);//键下+键。
    keybd_event(109,MapVirtualKey(109,0), KEYEVENTF_KEYUP,0);//放开+键。
    keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),KEYEVENTF_KEYUP,0);//放开CTRL键

    SetCursorPos(pc.x(),pc.y());
}

void MainWindow::on_up_clicked()
{
    QPoint pc=cursor().pos();//获取当前鼠标位置
    QPoint p=speechIEwidget->pos();
    p=mapToGlobal(p);
    SetCursorPos(p.x()+3,p.y()+3);
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

    keybd_event(38,MapVirtualKey(38,0),0,0);//键下up键。
    keybd_event(38,MapVirtualKey(38,0), KEYEVENTF_KEYUP,0);//放开up键。

    SetCursorPos(pc.x(),pc.y());
}

void MainWindow::on_down_clicked()
{
    QPoint pc=cursor().pos();//获取当前鼠标位置
    QPoint p=speechIEwidget->pos();
    p=mapToGlobal(p);
    SetCursorPos(p.x()+3,p.y()+3);
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
    keybd_event(40,MapVirtualKey(40,0),0,0);//键下up键。
    keybd_event(40,MapVirtualKey(40,0), KEYEVENTF_KEYUP,0);//放开up键。
    SetCursorPos(pc.x(),pc.y());
}

void MainWindow::on_speechPrint_clicked()
{
    QPoint pc=cursor().pos();//获取当前鼠标位置
    QPoint p=speechIEwidget->pos();
    p=mapToGlobal(p);
    SetCursorPos(p.x()+3,p.y()+3);

    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

    keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),0,0); //按下CTRL键。
    keybd_event(80,MapVirtualKey(80,0),0,0);//键下P键。
    keybd_event(80,MapVirtualKey(80,0), KEYEVENTF_KEYUP,0);//放开P键。
    keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),KEYEVENTF_KEYUP,0);//放开CTRL键
    SetCursorPos(pc.x(),pc.y());
}

void MainWindow::on_speechFind2_clicked()
{

    QPoint pc=cursor().pos();//获取当前鼠标位置

    QPoint p=speechIEwidget->pos();
    p=mapToGlobal(p);

    find.X=p.x()+3,find.Y=p.y()+3;

    p=ui->speechQiangjun->pos();
    p=mapToGlobal(p);
    find.xbutton[1]=p.x(),find.ybutton[1]=p.y();

    p=ui->speechDangnei->pos();
    p=mapToGlobal(p);
    find.xbutton[2]=p.x(),find.ybutton[2]=p.y();

    p=ui->speechGaige->pos();
    p=mapToGlobal(p);
    find.xbutton[3]=p.x(),find.ybutton[3]=p.y();

    p=ui->speechQiangguo->pos();
    p=mapToGlobal(p);
    find.xbutton[4]=p.x(),find.ybutton[4]=p.y();

    p=ui->speechWaijiao->pos();
    p=mapToGlobal(p);
    find.xbutton[5]=p.x(),find.ybutton[5]=p.y();

    p=ui->speechXibu->pos();
    p=mapToGlobal(p);
    find.xbutton[6]=p.x(),find.ybutton[6]=p.y();

    p=ui->speech1->pos();
    p=mapToGlobal(p);
    find.xbutton[7]=p.x(),find.ybutton[7]=p.y();

    p=ui->speech2->pos();
    p=mapToGlobal(p);
    find.xbutton[8]=p.x(),find.ybutton[8]=p.y();

    p=ui->speech3->pos();
    p=mapToGlobal(p);
    find.xbutton[9]=p.x(),find.ybutton[9]=p.y();

    p=ui->speech4->pos();
    p=mapToGlobal(p);
    find.xbutton[10]=p.x(),find.ybutton[10]=p.y();

    p=ui->speech5->pos();
    p=mapToGlobal(p);
    find.xbutton[11]=p.x(),find.ybutton[11]=p.y();

    p=ui->speech6->pos();
    p=mapToGlobal(p);
    find.xbutton[12]=p.x(),find.ybutton[12]=p.y();

    p=ui->speech7->pos();
    p=mapToGlobal(p);
    find.xbutton[13]=p.x(),find.ybutton[13]=p.y();

    p=ui->speech8->pos();
    p=mapToGlobal(p);
    find.xbutton[14]=p.x(),find.ybutton[14]=p.y();

    p=ui->speech9->pos();
    p=mapToGlobal(p);
    find.xbutton[15]=p.x(),find.ybutton[15]=p.y();

    p=ui->speech10->pos();
    p=mapToGlobal(p);
    find.xbutton[16]=p.x(),find.ybutton[16]=p.y();

    find.show();

//    find.

}

void MainWindow::mousePressEvent(QMouseEvent *e){
    if((IEwidget->isHidden()==false)&&(e->x()>IEwidget->x()&&e->x()<(IEwidget->x()+IEwidget->width()))&&(e->y()>IEwidget->y())&&(e->y()<(IEwidget->y()+IEwidget->height())))
            return;
    if((speechIEwidget->isHidden()==false)&&(e->x()>speechIEwidget->x()&&e->x()<(speechIEwidget->x()+speechIEwidget->width()))&&(e->y()>speechIEwidget->y())&&(e->y()<(speechIEwidget->y()+speechIEwidget->height())))
            return;
    if((happyIEwidget->isHidden()==false)&&(e->x()>happyIEwidget->x()&&e->x()<(happyIEwidget->x()+happyIEwidget->width()))&&(e->y()>happyIEwidget->y())&&(e->y()<(happyIEwidget->y()+happyIEwidget->height())))
            return;
    if(e->button()==Qt::RightButton){
        if((speechIEwidget->isHidden()==false)&&(e->x()>speechIEwidget->x())&&(e->x()<(speechIEwidget->x()+speechIEwidget->width()))&&(e->y()>speechIEwidget->y())&&(e->y()<(speechIEwidget->y()+speechIEwidget->width())))
                return;
        if((rankIEwidget->isHidden()==false)&&(e->x()>rankIEwidget->x())&&(e->x()<(rankIEwidget->x()+rankIEwidget->width()))&&(e->y()>rankIEwidget->y())&&(e->y()<(rankIEwidget->y()+rankIEwidget->width())))
                return;
//        if(IEwidget->isHidden()==false) return;
//        if(happyIEwidget->isHidden()==false) return;
//        if(rankIEwidget->isHidden()==false) return;
        moveFlag=1;
        double x=e->pos().x();
        double y=e->pos().y();
        last=e->globalPos();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e){
    if((IEwidget->isHidden()==false)&&(e->x()>IEwidget->x()&&e->x()<(IEwidget->x()+IEwidget->width()))&&(e->y()>IEwidget->y())&&(e->y()<(IEwidget->y()+IEwidget->height())))
            return;
    if((speechIEwidget->isHidden()==false)&&(e->x()>speechIEwidget->x()&&e->x()<(speechIEwidget->x()+speechIEwidget->width()))&&(e->y()>speechIEwidget->y())&&(e->y()<(speechIEwidget->y()+speechIEwidget->height())))
            return;
    if((happyIEwidget->isHidden()==false)&&(e->x()>happyIEwidget->x()&&e->x()<(happyIEwidget->x()+happyIEwidget->width()))&&(e->y()>happyIEwidget->y())&&(e->y()<(happyIEwidget->y()+happyIEwidget->height())))
            return;
    if(moveFlag==0) return;
    if(e->button()==Qt::RightButton){
        moveFlag=0;
        int dx=e->globalX()-last.x();
        int dy=e->globalY()-last.y();
        move(x()+dx,y()+dy);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e){
    if((IEwidget->isHidden()==false)&&(e->x()>IEwidget->x()&&e->x()<(IEwidget->x()+IEwidget->width()))&&(e->y()>IEwidget->y())&&(e->y()<(IEwidget->y()+IEwidget->height())))
            return;
    if((speechIEwidget->isHidden()==false)&&(e->x()>speechIEwidget->x()&&e->x()<(speechIEwidget->x()+speechIEwidget->width()))&&(e->y()>speechIEwidget->y())&&(e->y()<(speechIEwidget->y()+speechIEwidget->height())))
            return;
    if((happyIEwidget->isHidden()==false)&&(e->x()>happyIEwidget->x()&&e->x()<(happyIEwidget->x()+happyIEwidget->width()))&&(e->y()>happyIEwidget->y())&&(e->y()<(happyIEwidget->y()+happyIEwidget->height())))
            return;
    if(moveFlag==1){
         int dx=e->globalX()-last.x();
         int dy=e->globalY()-last.y();
         last=e->globalPos();
         move(x()+dx,y()+dy);
 }
}

void MainWindow::setWeizhi(){
    //按钮位置重设
    ui->shouye->setGeometry(ui->shouye->x()*beishu,ui->shouye->y()*beishu,ui->shouye->width()*beishu,ui->shouye->height()*beishu);
    ui->xilie->setGeometry(ui->xilie->x()*beishu,ui->xilie->y()*beishu,ui->xilie->width()*beishu,ui->xilie->height()*beishu);
    ui->video->setGeometry(ui->video->x()*beishu,ui->video->y()*beishu,ui->video->width()*beishu,ui->video->height()*beishu);
    ui->genzhe->setGeometry(ui->genzhe->x()*beishu,ui->genzhe->y()*beishu,ui->genzhe->width()*beishu,ui->genzhe->height()*beishu);
    ui->exam->setGeometry(ui->exam->x()*beishu,ui->exam->y()*beishu,ui->exam->width()*beishu,ui->exam->height()*beishu);
    ui->rank->setGeometry(ui->rank->x()*beishu,ui->rank->y()*beishu,ui->rank->width()*beishu,ui->rank->height()*beishu);
    ui->happy->setGeometry(ui->happy->x()*beishu,ui->happy->y()*beishu,ui->happy->width()*beishu,ui->happy->height()*beishu);
    ui->bbs->setGeometry(ui->bbs->x()*beishu,ui->bbs->y()*beishu,ui->bbs->width()*beishu,ui->bbs->height()*beishu);
    ui->exit->setGeometry(ui->exit->x()*beishu,ui->exit->y()*beishu,ui->exit->width()*beishu,ui->exit->height()*beishu);

    //speech页面控件位置重设
//    speechIEwidget->setGeometry(speechIEwidget->x()*beishu,speechIEwidget->y()*beishu,speechIEwidget->width()*beishu,speechIEwidget->height()*beishu);
    ui->speech1->setGeometry(ui->speech1->x()*beishu,ui->speech1->y()*beishu,ui->speech1->width()*beishu,ui->speech1->height()*beishu);
    ui->speech2->setGeometry(ui->speech2->x()*beishu,ui->speech2->y()*beishu,ui->speech2->width()*beishu,ui->speech2->height()*beishu);
    ui->speech3->setGeometry(ui->speech3->x()*beishu,ui->speech3->y()*beishu,ui->speech3->width()*beishu,ui->speech3->height()*beishu);
    ui->speech4->setGeometry(ui->speech4->x()*beishu,ui->speech4->y()*beishu,ui->speech4->width()*beishu,ui->speech4->height()*beishu);
    ui->speech5->setGeometry(ui->speech5->x()*beishu,ui->speech5->y()*beishu,ui->speech5->width()*beishu,ui->speech5->height()*beishu);
    ui->speech6->setGeometry(ui->speech6->x()*beishu,ui->speech6->y()*beishu,ui->speech6->width()*beishu,ui->speech6->height()*beishu);
    ui->speech7->setGeometry(ui->speech7->x()*beishu,ui->speech7->y()*beishu,ui->speech7->width()*beishu,ui->speech7->height()*beishu);
    ui->speech8->setGeometry(ui->speech8->x()*beishu,ui->speech8->y()*beishu,ui->speech8->width()*beishu,ui->speech8->height()*beishu);
    ui->speech9->setGeometry(ui->speech9->x()*beishu,ui->speech9->y()*beishu,ui->speech9->width()*beishu,ui->speech9->height()*beishu);
    ui->speech10->setGeometry(ui->speech10->x()*beishu,ui->speech10->y()*beishu,ui->speech10->width()*beishu,ui->speech10->height()*beishu);
    ui->speechDangnei->setGeometry(ui->speechDangnei->x()*beishu,ui->speechDangnei->y()*beishu,ui->speechDangnei->width()*beishu,ui->speechDangnei->height()*beishu);
    ui->speechQiangguo->setGeometry(ui->speechQiangguo->x()*beishu,ui->speechQiangguo->y()*beishu,ui->speechQiangguo->width()*beishu,ui->speechQiangguo->height()*beishu);
    ui->speechFind1->setGeometry(ui->speechFind1->x()*beishu,ui->speechFind1->y()*beishu,ui->speechFind1->width()*beishu,ui->speechFind1->height()*beishu);
    ui->speechFind2->setGeometry(ui->speechFind2->x()*beishu,ui->speechFind2->y()*beishu,ui->speechFind2->width()*beishu,ui->speechFind2->height()*beishu);
    ui->speechPrint->setGeometry(ui->speechPrint->x()*beishu,ui->speechPrint->y()*beishu,ui->speechPrint->width()*beishu,ui->speechPrint->height()*beishu);
    ui->speechGaige->setGeometry(ui->speechGaige->x()*beishu,ui->speechGaige->y()*beishu,ui->speechGaige->width()*beishu,ui->speechGaige->height()*beishu);
    ui->speechQiangjun->setGeometry(ui->speechQiangjun->x()*beishu,ui->speechQiangjun->y()*beishu,ui->speechQiangjun->width()*beishu,ui->speechQiangjun->height()*beishu);
    ui->speechWaijiao->setGeometry(ui->speechWaijiao->x()*beishu,ui->speechWaijiao->y()*beishu,ui->speechWaijiao->width()*beishu,ui->speechWaijiao->height()*beishu);
    ui->speechXibu->setGeometry(ui->speechXibu->x()*beishu,ui->speechXibu->y()*beishu,ui->speechXibu->width()*beishu,ui->speechXibu->height()*beishu);
    ui->add->setGeometry(ui->add->x()*beishu,ui->add->y()*beishu,ui->add->width()*beishu,ui->add->height()*beishu);
    ui->jian->setGeometry(ui->jian->x()*beishu,ui->jian->y()*beishu,ui->jian->width()*beishu,ui->jian->height()*beishu);
    ui->up->setGeometry(ui->up->x()*beishu,ui->up->y()*beishu,ui->up->width()*beishu,ui->up->height()*beishu);
    ui->down->setGeometry(ui->down->x()*beishu,ui->down->y()*beishu,ui->down->width()*beishu,ui->down->height()*beishu);

    ui->speechFind1Label->setGeometry(ui->speechFind1Label->x()*beishu,ui->speechFind1Label->y()*beishu,ui->speechFind1Label->width()*beishu,ui->speechFind1Label->height()*beishu);
    ui->speechFind2Label->setGeometry(ui->speechFind2Label->x()*beishu,ui->speechFind2Label->y()*beishu,ui->speechFind2Label->width()*beishu,ui->speechFind2Label->height()*beishu);
    ui->speechPrintLabel->setGeometry(ui->speechPrintLabel->x()*beishu,ui->speechPrintLabel->y()*beishu,ui->speechPrintLabel->width()*beishu,ui->speechPrintLabel->height()*beishu);

    //video页面控件位置重置
    ui->videoliangxue->setGeometry(ui->videoliangxue->x()*beishu,ui->videoliangxue->y()*beishu,ui->videoliangxue->width()*beishu,ui->videoliangxue->height()*beishu);
    ui->videonews->setGeometry(ui->videonews->x()*beishu,ui->videonews->y()*beishu,ui->videonews->width()*beishu,ui->videonews->height()*beishu);
    ui->videoshicha->setGeometry(ui->videoshicha->x()*beishu,ui->videoshicha->y()*beishu,ui->videoshicha->width()*beishu,ui->videoshicha->height()*beishu);
    ui->videoyongdian->setGeometry(ui->videoyongdian->x()*beishu,ui->videoyongdian->y()*beishu,ui->videoyongdian->width()*beishu,ui->videoyongdian->height()*beishu);
    ui->videoLast->setGeometry(ui->videoLast->x()*beishu,ui->videoLast->y()*beishu,ui->videoLast->width()*beishu,ui->videoLast->height()*beishu);
    ui->videoNext->setGeometry(ui->videoNext->x()*beishu,ui->videoNext->y()*beishu,ui->videoNext->width()*beishu,ui->videoNext->height()*beishu);
    ui->videoPlay->setGeometry(ui->videoPlay->x()*beishu,ui->videoPlay->y()*beishu,ui->videoPlay->width()*beishu,ui->videoPlay->height()*beishu);
    ui->videoSound->setGeometry(ui->videoSound->x()*beishu,ui->videoSound->y()*beishu,ui->videoSound->width()*beishu,ui->videoSound->height()*beishu);
    ui->videoSlider->setGeometry(ui->videoSlider->x()*beishu,ui->videoSlider->y()*beishu,ui->videoSlider->width()*beishu,ui->videoSlider->height()*beishu);

    //    ui->videoSoundAdd->setGeometry(ui->videoSoundAdd->x()*beishu,ui->videoSoundAdd->y()*beishu,ui->videoSoundAdd->width()*beishu,ui->videoSoundAdd->height()*beishu);

    //跟着页面控件位置重置
        ui->genzhelabel->setGeometry(ui->genzhelabel->x()*beishu,ui->genzhelabel->y()*beishu,ui->genzhelabel->width()*beishu,ui->genzhelabel->height()*beishu);
        ui->dangshi->setGeometry(ui->dangshi->x()*beishu,ui->dangshi->y()*beishu,ui->dangshi->width()*beishu,ui->dangshi->height()*beishu);
        ui->junshi->setGeometry(ui->junshi->x()*beishu,ui->junshi->y()*beishu,ui->junshi->width()*beishu,ui->junshi->height()*beishu);
        ui->malie->setGeometry(ui->malie->x()*beishu,ui->malie->y()*beishu,ui->malie->width()*beishu,ui->malie->height()*beishu);
        ui->guoxue->setGeometry(ui->guoxue->x()*beishu,ui->guoxue->y()*beishu,ui->guoxue->width()*beishu,ui->guoxue->height()*beishu);
        ui->next->setGeometry(ui->next->x()*beishu,ui->next->y()*beishu,ui->next->width()*beishu,ui->next->height()*beishu);
        ui->last->setGeometry(ui->last->x()*beishu,ui->last->y()*beishu,ui->last->width()*beishu,ui->last->height()*beishu);

    //测试页面控件位置重置
    ui->examlabel->setGeometry(ui->examlabel->x()*beishu,ui->examlabel->y()*beishu,ui->examlabel->width()*beishu,ui->examlabel->height()*beishu);
    ui->exama->setGeometry(ui->exama->x()*beishu,ui->exama->y()*beishu,ui->exama->width()*beishu,ui->exama->height()*beishu);
    ui->examb->setGeometry(ui->examb->x()*beishu,ui->examb->y()*beishu,ui->examb->width()*beishu,ui->examb->height()*beishu);
    ui->examc->setGeometry(ui->examc->x()*beishu,ui->examc->y()*beishu,ui->examc->width()*beishu,ui->examc->height()*beishu);
    ui->examd->setGeometry(ui->examd->x()*beishu,ui->examd->y()*beishu,ui->examd->width()*beishu,ui->examd->height()*beishu);
    ui->examnext->setGeometry(ui->examnext->x()*beishu,ui->examnext->y()*beishu,ui->examnext->width()*beishu,ui->examnext->height()*beishu);
    ui->examjindu->setGeometry(ui->examjindu->x()*beishu,ui->examjindu->y()*beishu,ui->examjindu->width()*beishu,ui->examjindu->height()*beishu);
    ui->examwelcome->setGeometry(ui->examwelcome->x()*beishu,ui->examwelcome->y()*beishu,ui->examwelcome->width()*beishu,ui->examwelcome->height()*beishu);
    ui->examwelcome2->setGeometry(ui->examwelcome2->x()*beishu,ui->examwelcome2->y()*beishu,ui->examwelcome2->width()*beishu,ui->examwelcome2->height()*beishu);
    ui->examshalou->setGeometry(ui->examshalou->x()*beishu,ui->examshalou->y()*beishu,ui->examshalou->width()*beishu,ui->examshalou->height()*beishu);
    ui->examJishi->setGeometry(ui->examJishi->x()*beishu,ui->examJishi->y()*beishu,ui->examJishi->width()*beishu,ui->examJishi->height()*beishu);

    //龙虎榜页面控件位置重置
    ui->ranktopLabel->setGeometry(ui->ranktopLabel->x()*beishu,ui->ranktopLabel->y()*beishu,ui->ranktopLabel->width()*beishu,ui->ranktopLabel->height()*beishu);
//    rankIEwidget->setGeometry(ui->rankIEwidget->x()*beishu,ui->rankIEwidget->y()*beishu,ui->rankIEwidget->width()*beishu,ui->rankIEwidget->height()*beishu);

    //happy页面重置
    ui->happylast->setGeometry(ui->happylast->x()*beishu,ui->happylast->y()*beishu,ui->happylast->width()*beishu*0.8,ui->happylast->height()*beishu*0.8);
    ui->happynext->setGeometry(ui->happynext->x()*beishu,ui->happynext->y()*beishu,ui->happynext->width()*beishu*0.8,ui->happynext->height()*beishu*0.8);
    ui->happyPlay->setGeometry(ui->happyPlay->x()*beishu,ui->happyPlay->y()*beishu,ui->happyPlay->width()*beishu*0.8,ui->happyPlay->height()*beishu*0.8);
    ui->happySound->setGeometry(ui->happySound->x()*beishu,ui->happySound->y()*beishu,ui->happySound->width()*beishu*0.8,ui->happySound->height()*beishu*0.8);
    ui->happySlider->setGeometry(ui->happySlider->x()*beishu,ui->happySlider->y()*beishu,ui->happySlider->width()*beishu*0.8,ui->happySlider->height()*beishu*0.8);
    //happyIEwidget->setGeometry(ui->happyIEwidget->x()*beishu,ui->happyIEwidget->y()*beishu,ui->happyIEwidget->width()*beishu,ui->happyIEwidget->height()*beishu);
}




bool MainWindow::eventFilter(QObject *target, QEvent *e)
{
    if(target==ui->shouye)
    {
        if(e->type() == QEvent::Enter){
            ui->shouye->setPalette(pared);
//            QSound tempsound("./sound/about.wav");
            QSound::play("./sound/about.wav");
        }
        else if(e->type()==QEvent::Leave){
            ui->shouye->setPalette(pablack);
        }
    }
    else if(target==ui->xilie)
    {
        if(e->type() == QEvent::Enter){
            ui->xilie->setPalette(pared);
            QSound::play("./sound/about.wav");
        }
        else if(e->type()==QEvent::Leave){
            ui->xilie->setPalette(pablack);
        }
    }
   else if(target==ui->video)
    {
        if(e->type() == QEvent::Enter){
            ui->video->setPalette(pared);
            QSound::play("./sound/about.wav");
        }
        else if(e->type()==QEvent::Leave){
            ui->video->setPalette(pablack);
        }
    }
    else if(target==ui->genzhe)
    {
        if(e->type() == QEvent::Enter){
            ui->genzhe->setPalette(pared);
            QSound::play("./sound/about.wav");
        }
        else if(e->type()==QEvent::Leave){
            ui->genzhe->setPalette(pablack);
        }
    }
    else if(target==ui->exam)
        {
            if(e->type() == QEvent::Enter){
                ui->exam->setPalette(pared);
                QSound::play("./sound/about.wav");
            }
            else if(e->type()==QEvent::Leave){
                ui->exam->setPalette(pablack);
            }
        }
    else if(target==ui->rank)
        {
            if(e->type() == QEvent::Enter){
                ui->rank->setPalette(pared);
                QSound::play("./sound/about.wav");
            }
            else if(e->type()==QEvent::Leave){
                ui->rank->setPalette(pablack);
            }
        }
    else if(target==ui->happy)
        {
            if(e->type() == QEvent::Enter){
                ui->happy->setPalette(pared);
                QSound::play("./sound/about.wav");
            }
            else if(e->type()==QEvent::Leave){
                ui->happy->setPalette(pablack);
            }
        }
    else if(target==ui->bbs)
        {
            if(e->type() == QEvent::Enter){
                ui->bbs->setPalette(pared);
                QSound::play("./sound/about.wav");
            }
            else if(e->type()==QEvent::Leave){
                ui->bbs->setPalette(pablack);
            }
        }
    else if(target==ui->exit)
        {
            if(e->type() == QEvent::Enter){
                ui->exit->setPalette(pared);
                QSound::play("./sound/about.wav");
            }
            else if(e->type()==QEvent::Leave){
                ui->exit->setPalette(pablack);
            }
        }


}

void MainWindow::changeEvent(QEvent* e) {
    if(e->type() == QEvent::WindowStateChange)
    {
        if(this->windowState() & Qt::WindowMinimized)
        {
            //do something after minimize
            if(changeflag==0){
                QPoint p=ui->label->pos();
                p=mapToGlobal(p);
                oldx=p.x(),oldy=p.y();
                qDebug()<<p.x()<<p.y();
                changeflag=1;
            }
             this->setFixedSize(bugLabelW,bugLabelH); //设置窗体固定大小

        }
        else
        {
          show();

          this->setFixedSize(bugLabelW,bugLabelH); //设置窗体固定大小
          showMaximized();
          if(minFlag==0){
                    sleep(1);
                    minFlag=1;
          }

          move(oldx+0,oldy+0);
          setGeometry(oldx,oldy,bugLabelW,bugLabelH);


//          QDesktopWidget* pDw = QApplication::desktop();//获得桌面窗体
//          QRect rect = pDw->screenGeometry();//获得分辨率
//          this->move(rect.width()/2,rect.height()/2);

            ui->video->update();
            this->repaint();
            this->update();

//          showNormal();
//          repaint();
//          update();
           qDebug()<<"max";
        }
    }
}

//QString MainWindow::loadFontFamilyFromTTF()
//{
//    static QString font;
//    static bool loaded = false;
//    if(!loaded)
//    {
//        loaded = true;
//        int loadedFontID = QFontDatabase::addApplicationFont(":/mnjyh.TTF");
//        QStringList loadedFontFamilies = QFontDatabase::applicationFontFamilies(loadedFontID);
//        if(!loadedFontFamilies.empty())
//            font = loadedFontFamilies.at(0);
//    }
//    return font;
////how to use this font
////    QString selfFont = loadFontFamilyFromTTF();
////    QFont f(selfFont);
////    f.setPixelSize(38);
////    lb_Progress->setFont(f);
//}

void MainWindow::setFilter(){

    ui->shouye->installEventFilter(this);
    ui->xilie->installEventFilter(this);
    ui->video->installEventFilter(this);//button为一个控件对象，通过installEventFilter(this)函数进行注册事件。
    ui->genzhe->installEventFilter(this);
    ui->exam->installEventFilter(this);
    ui->rank->installEventFilter(this);
    ui->happy->installEventFilter(this);
    ui->bbs->installEventFilter(this);
    ui->exit->installEventFilter(this);

 }


void MainWindow::on_videoPlay_pressed()
{
    ui->videoPlay->setGeometry(ui->videoPlay->x(),ui->videoPlay->y()+3,ui->videoPlay->width(),ui->videoPlay->height());
}

void MainWindow::on_videoPlay_released()
{
    ui->videoPlay->setGeometry(ui->videoPlay->x(),ui->videoPlay->y()-3,ui->videoPlay->width(),ui->videoPlay->height());
}

void MainWindow::on_videoLast_pressed()
{
    ui->videoLast->setGeometry(ui->videoLast->x(),ui->videoLast->y()+3,ui->videoLast->width(),ui->videoLast->height());
}

void MainWindow::on_videoLast_released()
{
    ui->videoLast->setGeometry(ui->videoLast->x(),ui->videoLast->y()-3,ui->videoLast->width(),ui->videoLast->height());
}

void MainWindow::on_videoNext_pressed()
{
    ui->videoNext->setGeometry(ui->videoNext->x(),ui->videoNext->y()+3,ui->videoNext->width(),ui->videoNext->height());
}

void MainWindow::on_videoNext_released()
{
    ui->videoNext->setGeometry(ui->videoNext->x(),ui->videoNext->y()-3,ui->videoNext->width(),ui->videoNext->height());
}


void MainWindow::on_videoSound_pressed()
{
    ui->videoSound->setGeometry(ui->videoSound->x(),ui->videoSound->y()+3,ui->videoSound->width(),ui->videoSound->height());
}

void MainWindow::on_videoSound_released()
{
    ui->videoSound->setGeometry(ui->videoSound->x(),ui->videoSound->y()-3,ui->videoSound->width(),ui->videoSound->height());
}

void MainWindow::on_videoSound_clicked()
{
    if(videoSoundFlag==0){//非静音
      ui->videoSound->setStyleSheet("QPushButton{border-image: url(:/sound.png);}");
       keybd_event(VK_VOLUME_MUTE,MapVirtualKey(VK_VOLUME_MUTE,0),KEYEVENTF_EXTENDEDKEY,0);
      keybd_event(VK_VOLUME_MUTE,MapVirtualKey(VK_VOLUME_MUTE,0),KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,0);
      videoSoundFlag=1;
    }
    else if(videoSoundFlag==1){//静音
      ui->videoSound->setStyleSheet("QPushButton{border-image: url(:/soundNo.png);}");
      keybd_event(VK_VOLUME_MUTE,MapVirtualKey(VK_VOLUME_MUTE,0),KEYEVENTF_EXTENDEDKEY,0);
      keybd_event(VK_VOLUME_MUTE,MapVirtualKey(VK_VOLUME_MUTE,0),KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,0);
      videoSoundFlag=0;
    }
}

void MainWindow::on_videoSlider_actionTriggered(int action)
{
//    qDebug()<<action;

//    AO_device->setVolume( qreal( (float)action/100 ) );

}

void MainWindow::on_videoSlider_sliderMoved(int position)
{
//     qDebug()<<position;
}

void MainWindow::on_videoSlider_rangeChanged(int min, int max)
{

}

void MainWindow::on_videoSlider_valueChanged(int value)
{
    changeValume(value);
}

void MainWindow::on_pushButton_3_clicked()
{
    tiN=40;
    setTiShu(tiN);
}
void MainWindow::setTiShu(int tiN){

    ui->examd->setCheckable(false);
    ui->examd->setVisible(false);

    QMovie*movie=new QMovie(":/shalou.gif");
    movie->scaledSize();
    ui->examshalou->setMovie(movie);
    movie->start();

    QMessageBox *tishi=new QMessageBox(this);

    tishi->setWindowTitle("提示");
    tishi->setText("测试题目将设置为"+QString::number(tiN)+"个！\n");
    tishi->exec();

    jiShi=0;
    ui->examjindu->setText("测试进度：1/"+QString::number(tiN));

    ui->examnext->setStyleSheet("QPushButton{border-image: url(:/next.png);}");

    duicnt=0;
    zuoticnt=1;

    initVis();

    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int xxx=qrand()%abcN;

    abcVis[xxx]=1;

    chuTiABC(xxx);
}

void MainWindow::on_pushButton_2_clicked()
{
    tiN=20;
    setTiShu(tiN);
}

void MainWindow::on_pushButton_5_clicked()
{
    tiN=80;
    setTiShu(tiN);
}

void MainWindow::on_pushButton_6_clicked()
{
    tiN=100;
    setTiShu(tiN);
}


void MainWindow::timerUpDate()
{
//    qDebug()<<"time";
   jiShi++;
//   qDebug()<<jiShi;
   if(ui->examwelcome->isHidden()==true)
       return;

   if(10-jiShi<0) return;

   ui->examJishi->setText(QString::number(10-jiShi)+"秒后将进入下一题");

   if(jiShi==10){
      ui->exame->setChecked(true);
      on_examnext_clicked();
      jiShi=0;
   }


}

void MainWindow::on_happyPlay_pressed()
{
    ui->happyPlay->setGeometry(ui->happyPlay->x(),ui->happyPlay->y()+3,ui->happyPlay->width(),ui->happyPlay->height());
}

void MainWindow::on_happyPlay_released()
{
    ui->happyPlay->setGeometry(ui->happyPlay->x(),ui->happyPlay->y()-3,ui->happyPlay->width(),ui->happyPlay->height());
}

void MainWindow::on_happySound_pressed()
{
    ui->happySound->setGeometry(ui->happySound->x(),ui->happySound->y()+3,ui->happySound->width(),ui->happySound->height());
}

void MainWindow::on_happySound_released()
{
    ui->happySound->setGeometry(ui->happySound->x(),ui->happySound->y()-3,ui->happySound->width(),ui->happySound->height());

}

void MainWindow::on_happyPlay_clicked()
{
    QPoint pc=cursor().pos();//获取当前鼠标位置

    QPoint p=happyIEwidget->pos();

    p=mapToGlobal(p);

    SetCursorPos(p.x()+3,p.y()+3);

    mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);

    keybd_event(40,MapVirtualKey(40,0),0,0);//键下down键。
    keybd_event(40,MapVirtualKey(40,0), KEYEVENTF_KEYUP,0);//放开down键。
    keybd_event(40,MapVirtualKey(40,0),0,0);//键下down键。
    keybd_event(40,MapVirtualKey(40,0), KEYEVENTF_KEYUP,0);//放开down键。
    keybd_event(40,MapVirtualKey(40,0),0,0);//键下down键。
    keybd_event(40,MapVirtualKey(40,0), KEYEVENTF_KEYUP,0);//放开down键。
    keybd_event(40,MapVirtualKey(40,0),0,0);//键下down键。
    keybd_event(40,MapVirtualKey(40,0), KEYEVENTF_KEYUP,0);//放开down键。
    keybd_event(40,MapVirtualKey(40,0),0,0);//键下down键。
    keybd_event(40,MapVirtualKey(40,0), KEYEVENTF_KEYUP,0);//放开down键。

    keybd_event(13,MapVirtualKey(13,0),0,0);//键下enter键。
    keybd_event(13,MapVirtualKey(13,0), KEYEVENTF_KEYUP,0);//放开enter键。

    SetCursorPos(pc.x(),pc.y());

    if(happyPlayFlag==0){//执行暂停功能，更换播放图片
      ui->happyPlay->setStyleSheet("QPushButton{border-image: url(:/play.png);}");
      happyPlayFlag=1;
    }
    else if(happyPlayFlag==1){
      ui->happyPlay->setStyleSheet("QPushButton{border-image: url(:/pause.png);}");
      happyPlayFlag=0;
    }
}

void MainWindow::on_happySound_clicked()
{
    if(videoSoundFlag==0){//非静音
      ui->happySound->setStyleSheet("QPushButton{border-image: url(:/sound.png);}");
      keybd_event(VK_VOLUME_MUTE,MapVirtualKey(VK_VOLUME_MUTE,0),KEYEVENTF_EXTENDEDKEY,0);
      keybd_event(VK_VOLUME_MUTE,MapVirtualKey(VK_VOLUME_MUTE,0),KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,0);
      videoSoundFlag=1;
    }
    else if(videoSoundFlag==1){//静音
      ui->happySound->setStyleSheet("QPushButton{border-image: url(:/soundNo.png);}");
      keybd_event(VK_VOLUME_MUTE,MapVirtualKey(VK_VOLUME_MUTE,0),KEYEVENTF_EXTENDEDKEY,0);
      keybd_event(VK_VOLUME_MUTE,MapVirtualKey(VK_VOLUME_MUTE,0),KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,0);
      videoSoundFlag=0;
    }
}

void MainWindow::on_happy_1_clicked()
{
    happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\1.swf");
    happyCnt=1;
}

void MainWindow::on_happy_2_clicked()
{
    happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\2.swf");
     happyCnt=2;
}

void MainWindow::on_happy_3_clicked()
{
    happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\3.swf");
     happyCnt=3;
}

void MainWindow::on_happy_4_clicked()
{
     happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\4.swf");
      happyCnt=4;
}

void MainWindow::on_happy_5_clicked()
{
     happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\5.swf");
      happyCnt=5;
}

void MainWindow::on_happy_6_clicked()
{
     happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\6.swf");
      happyCnt=6;
}

void MainWindow::on_happy_7_clicked()
{
     happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\7.swf");
      happyCnt=7;
}

void MainWindow::on_happy_8_clicked()
{
     happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\8.swf");
      happyCnt=8;
}

void MainWindow::on_happy_9_clicked()
{
     happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\9.swf");
      happyCnt=9;
}

void MainWindow::on_happy_10_clicked()
{
     happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\10.swf");
      happyCnt=10;
}

void MainWindow::on_happy_11_clicked()
{
     happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\11.swf");
      happyCnt=11;
}

void MainWindow::on_happy_12_clicked()
{
     happyIEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\happy\\12.swf");
      happyCnt=12;
}

void MainWindow::on_videoPlay_clicked()
{
    QPoint pc=cursor().pos();//获取当前鼠标位置

    QPoint p=IEwidget->pos();

    p=mapToGlobal(p);

    SetCursorPos(p.x()+3,p.y()+3);

    mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);

    keybd_event(40,MapVirtualKey(40,0),0,0);//键下down键。
    keybd_event(40,MapVirtualKey(40,0), KEYEVENTF_KEYUP,0);//放开down键。
    keybd_event(40,MapVirtualKey(40,0),0,0);//键下down键。
    keybd_event(40,MapVirtualKey(40,0), KEYEVENTF_KEYUP,0);//放开down键。
    keybd_event(40,MapVirtualKey(40,0),0,0);//键下down键。
    keybd_event(40,MapVirtualKey(40,0), KEYEVENTF_KEYUP,0);//放开down键。
    keybd_event(40,MapVirtualKey(40,0),0,0);//键下down键。
    keybd_event(40,MapVirtualKey(40,0), KEYEVENTF_KEYUP,0);//放开down键。
    keybd_event(40,MapVirtualKey(40,0),0,0);//键下down键。
    keybd_event(40,MapVirtualKey(40,0), KEYEVENTF_KEYUP,0);//放开down键。

    keybd_event(13,MapVirtualKey(13,0),0,0);//键下enter键。
    keybd_event(13,MapVirtualKey(13,0), KEYEVENTF_KEYUP,0);//放开enter键。

    SetCursorPos(pc.x(),pc.y());

    if(videoPlayFlag==0){//执行暂停功能，更换播放图片
      ui->videoPlay->setStyleSheet("QPushButton{border-image: url(:/play.png);}");
      videoPlayFlag=1;
    }

    else if(videoPlayFlag==1){
      ui->videoPlay->setStyleSheet("QPushButton{border-image: url(:/pause.png);}");
      videoPlayFlag=0;
    }

}

void MainWindow::on_videoNext_clicked()
{
    videoPlayFlag=0;
    ui->videoPlay->setStyleSheet("QPushButton{border-image: url(:/pause.png);}");
    if(videoMoshi=="yongdian"){
        videoCnt++;
        if(videoCnt>yongdianN) videoCnt=1;
        ui->videoyongdian->setCurrentIndex(videoCnt);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\yongdian\\yongdian("+QString::number(videoCnt)+").swf");
    }
    else if(videoMoshi=="liangxue"){
        videoCnt++;
        if(videoCnt>liangxueN) videoCnt=1;
         ui->videoliangxue->setCurrentIndex(videoCnt);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\liangxue\\liangxue("+QString::number(videoCnt)+").swf");
    }
    else if(videoMoshi=="shicha"){
        videoCnt++;
        if(videoCnt>shichaN) videoCnt=1;
         ui->videoshicha->setCurrentIndex(videoCnt);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\shichajundui\\("+QString::number(videoCnt)+").swf");
    }
    else if(videoMoshi=="news"){
        videoCnt++;
        if(videoCnt>newsN) videoCnt=1;
         ui->videonews->setCurrentIndex(videoCnt);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\news\\("+QString::number(videoCnt)+").swf");
    }

}

void MainWindow::on_videoLast_clicked()
{
    videoPlayFlag=0;
    ui->videoPlay->setStyleSheet("QPushButton{border-image: url(:/pause.png);}");
    if(videoMoshi=="yongdian"){
        videoCnt--;
        if(videoCnt<=0) videoCnt=yongdianN;
         ui->videoyongdian->setCurrentIndex(videoCnt);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\yongdian\\yongdian("+QString::number(videoCnt)+").swf");
    }
    else if(videoMoshi=="liangxue"){
        videoCnt--;
        if(videoCnt<=0) videoCnt=liangxueN;
         ui->videoliangxue->setCurrentIndex(videoCnt);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\liangxue\\liangxue("+QString::number(videoCnt)+").swf");
    }
    else if(videoMoshi=="shicha"){
        videoCnt--;
        if(videoCnt<=0) videoCnt=shichaN;
         ui->videoshicha->setCurrentIndex(videoCnt);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\shichajundui\\("+QString::number(videoCnt)+").swf");
    }
    else if(videoMoshi=="news"){
        videoCnt--;
        if(videoCnt<=0) videoCnt=newsN;
         ui->videonews->setCurrentIndex(videoCnt);
        IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\news\\("+QString::number(videoCnt)+").swf");
    }

}

void MainWindow::on_happySlider_valueChanged(int value)
{  
    changeValume(value);
}

void  MainWindow::setAdjustSize(){

    ui->shouye->adjustSize();
    ui->xilie->adjustSize();
    ui->video->adjustSize();
    ui->genzhe->adjustSize();
    ui->exam->adjustSize();
    ui->rank->adjustSize();
    ui->happy->adjustSize();
    ui->bbs->adjustSize();
    ui->exit->adjustSize();

    ui->speechFind1Label->adjustSize();
    ui->speechFind2Label->adjustSize();
    ui->speechPrintLabel->adjustSize();

//    ui->video->adjustSize();
//    ui->video->adjustSize();
//    ui->video->adjustSize();
//    ui->video->adjustSize();
//    ui->video->adjustSize();
//    ui->video->adjustSize();
//    ui->video->adjustSize();
//    ui->video->adjustSize();

}

void MainWindow::changeValume(int value){

    if(bugValume==0){
        bugValume=1;
        return;
        }

    qDebug()<<"what?";
    curValue=value;
    if(curValue>lastValue){ //加音
        qDebug()<<lastValue<<curValue;
        for(int i=lastValue/2;i<=curValue/2;i++){
            keybd_event(VK_VOLUME_UP,MapVirtualKey(VK_VOLUME_UP,0),KEYEVENTF_EXTENDEDKEY,0);
            keybd_event(VK_VOLUME_UP,MapVirtualKey(VK_VOLUME_UP,0),KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,0);

        }
        lastValue=curValue;
    }
    else if(curValue<lastValue){//减音
        qDebug()<<lastValue<<curValue;
        for(int i=curValue/2;i<=lastValue/2;i++){
            keybd_event(VK_VOLUME_DOWN,MapVirtualKey(VK_VOLUME_DOWN,0),KEYEVENTF_EXTENDEDKEY,0);
            keybd_event(VK_VOLUME_DOWN,MapVirtualKey(VK_VOLUME_DOWN,0),KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,0);

        }
        lastValue=curValue;
    }
}
