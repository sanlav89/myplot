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

private slots:
    void on_aLe_editingFinished();

    void on_bLe_editingFinished();

    void on_cLe_editingFinished();

    void on_dLe_editingFinished();

    void on_xGridChB_toggled(bool);

    void on_yGridChb_toggled(bool);

private:
    Ui::MainWidget *ui;
    MyPlot *plot;

    QVector<QPointF> function1(double a, double b, double c, double d);
    void updateCurve();
};
#endif // MAINWIDGET_H
