#include "serialreader.h"
#include <QDebug>

SerialReader::SerialReader(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
}

void SerialReader::start(const QString &portName)
{
    if (serial->isOpen())
        serial->close();

    serial->setPortName(portName);
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    qDebug() << "Trying to open port:" << portName;

    if (serial->open(QIODevice::ReadWrite)) {
        qDebug() << "✅ Serial port opened.";
    } else {
        qDebug() << "❌ Failed to open port:" << serial->errorString();
    }
}

void SerialReader::sendCommand(const QString &command)
{
    if (serial->isOpen()) {
        serial->write(command.toUtf8());
        qDebug() << "📤 Sent command:" << command;
    } else {
        qDebug() << "⚠️ Serial port is not open!";
    }
}