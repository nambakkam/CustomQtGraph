import QtQuick 2.9
import QtQuick.Layouts 1.2
GridLayout {
    id:scaleLayout
    property bool horizontal: true
    property real scaleheight: scaleLayout.width*0.05
    property real scaleWidth: scaleLayout.width*0.005
    property int ticksNumber: 21
    flow:horizontal?GridLayout.LeftToRight:GridLayout.TopToBottom
//    property type name: value

//    width: customLineChart.width
//    height: customLineChart.height*0.1
//    anchors.top: customLineChart.bottom
//    anchors.left: customLineChart.left
//    anchors.leftMargin: -0.5*customLineChart.width*0.005

//    spacing: ((customLineChart.width)/20-customLineChart.width*0.005)
    Repeater {
        model: ticksNumber // Change this number to determine the number of ticks
       Rectangle {
            id:scaleXRect
            implicitWidth: scaleWidth
            implicitHeight:  scaleheight
            color: "black"
            Text{
                id:scaleXTicks
                text:horizontal? index : ticksNumber-index-1
                anchors.top: scaleLayout.horizontal ? parent.bottom :undefined
                anchors.right: scaleLayout.horizontal ? undefined:parent.left
                anchors.rightMargin: scaleLayout.horizontal ? 0:0.5*scaleWidth
                anchors.horizontalCenter: scaleLayout.horizontal ?  parent.horizontalCenter:undefined
                anchors.verticalCenter: scaleLayout.horizontal? undefined:parent.verticalCenter
                font {
                    family:"ROBOTO"
                    styleName: "Medium"
                    pixelSize: horizontal? scaleheight:scaleWidth
                }
            }
        }
    }
}
