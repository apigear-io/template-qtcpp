#pragma once

#include <QtCore>
#include "api.h"

class TB_ENUM_EXPORT ApiFactory : public QObject, public ApiFactoryInterface
{
    Q_OBJECT
public:
    ApiFactory(QObject *parent=nullptr);
    static void set(ApiFactoryInterface *instance);
    static ApiFactoryInterface *get();
    virtual AbstractEnumInterface* createEnumInterface(QObject *parent);
private:
    static ApiFactoryInterface *s_instance;
};
