
#pragma once

#include <QtCore>
#include "iapifactory.h"

namespace testbed2 {
    class AbstractManyParamInterface;
    class AbstractNestedStruct1Interface;
    class AbstractNestedStruct2Interface;
    class AbstractNestedStruct3Interface;

/** 
* A static accesor for ApiFactory - a factory that creates an implementaion of interfaces in testbed2.
* It is used by Qml versions of interface implementation (instantionated in qml) to provide a backend version.
* A proper factory instance of your choice must be set. This factory by default returns empty interfaces.
* See ApiFactoryInterface implementations.
* See Qml example which uses OlinkFactory.
*/
class TESTBED2_API_EXPORT ApiFactory : public QObject, public IApiFactory
{
    Q_OBJECT
public:
    ApiFactory(QObject *parent=nullptr);
    /** 
    * Use this function to set desired version of interface implementation factory.
    * @param instance. An instance of the factory. This object doesn't take ownership of the factory instance.
    */
    static void set(IApiFactory* instance);

    /**
    * Set implementation of a factory or object of this type.
    * @return An IApiFactory implementation used to create objects.
    * WARNING Make sure a factory is set before calling ApiFactory::get(). 
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
