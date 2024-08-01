import QtQuick 2.15
import QtQuick.Window 2.15
import CustomColors 1.0

Window {
    width: 900
    height: 960
    visible: true
    title: qsTr("Crypto Tracker")
    color: Colors.almostWhite

    MainView {
        anchors.fill: parent
    }

}
