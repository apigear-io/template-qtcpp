#pragma once

#include <QtCore>
#include <QtNetwork>

#include "testbed2/api/apifactory.h"

namespace testbed2 {

class HttpFactory : public QObject, public ApiFactoryInterface
{
public:
    HttpFactory(QObject *parent = nullptr);
    std::shared_ptr<AbstractManyParamInterface> createManyParamInterface(QObject *parent) override;
    std::shared_ptr<AbstractNestedStruct1Interface> createNestedStruct1Interface(QObject *parent) override;
    std::shared_ptr<AbstractNestedStruct2Interface> createNestedStruct2Interface(QObject *parent) override;
    std::shared_ptr<AbstractNestedStruct3Interface> createNestedStruct3Interface(QObject *parent) override;
private:
    QNetworkAccessManager *m_network;
};

} // namespace testbed2
