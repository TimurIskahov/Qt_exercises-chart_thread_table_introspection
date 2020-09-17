#ifndef PLOTRANDOMWIDGET_H
#define PLOTRANDOMWIDGET_H

#include "iplot.h"
#include <QtCharts>
#include <QWidget>


class PlotRandomWidget: public IPlotRandomWidget
{
public:
    PlotRandomWidget(QWidget* parent);
    void addPoint(double y) override;
    void clear() override;

private:
    void rescaleAxsisX(double value);

    QtCharts::QLineSeries _series;
    QtCharts::QChart _chart;

    double _xCurrent = 0;
    const double _xDefaultAxsisMaximum = 100;
    double _xCurrentAxsisMaximum = _xDefaultAxsisMaximum;
};

#endif // PLOTRANDOMWIDGET_H
