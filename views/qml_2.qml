import QtQuick 2.0
import QtQuick.Controls 1.1

Rectangle{
    id:uio

    property variant context: qml_2Context
    property variant fields: qml_2Context.fileds


    property QtObject srcDict: QtObject{
        id: srcDict

    }

    Image {
        id: animation;
        source:"../Image/tree.jpg"
        fillMode: Image.Stretch
        anchors.fill: parent
    }
    Label {

        width: parent.width * 0.3
        height: parent.height * 0.3
        id: time1ab
        color: "black"
        anchors.top:parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 16
        font.family: "微软雅黑"
        font.letterSpacing:1
        font.bold: true
    }

    Timer {
        id:timer
        interval: 1000; running: true; repeat: true
        onTriggered: time1ab.text = Qt.formatDateTime(new Date(), "yyyy-MM-dd hh:mm:ss") // 星期 www.it165.net 年份 月份 号 大月份
    }

}
