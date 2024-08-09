
#pragma once

#include <QtCore>
#include "custom_types/api/iapifactory.h"

#if defined(CUSTOM_TYPES_QML_LIBRARY)
#  define CUSTOM_TYPES_QML_EXPORT Q_DECL_EXPORT
#else
#  define CUSTOM_TYPES_QML_EXPORT Q_DECL_IMPORT
#endif

namespace custom_types {

/** 
* A static accesor for ApiFactory - a factory that creates an implementaion of interfaces in custom_types.
* It is used by Qml versions of interface implementation (instantionated in qml) to provide a backend version.
* A proper factory instance of your choice must be set. This factory by default returns empty interfaces.
* See ApiFactoryInterface implementations.
* See Qml example which uses OlinkFactory.
*/
class CUSTOM_TYPES_QML_EXPORT ApiFactory : public QObject, public IApiFactory
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
private:
    static IApiFactory *s_instance;
};

} //namespace custom_types
