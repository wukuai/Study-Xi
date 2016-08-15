#include "mainwindow.h"
#include "kaitou.h"
#include "login.h"
#include <QApplication>
#include <QTime>
#include <QCoreApplication>
#include <QFontDatabase>
#include <QDebug>

void sleep(unsigned int msec){
    QTime reachTime =QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    Kaitou k;

    k.show();

    for (int i=1;i<=69;i++){
        sleep(250);
        if(k.tuichuFlag==1)
            break;
    }

    k.close();

    k.tuichu();



    Login login;
    login.show();
    sleep(1000);

    while(login.execflag==0){
        sleep(500);
        if(login.execflag==2)
             break;
    }
    login.close();
    if(login.execflag==1){
      w.show();
      w.id=login.id;
    }

    else if(login.execflag==2){
        w.close();
    }

    return a.exec();
}



