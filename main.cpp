#include <QGuiApplication>
#include <QDebug>
#include <test1.h>

int main(int argc,char* argv[])
{
    QGuiApplication a(argc,argv);

//    QVariantMap bb;
//    QVariantMap cc;
//    bb["aa"] = 11;
//    cc["aa"] = 11;
//    if(bb == cc)
//    {
//        qDebug()<<"bb = cc";

//    }

    test1 test;
    test.start();


    int ret = a.exec();
    return ret;
}

//  接下来创建一个类
