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

    // Добавление кривой на график
    void addCurve(
            QwtPlotCurve::CurveStyle style,
            const QPen &pen,
            const QVector<QPointF> &values
            );
    // Установка надписи по оси Х
    void setXLabel(const QString &label);
    // Установка надписи по оси Y
    void setYLabel(const QString &label);

private:
    QVector<QwtPlotCurve *> m_curves;   // Массив кривых на графике
    QwtPlotGrid *m_grid;                // Объект сетки
    QFont m_generalFont;                // Основной шрифт текста на графике

};

#endif // MYPLOT_H
