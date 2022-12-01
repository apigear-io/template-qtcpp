#include "olinkfactory.h"
#include "olinksamestruct1interface.h"
#include "olinksamestruct2interface.h"
#include "olinksameenum1interface.h"
#include "olinksameenum2interface.h"

namespace tb_same1 {

OLinkFactory::OLinkFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractSameStruct1Interface* OLinkFactory::createSameStruct1Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkSameStruct1Interface(parent);
}

AbstractSameStruct2Interface* OLinkFactory::createSameStruct2Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkSameStruct2Interface(parent);
}

AbstractSameEnum1Interface* OLinkFactory::createSameEnum1Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkSameEnum1Interface(parent);
}

AbstractSameEnum2Interface* OLinkFactory::createSameEnum2Interface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkSameEnum2Interface(parent);
}

} //namespace tb_same1