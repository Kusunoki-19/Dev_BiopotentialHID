#ifndef GRAPHDATA_H
#define GRAPHDATA_H

#include <QObject>
#include <QVector>
#include <QVector2D>

#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>

class GraphData : public QObject
{
    Q_OBJECT
public:
    explicit GraphData(QObject *parent = nullptr);

    Q_INVOKABLE QVector2D plotPathDots();

    Q_INVOKABLE bool readStart();
    Q_INVOKABLE bool readStop();

    Q_PROPERTY(qreal graphWidth  READ graphWidth  WRITE setGraphWidth  NOTIFY graphWidthChanged )
    Q_PROPERTY(qreal graphHeight READ graphHeight WRITE setGraphHeight NOTIFY graphHeightChanged)
    Q_PROPERTY(qreal xMax READ xMax WRITE setXMax NOTIFY xMaxChanged)
    Q_PROPERTY(qreal xMin READ xMin WRITE setXMin NOTIFY xMinChanged)
    Q_PROPERTY(qreal yMax READ yMax WRITE setYMax NOTIFY yMaxChanged)
    Q_PROPERTY(qreal yMin READ yMin WRITE setYMin NOTIFY yMinChanged)


    qreal graphWidth() const;
    void setGraphWidth(qreal newGraphWidth);

    qreal graphHeight() const;
    void setGraphHeight(qreal newGraphHeight);

    qreal xMax() const;
    void setXMax(qreal newXMax);

    qreal xMin() const;
    void setXMin(qreal newXMin);

    qreal yMax() const;
    void setYMax(qreal newYMax);

    qreal yMin() const;
    void setYMin(qreal newYMin);


signals:
    void plotPathDotsChanged();
    void graphWidthChanged();
    void graphHeightChanged();
    void xMaxChanged();
    void xMinChanged();
    void yMaxChanged();
    void yMinChanged();

private: // Methods.
    QVector<double> _readoutPortData();


private: // Members.
    qreal m_graphWidth;
    qreal m_graphHeight;
    qreal m_xMax;
    qreal m_xMin;
    qreal m_yMax;
    qreal m_yMin;
    QSerialPort *mpSerialPort = nullptr;
    QTimer *mpSerialReadTimer = nullptr;
};

#endif // GRAPHDATA_H
