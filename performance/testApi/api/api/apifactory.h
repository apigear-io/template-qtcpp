
#pragma once

#include <QtCore>
#include "iapifactory.h"

namespace api {
    class AbstractTestApi0;
    class AbstractTestApi1;
    class AbstractTestApi2;
    class AbstractTestApi3;
    class AbstractTestApi4;
    class AbstractTestApi5;
    class AbstractTestApi6;
    class AbstractTestApi7;
    class AbstractTestApi8;
    class AbstractTestApi9;
    class AbstractTestApi10;
    class AbstractTestApi11;
    class AbstractTestApi12;
    class AbstractTestApi13;
    class AbstractTestApi14;
    class AbstractTestApi15;
    class AbstractTestApi16;
    class AbstractTestApi17;
    class AbstractTestApi18;
    class AbstractTestApi19;
    class AbstractTestApi20;
    class AbstractTestApi21;
    class AbstractTestApi22;
    class AbstractTestApi23;
    class AbstractTestApi24;
    class AbstractTestApi25;
    class AbstractTestApi26;
    class AbstractTestApi27;
    class AbstractTestApi28;
    class AbstractTestApi29;
    class AbstractTestApi30;
    class AbstractTestApi31;
    class AbstractTestApi32;
    class AbstractTestApi33;
    class AbstractTestApi34;
    class AbstractTestApi35;
    class AbstractTestApi36;
    class AbstractTestApi37;
    class AbstractTestApi38;
    class AbstractTestApi39;
    class AbstractTestApi40;
    class AbstractTestApi41;
    class AbstractTestApi42;
    class AbstractTestApi43;
    class AbstractTestApi44;
    class AbstractTestApi45;
    class AbstractTestApi46;
    class AbstractTestApi47;
    class AbstractTestApi48;
    class AbstractTestApi49;
    class AbstractTestApi50;
    class AbstractTestApi51;
    class AbstractTestApi52;
    class AbstractTestApi53;
    class AbstractTestApi54;
    class AbstractTestApi55;
    class AbstractTestApi56;
    class AbstractTestApi57;
    class AbstractTestApi58;
    class AbstractTestApi59;
    class AbstractTestApi60;
    class AbstractTestApi61;
    class AbstractTestApi62;
    class AbstractTestApi63;
    class AbstractTestApi64;
    class AbstractTestApi65;
    class AbstractTestApi66;
    class AbstractTestApi67;
    class AbstractTestApi68;
    class AbstractTestApi69;
    class AbstractTestApi70;
    class AbstractTestApi71;
    class AbstractTestApi72;
    class AbstractTestApi73;
    class AbstractTestApi74;
    class AbstractTestApi75;
    class AbstractTestApi76;
    class AbstractTestApi77;
    class AbstractTestApi78;
    class AbstractTestApi79;
    class AbstractTestApi80;
    class AbstractTestApi81;
    class AbstractTestApi82;
    class AbstractTestApi83;
    class AbstractTestApi84;
    class AbstractTestApi85;
    class AbstractTestApi86;
    class AbstractTestApi87;
    class AbstractTestApi88;
    class AbstractTestApi89;
    class AbstractTestApi90;
    class AbstractTestApi91;
    class AbstractTestApi92;
    class AbstractTestApi93;
    class AbstractTestApi94;
    class AbstractTestApi95;
    class AbstractTestApi96;
    class AbstractTestApi97;
    class AbstractTestApi98;
    class AbstractTestApi99;

/** 
* A static accesor for ApiFactory - a factory that creates an implementaion of interfaces in api.
* It is used by Qml versions of interface implementation (instantionated in qml) to provide a backend version.
* A proper factory instance of your choice must be set. This factory by default returns empty interfaces.
* See ApiFactoryInterface implementations.
* See Qml example which uses OlinkFactory.
*/
class API_API_EXPORT ApiFactory : public QObject, public IApiFactory
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
    std::shared_ptr<AbstractTestApi0> createTestApi0(QObject *parent) override;
    std::shared_ptr<AbstractTestApi1> createTestApi1(QObject *parent) override;
    std::shared_ptr<AbstractTestApi2> createTestApi2(QObject *parent) override;
    std::shared_ptr<AbstractTestApi3> createTestApi3(QObject *parent) override;
    std::shared_ptr<AbstractTestApi4> createTestApi4(QObject *parent) override;
    std::shared_ptr<AbstractTestApi5> createTestApi5(QObject *parent) override;
    std::shared_ptr<AbstractTestApi6> createTestApi6(QObject *parent) override;
    std::shared_ptr<AbstractTestApi7> createTestApi7(QObject *parent) override;
    std::shared_ptr<AbstractTestApi8> createTestApi8(QObject *parent) override;
    std::shared_ptr<AbstractTestApi9> createTestApi9(QObject *parent) override;
    std::shared_ptr<AbstractTestApi10> createTestApi10(QObject *parent) override;
    std::shared_ptr<AbstractTestApi11> createTestApi11(QObject *parent) override;
    std::shared_ptr<AbstractTestApi12> createTestApi12(QObject *parent) override;
    std::shared_ptr<AbstractTestApi13> createTestApi13(QObject *parent) override;
    std::shared_ptr<AbstractTestApi14> createTestApi14(QObject *parent) override;
    std::shared_ptr<AbstractTestApi15> createTestApi15(QObject *parent) override;
    std::shared_ptr<AbstractTestApi16> createTestApi16(QObject *parent) override;
    std::shared_ptr<AbstractTestApi17> createTestApi17(QObject *parent) override;
    std::shared_ptr<AbstractTestApi18> createTestApi18(QObject *parent) override;
    std::shared_ptr<AbstractTestApi19> createTestApi19(QObject *parent) override;
    std::shared_ptr<AbstractTestApi20> createTestApi20(QObject *parent) override;
    std::shared_ptr<AbstractTestApi21> createTestApi21(QObject *parent) override;
    std::shared_ptr<AbstractTestApi22> createTestApi22(QObject *parent) override;
    std::shared_ptr<AbstractTestApi23> createTestApi23(QObject *parent) override;
    std::shared_ptr<AbstractTestApi24> createTestApi24(QObject *parent) override;
    std::shared_ptr<AbstractTestApi25> createTestApi25(QObject *parent) override;
    std::shared_ptr<AbstractTestApi26> createTestApi26(QObject *parent) override;
    std::shared_ptr<AbstractTestApi27> createTestApi27(QObject *parent) override;
    std::shared_ptr<AbstractTestApi28> createTestApi28(QObject *parent) override;
    std::shared_ptr<AbstractTestApi29> createTestApi29(QObject *parent) override;
    std::shared_ptr<AbstractTestApi30> createTestApi30(QObject *parent) override;
    std::shared_ptr<AbstractTestApi31> createTestApi31(QObject *parent) override;
    std::shared_ptr<AbstractTestApi32> createTestApi32(QObject *parent) override;
    std::shared_ptr<AbstractTestApi33> createTestApi33(QObject *parent) override;
    std::shared_ptr<AbstractTestApi34> createTestApi34(QObject *parent) override;
    std::shared_ptr<AbstractTestApi35> createTestApi35(QObject *parent) override;
    std::shared_ptr<AbstractTestApi36> createTestApi36(QObject *parent) override;
    std::shared_ptr<AbstractTestApi37> createTestApi37(QObject *parent) override;
    std::shared_ptr<AbstractTestApi38> createTestApi38(QObject *parent) override;
    std::shared_ptr<AbstractTestApi39> createTestApi39(QObject *parent) override;
    std::shared_ptr<AbstractTestApi40> createTestApi40(QObject *parent) override;
    std::shared_ptr<AbstractTestApi41> createTestApi41(QObject *parent) override;
    std::shared_ptr<AbstractTestApi42> createTestApi42(QObject *parent) override;
    std::shared_ptr<AbstractTestApi43> createTestApi43(QObject *parent) override;
    std::shared_ptr<AbstractTestApi44> createTestApi44(QObject *parent) override;
    std::shared_ptr<AbstractTestApi45> createTestApi45(QObject *parent) override;
    std::shared_ptr<AbstractTestApi46> createTestApi46(QObject *parent) override;
    std::shared_ptr<AbstractTestApi47> createTestApi47(QObject *parent) override;
    std::shared_ptr<AbstractTestApi48> createTestApi48(QObject *parent) override;
    std::shared_ptr<AbstractTestApi49> createTestApi49(QObject *parent) override;
    std::shared_ptr<AbstractTestApi50> createTestApi50(QObject *parent) override;
    std::shared_ptr<AbstractTestApi51> createTestApi51(QObject *parent) override;
    std::shared_ptr<AbstractTestApi52> createTestApi52(QObject *parent) override;
    std::shared_ptr<AbstractTestApi53> createTestApi53(QObject *parent) override;
    std::shared_ptr<AbstractTestApi54> createTestApi54(QObject *parent) override;
    std::shared_ptr<AbstractTestApi55> createTestApi55(QObject *parent) override;
    std::shared_ptr<AbstractTestApi56> createTestApi56(QObject *parent) override;
    std::shared_ptr<AbstractTestApi57> createTestApi57(QObject *parent) override;
    std::shared_ptr<AbstractTestApi58> createTestApi58(QObject *parent) override;
    std::shared_ptr<AbstractTestApi59> createTestApi59(QObject *parent) override;
    std::shared_ptr<AbstractTestApi60> createTestApi60(QObject *parent) override;
    std::shared_ptr<AbstractTestApi61> createTestApi61(QObject *parent) override;
    std::shared_ptr<AbstractTestApi62> createTestApi62(QObject *parent) override;
    std::shared_ptr<AbstractTestApi63> createTestApi63(QObject *parent) override;
    std::shared_ptr<AbstractTestApi64> createTestApi64(QObject *parent) override;
    std::shared_ptr<AbstractTestApi65> createTestApi65(QObject *parent) override;
    std::shared_ptr<AbstractTestApi66> createTestApi66(QObject *parent) override;
    std::shared_ptr<AbstractTestApi67> createTestApi67(QObject *parent) override;
    std::shared_ptr<AbstractTestApi68> createTestApi68(QObject *parent) override;
    std::shared_ptr<AbstractTestApi69> createTestApi69(QObject *parent) override;
    std::shared_ptr<AbstractTestApi70> createTestApi70(QObject *parent) override;
    std::shared_ptr<AbstractTestApi71> createTestApi71(QObject *parent) override;
    std::shared_ptr<AbstractTestApi72> createTestApi72(QObject *parent) override;
    std::shared_ptr<AbstractTestApi73> createTestApi73(QObject *parent) override;
    std::shared_ptr<AbstractTestApi74> createTestApi74(QObject *parent) override;
    std::shared_ptr<AbstractTestApi75> createTestApi75(QObject *parent) override;
    std::shared_ptr<AbstractTestApi76> createTestApi76(QObject *parent) override;
    std::shared_ptr<AbstractTestApi77> createTestApi77(QObject *parent) override;
    std::shared_ptr<AbstractTestApi78> createTestApi78(QObject *parent) override;
    std::shared_ptr<AbstractTestApi79> createTestApi79(QObject *parent) override;
    std::shared_ptr<AbstractTestApi80> createTestApi80(QObject *parent) override;
    std::shared_ptr<AbstractTestApi81> createTestApi81(QObject *parent) override;
    std::shared_ptr<AbstractTestApi82> createTestApi82(QObject *parent) override;
    std::shared_ptr<AbstractTestApi83> createTestApi83(QObject *parent) override;
    std::shared_ptr<AbstractTestApi84> createTestApi84(QObject *parent) override;
    std::shared_ptr<AbstractTestApi85> createTestApi85(QObject *parent) override;
    std::shared_ptr<AbstractTestApi86> createTestApi86(QObject *parent) override;
    std::shared_ptr<AbstractTestApi87> createTestApi87(QObject *parent) override;
    std::shared_ptr<AbstractTestApi88> createTestApi88(QObject *parent) override;
    std::shared_ptr<AbstractTestApi89> createTestApi89(QObject *parent) override;
    std::shared_ptr<AbstractTestApi90> createTestApi90(QObject *parent) override;
    std::shared_ptr<AbstractTestApi91> createTestApi91(QObject *parent) override;
    std::shared_ptr<AbstractTestApi92> createTestApi92(QObject *parent) override;
    std::shared_ptr<AbstractTestApi93> createTestApi93(QObject *parent) override;
    std::shared_ptr<AbstractTestApi94> createTestApi94(QObject *parent) override;
    std::shared_ptr<AbstractTestApi95> createTestApi95(QObject *parent) override;
    std::shared_ptr<AbstractTestApi96> createTestApi96(QObject *parent) override;
    std::shared_ptr<AbstractTestApi97> createTestApi97(QObject *parent) override;
    std::shared_ptr<AbstractTestApi98> createTestApi98(QObject *parent) override;
    std::shared_ptr<AbstractTestApi99> createTestApi99(QObject *parent) override;
private:
    static IApiFactory *s_instance;
};

} //namespace api
