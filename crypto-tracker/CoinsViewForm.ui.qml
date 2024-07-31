import QtQuick 2.15
import QtQuick.Layouts 1.3
import "Components/CryptoLabel"

Item {
    property alias model: repeater.model
    ColumnLayout {
        anchors.fill: parent
        Repeater {
            id: repeater

            Layout.fillHeight: true
            Layout.fillWidth: true

            delegate: CryptoLabel {
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
