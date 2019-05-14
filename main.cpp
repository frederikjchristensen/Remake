#include "dialog.h"
#include <QApplication>
#include "serialportreader.h"
#include <QApplication>
#include <QCoreApplication>
#include <QSerialPort>
#include <QStringList>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    QTextStream standardOutput(stdout);
    QSerialPort serialPort;
    const QString serialPortName = "COM5";

    serialPort.setPortName(serialPortName);
    serialPort.setBaudRate(9600);

    if (!serialPort.open(QIODevice::ReadOnly)) {
        standardOutput << QObject::tr("Failed to open port %1, error: %2")
                          .arg(serialPortName)
                          .arg(serialPort.errorString())
                       << endl;

    }
    SerialPortReader serialPortReader(&serialPort);

    return a.exec();
}
