#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>

// End of message, data plotted, clear all the QByteArrays and reset the bools.
void MainWindow::clearFrame(){
    headerRead = false;
    channelFrame.clear();
    data1Bytes.clear();
    data2Bytes.clear();
    data3Bytes.clear();
    data4Bytes.clear();
    footerRead = false;
    footer.clear();
}
