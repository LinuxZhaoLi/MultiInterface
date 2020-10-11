#include "viewcontext.h"
#include <QDebug>

ViewContext::ViewContext(QObject *parent):QObject(parent)
{

}

QVariantMap &ViewContext::fields()
{
    return selfFields;
}

void ViewContext::setFields(const QVariantMap &fields)
{
    if(fields == selfFields)
        return ;
    selfFields = fields;
    emit fieldsChanged();
}

QVariant ViewContext::fieldValue(const QString &name)           // 获取字段的值
{
    return selfFields.value(name);
}

void ViewContext::setFieldValue(const QString &name, const QVariant &value)
{
    if(selfFields.value(name) == value)
    {
        return;
    }
    selfFields[name] = value;
    emit fieldsChanged();

}

QVariant ViewContext::invoke(const QString &method, const QVariant &paramters)
{
    QVariant result;
    emit viewInvoke(method,paramters,result);
    return result;
}

QString ViewContext::byteToString(const QVariant &b)
{
    QByteArray array = b.toByteArray();
    return QString(array.toHex()).toUpper();
}

QString ViewContext::timeFormatYYYY_MM_DD(const QString &str)
{
    return str;
}

QString ViewContext::timeFormatMM_DD_hh_mm(const QString &str)
{
    return str;
}

ViewContext::~ViewContext()
{

}









