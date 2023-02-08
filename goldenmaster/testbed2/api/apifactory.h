
#pragma once

#include <QtCore>
#include "iapifactory.h"

namespace testbed2 {
    class AbstractManyParamInterface;
    class AbstractNestedStruct1Interface;
    class AbstractNestedStruct2Interface;
    class AbstractNestedStruct3Interface;

/** 
* A Factory that creates an implementaion of interfaces in testbed2.
* Factory is used by Qml versions of interface implementation to provide a backend version.
* By default this factory produces the simulation version of implementation.
* See other IApiFactory implementation.
*/
class TESTBED2_API_EXPORT ApiFactory : public QObject, public IApiFactory
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
    std::shared_ptr<AbstractManyParamInterface> createManyParamInterface(QObject *parent) override;
    std::shared_ptr<AbstractNestedStruct1Interface> createNestedStruct1Interface(QObject *parent) override;
    std::shared_ptr<AbstractNestedStruct2Interface> createNestedStruct2Interface(QObject *parent) override;
    std::shared_ptr<AbstractNestedStruct3Interface> createNestedStruct3Interface(QObject *parent) override;
private:
    static IApiFactory *s_instance;
};

} //namespace testbed2
