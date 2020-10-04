#ifndef MYPLOT_H
#define MYPLOT_H

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

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

private:
    QVector<QwtPlotCurve *> m_curves;


};

#endif // MYPLOT_H
