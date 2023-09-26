import QtQuick 2.9
import QtQuick.Window 2.2
import Charts 1.0

Window {
    visible: true
    width: 800
    height: 480
    title: qsTr("Charts")
    color: "black"

    AreaChart{
        id: chrt_areachart
        x:200
        y:140
        width: 220
        height: 230
    }
}
