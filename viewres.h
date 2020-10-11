#ifndef VIEWRES_H
#define VIEWRES_H
#include <QVariantMap>
#include <QObject>

class ViewRes : public QObject
{
    Q_OBJECT
public:
   explicit ViewRes(QObject *parent = 0);
    QVariantMap Images();
    ~ViewRes();

};

#endif // VIEWRES_H
