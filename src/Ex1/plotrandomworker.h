#ifndef PLOTRANDOMWORKER_H
#define PLOTRANDOMWORKER_H

#include <QThread>
#include <QPointer>
#include "iplot.h"

class PlotRandomWorker : public QThread
{
     Q_OBJECT

public:
    PlotRandomWorker(QPointer<IPlotRandomWidget> plot);
    void run() override;

private:
    static double generateRandom();
    QPointer<IPlotRandomWidget> _plot;
};

#endif // PLOTRANDOMWORKER_H
