/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 6.2
import QtQuick.Controls 6.2
import UntitledProject

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    AnimatedImage {
        id: animatedImage
        x: 126
        y: 9
        width: 1656
        height: 1058
        source: "../../../Pictures/Saved Pictures/WhatsApp Image 2023-05-16 at 8.27.36 PM.jpeg"
    }
}
