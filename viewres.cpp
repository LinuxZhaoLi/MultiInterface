#include "viewres.h"



ViewRes::ViewRes(QObject *parent):QObject(parent)
{

}

//QMap<int,QString> ViewRes::Images()
//{
//    QMap<int, QString> imageMap;
//    imageMap[1] = "./Images/sno.gif";
//}

QVariantMap ViewRes::Images()
{
    QVariantMap imageMap;
    imageMap["1"] = "./Images/sno.gif";
    return imageMap;
}

ViewRes::~ViewRes()
{

}
