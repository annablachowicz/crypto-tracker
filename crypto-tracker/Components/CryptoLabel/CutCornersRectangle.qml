import QtQuick 2.15

Item {
    property double heightUnit: height/3
    property double widthUnit: width/7
    property color fillColor

    Rectangle {
        id: leftSmallRect
        anchors.top: parent.top
        anchors.left: parent.left
        height: heightUnit * 2
        width: widthUnit
        color: parent.fillColor
    }
    Rectangle {
        id: bigRect
        anchors.top: parent.top
        anchors.left: leftSmallRect.right
        height: parent.height
        width: widthUnit * 5
        color: parent.fillColor
    }
    Rectangle {
        id: smallRightRect
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        height: heightUnit * 2
        width: widthUnit
        color: parent.fillColor
    }
    Rectangle {
        id: square1
        anchors.top: leftSmallRect.bottom
        anchors.left: parent.left
        height: Math.sqrt(Math.pow(heightUnit,2) + Math.pow(widthUnit, 2))
        width: height
        transformOrigin: Item.TopLeft
        rotation: -45
        color: parent.fillColor
    }
    Rectangle {
        id: square2
        anchors.bottom: smallRightRect.top
        anchors.right: parent.right
        height: Math.sqrt(Math.pow(heightUnit,2) + Math.pow(widthUnit, 2))
        width: height
        transformOrigin: Item.BottomRight
        rotation: -45
        color: parent.fillColor
    }
}
