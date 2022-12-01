#include "olinkfactory.h"
#include "olinksimpleinterface.h"
#include "olinksimplearrayinterface.h"

namespace tb_simple {

OLinkFactory::OLinkFactory(QObject *parent)
    : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

AbstractSimpleInterface* OLinkFactory::createSimpleInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkSimpleInterface(parent);
}

AbstractSimpleArrayInterface* OLinkFactory::createSimpleArrayInterface(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    return new OLinkSimpleArrayInterface(parent);
}

} //namespace tb_simple