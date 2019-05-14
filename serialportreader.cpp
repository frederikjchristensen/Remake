#include "serialportreader.h"
#include <iomanip>      // std::setprecision
#include <QCoreApplication>
#include <stdlib.h>     /* atof */
#include <iostream>
#include <stdio.h>

SerialPortReader::SerialPortReader(QSerialPort *serialPort, QObject *parent) :
    QObject(parent),
    m_serialPort(serialPort),
    m_standardOutput(stdout)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialPortReader::handleReadyRead);
}



double SerialPortReader::handleReadyRead()
{
    m_readData.append(m_serialPort->readAll());
    double serial_reading=0.0;
    QString payload;

    if (pp.payload(&m_readData,&payload))
    {
        serial_reading= payload.toDouble();
        std::cout << " : " << serial_reading << std::endl;
    }
    return serial_reading;
}


