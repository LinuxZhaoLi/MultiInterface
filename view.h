#include <QObject>
#include <QtQuick>
#include <viewcontext.h>
#include <QSettings>
#include <QTextCodec>       // QTextCodec类提供文本编码之间的转换

#ifndef VIEW_H
#define VIEW_H

/*
 界面类
 方法：
    1 设置名字
 属性：
    1 QQuickView类提供了一个显示Qt快速用户界面的窗口。对象
    2
 */
class View : public QObject
{
    Q_OBJECT
public:

    explicit View(QObject *parent = 0);                             // 1 构造函数
    void setName(const QString name);                               // 2 设置名字
    QQuickView* view(const QString &objectName = QString());        // 3 返回一个界面对象
    ViewContext* context(const QString &viewName);                   // 4 返回一个上下文对象
    bool initViews(QString iniFile);                                // 5 初始化界面
    QVariant settingValue(                                          // 6 读取配置文件
            const QString &name,
            const QString &group,
            const QString &defaultValue,
            const QString &fileName);
    QList<QString> names();                                          // 7 返回界面对象的名字

    ~View();
public:

public slots:
    void onViewInvoke(const QString &method,                        // 8 中转qml信息
                      const QVariant &paramters,
                       QVariant &result);
signals:
    void updateCommand(QVariantMap& v, QVariant &result);

private:
    QString name;
    ViewContext viewContext;
    QMap<QString,QQuickView*> views;                             // 界面管理器
    QMap<QString,ViewContext*> contexts;                         // 上下文管理器

};

#endif // VIEW_H
