import QtQuick 2.9
import Charts 1.0

Rectangle{
    id:chartholder
    anchors.fill: parent
    color:"beige"

    AreaChart{
    id: chrt_areachart
    anchors.centerIn: parent
    width:parent.width*0.5
    height:parent.height*0.5
    Component.onCompleted: {
        chrt_areachart.set_graphHeight(height)
        chrt_areachart.set_graphWidth(width)
        chrt_areachart.update()

    }

    onWidthChanged: {
        chrt_areachart.set_graphHeight(height)
        chrt_areachart.set_graphWidth(width)
        chrt_areachart.update()
    }
    onHeightChanged: {
        chrt_areachart.set_graphHeight(height)
        chrt_areachart.set_graphWidth(width)
        chrt_areachart.update()
    }

    }

}
