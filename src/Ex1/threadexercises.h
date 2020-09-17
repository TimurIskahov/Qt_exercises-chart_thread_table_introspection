#ifndef THREADEXERCISES_H
#define THREADEXERCISES_H

#include <QObject>
#include <QPushButton>
#include <QGroupBox>
#include <QPointer>
#include "iplot.h"
#include "plotrandomworker.h"


struct ThreadExercisesWidgets
{
    QPushButton* playButton = nullptr;
    QPushButton* pauseButton = nullptr;
    QPushButton* stopButton = nullptr;
    QGroupBox* groupBox = nullptr;
};

class ThreadExercises: public QObject
{
    Q_OBJECT

public:
    ThreadExercises(ThreadExercisesWidgets widgets, QObject *parent = nullptr);
    ~ThreadExercises();

private:
    QPointer<IPlotRandomWidget> plot = nullptr;
    QPointer<PlotRandomWorker> worker = nullptr;

private slots:
    void play();
    void pause();
    void stop();
};

#endif // THREADEXERCISES_H
