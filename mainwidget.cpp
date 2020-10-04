#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <qmath.h>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    plot = new MyPlot("My graphic", this);
    ui->verticalLayout->addWidget(plot);

    // График функции:
//    y = a * cos (b * x) + c * cos (d * x)
    plot->addCurve(QwtPlotCurve::Lines, QPen(Qt::cyan, 0.8), function1(1, 1, 1, 1));
}

MainWidget::~MainWidget()
{
    delete ui;
}

QVector<QPointF> MainWidget::function1(double a, double b, double c, double d)
{
    QVector<QPointF> result;
    // Заполнение массива result парами x, y
    for (int i = 0; i < 1000; i++) {
        double x = 0.1 * i;
        double y = a * cos (b * x) + c * cos (d * x);
        result.append(QPointF(x, y));
    }

    return result;
}

