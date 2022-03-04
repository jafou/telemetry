#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>

// This channel contains the potensiometer data (Linear displacement of the shock absorbers)
void MainWindow::channel5(unsigned short int *values){
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    // Perform Linear Calibration
    calibratedValues[0] = values[0]*PotFrontLeftMultiplicator + PotFrontLeftOffset;
    calibratedValues[1] = values[1]*PotFrontRightMultiplicator + PotFrontRightOffset;
    calibratedValues[2] = values[2]*PotRearRightMultiplicator + PotRearRightOffset;
    calibratedValues[3] = values[3]*PotRearLeftMultiplicator + PotRearLeftOffset;

    // Update the graphs of the Potensiometers of the Suspension Tab
    ui->Suspension_Graphs_PotFL->graph(0)->addData(key,(double)(calibratedValues[0]));
    ui->Suspension_Graphs_PotFL->graph(1)->clearData();
    ui->Suspension_Graphs_PotFL->graph(1)->addData(key,(double)(calibratedValues[0]));
    //remove data of lines that's outside visible range:
    ui->Suspension_Graphs_PotFL->graph(0)->removeDataBefore(key-20);
    ui->Suspension_Graphs_PotFL->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->Suspension_Graphs_PotFL->graph(0)->rescaleValueAxis();
    ui->Suspension_Graphs_PotFL->graph(1)->rescaleValueAxis(true);

    ui->Suspension_Graphs_PotFL->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->Suspension_Graphs_PotFL->yAxis->setRange(0, 5, Qt::AlignLeft);
    ui->Suspension_Graphs_PotFL->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Suspension_Graphs_PotFL->replot();

    ui->Suspension_Graphs_PotFR->graph(0)->addData(key,(double)(calibratedValues[1]));
    ui->Suspension_Graphs_PotFR->graph(1)->clearData();
    ui->Suspension_Graphs_PotFR->graph(1)->addData(key,(double)(calibratedValues[1]));
    //remove data of lines that's outside visible range:
    ui->Suspension_Graphs_PotFR->graph(0)->removeDataBefore(key-20);
    ui->Suspension_Graphs_PotFR->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->Suspension_Graphs_PotFR->graph(0)->rescaleValueAxis();
    ui->Suspension_Graphs_PotFR->graph(1)->rescaleValueAxis(true);

    ui->Suspension_Graphs_PotFR->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->Suspension_Graphs_PotFR->yAxis->setRange(0, 5, Qt::AlignLeft);
    ui->Suspension_Graphs_PotFR->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Suspension_Graphs_PotFR->replot();

    ui->Suspension_Graphs_PotRR->graph(0)->addData(key,(double)(calibratedValues[2]));
    ui->Suspension_Graphs_PotRR->graph(1)->clearData();
    ui->Suspension_Graphs_PotRR->graph(1)->addData(key,(double)(calibratedValues[2]));
    //remove data of lines that's outside visible range:
    ui->Suspension_Graphs_PotRR->graph(0)->removeDataBefore(key-20);
    ui->Suspension_Graphs_PotRR->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->Suspension_Graphs_PotRR->graph(0)->rescaleValueAxis();
    ui->Suspension_Graphs_PotRR->graph(1)->rescaleValueAxis(true);

    ui->Suspension_Graphs_PotRR->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->Suspension_Graphs_PotRR->yAxis->setRange(0, 5, Qt::AlignLeft);
    ui->Suspension_Graphs_PotRR->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Suspension_Graphs_PotRR->replot();

    ui->Suspension_Graphs_PotRL->graph(0)->addData(key,(double)(calibratedValues[3]));
    ui->Suspension_Graphs_PotRL->graph(1)->clearData();
    ui->Suspension_Graphs_PotRL->graph(1)->addData(key,(double)(calibratedValues[3]));
    //remove data of lines that's outside visible range:
    ui->Suspension_Graphs_PotRL->graph(0)->removeDataBefore(key-20);
    ui->Suspension_Graphs_PotRL->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->Suspension_Graphs_PotRL->graph(0)->rescaleValueAxis();
    ui->Suspension_Graphs_PotRL->graph(1)->rescaleValueAxis(true);

    ui->Suspension_Graphs_PotRL->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->Suspension_Graphs_PotRL->yAxis->setRange(0, 5, Qt::AlignLeft);
    ui->Suspension_Graphs_PotRL->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Suspension_Graphs_PotRL->replot();
}
