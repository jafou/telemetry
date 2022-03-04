#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>

void MainWindow::channel2(unsigned short int *values){
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    // Perform Linear Calibration
    calibratedValues[0] = values[0]*MAPMultiplicator + MAPOffset;
    calibratedValues[1] = values[1]*LambdaMultiplicator + LambdaOffset;
    calibratedValues[2] = values[2]*EngineTempMultiplicator + EngineTempOffset;
    calibratedValues[3] = values[3]*CoolerTempMultiplicator + CoolerTempOffset;

    // Update the graph of the MAP of the Fuel Tab
    ui->Fuel_Graphs_MAP->graph(0)->addData(key,(double)(calibratedValues[0]));
    ui->Fuel_Graphs_MAP->graph(1)->clearData();
    ui->Fuel_Graphs_MAP->graph(1)->addData(key,(double)(calibratedValues[0]));
    //remove data of lines that's outside visible range:
    ui->Fuel_Graphs_MAP->graph(0)->removeDataBefore(key-20);
    ui->Fuel_Graphs_MAP->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->Fuel_Graphs_MAP->graph(0)->rescaleValueAxis();
    ui->Fuel_Graphs_MAP->graph(1)->rescaleValueAxis(true);

    ui->Fuel_Graphs_MAP->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->Fuel_Graphs_MAP->yAxis->setRange(0, 5, Qt::AlignLeft);
    ui->Fuel_Graphs_MAP->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Fuel_Graphs_MAP->replot();

    // Update the bar and lcd display of the MAP of the Fuel Tab
    ui->Fuel_Bars_MAP->display((double)calibratedValues[0]);
    ui->Fuel_Bars_MAPBar->setRange(0,105);
    ui->Fuel_Bars_MAPBar->setValue(calibratedValues[0]);

    // Update the graph of the Lambda of the Fuel Tab
    ui->Fuel_Graphs_Lambda->graph(0)->addData(key,(double)(calibratedValues[1])/100);
    ui->Fuel_Graphs_Lambda->graph(1)->clearData();
    ui->Fuel_Graphs_Lambda->graph(1)->addData(key,(double)(calibratedValues[1])/100);
    //remove data of lines that's outside visible range:
    ui->Fuel_Graphs_Lambda->graph(0)->removeDataBefore(key-20);
    ui->Fuel_Graphs_Lambda->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->Fuel_Graphs_Lambda->graph(0)->rescaleValueAxis();
    ui->Fuel_Graphs_Lambda->graph(1)->rescaleValueAxis(true);

    ui->Fuel_Graphs_Lambda->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->Fuel_Graphs_Lambda->yAxis->setRange(0, 5, Qt::AlignLeft);
    ui->Fuel_Graphs_Lambda->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Fuel_Graphs_Lambda->replot();

    // Update the lcd display of the Lambda of the Fuel Tab
    ui->Fuel_Bars_Lambda->display((double)(calibratedValues[1])/100);

    // Update the graph of the Engine Temperature of the Engine Tab
    ui->Engine_Graphs_EngineTemp->graph(0)->addData(key,(double)(calibratedValues[2]));
    ui->Engine_Graphs_EngineTemp->graph(1)->clearData();
    ui->Engine_Graphs_EngineTemp->graph(1)->addData(key,(double)(calibratedValues[2]));
    //remove data of lines that's outside visible range:
    ui->Engine_Graphs_EngineTemp->graph(0)->removeDataBefore(key-20);
    ui->Engine_Graphs_EngineTemp->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->Engine_Graphs_EngineTemp->graph(0)->rescaleValueAxis();
    ui->Engine_Graphs_EngineTemp->graph(1)->rescaleValueAxis(true);

    ui->Engine_Graphs_EngineTemp->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->Engine_Graphs_EngineTemp->yAxis->setRange(0, 5, Qt::AlignLeft);
    ui->Engine_Graphs_EngineTemp->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Engine_Graphs_EngineTemp->replot();

    // Update the progress bar of the Engine Temperature of the Engine Tab
    ui->Engine_Bars_EngineTemperature->setRange(0,120);
    ui->Engine_Bars_EngineTemperature->setValue(calibratedValues[2]);

}
