import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

RowLayout {
    height: 100
    Image {
        source: "qrc:/resources/images/red-x-line-icon.svg"
        Layout.preferredWidth: 30
        Layout.preferredHeight: 30
        fillMode: Image.PreserveAspectFit;
    }

    Label {
        id: staleDataLabel
        Layout.fillWidth: true
        text: qsTr("stale data")
        color: "red"
        font.capitalization: Font.AllUppercase
    }

}
