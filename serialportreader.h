#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QByteArray>
#include <QSerialPort>
#include <QtSerialPort/QSerialPort>

#include <QTextStream>
#include <QTimer>
#include "protocolparser.h"

class SerialPortReader : public QObject
{
    Q_OBJECT

public:
    explicit SerialPortReader(QSerialPort *serialPort, QObject *parent = (QObject *)0);

private slots:
    double handleReadyRead();

private:
    QSerialPort *m_serialPort = (QSerialPort *)0;
    QByteArray m_readData;
    QTextStream m_standardOutput;
    protocolParser pp;

};

#endif // SERIALPORTREADER_H
