
#pragma once

#include <QtCore>
#include "iapifactory.h"

namespace tb_same2 {
    class AbstractSameStruct1Interface;
    class AbstractSameStruct2Interface;
    class AbstractSameEnum1Interface;
    class AbstractSameEnum2Interface;

/** 
* A Factory that creates an implementaion of interfaces in tb.same2.
* Factory is used by Qml versions of interface implementation to provide a backend version.
* By default this factory produces the simulation version of implementation.
* See other IApiFactory implementation.
*/
class TB_SAME2_API_EXPORT ApiFactory : public QObject, public IApiFactory
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
    std::shared_ptr<AbstractSameStruct1Interface> createSameStruct1Interface(QObject *parent) override;
    std::shared_ptr<AbstractSameStruct2Interface> createSameStruct2Interface(QObject *parent) override;
    std::shared_ptr<AbstractSameEnum1Interface> createSameEnum1Interface(QObject *parent) override;
    std::shared_ptr<AbstractSameEnum2Interface> createSameEnum2Interface(QObject *parent) override;
private:
    static IApiFactory *s_instance;
};

} //namespace tb_same2
