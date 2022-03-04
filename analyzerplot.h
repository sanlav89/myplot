#ifndef ANALYZERPLOT_H
#define ANALYZERPLOT_H

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_marker.h>
#include <qwt_text.h>
#include <vector>
#include "types.h"

class AnalyzerPlot : public QwtPlot
{
    Q_OBJECT
public:
    AnalyzerPlot(const enpoly_t &enpoly = enpoly_t{0, 1}, QWidget *parent = nullptr);
    ~AnalyzerPlot();

    void updateSpectrum(const spectrum_t &spectrum);
    void updateActivities(const activities_t &activities);
    void updateNuclides(const nuclideid_t &nuclides);
    void updateEnergyScale(const enpoly_t &enpoly);

private:

    const int MaxMarkersCount = 10;

    QwtPlotCurve *m_curve;
    QwtText m_activityInfo;
    std::vector<QwtPlotMarker *> m_markers;

    std::vector<qreal> m_energyValues;
    std::vector<qreal> m_countsValues;

};

#endif // ANALYZERPLOT_H
