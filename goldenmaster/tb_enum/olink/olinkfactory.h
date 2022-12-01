#pragma once

#include <QtCore>

#include "tb_enum/api/apifactory.h"

namespace tb_enum {

class OLinkFactory : public QObject, public ApiFactoryInterface
{
public:
    OLinkFactory(QObject *parent = nullptr);
    AbstractEnumInterface* createEnumInterface(QObject *parent) override;
};

} //namespace tb_enum
