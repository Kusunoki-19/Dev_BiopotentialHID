import QtQuick 2.12
import QtQuick.Controls 2.0
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12

import SerialComponents 1.0

Window {
    width: 640
    height: 480
    visible: true
    Connections {
        target: GraphData
        function onPlotPathDotsChanged() {
            graphCanvas.requestPaint()
        }
    }
    RowLayout {
        anchors.fill:parent
        // GraphArea.
        Item {
            Layout.fillWidth:true
            Layout.fillHeight:true
            Canvas {
                id:graphCanvas
                onPaint: {
                    var plotData = GraphData.plotPathDots()
                    var ctx = getContext('2d')
                    ctx.beginPaht()
                    ctx.moveTo(plotData[0].x ,plotData[0].y)
                    for(var i = 1; i < plotData.length(); i++) {
                        ctx.lineTo(plotData[i].x, plotData[i].y)
                    }
                    ctx.stroke()
                }

            }
        }
        Item {
            // UtilityArea.
            Layout.fillWidth:true
            Layout.fillHeight:true
            ColumnLayout {
                anchors.fill:parent
                Item {
                    Layout.fillWidth:true
                    Layout.fillHeight:true
                    Button {
                        text:"readStart"
                        onClicked: {
                            GraphData.readStart()
                        }
                    }
                }
                Item {
                    Layout.fillWidth:true
                    Layout.fillHeight:true
                    Button {
                        text:"readStop"
                        onClicked: {
                            GraphData.readStop()
                        }
                    }
                }
            }
        }
    }


}
