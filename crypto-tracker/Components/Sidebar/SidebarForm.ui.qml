import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import CustomColors 1.0

Rectangle {
    property alias sortControl: sortControl
    property alias networkErrorLabel: networkErrorLabel
    property alias staleDataIndicator: staleDataIndicator
    property alias loadingImage: loadingImage
    property alias randomChangesButton: randomChangesButton

    color: Colors.lightBackground
    width: 200

    ColumnLayout {
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width
        height: 400
        spacing: 20

        SortControl {
            id: sortControl
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 2
            color: Colors.mediumBackground
        }

        Switch {
            id: randomChangesButton
            Layout.fillWidth: true
            Layout.preferredHeight: 40

            text: qsTr("Random changes");
            palette.windowText: Colors.shadow
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 2
            color: Colors.mediumBackground
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

        Item {
            id: loadingImage
            Layout.fillWidth: true
            Layout.preferredHeight: 50
            Image {
                anchors.centerIn: parent
                height: 50
                width: 50
                source: "qrc:/resources/images/wait-loader-icon.svg"
            }
        }
    }
}
