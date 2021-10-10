#ifndef AXISCALC_H
#define AXISCALC_H

#include <vector>

class AxisCalc
{
public:
    explicit AxisCalc();
    ~AxisCalc();

    bool setDataMax(double dataMax);
    bool setDataMin(double dataMin);
    bool setGraphLen(double graphLen);

    enum AXIS_TYPE{
        AXIS_TYPE_LINEAR,
        AXIS_TYPE_LOG,
    };

    std::vector<double> getSlicePointsOnGraphLen(AxisCalc::AXIS_TYPE axisType, std::vector<int> graphPlotInterval); //軸タイプ上での、一定間隔スライス座標リストを返す.
    std::vector<double> getSpecificPointsOnGraphLen(AxisCalc::AXIS_TYPE axisType, std::vector<int> expression);     //軸タイプ上での、一定間隔スライス座標リストを返す.
};

#endif // AXISCALC_H
