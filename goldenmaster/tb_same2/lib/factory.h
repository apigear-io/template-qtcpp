#pragma once

#include <QtCore>

#include "tb_same2/api/apifactory.h"

namespace tb_same2 {

class Factory : public QObject, public ApiFactoryInterface
{
public:
    Factory(QObject *parent = nullptr);
    AbstractSameStruct1Interface* createSameStruct1Interface(QObject *parent) override;
    AbstractSameStruct2Interface* createSameStruct2Interface(QObject *parent) override;
    AbstractSameEnum1Interface* createSameEnum1Interface(QObject *parent) override;
    AbstractSameEnum2Interface* createSameEnum2Interface(QObject *parent) override;
};

} // namespace tb_same2

