#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void readSerialBytes();
    int decipherTheChannel(QByteArray channelFrame);
    unsigned short int bytes2ShortInt(QByteArray bytesArray);
    void readDataFrame();
    void channel1(unsigned short int *values);
    void channel2(unsigned short int *values);
    void channel3(unsigned short int *values);
    void channel4(unsigned short int *values);
    void channel5(unsigned short int *values);
    void channel6(unsigned short int *values);
    void clearFrame();



private:
    Ui::MainWindow *ui;

    QSerialPort *serialAntenna;
    static const quint16 serial_antenna_vendor_id = 10755; //to be replaced with the serial antenna vendor id
    static const quint16 serial_antenna_product_id =67; //to be replaced with the serial antenna product id
    void graphsInitialisation();
    QByteArray dataBytes;
    QByteArray serialData;
    QByteArray firstByte;
    QByteArray data1Bytes;
    QByteArray data2Bytes;
    QByteArray data3Bytes;
    QByteArray data4Bytes;
    QByteArray channelFrame;
    QByteArray trash;
    QByteArray footer;

    // Calibration Variables
    const static double RPMMultiplicator = 1;
    const static double RPMOffset = 0;
    const static double WheelSpeedMultiplicator = 0.1;
    const static double WheelSpeedOffset = 0;
    const static double TPMultiplicator = 0.1;
    const static double TPOffset = 0;
    const static double BatteryVoltageMultiplicator = 0.01;
    const static double BatteryVoltageOffset = 0;
    const static double MAPMultiplicator = 0.1;
    const static double MAPOffset = 0;
    const static double LambdaMultiplicator = 0.001;
    const static double LambdaOffset = 0;
    const static double EngineTempMultiplicator = 0.1;
    const static double EngineTempOffset = 0;
    const static double CoolerTempMultiplicator = 0.1;
    const static double CoolerTempOffset = 0;
    const static double OilPressureMultiplicator = 0.1;
    const static double OilPressureOffset = 0;
    const static double OilTempMultiplicator = 0.1;
    const static double OilTempOffset = 0;
    const static double FuelPressureMultiplicator = 0.1;
    const static double FuelPressureOffset = 0;
    const static double ACC_XMultiplicator = -0.005;
    const static double ACC_XOffset = 166.374;
    const static double ACC_YMultiplicator = -0.005;
    const static double ACC_YOffset = 158.308;
    const static double PotFrontLeftMultiplicator = -0.0012;
    const static double PotFrontLeftOffset = 29.3037;
    const static double PotFrontRightMultiplicator = 1;
    const static double PotFrontRightOffset = 0;
    const static double PotRearRightMultiplicator = 1;
    const static double PotRearRightOffset = 0;
    const static double PotRearLeftMultiplicator = -0.0012;
    const static double PotRearLeftOffset = 21.0018;
    const static double SteeringAngleMultiplicator = 1; // To be changed!!
    const static double SteeringAngleOffset = 0;
    const static int max_iterations = 10;
    const static double WB = 1; // To be changed!!

    int iterations;
    double sum_x,sum_y;
    int GGDiagramCounter;
    unsigned short int currentChannel;
    unsigned short int valuesOf2Bytes[4];//This array is used to store the 4 values of 2 bytes.(we'll see later the type)
    double calibratedValues[4];
    bool headerRead;//Bool variable that holds if the header has been read or not.
    bool footerRead;//Bool variable that holds if the footer has been read or not.
    void delay(int millisecondsToWait);//Custom made delay function for debugging purposes.

};

#endif // MAINWINDOW_H
