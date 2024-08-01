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

    ColumnLayout {
        anchors.fill: parent
        Label {
            text: qsTr("Sort")
            Layout.leftMargin: 20
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
