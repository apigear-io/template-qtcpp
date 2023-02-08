
#pragma once

#include <QtCore>
#include "iapifactory.h"

namespace tb_simple {
    class AbstractSimpleInterface;
    class AbstractSimpleArrayInterface;

/** 
* A Factory that creates an implementaion of interfaces in tb.simple.
* Factory is used by Qml versions of interface implementation to provide a backend version.
* By default this factory produces the simulation version of implementation.
* See other IApiFactory implementation.
*/
class TB_SIMPLE_API_EXPORT ApiFactory : public QObject, public IApiFactory
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
    std::shared_ptr<AbstractSimpleInterface> createSimpleInterface(QObject *parent) override;
    std::shared_ptr<AbstractSimpleArrayInterface> createSimpleArrayInterface(QObject *parent) override;
private:
    static IApiFactory *s_instance;
};

} //namespace tb_simple
