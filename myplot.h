#ifndef MYPLOT_H
#define MYPLOT_H

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>

class MyPlot : public QwtPlot
{
    Q_OBJECT
public:
    MyPlot(const QString &title, QWidget *parent = nullptr);
    ~MyPlot();

    void addCurve(
            QwtPlotCurve::CurveStyle style,
            const QPen &pen,
            const QVector<QPointF> &values
            );

    void updateCurveValues(int curveId, const QVector<QPointF> &values);
    void setGrid(bool xEnabled, bool yEnabled, const QPen &pen);

private:
    QVector<QwtPlotCurve *> m_curves;
    QwtPlotGrid *m_grid;

};

#endif // MYPLOT_H
