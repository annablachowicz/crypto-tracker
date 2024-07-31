import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

CutCornersRectangleWithBorder {
    width: 350
    height: 150
    anchors.centerIn: parent

    Item {
        anchors.fill: parent

        Image {
            id: cryptoLogo
            anchors.left: parent.left
            anchors.top: parent.top
        }

        ColumnLayout {
            anchors.left: cryptoLogo.right
            anchors.verticalCenter: parent.verticalCenter

            Row {
                spacing: 20

                Label {
                    id: cryptoName
                    text: "Bitcoin"
                }
                Label {
                    id: ticker
                    text: "BTC"
                }
            }
            Label {
                id: currentPrice
                text: "Current price: "
            }
            Label {
                id: change1h
                text: "1h: "
            }
            Label {
                id: change24h
                text: "24h: "
            }

        }

    }
}
