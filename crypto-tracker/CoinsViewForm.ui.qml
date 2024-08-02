import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.3
import CustomColors 1.0
import "Components/CryptoLabel"

Rectangle {
    id: root

    property alias model: repeater.model
    property alias colorOverlay: colorOverlay

    ScrollView {
        id: scrollView
        anchors.fill: parent

        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        contentHeight: columnLayout.height
        clip: true

        ColumnLayout {
            id: columnLayout
            width: root.width

            Repeater {
                id: repeater
                delegate: CryptoLabel {
                    Layout.alignment: Qt.AlignHCenter
                    cryptoLogo: model.image
                    cryptoName: model.name
                    ticker: model.ticker
                    price: model.price
                    change1h: model.priceChange1h
                    change24h: model.priceChange24h
                }
            }
        }
    }

    ColorOverlay {
        id: colorOverlay
        anchors.fill: root
        source: root
        visible: false
        color: Colors.overlay
    }

}
