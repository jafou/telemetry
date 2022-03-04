#include "mainwindow.h"
#include "ui_mainwindow.h"

// Function responsible for reading the 8byte data frame of the serial message
void MainWindow::readDataFrame(){
    //Read bytes for data1 until you have read 2.
    while(serialAntenna->bytesAvailable() >= 1 && data1Bytes.length() < 2){
        data1Bytes.append(serialAntenna->read(2-data1Bytes.length()));
    }
    //If you have read 2 bytes for data1, read bytes for data2 until you have read 2.
    while(serialAntenna->bytesAvailable() >=1 && data1Bytes.length() == 2 && data2Bytes.length() < 2){
        data2Bytes.append(serialAntenna->read(2-data2Bytes.length()));
    }
    //If you have read 2 bytes for data1 and 2 bytes for data2 read bytes for data3 until you have read 2.
    while(serialAntenna->bytesAvailable() >=1 && data1Bytes.length() == 2 && data2Bytes.length() == 2 && data3Bytes.length() < 2){
        data3Bytes.append(serialAntenna->read(2-data3Bytes.length()));
    }
    //If you have read 2 bytes for data1,2 bytes for data2 and 2 bytes for data3 read bytes for data4 until you have read 2.
    while(serialAntenna->bytesAvailable() >=1 && data1Bytes.length() == 2 && data2Bytes.length() == 2 && data3Bytes.length() == 2 && data4Bytes.length() < 2){
        data4Bytes.append(serialAntenna->read(2-data4Bytes.length()));
    }
    if(serialAntenna->bytesAvailable() > 1 && footerRead == false && data1Bytes.length() == 2 && data2Bytes.length() == 2 && data3Bytes.length() == 2 && data4Bytes.length() == 2){
        footer.append(serialAntenna->read(2));
        if (footer[0] == '.' && footer[1] == '\n'){
            footerRead = true;
        }
        else{
            // If we enter here it means that the bytes that arrived after the data frame are not the footer.
            // Therefore, there has been an error and we should exit and start with a new message.
            headerRead = false;
            channelFrame.clear();
            data1Bytes.clear();
            data2Bytes.clear();
            data3Bytes.clear();
            data4Bytes.clear();
            footerRead = false;
            footer.clear();
        }
    }
    if (data1Bytes.length() == 2 && data2Bytes.length() == 2 && data3Bytes.length() == 2 && data4Bytes.length() == 2 && footerRead == true){
        valuesOf2Bytes[0] = bytes2ShortInt(data1Bytes);
        valuesOf2Bytes[1] = bytes2ShortInt(data2Bytes);
        valuesOf2Bytes[2] = bytes2ShortInt(data3Bytes);
        valuesOf2Bytes[3] = bytes2ShortInt(data4Bytes);
    }
}
