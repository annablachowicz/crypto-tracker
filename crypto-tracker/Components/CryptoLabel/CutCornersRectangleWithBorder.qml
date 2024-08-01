import QtQuick 2.15
import CustomColors 1.0

CutCornersRectangle {
    property color borderColor: Colors.mediumBackground
    property color color: Colors.lightBackground
    fillColor: borderColor

    CutCornersRectangle {
        anchors.centerIn: parent
        fillColor: parent.color
        width: parent.width - 8
        height: parent.height - 8
    }
}
