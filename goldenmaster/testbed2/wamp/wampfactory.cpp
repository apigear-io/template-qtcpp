#include "wampfactory.h"
#include "wampmanyparaminterface.h"
#include "wampnestedstruct1interface.h"
#include "wampnestedstruct2interface.h"
#include "wampnestedstruct3interface.h"

WampFactory::WampFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractManyParamInterface* WampFactory::createManyParamInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampManyParamInterface(parent);
}

AbstractNestedStruct1Interface* WampFactory::createNestedStruct1Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampNestedStruct1Interface(parent);
}

AbstractNestedStruct2Interface* WampFactory::createNestedStruct2Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampNestedStruct2Interface(parent);
}

AbstractNestedStruct3Interface* WampFactory::createNestedStruct3Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new WampNestedStruct3Interface(parent);
}
