import QtQuick 2.9
import Charts 1.0

Rectangle{
    id:chartholder
    anchors.fill: parent
    color:"beige"

    Linechart{
    id: chrt_Linechart
    anchors.centerIn: parent
    width:parent.width*0.5
    height:parent.height*0.5
    clip: false
    }

}
