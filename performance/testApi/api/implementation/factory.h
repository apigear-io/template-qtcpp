#pragma once

#include <QtCore>

#include "api/api/iapifactory.h"
#if defined(API_IMPL_LIBRARY)
#  define API_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define API_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace api {

/** 
* A Factory that creates the actual implementaion for interfaces in api
* You can check the usage of IApiFactory in Qml versions of interface implementation.
* By default this factory is not used as IApiFactory.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class API_IMPL_EXPORT Factory : public QObject, public IApiFactory
{
public:
    Factory(QObject *parent = nullptr);
    /** @return implementation of TestApi0 */
    std::shared_ptr<AbstractTestApi0> createTestApi0(QObject *parent) override;
    /** @return implementation of TestApi1 */
    std::shared_ptr<AbstractTestApi1> createTestApi1(QObject *parent) override;
    /** @return implementation of TestApi2 */
    std::shared_ptr<AbstractTestApi2> createTestApi2(QObject *parent) override;
    /** @return implementation of TestApi3 */
    std::shared_ptr<AbstractTestApi3> createTestApi3(QObject *parent) override;
    /** @return implementation of TestApi4 */
    std::shared_ptr<AbstractTestApi4> createTestApi4(QObject *parent) override;
    /** @return implementation of TestApi5 */
    std::shared_ptr<AbstractTestApi5> createTestApi5(QObject *parent) override;
    /** @return implementation of TestApi6 */
    std::shared_ptr<AbstractTestApi6> createTestApi6(QObject *parent) override;
    /** @return implementation of TestApi7 */
    std::shared_ptr<AbstractTestApi7> createTestApi7(QObject *parent) override;
    /** @return implementation of TestApi8 */
    std::shared_ptr<AbstractTestApi8> createTestApi8(QObject *parent) override;
    /** @return implementation of TestApi9 */
    std::shared_ptr<AbstractTestApi9> createTestApi9(QObject *parent) override;
    /** @return implementation of TestApi10 */
    std::shared_ptr<AbstractTestApi10> createTestApi10(QObject *parent) override;
    /** @return implementation of TestApi11 */
    std::shared_ptr<AbstractTestApi11> createTestApi11(QObject *parent) override;
    /** @return implementation of TestApi12 */
    std::shared_ptr<AbstractTestApi12> createTestApi12(QObject *parent) override;
    /** @return implementation of TestApi13 */
    std::shared_ptr<AbstractTestApi13> createTestApi13(QObject *parent) override;
    /** @return implementation of TestApi14 */
    std::shared_ptr<AbstractTestApi14> createTestApi14(QObject *parent) override;
    /** @return implementation of TestApi15 */
    std::shared_ptr<AbstractTestApi15> createTestApi15(QObject *parent) override;
    /** @return implementation of TestApi16 */
    std::shared_ptr<AbstractTestApi16> createTestApi16(QObject *parent) override;
    /** @return implementation of TestApi17 */
    std::shared_ptr<AbstractTestApi17> createTestApi17(QObject *parent) override;
    /** @return implementation of TestApi18 */
    std::shared_ptr<AbstractTestApi18> createTestApi18(QObject *parent) override;
    /** @return implementation of TestApi19 */
    std::shared_ptr<AbstractTestApi19> createTestApi19(QObject *parent) override;
    /** @return implementation of TestApi20 */
    std::shared_ptr<AbstractTestApi20> createTestApi20(QObject *parent) override;
    /** @return implementation of TestApi21 */
    std::shared_ptr<AbstractTestApi21> createTestApi21(QObject *parent) override;
    /** @return implementation of TestApi22 */
    std::shared_ptr<AbstractTestApi22> createTestApi22(QObject *parent) override;
    /** @return implementation of TestApi23 */
    std::shared_ptr<AbstractTestApi23> createTestApi23(QObject *parent) override;
    /** @return implementation of TestApi24 */
    std::shared_ptr<AbstractTestApi24> createTestApi24(QObject *parent) override;
    /** @return implementation of TestApi25 */
    std::shared_ptr<AbstractTestApi25> createTestApi25(QObject *parent) override;
    /** @return implementation of TestApi26 */
    std::shared_ptr<AbstractTestApi26> createTestApi26(QObject *parent) override;
    /** @return implementation of TestApi27 */
    std::shared_ptr<AbstractTestApi27> createTestApi27(QObject *parent) override;
    /** @return implementation of TestApi28 */
    std::shared_ptr<AbstractTestApi28> createTestApi28(QObject *parent) override;
    /** @return implementation of TestApi29 */
    std::shared_ptr<AbstractTestApi29> createTestApi29(QObject *parent) override;
    /** @return implementation of TestApi30 */
    std::shared_ptr<AbstractTestApi30> createTestApi30(QObject *parent) override;
    /** @return implementation of TestApi31 */
    std::shared_ptr<AbstractTestApi31> createTestApi31(QObject *parent) override;
    /** @return implementation of TestApi32 */
    std::shared_ptr<AbstractTestApi32> createTestApi32(QObject *parent) override;
    /** @return implementation of TestApi33 */
    std::shared_ptr<AbstractTestApi33> createTestApi33(QObject *parent) override;
    /** @return implementation of TestApi34 */
    std::shared_ptr<AbstractTestApi34> createTestApi34(QObject *parent) override;
    /** @return implementation of TestApi35 */
    std::shared_ptr<AbstractTestApi35> createTestApi35(QObject *parent) override;
    /** @return implementation of TestApi36 */
    std::shared_ptr<AbstractTestApi36> createTestApi36(QObject *parent) override;
    /** @return implementation of TestApi37 */
    std::shared_ptr<AbstractTestApi37> createTestApi37(QObject *parent) override;
    /** @return implementation of TestApi38 */
    std::shared_ptr<AbstractTestApi38> createTestApi38(QObject *parent) override;
    /** @return implementation of TestApi39 */
    std::shared_ptr<AbstractTestApi39> createTestApi39(QObject *parent) override;
    /** @return implementation of TestApi40 */
    std::shared_ptr<AbstractTestApi40> createTestApi40(QObject *parent) override;
    /** @return implementation of TestApi41 */
    std::shared_ptr<AbstractTestApi41> createTestApi41(QObject *parent) override;
    /** @return implementation of TestApi42 */
    std::shared_ptr<AbstractTestApi42> createTestApi42(QObject *parent) override;
    /** @return implementation of TestApi43 */
    std::shared_ptr<AbstractTestApi43> createTestApi43(QObject *parent) override;
    /** @return implementation of TestApi44 */
    std::shared_ptr<AbstractTestApi44> createTestApi44(QObject *parent) override;
    /** @return implementation of TestApi45 */
    std::shared_ptr<AbstractTestApi45> createTestApi45(QObject *parent) override;
    /** @return implementation of TestApi46 */
    std::shared_ptr<AbstractTestApi46> createTestApi46(QObject *parent) override;
    /** @return implementation of TestApi47 */
    std::shared_ptr<AbstractTestApi47> createTestApi47(QObject *parent) override;
    /** @return implementation of TestApi48 */
    std::shared_ptr<AbstractTestApi48> createTestApi48(QObject *parent) override;
    /** @return implementation of TestApi49 */
    std::shared_ptr<AbstractTestApi49> createTestApi49(QObject *parent) override;
    /** @return implementation of TestApi50 */
    std::shared_ptr<AbstractTestApi50> createTestApi50(QObject *parent) override;
    /** @return implementation of TestApi51 */
    std::shared_ptr<AbstractTestApi51> createTestApi51(QObject *parent) override;
    /** @return implementation of TestApi52 */
    std::shared_ptr<AbstractTestApi52> createTestApi52(QObject *parent) override;
    /** @return implementation of TestApi53 */
    std::shared_ptr<AbstractTestApi53> createTestApi53(QObject *parent) override;
    /** @return implementation of TestApi54 */
    std::shared_ptr<AbstractTestApi54> createTestApi54(QObject *parent) override;
    /** @return implementation of TestApi55 */
    std::shared_ptr<AbstractTestApi55> createTestApi55(QObject *parent) override;
    /** @return implementation of TestApi56 */
    std::shared_ptr<AbstractTestApi56> createTestApi56(QObject *parent) override;
    /** @return implementation of TestApi57 */
    std::shared_ptr<AbstractTestApi57> createTestApi57(QObject *parent) override;
    /** @return implementation of TestApi58 */
    std::shared_ptr<AbstractTestApi58> createTestApi58(QObject *parent) override;
    /** @return implementation of TestApi59 */
    std::shared_ptr<AbstractTestApi59> createTestApi59(QObject *parent) override;
    /** @return implementation of TestApi60 */
    std::shared_ptr<AbstractTestApi60> createTestApi60(QObject *parent) override;
    /** @return implementation of TestApi61 */
    std::shared_ptr<AbstractTestApi61> createTestApi61(QObject *parent) override;
    /** @return implementation of TestApi62 */
    std::shared_ptr<AbstractTestApi62> createTestApi62(QObject *parent) override;
    /** @return implementation of TestApi63 */
    std::shared_ptr<AbstractTestApi63> createTestApi63(QObject *parent) override;
    /** @return implementation of TestApi64 */
    std::shared_ptr<AbstractTestApi64> createTestApi64(QObject *parent) override;
    /** @return implementation of TestApi65 */
    std::shared_ptr<AbstractTestApi65> createTestApi65(QObject *parent) override;
    /** @return implementation of TestApi66 */
    std::shared_ptr<AbstractTestApi66> createTestApi66(QObject *parent) override;
    /** @return implementation of TestApi67 */
    std::shared_ptr<AbstractTestApi67> createTestApi67(QObject *parent) override;
    /** @return implementation of TestApi68 */
    std::shared_ptr<AbstractTestApi68> createTestApi68(QObject *parent) override;
    /** @return implementation of TestApi69 */
    std::shared_ptr<AbstractTestApi69> createTestApi69(QObject *parent) override;
    /** @return implementation of TestApi70 */
    std::shared_ptr<AbstractTestApi70> createTestApi70(QObject *parent) override;
    /** @return implementation of TestApi71 */
    std::shared_ptr<AbstractTestApi71> createTestApi71(QObject *parent) override;
    /** @return implementation of TestApi72 */
    std::shared_ptr<AbstractTestApi72> createTestApi72(QObject *parent) override;
    /** @return implementation of TestApi73 */
    std::shared_ptr<AbstractTestApi73> createTestApi73(QObject *parent) override;
    /** @return implementation of TestApi74 */
    std::shared_ptr<AbstractTestApi74> createTestApi74(QObject *parent) override;
    /** @return implementation of TestApi75 */
    std::shared_ptr<AbstractTestApi75> createTestApi75(QObject *parent) override;
    /** @return implementation of TestApi76 */
    std::shared_ptr<AbstractTestApi76> createTestApi76(QObject *parent) override;
    /** @return implementation of TestApi77 */
    std::shared_ptr<AbstractTestApi77> createTestApi77(QObject *parent) override;
    /** @return implementation of TestApi78 */
    std::shared_ptr<AbstractTestApi78> createTestApi78(QObject *parent) override;
    /** @return implementation of TestApi79 */
    std::shared_ptr<AbstractTestApi79> createTestApi79(QObject *parent) override;
    /** @return implementation of TestApi80 */
    std::shared_ptr<AbstractTestApi80> createTestApi80(QObject *parent) override;
    /** @return implementation of TestApi81 */
    std::shared_ptr<AbstractTestApi81> createTestApi81(QObject *parent) override;
    /** @return implementation of TestApi82 */
    std::shared_ptr<AbstractTestApi82> createTestApi82(QObject *parent) override;
    /** @return implementation of TestApi83 */
    std::shared_ptr<AbstractTestApi83> createTestApi83(QObject *parent) override;
    /** @return implementation of TestApi84 */
    std::shared_ptr<AbstractTestApi84> createTestApi84(QObject *parent) override;
    /** @return implementation of TestApi85 */
    std::shared_ptr<AbstractTestApi85> createTestApi85(QObject *parent) override;
    /** @return implementation of TestApi86 */
    std::shared_ptr<AbstractTestApi86> createTestApi86(QObject *parent) override;
    /** @return implementation of TestApi87 */
    std::shared_ptr<AbstractTestApi87> createTestApi87(QObject *parent) override;
    /** @return implementation of TestApi88 */
    std::shared_ptr<AbstractTestApi88> createTestApi88(QObject *parent) override;
    /** @return implementation of TestApi89 */
    std::shared_ptr<AbstractTestApi89> createTestApi89(QObject *parent) override;
    /** @return implementation of TestApi90 */
    std::shared_ptr<AbstractTestApi90> createTestApi90(QObject *parent) override;
    /** @return implementation of TestApi91 */
    std::shared_ptr<AbstractTestApi91> createTestApi91(QObject *parent) override;
    /** @return implementation of TestApi92 */
    std::shared_ptr<AbstractTestApi92> createTestApi92(QObject *parent) override;
    /** @return implementation of TestApi93 */
    std::shared_ptr<AbstractTestApi93> createTestApi93(QObject *parent) override;
    /** @return implementation of TestApi94 */
    std::shared_ptr<AbstractTestApi94> createTestApi94(QObject *parent) override;
    /** @return implementation of TestApi95 */
    std::shared_ptr<AbstractTestApi95> createTestApi95(QObject *parent) override;
    /** @return implementation of TestApi96 */
    std::shared_ptr<AbstractTestApi96> createTestApi96(QObject *parent) override;
    /** @return implementation of TestApi97 */
    std::shared_ptr<AbstractTestApi97> createTestApi97(QObject *parent) override;
    /** @return implementation of TestApi98 */
    std::shared_ptr<AbstractTestApi98> createTestApi98(QObject *parent) override;
    /** @return implementation of TestApi99 */
    std::shared_ptr<AbstractTestApi99> createTestApi99(QObject *parent) override;
};

} // namespace api

