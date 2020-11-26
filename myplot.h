#ifndef MYPLOT_H
#define MYPLOT_H

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include "myzoomer.h"

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
            const QVector<QPointF> &values = QVector<QPointF>()
            );
    // Включение / выклчение отбражения сетки на графике
    void setGrid(bool xEnabled, bool yEnabled, const QPen &pen);
    // Установка надписи по оси Х
    void setXLabel(const QString &label);
    // Установка надписи по оси Y
    void setYLabel(const QString &label);
    // Обновление данных кривой под номером curveId
    void updateCurveValues(int curveId, const QVector<QPointF> &values);

protected:
    QVector<QwtPlotCurve *> m_curves;   // Массив кривых на графике
    QwtPlotGrid *m_grid;                // Объект сетки
    QFont m_generalFont;                // Основной шрифт текста на графике
    MyZoomer *zoomer;

    qreal m_xmax;
    qreal m_xmin;
    qreal m_ymax;
    qreal m_ymin;

    virtual void wheelEvent(QWheelEvent *e) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *e) override;

};

#endif // MYPLOT_H
