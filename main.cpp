#ifdef __QT__ON__
#include <QCoreApplication>
#endif

#ifndef __QT__ON__
#define qDebug() std::cout << std::endl
#endif

#include "protocoler.h"
#include <iostream>

int main(int argc, char *argv[])
{

#ifdef __QT__ON__
    QCoreApplication a(argc, argv);
#endif

    Protocoler protocol;

    protocol.insert("Hello from client");

    qDebug() << protocol.getBLock();

    if (protocol.checkFull("12\nqaswedfrtghy"))
    {
        qDebug() << "Full block";
    }

    protocol.clear();

    protocol.insert("Hello from server");

    qDebug() << protocol.getBLock();

    if (protocol.checkFull("12\nqaswedfrtghy"))
    {
        qDebug() << "Full block";
    }

#ifdef __QT__ON__
    return a.exec();
#else
    return 0;
#endif
}
