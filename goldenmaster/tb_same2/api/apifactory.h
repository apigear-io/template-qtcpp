#pragma once

#include <QtCore>
#include "api.h"

class TB_SAME2_EXPORT ApiFactory : public QObject, public ApiFactoryInterface
{
    Q_OBJECT
public:
    ApiFactory(QObject *parent=nullptr);
    static void set(ApiFactoryInterface *instance);
    static ApiFactoryInterface *get();
    virtual AbstractSameStruct1Interface* createSameStruct1Interface(QObject *parent);
    virtual AbstractSameStruct2Interface* createSameStruct2Interface(QObject *parent);
    virtual AbstractSameEnum1Interface* createSameEnum1Interface(QObject *parent);
    virtual AbstractSameEnum2Interface* createSameEnum2Interface(QObject *parent);
private:
    static ApiFactoryInterface *s_instance;
};
