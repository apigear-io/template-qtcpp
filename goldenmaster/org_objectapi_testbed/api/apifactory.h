#pragma once

#include <QtCore>
#include "api.h"

class ORG_OBJECTAPI_TESTBED_EXPORT ApiFactory : public QObject, public ApiFactoryInterface
{
    Q_OBJECT
public:
    ApiFactory(QObject *parent=nullptr);
    static void set(ApiFactoryInterface *instance);
    static ApiFactoryInterface *get();
    virtual AbstractInterface1* createInterface1(QObject *parent);
    virtual AbstractInterface2* createInterface2(QObject *parent);
private:
    static ApiFactoryInterface *s_instance;
};
