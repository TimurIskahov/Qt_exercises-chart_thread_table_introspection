#include "plotrandomworker.h"
#include <QThread>
#include <QRandomGenerator>
#include "random"

PlotRandomWorker::PlotRandomWorker(QPointer<IPlotRandomWidget> plot)
    :_plot(plot)
{

}

void PlotRandomWorker::run()
{
    forever
    {
        if (QThread::currentThread()->isInterruptionRequested())
            return;

        if(!_plot.isNull())
            _plot->addPoint(generateRandom());

        QThread::msleep(100);
    }
}


double PlotRandomWorker::generateRandom()
{

    std::uniform_real_distribution<> dist(1, 2.5);
    return dist(*QRandomGenerator::global());
}
