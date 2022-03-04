#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>

void MainWindow::channel1(unsigned short int *values){
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    // Update the graph
    ui->General_Graphs_EngineRPM->graph(0)->addData(key,(double)(values[0])/100);
    ui->General_Graphs_EngineRPM->graph(1)->clearData();
    ui->General_Graphs_EngineRPM->graph(1)->addData(key,(double)(values[0])/100);
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

   // ui->General_Graphs_CorrSpeed->graph(0)->addData(key,(double)(values[1])/100);// mallon den xreiazetai!
    //ui->General_Graphs_CorrSpeed->graph(1)->clearData();
    //ui->General_Graphs_CorrSpeed->graph(1)->addData(key,(double)(values[1])/100);
    //remove data of lines that's outside visible range:
   // ui->General_Graphs_CorrSpeed->graph(0)->removeDataBefore(key-20);
    //ui->General_Graphs_CorrSpeed->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    //ui->General_Graphs_CorrSpeed->graph(0)->rescaleValueAxis();
   // ui->General_Graphs_CorrSpeed->graph(1)->rescaleValueAxis(true);

    //ui->General_Graphs_CorrSpeed->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    //ui->General_Graphs_CorrSpeed->yAxis->setRange(0, 5, Qt::AlignLeft);
    //ui->General_Graphs_CorrSpeed->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    //ui->General_Graphs_CorrSpeed->replot();

    ui->General_Graphs_ThrottlePos->graph(0)->addData(key,(double)(values[2])/100);
    ui->General_Graphs_ThrottlePos->graph(1)->clearData();
    ui->General_Graphs_ThrottlePos->graph(1)->addData(key,(double)(values[2])/100);
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

    //ui->General_Graphs_Gear->graph(0)->addData(key,(double)(values[3])/100);
    //ui->General_Graphs_Gear->graph(1)->clearData();
    //ui->General_Graphs_Gear->graph(1)->addData(key,(double)(values[3])/100);
    //remove data of lines that's outside visible range:
    //ui->General_Graphs_Gear->graph(0)->removeDataBefore(key-20);
    //ui->General_Graphs_Gear->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    //ui->General_Graphs_Gear->graph(0)->rescaleValueAxis();
    //ui->General_Graphs_Gear->graph(1)->rescaleValueAxis(true);

    //ui->General_Graphs_Gear->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    //ui->General_Graphs_Gear->yAxis->setRange(0, 5, Qt::AlignLeft);
    //ui->General_Graphs_Gear->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    //ui->General_Graphs_Gear->replot();
}
