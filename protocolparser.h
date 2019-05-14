#ifndef PROTOCOLPARSER_H
#define PROTOCOLPARSER_H
#include <QByteArray>
#include <QTextStream>

class protocolParser
{
public:
    int payload(QByteArray *readData, QString *payload);
};

#endif // PROTOCOLPARSER_H
