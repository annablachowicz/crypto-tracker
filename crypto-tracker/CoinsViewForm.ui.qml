import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import "Components/CryptoLabel"

Item {
    id: root

    property alias model: repeater.model

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

}
