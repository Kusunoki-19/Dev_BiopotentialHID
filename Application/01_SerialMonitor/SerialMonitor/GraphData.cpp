#include "GraphData.h"

#include <QDebug>
GraphData::GraphData(QObject *parent) : QObject(parent)
{
    mpSerialReadTimer = new QTimer(this);

}

QVector2D GraphData::plotPathDots()
{
    return QVector2D(); // [#todo] 実装.
}


bool GraphData::readStart()
{

    foreach( const QSerialPortInfo info, QSerialPortInfo::availablePorts() ){
        qDebug() << "Name        :" << info.portName();
        qDebug() << "Description :" << info.description();
        qDebug() << "Manufacturer:" << info.manufacturer() << "n";
    }

    mpSerialPort = new QSerialPort(this);

    mpSerialPort->setPortName(QString("cu.usbmodem101"));
    mpSerialPort->setBaudRate(QSerialPort::Baud115200);
    mpSerialPort->setDataBits(QSerialPort::Data8);
    mpSerialPort->setParity(QSerialPort::NoParity);
    mpSerialPort->setStopBits(QSerialPort::OneStop);

    if (mpSerialPort->open(QIODevice::ReadWrite)){
        qDebug() << "Successed Open Port:" << mpSerialPort->portName();
        return true;
    } else {
        qDebug() << "Failed Open Port:" << mpSerialPort->portName();
        return false;
    }
}

bool GraphData::readStop()
{
    if(mpSerialPort->isOpen()) {
        mpSerialPort->close();
        return true;
    } else {
        return false;
    }
}

qreal GraphData::graphWidth() const
{
    return m_graphWidth;
}

void GraphData::setGraphWidth(qreal newGraphWidth)
{
    m_graphWidth = newGraphWidth;
}

qreal GraphData::graphHeight() const
{
    return m_graphHeight;
}

void GraphData::setGraphHeight(qreal newGraphHeight)
{
    m_graphHeight = newGraphHeight;
}

qreal GraphData::xMax() const
{
    return m_xMax;
}

void GraphData::setXMax(qreal newXMax)
{
    if (qFuzzyCompare(m_xMax, newXMax))
        return;
    m_xMax = newXMax;
    emit xMaxChanged();
}

qreal GraphData::xMin() const
{
    return m_xMin;
}

void GraphData::setXMin(qreal newXMin)
{
    if (qFuzzyCompare(m_xMin, newXMin))
        return;
    m_xMin = newXMin;
    emit xMinChanged();
}

qreal GraphData::yMax() const
{
    return m_yMax;
}

void GraphData::setYMax(qreal newYMax)
{
    if (qFuzzyCompare(m_yMax, newYMax))
        return;
    m_yMax = newYMax;
    emit yMaxChanged();
}

qreal GraphData::yMin() const
{
    return m_yMin;
}

void GraphData::setYMin(qreal newYMin)
{
    if (qFuzzyCompare(m_yMin, newYMin))
        return;
    m_yMin = newYMin;
    emit yMinChanged();
}

QVector<double> GraphData::_readoutPortData() 
{ 

}
