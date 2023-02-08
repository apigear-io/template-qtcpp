
#pragma once

#include <QtCore>
#include "iapifactory.h"

namespace tb_enum {
    class AbstractEnumInterface;

/** 
* A Factory that creates an implementaion of interfaces in tb.enum.
* Factory is used by Qml versions of interface implementation to provide a backend version.
* By default this factory produces the simulation version of implementation.
* See other IApiFactory implementation.
*/
class TB_ENUM_API_EXPORT ApiFactory : public QObject, public IApiFactory
{
    Q_OBJECT
public:
    ApiFactory(QObject *parent=nullptr);
    /** 
    * Use this function to set desired version of interface implementation factory.
    * @param instance. An instance of the factory. This object doesn't take ownership of the factory instance.
    * WARNING this function may be used only once, and only before calling ApiFactory::get(). 
    */
    static void set(IApiFactory* instance);

    /**
    * Set implementation of a factory or object of this type.
    * @return An IApiFactory implementation used to create objects.
    */
    static IApiFactory *get();
    std::shared_ptr<AbstractEnumInterface> createEnumInterface(QObject *parent) override;
private:
    static IApiFactory *s_instance;
};

} //namespace tb_enum
