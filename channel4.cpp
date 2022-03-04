#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include <math.h>

// This channel contains the Longtitudinal and Lateral Acceleration data
// and will be used for the GGDiagram. It also contains the wheelspeed and steering angle signal
// Still don't know how to do that. Improvising in progress
void MainWindow::channel4(unsigned short int *values){
    // Perform linear calibration and convert to g's.
    calibratedValues[0] = (values[0]*ACC_XMultiplicator + ACC_XOffset)/9.81;
    calibratedValues[1] = (values[1]*ACC_YMultiplicator + ACC_YOffset)/9.81;
    calibratedValues[2] = (values[2]*WheelSpeedMultiplicator + WheelSpeedOffset);
    calibratedValues[3] = (values[3]*SteeringAngleMultiplicator + SteeringAngleOffset);

    // Check if we have reached the number of data to be averaged
    if (iterations == max_iterations){
        // Update the GGDiagram
        ui->Suspension_Graphs_GGDiagram->graph(0)->addData(sum_x / max_iterations,sum_y / max_iterations);

        ui->Suspension_Graphs_GGDiagram->xAxis->setRange(-2.5,2.5);
        ui->Suspension_Graphs_GGDiagram->yAxis->setRange(-2.5,2.5);
        //rescale value (vertical) axis to fit the current data:
        ui->Suspension_Graphs_GGDiagram->graph(0)->rescaleValueAxis(true);
        ui->Suspension_Graphs_GGDiagram->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui->Suspension_Graphs_GGDiagram->replot();
        // Zero the iterations and start over
        iterations = 0;
        sum_x = 0;
        sum_y = 0;
    }
    else{
        sum_x += calibratedValues[0];
        sum_y += calibratedValues[1];
        iterations++;
    }
    // Update the GGDiagram of the Suspension Tab
    /*if (GGDiagramCounter == 30){
        GGDiagramCounter = 0;
        ui->Suspension_Graphs_GGDiagram->graph(0)->clearData();
    }
    ui->Suspension_Graphs_GGDiagram->graph(0)->addData((double)values[0]/10 - 2.5,(double)values[1]/10 - 2.5);

    ui->Suspension_Graphs_GGDiagram->xAxis->setRange(-2.5,2.5);
    ui->Suspension_Graphs_GGDiagram->yAxis->setRange(-2.5,2.5);
    //rescale value (vertical) axis to fit the current data:
    ui->Suspension_Graphs_GGDiagram->graph(0)->rescaleValueAxis(true);
    ui->Suspension_Graphs_GGDiagram->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Suspension_Graphs_GGDiagram->replot();
    GGDiagramCounter ++;*/

    // Calculate the USD (Understeer Gradient)
    double USD;
    // Change the definition to SI (Dimitra!!). Check the unit of the steering angle. Equation needs rads
    USD = (calibratedValues[3] - atan(WB/pow(calibratedValues[2]*1.467,2)/(calibratedValues[1]*32.167)))/calibratedValues[1];

    // Update the Understeer Gradient plot
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    ui->Suspension_Graphs_UndersteerGradient->graph(0)->addData(key,USD);
    ui->Suspension_Graphs_UndersteerGradient->graph(1)->clearData();
    ui->Suspension_Graphs_UndersteerGradient->graph(1)->addData(key,USD);
    //remove data of lines that's outside visible range:
    ui->Suspension_Graphs_UndersteerGradient->graph(0)->removeDataBefore(key-20);
    ui->Suspension_Graphs_UndersteerGradient->graph(1)->removeDataBefore(key-20);
    //rescale value (vertical) axis to fit the current data:
    ui->Suspension_Graphs_UndersteerGradient->graph(0)->rescaleValueAxis();
    ui->Suspension_Graphs_UndersteerGradient->graph(1)->rescaleValueAxis(true);

    ui->Suspension_Graphs_UndersteerGradient->xAxis->setRange(key+0.25, 20, Qt::AlignRight);
    ui->Suspension_Graphs_UndersteerGradient->yAxis->setRange(0, 5, Qt::AlignLeft); // Ask Dimitra about the range of values!!!
    ui->Suspension_Graphs_UndersteerGradient->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Suspension_Graphs_UndersteerGradient->replot();
}
