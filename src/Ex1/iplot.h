#ifndef IPLOT_H
#define IPLOT_H

#include <QWidget>

class IPlotRandomWidget : public QWidget
{
public:
    IPlotRandomWidget(QWidget *parent)
        :QWidget(parent){}

    //virtual ~IPlotRandomWidget(){}
    virtual void addPoint(double y) = 0;
    virtual void clear() = 0 ;
};

#endif // IPLOT_H
