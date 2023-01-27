#pragma once

#include <QtCore>
#include "api.h"

namespace tb_enum {


/** 
* A Factory that creates an implementaion of interfaces in tb.enum.
* Factory is used by Qml versions of interface implementation to provide a backend version.
* By default this factory produces the simulation version of implementation.
* See other ApiFactoryInterface implementation.
*/
class TB_ENUM_EXPORT ApiFactory : public QObject, public ApiFactoryInterface
{
    Q_OBJECT
public:
    ApiFactory(QObject *parent=nullptr);
    /** 
    * Use this function to set desired version of interface implementation factory.
    * @param instance. An instance of the factory. This object doesn't take ownership of the factory instance.
    * WARNING this function may be used only once, and only before calling ApiFactory::get(). 
    */
    static void set(ApiFactoryInterface* instance);

    /**
    * Set implementation of a factory or object of this type.
    * @return An ApiFactoryInterface implementation used to create objects.
    */
    static ApiFactoryInterface *get();
    virtual AbstractEnumInterface* createEnumInterface(QObject *parent);
private:
    static ApiFactoryInterface *s_instance;
};

} //namespace tb_enum
