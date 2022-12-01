#include "olinkfactory.h"
#include "olinkmanyparaminterface.h"
#include "olinknestedstruct1interface.h"
#include "olinknestedstruct2interface.h"
#include "olinknestedstruct3interface.h"

namespace testbed2 {

OLinkFactory::OLinkFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractManyParamInterface* OLinkFactory::createManyParamInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkManyParamInterface(parent);
}

AbstractNestedStruct1Interface* OLinkFactory::createNestedStruct1Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkNestedStruct1Interface(parent);
}

AbstractNestedStruct2Interface* OLinkFactory::createNestedStruct2Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkNestedStruct2Interface(parent);
}

AbstractNestedStruct3Interface* OLinkFactory::createNestedStruct3Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkNestedStruct3Interface(parent);
}

} //namespace testbed2