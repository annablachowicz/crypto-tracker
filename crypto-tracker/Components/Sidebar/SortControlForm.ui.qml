import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import CustomColors 1.0
import "../"

Item {
    property alias rankingButton: rankingButton
    property alias priceButton: priceButton
    property alias change24hButton: change24hButton
    property alias nameButton: nameButton
    property alias ascendingButton: ascendingButton
    property alias descendingButton: descendingButton

    id: root
    height: 400
    width: 200

    ColumnLayout {
        anchors.fill: parent
        spacing: 20

        Label {
            text: qsTr("Sort")
            Layout.leftMargin: 20
            Layout.topMargin: 10
            Layout.alignment: Qt.AlignVCenter
            color: Colors.almostWhite
        }

        Rectangle {
            Layout.fillWidth: true
            height: 1
            color: Colors.accent
        }

        ColumnLayout {
            CustomRadioButton {
                id: rankingButton
                text: qsTr("ranking")
                checked: true
            }
            CustomRadioButton {
                id: priceButton
                text: qsTr("price")
            }
            CustomRadioButton {
                id: change24hButton
                text: qsTr("24 hour change")
            }
            CustomRadioButton {
                id: nameButton
                text: qsTr("name")
            }
        }

        Rectangle {
            Layout.fillWidth: true
            height: 1
            color: Colors.accent
        }

        ColumnLayout {
            CustomRadioButton {
                id: ascendingButton
                text: qsTr("ascending")
                checked: true
            }
            CustomRadioButton {
                id: descendingButton
                text: qsTr("descending")
            }
        }
    }
}
