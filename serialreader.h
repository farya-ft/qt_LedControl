#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QObject>
#include <QSerialPort>

class SerialReader : public QObject
{
    Q_OBJECT
public:
    explicit SerialReader(QObject *parent = nullptr);

    Q_INVOKABLE void start(const QString &portName);
    Q_INVOKABLE void sendCommand(const QString &command);

private:
    QSerialPort *serial;
};

#endif // SERIALREADER_H