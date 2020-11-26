#include "myplot.h"
#include <QWheelEvent>
#include <QMouseEvent>

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

    // Зумер
    zoomer = new MyZoomer(this->canvas());
    zoomer->setRubberBandPen(QPen(Qt::white));
    zoomer->setTrackerPen(QPen(Qt::white));
    zoomer->setTrackerFont(m_generalFont);
    zoomer->setMousePattern(QwtEventPattern::MouseSelect1, Qt::LeftButton);
    zoomer->setMousePattern(QwtEventPattern::MouseSelect2, Qt::NoButton);
    zoomer->setMousePattern(QwtEventPattern::MouseSelect3, Qt::NoButton);
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
    curve->attach(this);
    m_curves.append(curve);
    updateCurveValues(m_curves.size() - 1, values);
}

// Обновление данных кривой под номером curveId
void MyPlot::updateCurveValues(int curveId, const QVector<QPointF> &values)
{
    m_curves[curveId]->setSamples(values);
    replot();

    if (m_curves.size() > 0) {
        m_xmin = m_curves[0]->minXValue();
        m_xmax = m_curves[0]->maxXValue();
        for (int i = 0; i < m_curves.size(); i++) {
            if (m_curves[i]->minXValue() < m_xmin) {
                m_xmin = m_curves[i]->minXValue();
            }
            if (m_curves[i]->maxXValue() > m_xmax) {
                m_xmax = m_curves[i]->maxXValue();
            }
        }
        m_ymin = axisScaleDiv(QwtPlot::yLeft).lowerBound();
        m_ymax = axisScaleDiv(QwtPlot::yLeft).upperBound();
    }

}

// Включение / выклчение отбражения сетки на графике
void MyPlot::setGrid(bool xEnabled, bool yEnabled, const QPen &pen)
{
    m_grid->enableX(xEnabled);
    m_grid->enableY(yEnabled);
    m_grid->setPen(pen);
    replot();
}

// Скроллинг
void MyPlot::wheelEvent(QWheelEvent *e)
{
    double xmin = axisScaleDiv(QwtPlot::xBottom).lowerBound();
    double xmax = axisScaleDiv(QwtPlot::xBottom).upperBound();
    double ymin = axisScaleDiv(QwtPlot::yLeft).lowerBound();
    double ymax = axisScaleDiv(QwtPlot::yLeft).upperBound();
    double delta;

    if (e->modifiers() == Qt::ShiftModifier) {
        delta = (xmax - xmin) * 0.001 * e->angleDelta().y();
        xmin += delta;
        xmax += delta;
        if (xmin < m_xmin) {
            xmax -= delta;
            xmin = m_xmin;
        }
        if (xmax > m_xmax) {
            xmin -= delta;
            xmax = m_xmax;
        }
    } else if (e->modifiers() == Qt::ControlModifier) {
        delta = (xmax - xmin) * 0.001 * e->angleDelta().y();
        xmin += delta;
        xmax -= delta;
        if (xmin < m_xmin) {
            xmin = m_xmin;
        }
        if (xmax > m_xmax) {
            xmax = m_xmax;
        }
    } else if (e->modifiers() == Qt::AltModifier) {
        delta = (ymax - ymin) * 0.001 * e->angleDelta().x();
        ymax += delta;
        ymin += delta;
        if (ymin < m_ymin) {
            ymax -= delta;
            ymin = m_ymin;
        }
        if (ymax > m_ymax) {
            ymin -= delta;
            ymax = m_ymax;
        }
    } else {
        delta = (ymax - ymin) * 0.001 * e->angleDelta().y();
        ymax += delta;
        ymin -= delta;
        if (ymin < m_ymin) {
            ymin = m_ymin;
        }
        if (ymax > m_ymax) {
            ymax = m_ymax;
        }
    }

    setAxisScale(QwtPlot::xBottom, xmin, xmax);
    setAxisScale(QwtPlot::yLeft, ymin, ymax);
    replot();
}

// Возврат к полной картинке по двойному щелчку
void MyPlot::mouseDoubleClickEvent(QMouseEvent *e)
{
    if ( e->button() == Qt::LeftButton ) {
        setAxisScale(QwtPlot::xBottom, m_xmin, m_xmax);
        setAxisScale(QwtPlot::yLeft, m_ymin, m_ymax);
        replot();
    }
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
