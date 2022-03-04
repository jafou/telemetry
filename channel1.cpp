#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>

// This channel contains the RPM, Wheelspeed (will change), Throttle Position and Battery voltage
void MainWindow::channel1(unsigned short int *values){
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    // Perform Linear Calibration
    calibratedValues[0] = values[0]*RPMMultiplicator + RPMOffset;
    calibratedValues[1] = values[1]*WheelSpeedMultiplicator + WheelSpeedOffset;
    calibratedValues[2] = values[2]*TPMultiplicator + TPOffset;
    calibratedValues[3] = values[3]*BatteryVoltageMultiplicator + BatteryVoltageOffset;

    // Update the graph of the RPM of the General Tab
    ui->General_Graphs_EngineRPM->graph(0)->addData(key,calibratedValues[0]);
    ui->General_Graphs_EngineRPM->graph(1)->clearData();
    ui->General_Graphs_EngineRPM->graph(1)->addData(key,calibratedValues[0]);
    //remove data of lines that's outside visible range:
    ui->General_Graphs_EngineRPM->graph(0)->removeDataBefore(key-20);
    ui->General_Graphs_EngineRPM->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->General_Graphs_EngineRPM->graph(0)->rescaleValueAxis();
    ui->General_Graphs_EngineRPM->graph(1)->rescaleValueAxis(true);

    ui->General_Graphs_EngineRPM->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->General_Graphs_EngineRPM->yAxis->setRange(0, 5, Qt::AlignLeft);
    ui->General_Graphs_EngineRPM->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->General_Graphs_EngineRPM->replot();

    // Update the lcd displays of the EngineRPM
    ui->General_Bars_EngineRPM->display(calibratedValues[0]);
    ui->Engine_Bars_EngineRPM->display(calibratedValues[0]);
    ui->Fuel_Bars_EngineRPM->display(calibratedValues[0]);

    // Update the lcd displays of the Wheel Speed
    ui->General_Bars_WheelSpeed->display(calibratedValues[1]);
    ui->Suspension_Bars_WheelSpeed->display(calibratedValues[1]);

    // Update the Throttle Position graph of the general tab
    ui->General_Graphs_ThrottlePos->graph(0)->addData(key,calibratedValues[2]);
    ui->General_Graphs_ThrottlePos->graph(1)->clearData();
    ui->General_Graphs_ThrottlePos->graph(1)->addData(key,calibratedValues[2]);
    //remove data of lines that's outside visible range:
    ui->General_Graphs_ThrottlePos->graph(0)->removeDataBefore(key-20);
    ui->General_Graphs_ThrottlePos->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->General_Graphs_ThrottlePos->graph(0)->rescaleValueAxis();
    ui->General_Graphs_ThrottlePos->graph(1)->rescaleValueAxis(true);

    ui->General_Graphs_ThrottlePos->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->General_Graphs_ThrottlePos->yAxis->setRange(0, 5, Qt::AlignLeft);
    ui->General_Graphs_ThrottlePos->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->General_Graphs_ThrottlePos->replot();

    // Update the lcd displays and the progress bars of the Throttle Position
    ui->General_Bars_ThrottlePos->display(calibratedValues[2]);
    ui->Fuel_Bars_ThrottlePos->setRange(0,100);
    ui->General_Bars_ThrottlePosBar->setRange(0,100);
    ui->Fuel_Bars_ThrottlePos->setValue(calibratedValues[2]);
    ui->General_Bars_ThrottlePosBar->setValue(calibratedValues[2]);

    // Update the lcd display of the Battery Voltage
    ui->General_Bars_BatVolt->display((double)(calibratedValues[3])/100);
    ui->General_Bars_BatVoltBar->setRange(0,15);
    ui->General_Bars_BatVoltBar->setValue(calibratedValues[3]/100);
    ui->Engine_Bars_BatVolt->display(calibratedValues[3]/100);
}

