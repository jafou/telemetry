#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>


//Initialize ALL the GUI's graphs

void MainWindow::graphsInitialisation(){
    //Initialize the graphs of the General Tab
    ui->General_Graphs_EngineRPM->addGraph(); // blue line
    ui->General_Graphs_EngineRPM->graph(0)->setPen(QPen(Qt::blue));
    ui->General_Graphs_EngineRPM->addGraph(); // blue dot
    ui->General_Graphs_EngineRPM->graph(1)->setPen(QPen(Qt::blue));
    ui->General_Graphs_EngineRPM->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->General_Graphs_EngineRPM->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->General_Graphs_EngineRPM->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->General_Graphs_EngineRPM->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->General_Graphs_EngineRPM->xAxis->setAutoTickStep(false);
    ui->General_Graphs_EngineRPM->xAxis->setTickStep(4);
    ui->General_Graphs_EngineRPM->axisRect()->setupFullAxesBox();
    ui->General_Graphs_EngineRPM->xAxis->setLabel("Time");
    ui->General_Graphs_EngineRPM->yAxis->setLabel("RPM");

    ui->General_Graphs_ThrottlePos->addGraph(); // magenta line
    ui->General_Graphs_ThrottlePos->graph(0)->setPen(QPen(Qt::magenta));
    ui->General_Graphs_ThrottlePos->addGraph(); // magenta dot
    ui->General_Graphs_ThrottlePos->graph(1)->setPen(QPen(Qt::magenta));
    ui->General_Graphs_ThrottlePos->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->General_Graphs_ThrottlePos->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->General_Graphs_ThrottlePos->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->General_Graphs_ThrottlePos->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->General_Graphs_ThrottlePos->xAxis->setAutoTickStep(false);
    ui->General_Graphs_ThrottlePos->xAxis->setTickStep(4);
    ui->General_Graphs_ThrottlePos->axisRect()->setupFullAxesBox();
    ui->General_Graphs_ThrottlePos->xAxis->setLabel("Time");
    ui->General_Graphs_ThrottlePos->yAxis->setLabel("%");

    //Initialize the graphs of the Engine Tab
    ui->Engine_Graphs_EngineTemp->addGraph(); // magenta line
    ui->Engine_Graphs_EngineTemp->graph(0)->setPen(QPen(Qt::magenta));
    ui->Engine_Graphs_EngineTemp->addGraph(); // magenta dot
    ui->Engine_Graphs_EngineTemp->graph(1)->setPen(QPen(Qt::magenta));
    ui->Engine_Graphs_EngineTemp->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->Engine_Graphs_EngineTemp->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->Engine_Graphs_EngineTemp->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Engine_Graphs_EngineTemp->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->Engine_Graphs_EngineTemp->xAxis->setAutoTickStep(false);
    ui->Engine_Graphs_EngineTemp->xAxis->setTickStep(4);
    ui->Engine_Graphs_EngineTemp->axisRect()->setupFullAxesBox();
    ui->Engine_Graphs_EngineTemp->xAxis->setLabel("Time");
    ui->Engine_Graphs_EngineTemp->yAxis->setLabel("Temperature");

    ui->Engine_Graphs_OilPressure->addGraph(); // magenta line
    ui->Engine_Graphs_OilPressure->graph(0)->setPen(QPen(Qt::magenta));
    ui->Engine_Graphs_OilPressure->addGraph(); // magenta dot
    ui->Engine_Graphs_OilPressure->graph(1)->setPen(QPen(Qt::magenta));
    ui->Engine_Graphs_OilPressure->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->Engine_Graphs_OilPressure->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->Engine_Graphs_OilPressure->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Engine_Graphs_OilPressure->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->Engine_Graphs_OilPressure->xAxis->setAutoTickStep(false);
    ui->Engine_Graphs_OilPressure->xAxis->setTickStep(4);
    ui->Engine_Graphs_OilPressure->axisRect()->setupFullAxesBox();
    ui->Engine_Graphs_OilPressure->xAxis->setLabel("Time");
    ui->Engine_Graphs_OilPressure->yAxis->setLabel("Pressure");

    ui->Engine_Graphs_FuelPressure->addGraph(); // magenta line
    ui->Engine_Graphs_FuelPressure->graph(0)->setPen(QPen(Qt::magenta));
    ui->Engine_Graphs_FuelPressure->addGraph(); // magenta dot
    ui->Engine_Graphs_FuelPressure->graph(1)->setPen(QPen(Qt::magenta));
    ui->Engine_Graphs_FuelPressure->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->Engine_Graphs_FuelPressure->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->Engine_Graphs_FuelPressure->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Engine_Graphs_FuelPressure->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->Engine_Graphs_FuelPressure->xAxis->setAutoTickStep(false);
    ui->Engine_Graphs_FuelPressure->xAxis->setTickStep(4);
    ui->Engine_Graphs_FuelPressure->axisRect()->setupFullAxesBox();
    ui->Engine_Graphs_FuelPressure->xAxis->setLabel("Time");
    ui->Engine_Graphs_FuelPressure->yAxis->setLabel("Pressure");

    //Initialize the graphs of the Fuel Tab
    ui->Fuel_Graphs_MAP->addGraph(); // blue line
    ui->Fuel_Graphs_MAP->graph(0)->setPen(QPen(Qt::blue));
    ui->Fuel_Graphs_MAP->addGraph(); // blue dot
    ui->Fuel_Graphs_MAP->graph(1)->setPen(QPen(Qt::blue));
    ui->Fuel_Graphs_MAP->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->Fuel_Graphs_MAP->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->Fuel_Graphs_MAP->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Fuel_Graphs_MAP->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->Fuel_Graphs_MAP->xAxis->setAutoTickStep(false);
    ui->Fuel_Graphs_MAP->xAxis->setTickStep(4);
    ui->Fuel_Graphs_MAP->axisRect()->setupFullAxesBox();
    ui->Fuel_Graphs_MAP->xAxis->setLabel("Time");
    ui->Fuel_Graphs_MAP->yAxis->setLabel("Pressure");

    ui->Fuel_Graphs_FuelPressure->addGraph(); // blue line
    ui->Fuel_Graphs_FuelPressure->graph(0)->setPen(QPen(Qt::blue));
    ui->Fuel_Graphs_FuelPressure->addGraph(); // blue dot
    ui->Fuel_Graphs_FuelPressure->graph(1)->setPen(QPen(Qt::blue));
    ui->Fuel_Graphs_FuelPressure->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->Fuel_Graphs_FuelPressure->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->Fuel_Graphs_FuelPressure->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Fuel_Graphs_FuelPressure->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->Fuel_Graphs_FuelPressure->xAxis->setAutoTickStep(false);
    ui->Fuel_Graphs_FuelPressure->xAxis->setTickStep(4);
    ui->Fuel_Graphs_FuelPressure->axisRect()->setupFullAxesBox();
    ui->Fuel_Graphs_FuelPressure->xAxis->setLabel("Time");
    ui->Fuel_Graphs_FuelPressure->yAxis->setLabel("Pressure");

    ui->Fuel_Graphs_Lambda->addGraph(); // blue line
    ui->Fuel_Graphs_Lambda->graph(0)->setPen(QPen(Qt::blue));
    ui->Fuel_Graphs_Lambda->addGraph(); // blue dot
    ui->Fuel_Graphs_Lambda->graph(1)->setPen(QPen(Qt::blue));
    ui->Fuel_Graphs_Lambda->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->Fuel_Graphs_Lambda->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->Fuel_Graphs_Lambda->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Fuel_Graphs_Lambda->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->Fuel_Graphs_Lambda->xAxis->setAutoTickStep(false);
    ui->Fuel_Graphs_Lambda->xAxis->setTickStep(4);
    ui->Fuel_Graphs_Lambda->axisRect()->setupFullAxesBox();
    ui->Fuel_Graphs_Lambda->xAxis->setLabel("Time");
    ui->Fuel_Graphs_Lambda->yAxis->setLabel("Lambda");

    // Initialise the graphs of the Suspension Tab
    ui->Suspension_Graphs_PotFL->addGraph(); // blue line
    ui->Suspension_Graphs_PotFL->graph(0)->setPen(QPen(Qt::blue));
    ui->Suspension_Graphs_PotFL->addGraph(); // blue dot
    ui->Suspension_Graphs_PotFL->graph(1)->setPen(QPen(Qt::blue));
    ui->Suspension_Graphs_PotFL->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->Suspension_Graphs_PotFL->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->Suspension_Graphs_PotFL->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Suspension_Graphs_PotFL->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->Suspension_Graphs_PotFL->xAxis->setAutoTickStep(false);
    ui->Suspension_Graphs_PotFL->xAxis->setTickStep(4);
    ui->Suspension_Graphs_PotFL->axisRect()->setupFullAxesBox();
    ui->Suspension_Graphs_PotFL->xAxis->setLabel("Time");
    ui->Suspension_Graphs_PotFL->yAxis->setLabel("Lambda");

    ui->Suspension_Graphs_PotFR->addGraph(); // blue line
    ui->Suspension_Graphs_PotFR->graph(0)->setPen(QPen(Qt::blue));
    ui->Suspension_Graphs_PotFR->addGraph(); // blue dot
    ui->Suspension_Graphs_PotFR->graph(1)->setPen(QPen(Qt::blue));
    ui->Suspension_Graphs_PotFR->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->Suspension_Graphs_PotFR->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->Suspension_Graphs_PotFR->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Suspension_Graphs_PotFR->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->Suspension_Graphs_PotFR->xAxis->setAutoTickStep(false);
    ui->Suspension_Graphs_PotFR->xAxis->setTickStep(4);
    ui->Suspension_Graphs_PotFR->axisRect()->setupFullAxesBox();
    ui->Suspension_Graphs_PotFR->xAxis->setLabel("Time");
    ui->Suspension_Graphs_PotFR->yAxis->setLabel("Lambda");

    ui->Suspension_Graphs_PotRR->addGraph(); // blue line
    ui->Suspension_Graphs_PotRR->graph(0)->setPen(QPen(Qt::blue));
    ui->Suspension_Graphs_PotRR->addGraph(); // blue dot
    ui->Suspension_Graphs_PotRR->graph(1)->setPen(QPen(Qt::blue));
    ui->Suspension_Graphs_PotRR->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->Suspension_Graphs_PotRR->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->Suspension_Graphs_PotRR->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Suspension_Graphs_PotRR->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->Suspension_Graphs_PotRR->xAxis->setAutoTickStep(false);
    ui->Suspension_Graphs_PotRR->xAxis->setTickStep(4);
    ui->Suspension_Graphs_PotRR->axisRect()->setupFullAxesBox();
    ui->Suspension_Graphs_PotRR->xAxis->setLabel("Time");
    ui->Suspension_Graphs_PotRR->yAxis->setLabel("Lambda");

    ui->Suspension_Graphs_PotRL->addGraph(); // blue line
    ui->Suspension_Graphs_PotRL->graph(0)->setPen(QPen(Qt::blue));
    ui->Suspension_Graphs_PotRL->addGraph(); // blue dot
    ui->Suspension_Graphs_PotRL->graph(1)->setPen(QPen(Qt::blue));
    ui->Suspension_Graphs_PotRL->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->Suspension_Graphs_PotRL->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->Suspension_Graphs_PotRL->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Suspension_Graphs_PotRL->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->Suspension_Graphs_PotRL->xAxis->setAutoTickStep(false);
    ui->Suspension_Graphs_PotRL->xAxis->setTickStep(4);
    ui->Suspension_Graphs_PotRL->axisRect()->setupFullAxesBox();
    ui->Suspension_Graphs_PotRL->xAxis->setLabel("Time");
    ui->Suspension_Graphs_PotRL->yAxis->setLabel("Lambda");

    ui->Suspension_Graphs_GGDiagram->addGraph();
    ui->Suspension_Graphs_GGDiagram->graph(0)->setPen(QPen(Qt::red));
    ui->Suspension_Graphs_GGDiagram->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->Suspension_Graphs_GGDiagram->graph(0)->setScatterStyle(QCPScatterStyle::ssCrossCircle);

    ui->Suspension_Graphs_GGDiagram->axisRect()->setupFullAxesBox();
    ui->Suspension_Graphs_GGDiagram->xAxis->setLabel("Longtitudinal");
    ui->Suspension_Graphs_GGDiagram->yAxis->setLabel("Lateral");

    ui->Suspension_Graphs_UndersteerGradient->addGraph(); // blue line
    ui->Suspension_Graphs_UndersteerGradient->graph(0)->setPen(QPen(Qt::blue));
    ui->Suspension_Graphs_UndersteerGradient->addGraph(); // blue dot
    ui->Suspension_Graphs_UndersteerGradient->graph(1)->setPen(QPen(Qt::blue));
    ui->Suspension_Graphs_UndersteerGradient->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->Suspension_Graphs_UndersteerGradient->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->Suspension_Graphs_UndersteerGradient->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Suspension_Graphs_UndersteerGradient->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->Suspension_Graphs_UndersteerGradient->xAxis->setAutoTickStep(false);
    ui->Suspension_Graphs_UndersteerGradient->xAxis->setTickStep(4);
    ui->Suspension_Graphs_UndersteerGradient->axisRect()->setupFullAxesBox();
    ui->Suspension_Graphs_UndersteerGradient->xAxis->setLabel("Time");
    ui->Suspension_Graphs_UndersteerGradient->yAxis->setLabel("k");
}
