#include <QObject>
#include <QVariantMap>

#ifndef VIEWCONTEXT_H
#define VIEWCONTEXT_H

/*
 上下文管理器类
  (1) Q_PROPERTY()是一个宏，用来在一个类中声明一个属性property.
 （2）拥有一个私有属性，map。
  (3)  宏定义属性：  提供读写和改变信号。
*/
class ViewContext : public QObject
{
    Q_OBJECT

public:
    explicit ViewContext(QObject *parent = 0);          // 1
    //    Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QVariantMap fields READ fields WRITE setFields NOTIFY fieldsChanged)     //2
    QVariantMap &fields();                                                              //3 返回一个map
    void setFields(const QVariantMap &fields);                                           // 4 设置上下文

    Q_INVOKABLE QVariant fieldValue(const QString &name);                               // 5 读取字段的值
    Q_INVOKABLE void setFieldValue(const QString &name,const QVariant &value);              // 6 添加字段的值

    Q_INVOKABLE QVariant invoke(const QString &method, const QVariant &paramters);      //7 援用,提供给qml调用
    Q_INVOKABLE QString byteToString(const QVariant &b);                                // 8 字节转化为字符串
    Q_INVOKABLE QString timeFormatYYYY_MM_DD(const QString &str);                       // 9 时间格式转化
    Q_INVOKABLE QString timeFormatMM_DD_hh_mm(const QString &str);                      // 10 时间格式转化

    ~ViewContext();

signals:
    void fieldsChanged();                                                               // 11 c++中改变字段会发送此信号
    void viewInvoke(const QString &method,const QVariant &parameters,QVariant &result);  // 12 qml发送消息

private:
    QVariantMap selfFields;         // 私有属性，是一个字典。
};

#endif // VIEWCONTEXT_H
