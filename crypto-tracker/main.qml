import QtQuick 2.15
import QtQuick.Window 2.15
import "Components/CryptoLabel"

Window {
    width: 720
    height: 960
    visible: true
    title: qsTr("Hello World")

    CoinsView {
    }
}
