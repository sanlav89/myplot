#include "myplot.h"

MyPlot::MyPlot(const QString &title, QWidget *parent) :
    QwtPlot(title, parent)
{
    m_grid = new QwtPlotGrid;
    m_grid->enableXMin(true);
    m_grid->enableYMin(true);
    m_grid->enableX(false);
    m_grid->enableY(false);
    m_grid->attach(this);

    // Шрифт осей
    setAxisFont(QwtPlot::xBottom,  QFont("Helvetica", 8));
    setAxisFont(QwtPlot::yLeft,  QFont("Helvetica", 8));
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

void MyPlot::setGrid(bool xEnabled, bool yEnabled, const QPen &pen)
{
    m_grid->enableX(xEnabled);
    m_grid->enableY(yEnabled);
    m_grid->setPen(pen);
    replot();
}

void MyPlot::setXLabel(const QString &label)
{
    QwtText t;
    t.setText(label);
    t.setFont(QFont("Helvetica", 8));
    setAxisTitle(QwtPlot::xBottom, t);
}

void MyPlot::setYLabel(const QString &label)
{
    QwtText t;
    t.setText(label);
    t.setFont(QFont("Helvetica", 8));
    setAxisTitle(QwtPlot::yLeft, t);
}
