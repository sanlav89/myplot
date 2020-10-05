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

    // Методы установки/изменения информации на графике

    // Добавление кривой на график
    void addCurve(
            QwtPlotCurve::CurveStyle style,
            const QPen &pen,
            const QVector<QPointF> &values
            );
    // Обновление данных кривой под номером curveId
    void updateCurveValues(int curveId, const QVector<QPointF> &values);
    // Включение / выклчение отбражения сетки на графике
    void setGrid(bool xEnabled, bool yEnabled, const QPen &pen);
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
