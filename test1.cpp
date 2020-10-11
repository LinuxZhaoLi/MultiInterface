#include "test1.h"

test1::test1(QObject *parent):QObject(parent)
{
initView();
}

test1::~test1()
{

}

bool test1::start()
{
    if(!view.initViews("./test.ini"))
    {
        qDebug()<<"读取test.ini 失败";
        return false;

    }

    QList<QString> viewNames = view.names();
        for(int i = 0; i< viewNames.length();i++)
        {
                QString name = viewNames[i];
                view.view(name) -> setVisible(true);
                qDebug()<< name;

        }
        return true;
}

void test1::initView()
{
    this->view.context("qml_1")-> setFieldValue("resImage",m_res.Images());
    this->view.context("qml_1")-> setFieldValue("imageIndex",0);

    this->view.context("qml_2")-> setFieldValue("resImage",m_res.Images());
    this->view.context("qml_2")-> setFieldValue("imageIndex",0);
    this->view.context("qml_3")-> setFieldValue("resImage",m_res.Images());
    this->view.context("qml_3")-> setFieldValue("imageIndex",0);

    this->view.context("qml_4")-> setFieldValue("resImage",m_res.Images());
    this->view.context("qml_4")-> setFieldValue("imageIndex",0);

    this->view.context("qml_5")-> setFieldValue("resImage",m_res.Images());
    this->view.context("qml_5")-> setFieldValue("imageIndex",0);

    this->view.context("qml_6")-> setFieldValue("resImage",m_res.Images());
    this->view.context("qml_6")-> setFieldValue("imageIndex",0);
}
