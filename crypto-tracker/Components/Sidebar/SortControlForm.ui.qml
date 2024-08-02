import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import CustomColors 1.0

Item {
    property alias rankingButton: rankingButton
    property alias priceButton: priceButton
    property alias change24hButton: change24hButton
    property alias nameButton: nameButton
    property alias ascendingButton: ascendingButton
    property alias descendingButton: descendingButton

    id: root
    height: 200
    width: 160

    ColumnLayout {
        anchors.fill: parent
        spacing: 20

        Label {
            text: qsTr("Sort")
            Layout.leftMargin: 20
        }

        Rectangle {
            width: parent.width
            height: 2
            color: Colors.mediumBackground
        }

        ColumnLayout {
            RadioButton {
                id: rankingButton
                text: qsTr("ranking")
                checked: true
            }
            RadioButton {
                id: priceButton
                text: qsTr("price")
            }
            RadioButton {
                id: change24hButton
                text: qsTr("24 hour change")
            }
            RadioButton {
                id: nameButton
                text: qsTr("name")
            }
        }

        Rectangle {
            width: parent.width
            height: 2
            color: Colors.mediumBackground
        }

        ColumnLayout {
            RadioButton {
                id: ascendingButton
                text: qsTr("ascending")
                checked: true
            }
            RadioButton {
                id: descendingButton
                text: qsTr("descending")
            }
        }
    }
}
