#include "kaitou.h"
#include "ui_kaitou.h"


Kaitou::Kaitou(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kaitou)
{
    ui->setupUi(this);

    setWindowTitle("习主席系列重要讲话精神学习系统 V2.0");

    QAxWidget *temp=new QAxWidget(this);
    IEwidget= temp;
    IEwidget->setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}")); //设定控制器(flash)
    IEwidget->setGeometry(ui->label->x(),ui->label->y(),ui->label->width(),ui->label->height());
    ui->label->setVisible(false);
    IEwidget->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath()+"\\swf\\bwcx.swf");

    IEwidget->setFocusPolicy(Qt::NoFocus);
    ui->label->setFocusPolicy(Qt::NoFocus);

    tuichuFlag=0;

    setWindowFlags(Qt::FramelessWindowHint);
}


Kaitou::~Kaitou()
{
    delete ui;
}

void Kaitou::sleep(unsigned int msec){
    QTime reachTime =QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

void Kaitou::tuichu(){
    delete IEwidget;
}

void Kaitou::keyPressEvent(QKeyEvent  *event)
{
    qDebug()<<"kkkk";
     if(event->key()==Qt::Key_Escape)
    {
        tuichuFlag=1;
        qDebug()<<"qqqqq";
    }
}


void Kaitou::mousePressEvent(QMouseEvent *e){
    ui->centralwidget->setFocus();
    qDebug()<<"press";
}
