#pragma once

#include <QtCore>
#include "api.h"

namespace testbed1 {


/** 
* A Factory that creates an implementaion of interfaces in testbed1.
* Factory is used by Qml versions of interface implementation to provide a backend version.
* By default this factory produces the simulation version of implementation.
* See other ApiFactoryInterface implementation.
*/
class TESTBED1_EXPORT ApiFactory : public QObject, public ApiFactoryInterface
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
    virtual AbstractStructInterface* createStructInterface(QObject *parent);
    virtual AbstractStructArrayInterface* createStructArrayInterface(QObject *parent);
private:
    static ApiFactoryInterface *s_instance;
};

} //namespace testbed1
