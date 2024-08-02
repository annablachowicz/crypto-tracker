import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.12
import CustomColors 1.0

CutCornersRectangleWithBorder {
    id: root
    property alias cryptoLogo: cryptoLogo.source
    property alias cryptoName: cryptoName.text
    property alias ticker: ticker.text
    property alias animation: animation
    property string currency
    property double price
    property double change1h
    property double change24h

    width: 350
    height: 150

    Item {
        anchors.fill: parent

        Image {
            id: cryptoLogo
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: parent.height * 0.2
            anchors.topMargin: parent.height * 0.2
            height: parent.height * 0.6
            width: height
        }

        ColumnLayout {
            anchors.left: cryptoLogo.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: parent.height * 0.2

            Row {
                spacing: 20

                Label {
                    id: cryptoName
                }
                Label {
                    id: ticker
                    color: "grey"
                    font.capitalization: Font.AllUppercase
                }
            }

            Label {
                id: currentPrice
                text: qsTr("Current price: ") + price + (" ") + currency
            }

            Row {
                id: change1hRow
                spacing: 5
                Label {
                    text: qsTr("1h:")
                } Label {
                    color: change1h === 0 ? "black" : change1h >= 0 ? "green" : "red"
                    text: change1h.toFixed(2) + " %"
                }
            }
            Row {
                id: change24hRow
                spacing: 5
                Label {
                    text: qsTr("24h:")
                } Label {
                    color: change24h === 0 ? "black" : change24h >= 0 ? "green" : "red"
                    text: change24h.toFixed(2) + " %"
                }
            }

        }

    }

    ColorOverlay {
        anchors.fill: root
        source: root
        color: "transparent"

        SequentialAnimation on color {
            id: animation
            ColorAnimation {
                to: Colors.overlay
                duration: 250
            }
            ColorAnimation {
                to: "transparent"
                duration: 250
            }
        }


    }


}
