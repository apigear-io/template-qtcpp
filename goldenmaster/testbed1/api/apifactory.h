#pragma once

#include <QtCore>
#include "api.h"

class TESTBED1_EXPORT ApiFactory : public QObject, public ApiFactoryInterface
{
    Q_OBJECT
public:
    ApiFactory(QObject *parent=nullptr);
    static void set(ApiFactoryInterface *instance);
    static ApiFactoryInterface *get();
    virtual AbstractStructInterface* createStructInterface(QObject *parent);
    virtual AbstractStructArrayInterface* createStructArrayInterface(QObject *parent);
private:
    static ApiFactoryInterface *s_instance;
};
