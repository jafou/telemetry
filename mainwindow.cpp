#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphsinitialisation.cpp"
#include "readdataframe.cpp"
#include "channel1.cpp"
#include "channel2.cpp"
#include "channel3.cpp"
#include "channel4.cpp"
#include "channel5.cpp"
#include "channel6.cpp"
#include "clearframe.cpp"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <iostream>
#include <QTimer>
#include <windows.h>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QtMath>
#include <QVector>
#include <string>
#include <QStringList>
#include <QTime>
#include <QSignalMapper>
#include <math.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Start embedding Jafou's code from here.
    serialAntenna = new QSerialPort(this);
    headerRead = false;
    footerRead = false;

    //Initialize the graphs of the General Tab
    graphsInitialisation();
    //Initialize the counter of the GGDiagram. When it reaches a specified value, all previous data will be deleted.
    GGDiagramCounter = 0;
    iterations = 0;
    sum_x = 0;
    sum_y = 0;

    /* Testing code, printing the description, vendor id and product id of all ports.
     * Used to define the values for the serial Antenna and put them in the mainwindow.h file

    qDebug()<<"Number of ports: "<<QSerialPortInfo::availablePorts().length()<<"\n";
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        cout << "Description: " << serialPortInfo.description().toStdString() << "\n";
        cout<<"Has vendor id?: " << serialPortInfo.hasVendorIdentifier() << "\n";
        cout<<"Vendor ID: "<<serialPortInfo.vendorIdentifier()<<"\n";
        cout<<"Has product ID?: "<<serialPortInfo.hasProductIdentifier()<<"\n";
        cout<<"Product ID: "<<serialPortInfo.productIdentifier()<<"\n";
    }*/

    /*Identify the port the serial Antenna is on by checking all available serial ports
     * and comparing to see if they match the serial Antenna characteristics
     */
    bool antenna_is_available = false;
    QString serial_antenna_port_name;

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        //check if the serialPort has both a product identifier and a vendor identifier
        if (serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            //check if the product ID and the vendor ID correspond to the ones of the serial antenna
            if ((serialPortInfo.vendorIdentifier() == serial_antenna_vendor_id) && (serialPortInfo.productIdentifier() == serial_antenna_product_id)){
                antenna_is_available = true;
                serial_antenna_port_name = serialPortInfo.portName();
            }
        }
    }

    // Open and configure the antenna port if available
    if (antenna_is_available){
        //cout << "Found the serial_antenna port"<<endl;
        serialAntenna->setPortName(serial_antenna_port_name);
        serialAntenna->open(QSerialPort::ReadOnly);
        serialAntenna->setBaudRate(QSerialPort::Baud38400);
        serialAntenna->setDataBits(QSerialPort::Data8);
        serialAntenna->setFlowControl(QSerialPort::NoFlowControl);
        serialAntenna->setParity(QSerialPort::NoParity);
        serialAntenna->setStopBits(QSerialPort::OneStop);
        connect(serialAntenna,SIGNAL(readyRead()),this,SLOT(readSerialBytes()));

    }
    else{
        cout<<"Couldn't find the antenna"<<endl;
        QMessageBox::warning(this,"Serial Port Error","Couldn't open serial port to the antenna.");
    }

}

//This function is called every time new data are available at the port.
void MainWindow::readSerialBytes(){
    firstByte = serialAntenna->peek(1);
    if (firstByte[0] == '~' && headerRead == false){ //Checks if the first byte received is the header of the message.
        //The next thing to read is the 2 bytes of the channel address.
        //At this point we have to check the address of the channel.
        firstByte = serialAntenna->read(1);
        headerRead = true;
        if (serialAntenna->bytesAvailable() >= 1 && channelFrame.length() < 2){
            channelFrame.append(serialAntenna->read(2-channelFrame.length()));
        }
    }
    /*Enters here if the byte read is not the expected header
     * This might happen if some part of the data frame arrives later.
     */
    else if(headerRead){//The header has been read in a previous cycle.
        if (channelFrame.length() != 2 && serialAntenna->bytesAvailable() >=1){
            channelFrame.append(serialAntenna->read(2-channelFrame.length()));
            //cout<<channelFrame.length()<<endl;
        }
    }
    else{
        trash = serialAntenna->read(1); //In case the communication starts in the middle of a message, we discard
                                        //everything we receive until a new header arrives.
    }

    //Having read the channel bytes, we enter the switch case.
    if (channelFrame.length() == 2){// This switch case includes ALL the possible channel cases.
        switch (decipherTheChannel(channelFrame)){//PROBLEM!! decipherTheChannel() is called every time! TO FIX!
            case 0x5F0:
                readDataFrame();
                channel1(valuesOf2Bytes);
                clearFrame();
                break;
            case 0x5F1:
                readDataFrame();
                channel2(valuesOf2Bytes);
                clearFrame();
                break;
            case 0x5F2:
                readDataFrame();
                channel3(valuesOf2Bytes);
                clearFrame();
                break;
            case 0x5F3:
                readDataFrame();
                channel4(valuesOf2Bytes);
                clearFrame();
                break;
            case 0x5F4:
                readDataFrame();
                channel5(valuesOf2Bytes);
                clearFrame();
                break;
            case 0x5F5:
                readDataFrame();
                channel6(valuesOf2Bytes);
                clearFrame();
                break;
            default:
                cout<<"Invalid channel number"<<endl;
        }
    }
}

/*The following function receives the byte array that contains the 2 bytes of the channels address
* Its purpose is to compose the address and act accordingly.
*/
int MainWindow::decipherTheChannel(QByteArray channelFrame){
    //Channe frame is received correctly.
    currentChannel = bytes2ShortInt(channelFrame);
    //cout<<currentChannel<<endl;
    return currentChannel;
}

/*This function receives as an argument a byte array of 2 bytes
 * and returns the integer that is composed of these 2 bytes.
 */
unsigned short int MainWindow::bytes2ShortInt(QByteArray bytesArray){
    union{
        unsigned short int intVariable;
        unsigned char  tempArray[2];
    }u;
    //Pay attention to the order of the bytes
    u.tempArray[0] = bytesArray[0];
    u.tempArray[1] = bytesArray[1];
    return u.intVariable;
}

void MainWindow::delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


