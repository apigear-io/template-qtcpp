
#pragma once

#include <QtCore>
#include "tb_same1/api/iapifactory.h"

#if defined(TB_SAME1_QML_LIBRARY)
#  define TB_SAME1_QML_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME1_QML_EXPORT Q_DECL_IMPORT
#endif

namespace tb_same1 {
    class AbstractSameStruct1Interface;
    class AbstractSameStruct2Interface;
    class AbstractSameEnum1Interface;
    class AbstractSameEnum2Interface;

/** 
* A static accesor for ApiFactory - a factory that creates an implementaion of interfaces in tb.same1.
* It is used by Qml versions of interface implementation (instantionated in qml) to provide a backend version.
* A proper factory instance of your choice must be set. This factory by default returns empty interfaces.
* See ApiFactoryInterface implementations.
* See Qml example which uses OlinkFactory.
*/
class TB_SAME1_QML_EXPORT ApiFactory : public QObject, public IApiFactory
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
    std::shared_ptr<AbstractSameStruct1Interface> createSameStruct1Interface(QObject *parent) override;
    std::shared_ptr<AbstractSameStruct2Interface> createSameStruct2Interface(QObject *parent) override;
    std::shared_ptr<AbstractSameEnum1Interface> createSameEnum1Interface(QObject *parent) override;
    std::shared_ptr<AbstractSameEnum2Interface> createSameEnum2Interface(QObject *parent) override;
private:
    static IApiFactory *s_instance;
};

} //namespace tb_same1
