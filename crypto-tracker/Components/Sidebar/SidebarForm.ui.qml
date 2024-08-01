import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import CustomColors 1.0

Item {
    property alias rankingButton: rankingButton
    property alias priceButton: priceButton
    property alias change24hButton: change24hButton
    property alias nameButton: nameButton

    id: root
    height: 200
    width: 160

    Column {
        anchors.fill: parent
        Rectangle {
            color: Colors.lightBackground
            border.color: Colors.mediumBackground
            border.width: 2
            width: root.width
            height: 40
            Label {
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Sort")
            }
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
    }
}
