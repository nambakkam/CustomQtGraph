import QtQuick 2.9
import Charts 1.0

Rectangle{
    id:chartholder
    anchors.fill: parent
    color:"beige"

    Linechart{
    id: customLineChart
    anchors.centerIn: parent
    width:parent.width*0.5
    height:parent.height*0.5
    clip: false
    }
    Axes{
        id:xScale
        horizontal: true
        scaleheight: customLineChart.gridHeight
        scaleWidth: customLineChart.gridWidth*0.1
        ticksNumber: 21
//        width: customLineChart.width
        height: scaleheight
        anchors.top: customLineChart.bottom
        anchors.left: customLineChart.left
        anchors.leftMargin: -0.5*scaleWidth
        columnSpacing: (customLineChart.gridWidth-scaleWidth)
        rowSpacing: 0
    }
    Axes{
        id:yScale
        horizontal: false
        scaleheight: customLineChart.gridHeight*0.1
        scaleWidth: customLineChart.gridWidth*0.5
        ticksNumber: 20
        anchors.right: customLineChart.left
        anchors.top: customLineChart.top
        anchors.topMargin: -0.5*scaleheight
        width: scaleWidth
        rowSpacing: (customLineChart.gridHeight-1*scaleheight)
        columnSpacing: 0
    }

}
