import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.12
import CustomColors 1.0

Item {
    property alias cryptoLogo: cryptoLogo.source
    property alias cryptoName: cryptoName.text
    property alias ticker: ticker.text
    property alias animation: animation
    property color fontColor: Colors.almostWhite
    property string currency
    property double price
    property double change1h
    property double change24h
    property string rank
    property string lastUpdate

    width: 350
    height: 160
    CutCornersRectangleWithBorder {
        id: rect

        anchors.centerIn: parent
        width: parent.width
        height: 150

        Item {
            anchors.fill: parent

            Image {
                id: cryptoLogo
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: parent.height * 0.15
                anchors.topMargin: parent.height * 0.2
                height: parent.height * 0.5
                width: height
            }

            ColumnLayout {
                anchors.left: cryptoLogo.right
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: parent.height * 0.15

                Row {
                    spacing: 20

                    Label {
                        id: cryptoName
                        color: fontColor
                    }
                    Label {
                        id: ticker
                        color: Colors.accent
                        font.capitalization: Font.AllUppercase
                    }
                }

                Label {
                    id: ranking
                    text: qsTr("Rank: ") + rank
                    color: fontColor
                }

                Label {
                    id: currentPrice
                    text: qsTr("Current price: ") + price.toFixed(2) + (" ") + currency
                    color: fontColor
                }

                Row {
                    id: change1hRow
                    spacing: 5
                    Label {
                        text: qsTr("1h:")
                        color: fontColor
                    } Label {
                        color: change1h === 0 ? fontColor : change1h >= 0 ? "green" : "red"
                        text: change1h.toFixed(2) + " %"
                    }
                }
                Row {
                    id: change24hRow
                    spacing: 5
                    Label {
                        text: qsTr("24h:")
                        color: fontColor
                    } Label {
                        color: change24h === 0 ? fontColor : change24h >= 0 ? "green" : "red"
                        text: change24h.toFixed(2) + " %"
                    }
                }

                Label {
                    id: lastUpdated
                    text: qsTr("Last update: ") + Qt.formatDateTime(lastUpdate, "dd.MM.yyyy hh:mm");
                    color: fontColor
                }
            }
        }

        ColorOverlay {
            anchors.fill: rect
            source: rect
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
}
