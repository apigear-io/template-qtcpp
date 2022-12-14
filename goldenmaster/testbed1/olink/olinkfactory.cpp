#include "olinkfactory.h"
#include "olinkstructinterface.h"
#include "olinkstructarrayinterface.h"

namespace testbed1 {

OLinkFactory::OLinkFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractStructInterface* OLinkFactory::createStructInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkStructInterface(parent);
}

AbstractStructArrayInterface* OLinkFactory::createStructArrayInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkStructArrayInterface(parent);
}

} //namespace testbed1