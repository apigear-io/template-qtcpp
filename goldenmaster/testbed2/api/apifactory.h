#pragma once

#include <QtCore>
#include "api.h"

namespace testbed2 {


/** 
* A Factory that creates an implementaion of interfaces in testbed2.
* Factory is used by Qml versions of interface implementation to provide a backend version.
* By default this factory produces the simulation version of implementation.
* See other ApiFactoryInterface implementation.
*/
class TESTBED2_EXPORT ApiFactory : public QObject, public ApiFactoryInterface
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
    virtual AbstractManyParamInterface* createManyParamInterface(QObject *parent);
    virtual AbstractNestedStruct1Interface* createNestedStruct1Interface(QObject *parent);
    virtual AbstractNestedStruct2Interface* createNestedStruct2Interface(QObject *parent);
    virtual AbstractNestedStruct3Interface* createNestedStruct3Interface(QObject *parent);
private:
    static ApiFactoryInterface *s_instance;
};

} //namespace testbed2
