import QtQuick 2.15

CutCornersRectangle {
    property color borderColor: "black"
    property color color: "white"
    fillColor: borderColor

    CutCornersRectangle {
        anchors.centerIn: parent
        fillColor: parent.color
        width: parent.width - 8
        height: parent.height - 8
    }
}
