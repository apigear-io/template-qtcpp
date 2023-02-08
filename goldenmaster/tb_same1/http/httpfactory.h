#pragma once

#include <QtCore>
#include <QtNetwork>

#include "tb_same1/api/iapifactory.h"

namespace tb_same1 {

class HttpFactory : public QObject, public IApiFactory
{
public:
    HttpFactory(QObject *parent = nullptr);
    std::shared_ptr<AbstractSameStruct1Interface> createSameStruct1Interface(QObject *parent) override;
    std::shared_ptr<AbstractSameStruct2Interface> createSameStruct2Interface(QObject *parent) override;
    std::shared_ptr<AbstractSameEnum1Interface> createSameEnum1Interface(QObject *parent) override;
    std::shared_ptr<AbstractSameEnum2Interface> createSameEnum2Interface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};

} // namespace tb_same1
