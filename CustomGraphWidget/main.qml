import QtQuick 2.9
import QtQuick.Window 2.2
import Charts 1.0
import QtQuick.Controls 2.0

ApplicationWindow {
    visible: true
    width: 800
    height: 480
    title: qsTr("Charts")
    color: "white"

    CustomGraph{
        id:graph
        anchors.centerIn: parent
    }

}
