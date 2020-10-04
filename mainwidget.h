#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "myplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    MyPlot *plot;

    QVector<QPointF> function1(double a, double b, double c, double d);
};
#endif // MAINWIDGET_H
