#include "plotrandomwidget.h"

PlotRandomWidget::PlotRandomWidget(QWidget* parent)
    :IPlotRandomWidget (parent)
{
    QChartView *chartView = new QChartView(&_chart);
    _chart.addSeries(&_series);

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, _xDefaultAxsisMaximum);
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 4);
    //_chart.addAxis(axisX, Qt::AlignBottom);
    //_chart.addAxis(axisY, Qt::AlignLeft);
    _chart.setAxisX(axisX, &_series);
    _chart.setAxisY(axisY, &_series);
    _chart.legend()->hide();

    QHBoxLayout *mainLayout = new QHBoxLayout(parent);
    mainLayout->addWidget(chartView);
}

void PlotRandomWidget::addPoint(double y)
{
    _series.append(_xCurrent, y);
    //если текущее значение по оси X стало больше, чем Xscale перерисуем шкалу
    if(_xCurrent >= _xCurrentAxsisMaximum)
    {
        _xCurrentAxsisMaximum = _xCurrent + _xDefaultAxsisMaximum;
        rescaleAxsisX(_xCurrentAxsisMaximum);
    }

    const double xStep = 1;
    _xCurrent +=xStep;
}

void PlotRandomWidget::clear()
{
    _series.clear();
    _xCurrent = 0;


    _xCurrentAxsisMaximum = _xDefaultAxsisMaximum;
    rescaleAxsisX(_xCurrentAxsisMaximum);

}

void PlotRandomWidget::rescaleAxsisX(double value)
{
     _chart.axisX()->setRange(0., value);
}
