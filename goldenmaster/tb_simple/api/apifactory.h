#pragma once

#include <QtCore>
#include "api.h"

namespace tb_simple {

class TB_SIMPLE_EXPORT ApiFactory : public QObject, public ApiFactoryInterface
{
    Q_OBJECT
public:
    ApiFactory(QObject *parent=nullptr);
    static void set(ApiFactoryInterface *instance);
    static ApiFactoryInterface *get();
    virtual AbstractSimpleInterface* createSimpleInterface(QObject *parent);
    virtual AbstractSimpleArrayInterface* createSimpleArrayInterface(QObject *parent);
private:
    static ApiFactoryInterface *s_instance;
};

} //namespace tb_simple