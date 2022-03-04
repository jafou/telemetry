#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>

void MainWindow::channel3(unsigned short int *values){
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    // Perform Linear Calibration
    calibratedValues[0] = values[0]*OilPressureMultiplicator + OilPressureOffset;
    calibratedValues[1] = values[1]*OilTempMultiplicator + OilTempOffset;
    calibratedValues[2] = values[2]*FuelPressureMultiplicator + FuelPressureOffset;

    // Update the graph of the Oil Pressure of the Engine Tab
    ui->Engine_Graphs_OilPressure->graph(0)->addData(key,(double)(calibratedValues[0]));
    ui->Engine_Graphs_OilPressure->graph(1)->clearData();
    ui->Engine_Graphs_OilPressure->graph(1)->addData(key,(double)(calibratedValues[0]));
    //remove data of lines that's outside visible range:
    ui->Engine_Graphs_OilPressure->graph(0)->removeDataBefore(key-20);
    ui->Engine_Graphs_OilPressure->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->Engine_Graphs_OilPressure->graph(0)->rescaleValueAxis();
    ui->Engine_Graphs_OilPressure->graph(1)->rescaleValueAxis(true);

    ui->Engine_Graphs_OilPressure->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->Engine_Graphs_OilPressure->yAxis->setRange(0, 5, Qt::AlignLeft);
    ui->Engine_Graphs_OilPressure->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Engine_Graphs_OilPressure->replot();

    // Update the bar of the Oil Pressure of the Engine Tab
    ui->Engine_Bars_OilPressure->setRange(30,650);
    ui->Engine_Bars_OilPressure->setValue(calibratedValues[0]);

    // Update the bar of the Oil Temperature of the Engine Tab
    ui->Engine_Bars_OilTemperature->setRange(0,100);
    ui->Engine_Bars_OilTemperature->setValue(calibratedValues[1]);

    // Update the graph of the Fuel Pressure of the Engine Tab
    ui->Engine_Graphs_FuelPressure->graph(0)->addData(key,(double)(calibratedValues[2]));
    ui->Engine_Graphs_FuelPressure->graph(1)->clearData();
    ui->Engine_Graphs_FuelPressure->graph(1)->addData(key,(double)(calibratedValues[2]));
    //remove data of lines that's outside visible range:
    ui->Engine_Graphs_FuelPressure->graph(0)->removeDataBefore(key-20);
    ui->Engine_Graphs_FuelPressure->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->Engine_Graphs_FuelPressure->graph(0)->rescaleValueAxis();
    ui->Engine_Graphs_FuelPressure->graph(1)->rescaleValueAxis(true);

    ui->Engine_Graphs_FuelPressure->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->Engine_Graphs_FuelPressure->yAxis->setRange(0, 5, Qt::AlignLeft);
    ui->Engine_Graphs_FuelPressure->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Engine_Graphs_FuelPressure->replot();

    // Update the graph of the Fuel Pressure of the Fuel Tab
    ui->Fuel_Graphs_FuelPressure->graph(0)->addData(key,(double)(calibratedValues[2]));
    ui->Fuel_Graphs_FuelPressure->graph(1)->clearData();
    ui->Fuel_Graphs_FuelPressure->graph(1)->addData(key,(double)(calibratedValues[2]));
    //remove data of lines that's outside visible range:
    ui->Fuel_Graphs_FuelPressure->graph(0)->removeDataBefore(key-20);
    ui->Fuel_Graphs_FuelPressure->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->Fuel_Graphs_FuelPressure->graph(0)->rescaleValueAxis();
    ui->Fuel_Graphs_FuelPressure->graph(1)->rescaleValueAxis(true);

    ui->Fuel_Graphs_FuelPressure->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->Fuel_Graphs_FuelPressure->yAxis->setRange(0, 5, Qt::AlignLeft);
    ui->Fuel_Graphs_FuelPressure->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Fuel_Graphs_FuelPressure->replot();

    // Update the bars and lcd displays of the Fuel Pressure
    ui->Engine_Bars_FuelPressureBar->setRange(0,500);
    ui->Engine_Bars_FuelPressureBar->setValue(calibratedValues[2]);
    ui->Engine_Bars_FuelPressure->display((double)calibratedValues[2]);
    ui->Fuel_Bars_FuelPressure->setRange(0,500);
    ui->Fuel_Bars_FuelPressure->setValue(calibratedValues[2]);
}
