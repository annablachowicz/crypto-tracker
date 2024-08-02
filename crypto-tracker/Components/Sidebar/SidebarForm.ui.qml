import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import CustomColors 1.0

Rectangle {
    property alias sortControl: sortControl
    property alias networkErrorLabel: networkErrorLabel
    property alias staleDataIndicator: staleDataIndicator

    color: Colors.lightBackground
    width: 200

    ColumnLayout {
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width
        height: 400

        SortControl {
            id: sortControl
        }

        StaleDataIndicator {
            id: staleDataIndicator
            Layout.fillWidth: true
            Layout.leftMargin: 20
        }

        Label {
            id: networkErrorLabel
            Layout.fillWidth: true
            Layout.leftMargin: 20
            Layout.rightMargin: 20
            wrapMode: Text.WordWrap
        }
    }
}
