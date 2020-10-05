#include "myplot.h"

MyPlot::MyPlot(const QString &title, QWidget *parent) :
    QwtPlot(title, parent),
    m_generalFont(QFont("Helvetica", 10))
{
    // Шрифт осей
    setAxisFont(QwtPlot::xBottom,  m_generalFont);
    setAxisFont(QwtPlot::yLeft, m_generalFont);

    // Фон
    QPalette pal;
    pal.setBrush(QPalette::Window, QBrush(QColor(50, 50, 100)));
    setPalette(pal);

    // Сетка
    m_grid = new QwtPlotGrid;
    m_grid->enableXMin(true);
    m_grid->enableYMin(true);
    m_grid->enableX(false);
    m_grid->enableY(false);
    m_grid->attach(this);
}

MyPlot::~MyPlot()
{

}

// Добавление кривой на график
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

// Обновление данных кривой под номером curveId
void MyPlot::updateCurveValues(int curveId, const QVector<QPointF> &values)
{
    m_curves[curveId]->setSamples(values);
    replot();
}

// Включение / выклчение отбражения сетки на графике
void MyPlot::setGrid(bool xEnabled, bool yEnabled, const QPen &pen)
{
    m_grid->enableX(xEnabled);
    m_grid->enableY(yEnabled);
    m_grid->setPen(pen);
    replot();
}

// Установка надписи по оси Х
void MyPlot::setXLabel(const QString &label)
{
    QwtText t;
    t.setText(label);
    t.setFont(m_generalFont);
    setAxisTitle(QwtPlot::xBottom, t);
}

// Установка надписи по оси Y
void MyPlot::setYLabel(const QString &label)
{
    QwtText t;
    t.setText(label);
    t.setFont(m_generalFont);
    setAxisTitle(QwtPlot::yLeft, t);
}
