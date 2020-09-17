#include "threadexercises.h"
#include <QDebug>
#include "plotrandomwidget.h"
#include "plotrandomworker.h"

ThreadExercises::ThreadExercises(ThreadExercisesWidgets widgets, QObject *parent)
    :QObject(parent)
{
    plot =new PlotRandomWidget(widgets.groupBox);

    connect(widgets.playButton, &QPushButton::clicked, this, &ThreadExercises::play);
    connect(widgets.pauseButton, &QPushButton::clicked, this, &ThreadExercises::pause);
    connect(widgets.stopButton, &QPushButton::clicked, this, &ThreadExercises::stop);

}

ThreadExercises::~ThreadExercises()
{
    if(!worker.isNull())
    {
        worker->requestInterruption();
        worker->wait();
    }
    qDebug()<<"ThreadExercises will be deleted";
}

void ThreadExercises::play()
{
    if(!worker.isNull())
        return;

    worker = new PlotRandomWorker(plot);
    connect(worker, &PlotRandomWorker::finished, worker, &QObject::deleteLater);
    worker->start();
}

void ThreadExercises::pause()
{
    if(worker.isNull())
        return;

    worker->requestInterruption();
}

void ThreadExercises::stop()
{
    if(!worker.isNull())
        pause();

    plot->clear();
}
