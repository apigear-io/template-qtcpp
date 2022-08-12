#include "wampfactory.h"
#include "wampsamestruct1interface.h"
#include "wampsamestruct2interface.h"
#include "wampsameenum1interface.h"
#include "wampsameenum2interface.h"

WampFactory::WampFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractSameStruct1Interface* WampFactory::createSameStruct1Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampSameStruct1Interface(parent);
}

AbstractSameStruct2Interface* WampFactory::createSameStruct2Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampSameStruct2Interface(parent);
}

AbstractSameEnum1Interface* WampFactory::createSameEnum1Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampSameEnum1Interface(parent);
}

AbstractSameEnum2Interface* WampFactory::createSameEnum2Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampSameEnum2Interface(parent);
}
