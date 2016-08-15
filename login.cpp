#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "QMessageBox"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{


    ui->setupUi(this);
     execflag=0;

    setWindowTitle("习主席系列重要讲话精神学习系统V2.0");


//       ui->mima->setEchoMode(QLineEdit::Password);
    ui->linepassword->setEchoMode(QLineEdit::Password);

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
//    MainWindow tempw;

    if(ui->lineid->text()==""||ui->linepassword->text()==""){
        QMessageBox *tishi=new QMessageBox(this);
        tishi->setWindowTitle("提示");
        tishi->setText("请输入账户信息 ！");
        tishi->exec();
        return;
    }


    QMap<QString,QString>name;

    QMap<QString,QString>password;

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

    id=ui->lineid->text();
    passwords=ui->linepassword->text();
    if(passwords!=password[id]){
        QMessageBox *tishi=new QMessageBox(this);
        tishi->setWindowTitle("提示");
        tishi->setText("密码或账户名错误 ！");
        tishi->exec();
    }
    else if(passwords==password[id]){
        QMessageBox *tishi=new QMessageBox(this);
        tishi->setWindowTitle("提示");
        tishi->setText("欢迎 "+name[id]+" 的到来");
        tishi->show();
        sleep(1000);
        tishi->close();
        execflag=1;
    }


}

void Login::sleep(unsigned int msec){
    QTime reachTime =QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

void Login::on_pushButton_3_clicked()
{
    execflag=2;
}
