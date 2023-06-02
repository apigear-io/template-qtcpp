#include "apifactory.h"
#include "api.h"


api::IApiFactory* api::ApiFactory::s_instance(nullptr);

namespace api {

ApiFactory::ApiFactory(QObject *parent)
    : QObject(parent)
{
}

void ApiFactory::set(IApiFactory *instance)
{
    if(s_instance) {
        qFatal("Can not set factory when factory already set");
    }
    s_instance = instance;
}

IApiFactory * ApiFactory::get()
{
    if(s_instance) {
        return s_instance;
    }
    return nullptr;
}

std::shared_ptr<AbstractTestApi0> ApiFactory::createTestApi0(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi0(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi0 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi1> ApiFactory::createTestApi1(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi1(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi1 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi2> ApiFactory::createTestApi2(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi2(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi2 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi3> ApiFactory::createTestApi3(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi3(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi3 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi4> ApiFactory::createTestApi4(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi4(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi4 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi5> ApiFactory::createTestApi5(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi5(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi5 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi6> ApiFactory::createTestApi6(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi6(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi6 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi7> ApiFactory::createTestApi7(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi7(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi7 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi8> ApiFactory::createTestApi8(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi8(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi8 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi9> ApiFactory::createTestApi9(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi9(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi9 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi10> ApiFactory::createTestApi10(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi10(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi10 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi11> ApiFactory::createTestApi11(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi11(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi11 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi12> ApiFactory::createTestApi12(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi12(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi12 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi13> ApiFactory::createTestApi13(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi13(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi13 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi14> ApiFactory::createTestApi14(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi14(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi14 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi15> ApiFactory::createTestApi15(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi15(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi15 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi16> ApiFactory::createTestApi16(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi16(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi16 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi17> ApiFactory::createTestApi17(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi17(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi17 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi18> ApiFactory::createTestApi18(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi18(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi18 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi19> ApiFactory::createTestApi19(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi19(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi19 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi20> ApiFactory::createTestApi20(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi20(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi20 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi21> ApiFactory::createTestApi21(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi21(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi21 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi22> ApiFactory::createTestApi22(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi22(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi22 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi23> ApiFactory::createTestApi23(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi23(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi23 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi24> ApiFactory::createTestApi24(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi24(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi24 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi25> ApiFactory::createTestApi25(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi25(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi25 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi26> ApiFactory::createTestApi26(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi26(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi26 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi27> ApiFactory::createTestApi27(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi27(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi27 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi28> ApiFactory::createTestApi28(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi28(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi28 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi29> ApiFactory::createTestApi29(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi29(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi29 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi30> ApiFactory::createTestApi30(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi30(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi30 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi31> ApiFactory::createTestApi31(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi31(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi31 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi32> ApiFactory::createTestApi32(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi32(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi32 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi33> ApiFactory::createTestApi33(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi33(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi33 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi34> ApiFactory::createTestApi34(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi34(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi34 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi35> ApiFactory::createTestApi35(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi35(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi35 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi36> ApiFactory::createTestApi36(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi36(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi36 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi37> ApiFactory::createTestApi37(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi37(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi37 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi38> ApiFactory::createTestApi38(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi38(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi38 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi39> ApiFactory::createTestApi39(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi39(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi39 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi40> ApiFactory::createTestApi40(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi40(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi40 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi41> ApiFactory::createTestApi41(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi41(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi41 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi42> ApiFactory::createTestApi42(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi42(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi42 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi43> ApiFactory::createTestApi43(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi43(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi43 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi44> ApiFactory::createTestApi44(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi44(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi44 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi45> ApiFactory::createTestApi45(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi45(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi45 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi46> ApiFactory::createTestApi46(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi46(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi46 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi47> ApiFactory::createTestApi47(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi47(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi47 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi48> ApiFactory::createTestApi48(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi48(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi48 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi49> ApiFactory::createTestApi49(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi49(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi49 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi50> ApiFactory::createTestApi50(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi50(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi50 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi51> ApiFactory::createTestApi51(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi51(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi51 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi52> ApiFactory::createTestApi52(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi52(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi52 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi53> ApiFactory::createTestApi53(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi53(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi53 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi54> ApiFactory::createTestApi54(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi54(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi54 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi55> ApiFactory::createTestApi55(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi55(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi55 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi56> ApiFactory::createTestApi56(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi56(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi56 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi57> ApiFactory::createTestApi57(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi57(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi57 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi58> ApiFactory::createTestApi58(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi58(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi58 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi59> ApiFactory::createTestApi59(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi59(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi59 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi60> ApiFactory::createTestApi60(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi60(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi60 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi61> ApiFactory::createTestApi61(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi61(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi61 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi62> ApiFactory::createTestApi62(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi62(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi62 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi63> ApiFactory::createTestApi63(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi63(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi63 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi64> ApiFactory::createTestApi64(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi64(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi64 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi65> ApiFactory::createTestApi65(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi65(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi65 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi66> ApiFactory::createTestApi66(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi66(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi66 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi67> ApiFactory::createTestApi67(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi67(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi67 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi68> ApiFactory::createTestApi68(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi68(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi68 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi69> ApiFactory::createTestApi69(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi69(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi69 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi70> ApiFactory::createTestApi70(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi70(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi70 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi71> ApiFactory::createTestApi71(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi71(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi71 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi72> ApiFactory::createTestApi72(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi72(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi72 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi73> ApiFactory::createTestApi73(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi73(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi73 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi74> ApiFactory::createTestApi74(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi74(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi74 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi75> ApiFactory::createTestApi75(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi75(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi75 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi76> ApiFactory::createTestApi76(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi76(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi76 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi77> ApiFactory::createTestApi77(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi77(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi77 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi78> ApiFactory::createTestApi78(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi78(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi78 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi79> ApiFactory::createTestApi79(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi79(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi79 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi80> ApiFactory::createTestApi80(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi80(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi80 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi81> ApiFactory::createTestApi81(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi81(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi81 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi82> ApiFactory::createTestApi82(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi82(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi82 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi83> ApiFactory::createTestApi83(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi83(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi83 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi84> ApiFactory::createTestApi84(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi84(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi84 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi85> ApiFactory::createTestApi85(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi85(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi85 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi86> ApiFactory::createTestApi86(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi86(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi86 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi87> ApiFactory::createTestApi87(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi87(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi87 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi88> ApiFactory::createTestApi88(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi88(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi88 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi89> ApiFactory::createTestApi89(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi89(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi89 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi90> ApiFactory::createTestApi90(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi90(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi90 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi91> ApiFactory::createTestApi91(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi91(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi91 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi92> ApiFactory::createTestApi92(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi92(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi92 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi93> ApiFactory::createTestApi93(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi93(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi93 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi94> ApiFactory::createTestApi94(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi94(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi94 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi95> ApiFactory::createTestApi95(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi95(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi95 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi96> ApiFactory::createTestApi96(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi96(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi96 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi97> ApiFactory::createTestApi97(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi97(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi97 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi98> ApiFactory::createTestApi98(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi98(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi98 cannot be created. ";
    return nullptr;
};

std::shared_ptr<AbstractTestApi99> ApiFactory::createTestApi99(QObject *parent) 
{
    auto factory = ApiFactory::get();
    if (factory)
    {
        return factory->createTestApi99(parent);
    }
    qCritical() << Q_FUNC_INFO << " No instance of factory set TestApi99 cannot be created. ";
    return nullptr;
};

} //namespace api