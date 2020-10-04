#include "myplot.h"

MyPlot::MyPlot(const QString &title, QWidget *parent) :
    QwtPlot(title, parent)
{

}

MyPlot::~MyPlot()
{

}

void MyPlot::addCurve(
        QwtPlotCurve::CurveStyle style,
        const QPen &pen,
        const QVector<QPointF> &values
        )
{
    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setStyle(style);
    curve->setPen(pen);
    curve->setSamples(values);
    curve->attach(this);
    m_curves.append(curve);
    replot();
}

void MyPlot::updateCurveValues(int curveId, const QVector<QPointF> &values)
{
    m_curves[curveId]->setSamples(values);
    replot();
}
