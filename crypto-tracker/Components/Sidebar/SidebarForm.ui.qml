import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import CustomColors 1.0

Rectangle {
    property alias sortControl: sortControl
    property alias networkErrorLabel: networkErrorLabel

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

        Label {
            id: networkErrorLabel
            Layout.leftMargin: 20
        }
    }
}
