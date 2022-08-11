#include "olinkfactory.h"
#include "olinkinterface1.h"
#include "olinkinterface2.h"

OLinkFactory::OLinkFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractInterface1* OLinkFactory::createInterface1(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkInterface1(parent);
}

AbstractInterface2* OLinkFactory::createInterface2(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkInterface2(parent);
}
