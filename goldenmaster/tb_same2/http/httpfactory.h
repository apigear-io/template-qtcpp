#pragma once

#include <QtCore>
#include <QtNetwork>

#include "tb_same2/api/apifactory.h"

namespace tb_same2 {

class HttpFactory : public QObject, public ApiFactoryInterface
{
public:
    HttpFactory(QObject *parent = nullptr);
    AbstractSameStruct1Interface* createSameStruct1Interface(QObject *parent) override;
    AbstractSameStruct2Interface* createSameStruct2Interface(QObject *parent) override;
    AbstractSameEnum1Interface* createSameEnum1Interface(QObject *parent) override;
    AbstractSameEnum2Interface* createSameEnum2Interface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};

} // namespace tb_same2
