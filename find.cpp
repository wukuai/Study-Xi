#include "find.h"
#include "ui_find.h"

Find::Find(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Find)
{
    ui->setupUi(this);

    for(int i=1;i<=16;i++){
        findExis[i]=false;
    }

    setWindowTitle("查找全部讲话内容");
    setButton();

   setWindowFlags(Qt::WindowStaysOnTopHint); //窗口置顶

   setWindowModality(Qt::ApplicationModal); //禁用其它窗口

   setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);//去掉最小化窗口

//    setWindowFlags(Qt::FramelessWindowHint |Qt::WindowStaysOnTopHint);

}

Find::~Find()
{
    delete ui;
}

void Find::on_find_clicked()
{
    for(int i=1;i<=16;i++){
        findExis[i]=false;
    }
    findText=ui->lineEdit->text();
    for(int i=1;i<=16;i++){
        QFile file("./html/find/"+QString::number(i)+".txt");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
             qDebug()<<"Can't open the file!"<<endl;
        }
        QTextStream in(&file);
        QString line="";
        while (!in.atEnd()){
        line=in.readLine();
        if(line.indexOf(findText)==-1){
            }
        else{
            qDebug()<<"have"<<i;
            findExis[i]=true;
            break;
            }
        }
    }
    setButton();
}

void Find::setButton(){

   ui->pushButton->setDisabled(!findExis[1]);
   ui->pushButton_2->setDisabled(!findExis[2]);
   ui->pushButton_3->setDisabled(!findExis[3]);
   ui->pushButton_4->setDisabled(!findExis[4]);
   ui->pushButton_5->setDisabled(!findExis[5]);
   ui->pushButton_6->setDisabled(!findExis[6]);
   ui->pushButton_7->setDisabled(!findExis[7]);
   ui->pushButton_8->setDisabled(!findExis[8]);
   ui->pushButton_9->setDisabled(!findExis[9]);
   ui->pushButton_10->setDisabled(!findExis[10]);
   ui->pushButton_11->setDisabled(!findExis[11]);
   ui->pushButton_12->setDisabled(!findExis[12]);
   ui->pushButton_13->setDisabled(!findExis[13]);
   ui->pushButton_14->setDisabled(!findExis[14]);
   ui->pushButton_15->setDisabled(!findExis[15]);
   ui->pushButton_16->setDisabled(!findExis[16]);
}


void Find::on_pushButton_clicked()
{
    clickButton(1);

     ctrlV();

}
void Find::ctrlV(){
        QClipboard *clipboard;
        clipboard->setText(ui->lineEdit->text());

        QPoint pc=cursor().pos();//获取当前鼠标位置

        SetCursorPos(X,Y);
        mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
        mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
        SetCursorPos(pc.x(),pc.y());


        sleep(1);

        keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),0,0); //按下CTRL键。
        keybd_event(0x46,MapVirtualKey(0x46,0),0,0);//键下F键。
        keybd_event(0x46,MapVirtualKey(0x46,0), KEYEVENTF_KEYUP,0);//放开F键。
        keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),KEYEVENTF_KEYUP,0);//放开CTRL键

       sleep(1);

        keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),0,0); //按下CTRL键。
        keybd_event(86,MapVirtualKey(86,0),0,0);//键下V键。
        keybd_event(86,MapVirtualKey(86,0), KEYEVENTF_KEYUP,0);//放开V键。
        keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),KEYEVENTF_KEYUP,0);//放开CTRL键

//        SetCursorPos(pc.x(),pc.y());

}

void Find::on_pushButton_2_clicked()
{
    clickButton(2);
    ctrlV();
}

void Find::on_pushButton_3_clicked()
{
      clickButton(3);
    ctrlV();
}

void Find::on_pushButton_4_clicked()
{
      clickButton(4);
    ctrlV();
}

void Find::on_pushButton_5_clicked()
{
    clickButton(5);
    ctrlV();
}

void Find::on_pushButton_6_clicked()
{
      clickButton(6);
    ctrlV();
}

void Find::on_pushButton_7_clicked()
{
      clickButton(7);
    ctrlV();
}

void Find::on_pushButton_8_clicked()
{
      clickButton(8);
    ctrlV();
}

void Find::on_pushButton_9_clicked()
{
      clickButton(9);
    ctrlV();
}

void Find::on_pushButton_10_clicked()
{
      clickButton(10);
    ctrlV();
}

void Find::on_pushButton_11_clicked()
{
     clickButton(11);
    ctrlV();
}

void Find::on_pushButton_12_clicked()
{
     clickButton(12);
    ctrlV();
}

void Find::on_pushButton_13_clicked()
{
     clickButton(13);
    ctrlV();
}

void Find::on_pushButton_14_clicked()
{
     clickButton(14);
    ctrlV();
}

void Find::on_pushButton_15_clicked()
{
     clickButton(15);
    ctrlV();
}

void Find::on_pushButton_16_clicked()
{
     clickButton(16);
    ctrlV();
}

void Find::clickButton(int b){

     close();

    QPoint pc=cursor().pos();//获取当前鼠标位置
    SetCursorPos(xbutton[b],ybutton[b]);
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
    SetCursorPos(pc.x(),pc.y());
}


void Find::sleep(unsigned int msec){
    QTime reachTime =QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}
