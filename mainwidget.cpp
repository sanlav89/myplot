#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <qmath.h>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    plot = new MyPlot("y = a * cos (b * x) + c * cos (d * x)", this);
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

void MainWidget::updateCurve()
{
    double a = ui->aLe->text().toDouble();
    double b = ui->bLe->text().toDouble();
    double c = ui->cLe->text().toDouble();
    double d = ui->dLe->text().toDouble();
    plot->updateCurveValues(0, function1(a, b, c, d));
}


void MainWidget::on_aLe_editingFinished()
{
    updateCurve();
}

void MainWidget::on_bLe_editingFinished()
{
    updateCurve();
}

void MainWidget::on_cLe_editingFinished()
{
    updateCurve();
}

void MainWidget::on_dLe_editingFinished()
{
    updateCurve();
}
