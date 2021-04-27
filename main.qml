import QtQuick 2.14
import QtQuick.Window 2.14
import httpRequest 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        HttpRequest {
            id: httpRequest
            signal audioInput
            Component.onCompleted: {
                console.log("httpRequest: ",httpRequest)
                httpRequest.setExtraHeaderValue("Content-Type", "application/json");
                httpRequest.postRequest("https://10.3.56.114:9443/api/v2.0/auth/login", "{\"authorization\": \"YWRtaW5pc3RyYXRvcjpwYXNzd29yZA==\"}")
            }

            onReplyTestRespone: {
                console.log("reply: ",reply);
            }

            function audioInputFunction(result) {
                console.log("result: ",result)
            }
        }

    }
}
