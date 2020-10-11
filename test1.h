#include <QObject>
#include <view.h>
#include <viewres.h>
#ifndef TEST1_H
#define TEST1_H


class test1: public QObject
{
    Q_OBJECT

public:
    explicit test1(QObject *parent =0 );
    ~test1();
    bool start();
    void stop();
    void initView(); // 初始化界面


private:
    View view;
    ViewRes m_res;
    typedef bool (test1::*func)(const QVariantMap &op);

    QMap<QString,test1::func> viewCommands;



};

#endif // TEST1_H
