#include "view.h"
#include <QDebug>

View::View(QObject *parent):QObject(parent)
{
}

void View::setName(const QString name)
{
    this->name = name;
}

QQuickView *View::view(const QString &objectName)
{
    QQuickView *view = NULL;

    if(objectName.isEmpty())            // 1 名字为空
    {
        Q_ASSERT(!views.isEmpty());    // 2 界面管理器为空
        view = views.first();
        return view;
    }
    else{
        if(!views.contains(objectName))   // 3 不包含这个名字
        {
            view = new QQuickView;
            views[objectName] = view;
            return view;
        }
    }
    view = views.value(objectName);
    if(view == NULL)
    {
        view = new QQuickView;
        views[objectName] = view;
    }
    return view;
}

ViewContext* View::context(const QString &viewName)
{
    ViewContext *context = NULL;
    if(viewName.isEmpty())              // 1 名字为空
    {
        context = contexts.first();
        return context;
    }
    context = contexts.value(viewName,NULL);    // 2 上下文为空
    if(context == NULL)
    {
          context = new ViewContext;
          contexts[viewName] = context;
    }
//    context->setFieldValue();
    return context;


}

bool View::initViews(QString iniFile)
{
     int viewCount = settingValue("count","views",0,iniFile).toInt();
     for(int i = 0;i< viewCount; i++)
     {
         QString group = QString("view.%1").arg(i);
         QString name = settingValue("name",group,"",iniFile).toString();
         QString source = settingValue("source",group,"",iniFile).toString();

         int left = settingValue("left",group,0,iniFile).toInt();
         int top = settingValue("top",group,0,iniFile).toInt();
         int width = settingValue("width",group,0,iniFile).toInt();
         int height = settingValue("height",group,0,iniFile).toInt();

         if(name.isEmpty() || source.isEmpty())
             return false;
         QQuickView *v = view(name);
         ViewContext *c = context(name);

         Q_ASSERT(v != NULL);
         Q_ASSERT(c != NULL);

         connect(c,SIGNAL(viewInvoke(QString,QVariant,QVariant&)),
                 SLOT(onViewInvoke(QString,QVariant,QVariant&)));

        // SizeViewToRootObject 视图将根据QML中的根项调整大小。
        // SizeRootObjectToView 视图将根据视图的大小自动调整根项的大小。
        v->setResizeMode(QQuickView::SizeRootObjectToView);

        v->rootContext()->setContextProperty(name+"Context",c);  // 设置上下文属性
        v->setSource(QUrl::fromLocalFile(source));
        v->setObjectName(name);
        v->setFlags(Qt::FramelessWindowHint);

        v->setGeometry(left,top,width,height);


     }
     return true;
}

QVariant View::settingValue(const QString &name,
                            const QString &group,
                            const QString &defaultValue,
                            const QString &fileName)
{
    QSettings settings(fileName,QSettings::IniFormat);
    settings.beginGroup(group);
    settings.setIniCodec(QTextCodec::codecForName("UTF-8"));
    QVariant value = settings.value(name,defaultValue);
    settings.endGroup();
    return value;
}

QList<QString> View::names()
{
    return views.keys();
}


View::~View()
{

}

void View::onViewInvoke(const QString &method,
                        const QVariant &paramters,
                         QVariant &result)
{
    Q_UNUSED(method);
    Q_UNUSED(paramters);
    Q_UNUSED(result);
    QVariantMap values = paramters.toMap();
    QVariantMap op;
    op["name"] = this->name;            // 界面管理器的名字
    op["conmand"] = method;
    op["paramters"] = values;

    emit this->updateCommand(op,result);

}


