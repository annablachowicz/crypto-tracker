import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import CustomColors 1.0

Popup {
    property alias errorLabel: errorLabel
    height: 180
    width: 280
    anchors.centerIn: parent
    background: Rectangle {
        color: Colors.almostWhite
        radius: 5
    }
    contentItem: ColumnLayout {
        anchors.fill: parent
        Label {
            id: errorLabel
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            color: Colors.shadow
        }
        Button {
            Layout.preferredWidth: 100
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("OK")
            onClicked: parseErrorPopup.close()
        }
    }
}
