import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 300
    height: 200
    title: "ESP32 LED Controller"
    color: "#212121"

    property bool isConnected: false

    Rectangle {
        anchors.fill: parent
        color: "#2b2b2b"

        Column {
            anchors.centerIn: parent
            spacing: 20

            Button {
                text: isConnected ? "Connected 🔗" : "Connect to ESP32"
                width: 200
                onClicked: {
                    serialReader.start("/dev/cu.usbserial-10") // پورت درست ESP32 توی مک
                    isConnected = true
                }
            }

            Button {
                text: "LED ON"
                width: 200
                onClicked: {
                    serialReader.sendCommand("LED_ON\n")
                }
            }

            Button {
                text: "LED OFF"
                width: 200
                onClicked: {
                    serialReader.sendCommand("LED_OFF\n")
                }
            }
        }
    }

    Connections {
        target: serialReader
        function onNewDataReceived(data) {
            console.log("✅ ESP32 says:", data)
        }
    }
}