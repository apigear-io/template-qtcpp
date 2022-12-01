#pragma once

#include <QtCore>
#include "api.h"

namespace testbed2 {

class TESTBED2_EXPORT ApiFactory : public QObject, public ApiFactoryInterface
{
    Q_OBJECT
public:
    ApiFactory(QObject *parent=nullptr);
    static void set(ApiFactoryInterface *instance);
    static ApiFactoryInterface *get();
    virtual AbstractManyParamInterface* createManyParamInterface(QObject *parent);
    virtual AbstractNestedStruct1Interface* createNestedStruct1Interface(QObject *parent);
    virtual AbstractNestedStruct2Interface* createNestedStruct2Interface(QObject *parent);
    virtual AbstractNestedStruct3Interface* createNestedStruct3Interface(QObject *parent);
private:
    static ApiFactoryInterface *s_instance;
};

} //namespace testbed2