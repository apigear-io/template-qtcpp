#include "olinkfactory.h"
#include "olink/olinktestapi0.h"
#include "olink/olinktestapi1.h"
#include "olink/olinktestapi2.h"
#include "olink/olinktestapi3.h"
#include "olink/olinktestapi4.h"
#include "olink/olinktestapi5.h"
#include "olink/olinktestapi6.h"
#include "olink/olinktestapi7.h"
#include "olink/olinktestapi8.h"
#include "olink/olinktestapi9.h"
#include "olink/olinktestapi10.h"
#include "olink/olinktestapi11.h"
#include "olink/olinktestapi12.h"
#include "olink/olinktestapi13.h"
#include "olink/olinktestapi14.h"
#include "olink/olinktestapi15.h"
#include "olink/olinktestapi16.h"
#include "olink/olinktestapi17.h"
#include "olink/olinktestapi18.h"
#include "olink/olinktestapi19.h"
#include "olink/olinktestapi20.h"
#include "olink/olinktestapi21.h"
#include "olink/olinktestapi22.h"
#include "olink/olinktestapi23.h"
#include "olink/olinktestapi24.h"
#include "olink/olinktestapi25.h"
#include "olink/olinktestapi26.h"
#include "olink/olinktestapi27.h"
#include "olink/olinktestapi28.h"
#include "olink/olinktestapi29.h"
#include "olink/olinktestapi30.h"
#include "olink/olinktestapi31.h"
#include "olink/olinktestapi32.h"
#include "olink/olinktestapi33.h"
#include "olink/olinktestapi34.h"
#include "olink/olinktestapi35.h"
#include "olink/olinktestapi36.h"
#include "olink/olinktestapi37.h"
#include "olink/olinktestapi38.h"
#include "olink/olinktestapi39.h"
#include "olink/olinktestapi40.h"
#include "olink/olinktestapi41.h"
#include "olink/olinktestapi42.h"
#include "olink/olinktestapi43.h"
#include "olink/olinktestapi44.h"
#include "olink/olinktestapi45.h"
#include "olink/olinktestapi46.h"
#include "olink/olinktestapi47.h"
#include "olink/olinktestapi48.h"
#include "olink/olinktestapi49.h"
#include "olink/olinktestapi50.h"
#include "olink/olinktestapi51.h"
#include "olink/olinktestapi52.h"
#include "olink/olinktestapi53.h"
#include "olink/olinktestapi54.h"
#include "olink/olinktestapi55.h"
#include "olink/olinktestapi56.h"
#include "olink/olinktestapi57.h"
#include "olink/olinktestapi58.h"
#include "olink/olinktestapi59.h"
#include "olink/olinktestapi60.h"
#include "olink/olinktestapi61.h"
#include "olink/olinktestapi62.h"
#include "olink/olinktestapi63.h"
#include "olink/olinktestapi64.h"
#include "olink/olinktestapi65.h"
#include "olink/olinktestapi66.h"
#include "olink/olinktestapi67.h"
#include "olink/olinktestapi68.h"
#include "olink/olinktestapi69.h"
#include "olink/olinktestapi70.h"
#include "olink/olinktestapi71.h"
#include "olink/olinktestapi72.h"
#include "olink/olinktestapi73.h"
#include "olink/olinktestapi74.h"
#include "olink/olinktestapi75.h"
#include "olink/olinktestapi76.h"
#include "olink/olinktestapi77.h"
#include "olink/olinktestapi78.h"
#include "olink/olinktestapi79.h"
#include "olink/olinktestapi80.h"
#include "olink/olinktestapi81.h"
#include "olink/olinktestapi82.h"
#include "olink/olinktestapi83.h"
#include "olink/olinktestapi84.h"
#include "olink/olinktestapi85.h"
#include "olink/olinktestapi86.h"
#include "olink/olinktestapi87.h"
#include "olink/olinktestapi88.h"
#include "olink/olinktestapi89.h"
#include "olink/olinktestapi90.h"
#include "olink/olinktestapi91.h"
#include "olink/olinktestapi92.h"
#include "olink/olinktestapi93.h"
#include "olink/olinktestapi94.h"
#include "olink/olinktestapi95.h"
#include "olink/olinktestapi96.h"
#include "olink/olinktestapi97.h"
#include "olink/olinktestapi98.h"
#include "olink/olinktestapi99.h"

namespace api {

OLinkFactory::OLinkFactory(ApiGear::ObjectLink::OLinkClient& client, QObject *parent)
    : QObject(parent),
      m_client(client)
{
    qDebug() << Q_FUNC_INFO;
}

std::shared_ptr<AbstractTestApi0> OLinkFactory::createTestApi0(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api0 = std::make_shared<OLinkTestApi0>();
    m_client.linkObjectSource(test_api0);
    return test_api0;
}

std::shared_ptr<AbstractTestApi1> OLinkFactory::createTestApi1(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api1 = std::make_shared<OLinkTestApi1>();
    m_client.linkObjectSource(test_api1);
    return test_api1;
}

std::shared_ptr<AbstractTestApi2> OLinkFactory::createTestApi2(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api2 = std::make_shared<OLinkTestApi2>();
    m_client.linkObjectSource(test_api2);
    return test_api2;
}

std::shared_ptr<AbstractTestApi3> OLinkFactory::createTestApi3(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api3 = std::make_shared<OLinkTestApi3>();
    m_client.linkObjectSource(test_api3);
    return test_api3;
}

std::shared_ptr<AbstractTestApi4> OLinkFactory::createTestApi4(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api4 = std::make_shared<OLinkTestApi4>();
    m_client.linkObjectSource(test_api4);
    return test_api4;
}

std::shared_ptr<AbstractTestApi5> OLinkFactory::createTestApi5(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api5 = std::make_shared<OLinkTestApi5>();
    m_client.linkObjectSource(test_api5);
    return test_api5;
}

std::shared_ptr<AbstractTestApi6> OLinkFactory::createTestApi6(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api6 = std::make_shared<OLinkTestApi6>();
    m_client.linkObjectSource(test_api6);
    return test_api6;
}

std::shared_ptr<AbstractTestApi7> OLinkFactory::createTestApi7(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api7 = std::make_shared<OLinkTestApi7>();
    m_client.linkObjectSource(test_api7);
    return test_api7;
}

std::shared_ptr<AbstractTestApi8> OLinkFactory::createTestApi8(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api8 = std::make_shared<OLinkTestApi8>();
    m_client.linkObjectSource(test_api8);
    return test_api8;
}

std::shared_ptr<AbstractTestApi9> OLinkFactory::createTestApi9(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api9 = std::make_shared<OLinkTestApi9>();
    m_client.linkObjectSource(test_api9);
    return test_api9;
}

std::shared_ptr<AbstractTestApi10> OLinkFactory::createTestApi10(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api10 = std::make_shared<OLinkTestApi10>();
    m_client.linkObjectSource(test_api10);
    return test_api10;
}

std::shared_ptr<AbstractTestApi11> OLinkFactory::createTestApi11(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api11 = std::make_shared<OLinkTestApi11>();
    m_client.linkObjectSource(test_api11);
    return test_api11;
}

std::shared_ptr<AbstractTestApi12> OLinkFactory::createTestApi12(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api12 = std::make_shared<OLinkTestApi12>();
    m_client.linkObjectSource(test_api12);
    return test_api12;
}

std::shared_ptr<AbstractTestApi13> OLinkFactory::createTestApi13(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api13 = std::make_shared<OLinkTestApi13>();
    m_client.linkObjectSource(test_api13);
    return test_api13;
}

std::shared_ptr<AbstractTestApi14> OLinkFactory::createTestApi14(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api14 = std::make_shared<OLinkTestApi14>();
    m_client.linkObjectSource(test_api14);
    return test_api14;
}

std::shared_ptr<AbstractTestApi15> OLinkFactory::createTestApi15(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api15 = std::make_shared<OLinkTestApi15>();
    m_client.linkObjectSource(test_api15);
    return test_api15;
}

std::shared_ptr<AbstractTestApi16> OLinkFactory::createTestApi16(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api16 = std::make_shared<OLinkTestApi16>();
    m_client.linkObjectSource(test_api16);
    return test_api16;
}

std::shared_ptr<AbstractTestApi17> OLinkFactory::createTestApi17(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api17 = std::make_shared<OLinkTestApi17>();
    m_client.linkObjectSource(test_api17);
    return test_api17;
}

std::shared_ptr<AbstractTestApi18> OLinkFactory::createTestApi18(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api18 = std::make_shared<OLinkTestApi18>();
    m_client.linkObjectSource(test_api18);
    return test_api18;
}

std::shared_ptr<AbstractTestApi19> OLinkFactory::createTestApi19(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api19 = std::make_shared<OLinkTestApi19>();
    m_client.linkObjectSource(test_api19);
    return test_api19;
}

std::shared_ptr<AbstractTestApi20> OLinkFactory::createTestApi20(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api20 = std::make_shared<OLinkTestApi20>();
    m_client.linkObjectSource(test_api20);
    return test_api20;
}

std::shared_ptr<AbstractTestApi21> OLinkFactory::createTestApi21(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api21 = std::make_shared<OLinkTestApi21>();
    m_client.linkObjectSource(test_api21);
    return test_api21;
}

std::shared_ptr<AbstractTestApi22> OLinkFactory::createTestApi22(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api22 = std::make_shared<OLinkTestApi22>();
    m_client.linkObjectSource(test_api22);
    return test_api22;
}

std::shared_ptr<AbstractTestApi23> OLinkFactory::createTestApi23(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api23 = std::make_shared<OLinkTestApi23>();
    m_client.linkObjectSource(test_api23);
    return test_api23;
}

std::shared_ptr<AbstractTestApi24> OLinkFactory::createTestApi24(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api24 = std::make_shared<OLinkTestApi24>();
    m_client.linkObjectSource(test_api24);
    return test_api24;
}

std::shared_ptr<AbstractTestApi25> OLinkFactory::createTestApi25(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api25 = std::make_shared<OLinkTestApi25>();
    m_client.linkObjectSource(test_api25);
    return test_api25;
}

std::shared_ptr<AbstractTestApi26> OLinkFactory::createTestApi26(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api26 = std::make_shared<OLinkTestApi26>();
    m_client.linkObjectSource(test_api26);
    return test_api26;
}

std::shared_ptr<AbstractTestApi27> OLinkFactory::createTestApi27(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api27 = std::make_shared<OLinkTestApi27>();
    m_client.linkObjectSource(test_api27);
    return test_api27;
}

std::shared_ptr<AbstractTestApi28> OLinkFactory::createTestApi28(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api28 = std::make_shared<OLinkTestApi28>();
    m_client.linkObjectSource(test_api28);
    return test_api28;
}

std::shared_ptr<AbstractTestApi29> OLinkFactory::createTestApi29(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api29 = std::make_shared<OLinkTestApi29>();
    m_client.linkObjectSource(test_api29);
    return test_api29;
}

std::shared_ptr<AbstractTestApi30> OLinkFactory::createTestApi30(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api30 = std::make_shared<OLinkTestApi30>();
    m_client.linkObjectSource(test_api30);
    return test_api30;
}

std::shared_ptr<AbstractTestApi31> OLinkFactory::createTestApi31(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api31 = std::make_shared<OLinkTestApi31>();
    m_client.linkObjectSource(test_api31);
    return test_api31;
}

std::shared_ptr<AbstractTestApi32> OLinkFactory::createTestApi32(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api32 = std::make_shared<OLinkTestApi32>();
    m_client.linkObjectSource(test_api32);
    return test_api32;
}

std::shared_ptr<AbstractTestApi33> OLinkFactory::createTestApi33(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api33 = std::make_shared<OLinkTestApi33>();
    m_client.linkObjectSource(test_api33);
    return test_api33;
}

std::shared_ptr<AbstractTestApi34> OLinkFactory::createTestApi34(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api34 = std::make_shared<OLinkTestApi34>();
    m_client.linkObjectSource(test_api34);
    return test_api34;
}

std::shared_ptr<AbstractTestApi35> OLinkFactory::createTestApi35(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api35 = std::make_shared<OLinkTestApi35>();
    m_client.linkObjectSource(test_api35);
    return test_api35;
}

std::shared_ptr<AbstractTestApi36> OLinkFactory::createTestApi36(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api36 = std::make_shared<OLinkTestApi36>();
    m_client.linkObjectSource(test_api36);
    return test_api36;
}

std::shared_ptr<AbstractTestApi37> OLinkFactory::createTestApi37(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api37 = std::make_shared<OLinkTestApi37>();
    m_client.linkObjectSource(test_api37);
    return test_api37;
}

std::shared_ptr<AbstractTestApi38> OLinkFactory::createTestApi38(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api38 = std::make_shared<OLinkTestApi38>();
    m_client.linkObjectSource(test_api38);
    return test_api38;
}

std::shared_ptr<AbstractTestApi39> OLinkFactory::createTestApi39(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api39 = std::make_shared<OLinkTestApi39>();
    m_client.linkObjectSource(test_api39);
    return test_api39;
}

std::shared_ptr<AbstractTestApi40> OLinkFactory::createTestApi40(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api40 = std::make_shared<OLinkTestApi40>();
    m_client.linkObjectSource(test_api40);
    return test_api40;
}

std::shared_ptr<AbstractTestApi41> OLinkFactory::createTestApi41(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api41 = std::make_shared<OLinkTestApi41>();
    m_client.linkObjectSource(test_api41);
    return test_api41;
}

std::shared_ptr<AbstractTestApi42> OLinkFactory::createTestApi42(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api42 = std::make_shared<OLinkTestApi42>();
    m_client.linkObjectSource(test_api42);
    return test_api42;
}

std::shared_ptr<AbstractTestApi43> OLinkFactory::createTestApi43(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api43 = std::make_shared<OLinkTestApi43>();
    m_client.linkObjectSource(test_api43);
    return test_api43;
}

std::shared_ptr<AbstractTestApi44> OLinkFactory::createTestApi44(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api44 = std::make_shared<OLinkTestApi44>();
    m_client.linkObjectSource(test_api44);
    return test_api44;
}

std::shared_ptr<AbstractTestApi45> OLinkFactory::createTestApi45(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api45 = std::make_shared<OLinkTestApi45>();
    m_client.linkObjectSource(test_api45);
    return test_api45;
}

std::shared_ptr<AbstractTestApi46> OLinkFactory::createTestApi46(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api46 = std::make_shared<OLinkTestApi46>();
    m_client.linkObjectSource(test_api46);
    return test_api46;
}

std::shared_ptr<AbstractTestApi47> OLinkFactory::createTestApi47(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api47 = std::make_shared<OLinkTestApi47>();
    m_client.linkObjectSource(test_api47);
    return test_api47;
}

std::shared_ptr<AbstractTestApi48> OLinkFactory::createTestApi48(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api48 = std::make_shared<OLinkTestApi48>();
    m_client.linkObjectSource(test_api48);
    return test_api48;
}

std::shared_ptr<AbstractTestApi49> OLinkFactory::createTestApi49(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api49 = std::make_shared<OLinkTestApi49>();
    m_client.linkObjectSource(test_api49);
    return test_api49;
}

std::shared_ptr<AbstractTestApi50> OLinkFactory::createTestApi50(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api50 = std::make_shared<OLinkTestApi50>();
    m_client.linkObjectSource(test_api50);
    return test_api50;
}

std::shared_ptr<AbstractTestApi51> OLinkFactory::createTestApi51(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api51 = std::make_shared<OLinkTestApi51>();
    m_client.linkObjectSource(test_api51);
    return test_api51;
}

std::shared_ptr<AbstractTestApi52> OLinkFactory::createTestApi52(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api52 = std::make_shared<OLinkTestApi52>();
    m_client.linkObjectSource(test_api52);
    return test_api52;
}

std::shared_ptr<AbstractTestApi53> OLinkFactory::createTestApi53(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api53 = std::make_shared<OLinkTestApi53>();
    m_client.linkObjectSource(test_api53);
    return test_api53;
}

std::shared_ptr<AbstractTestApi54> OLinkFactory::createTestApi54(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api54 = std::make_shared<OLinkTestApi54>();
    m_client.linkObjectSource(test_api54);
    return test_api54;
}

std::shared_ptr<AbstractTestApi55> OLinkFactory::createTestApi55(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api55 = std::make_shared<OLinkTestApi55>();
    m_client.linkObjectSource(test_api55);
    return test_api55;
}

std::shared_ptr<AbstractTestApi56> OLinkFactory::createTestApi56(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api56 = std::make_shared<OLinkTestApi56>();
    m_client.linkObjectSource(test_api56);
    return test_api56;
}

std::shared_ptr<AbstractTestApi57> OLinkFactory::createTestApi57(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api57 = std::make_shared<OLinkTestApi57>();
    m_client.linkObjectSource(test_api57);
    return test_api57;
}

std::shared_ptr<AbstractTestApi58> OLinkFactory::createTestApi58(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api58 = std::make_shared<OLinkTestApi58>();
    m_client.linkObjectSource(test_api58);
    return test_api58;
}

std::shared_ptr<AbstractTestApi59> OLinkFactory::createTestApi59(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api59 = std::make_shared<OLinkTestApi59>();
    m_client.linkObjectSource(test_api59);
    return test_api59;
}

std::shared_ptr<AbstractTestApi60> OLinkFactory::createTestApi60(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api60 = std::make_shared<OLinkTestApi60>();
    m_client.linkObjectSource(test_api60);
    return test_api60;
}

std::shared_ptr<AbstractTestApi61> OLinkFactory::createTestApi61(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api61 = std::make_shared<OLinkTestApi61>();
    m_client.linkObjectSource(test_api61);
    return test_api61;
}

std::shared_ptr<AbstractTestApi62> OLinkFactory::createTestApi62(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api62 = std::make_shared<OLinkTestApi62>();
    m_client.linkObjectSource(test_api62);
    return test_api62;
}

std::shared_ptr<AbstractTestApi63> OLinkFactory::createTestApi63(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api63 = std::make_shared<OLinkTestApi63>();
    m_client.linkObjectSource(test_api63);
    return test_api63;
}

std::shared_ptr<AbstractTestApi64> OLinkFactory::createTestApi64(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api64 = std::make_shared<OLinkTestApi64>();
    m_client.linkObjectSource(test_api64);
    return test_api64;
}

std::shared_ptr<AbstractTestApi65> OLinkFactory::createTestApi65(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api65 = std::make_shared<OLinkTestApi65>();
    m_client.linkObjectSource(test_api65);
    return test_api65;
}

std::shared_ptr<AbstractTestApi66> OLinkFactory::createTestApi66(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api66 = std::make_shared<OLinkTestApi66>();
    m_client.linkObjectSource(test_api66);
    return test_api66;
}

std::shared_ptr<AbstractTestApi67> OLinkFactory::createTestApi67(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api67 = std::make_shared<OLinkTestApi67>();
    m_client.linkObjectSource(test_api67);
    return test_api67;
}

std::shared_ptr<AbstractTestApi68> OLinkFactory::createTestApi68(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api68 = std::make_shared<OLinkTestApi68>();
    m_client.linkObjectSource(test_api68);
    return test_api68;
}

std::shared_ptr<AbstractTestApi69> OLinkFactory::createTestApi69(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api69 = std::make_shared<OLinkTestApi69>();
    m_client.linkObjectSource(test_api69);
    return test_api69;
}

std::shared_ptr<AbstractTestApi70> OLinkFactory::createTestApi70(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api70 = std::make_shared<OLinkTestApi70>();
    m_client.linkObjectSource(test_api70);
    return test_api70;
}

std::shared_ptr<AbstractTestApi71> OLinkFactory::createTestApi71(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api71 = std::make_shared<OLinkTestApi71>();
    m_client.linkObjectSource(test_api71);
    return test_api71;
}

std::shared_ptr<AbstractTestApi72> OLinkFactory::createTestApi72(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api72 = std::make_shared<OLinkTestApi72>();
    m_client.linkObjectSource(test_api72);
    return test_api72;
}

std::shared_ptr<AbstractTestApi73> OLinkFactory::createTestApi73(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api73 = std::make_shared<OLinkTestApi73>();
    m_client.linkObjectSource(test_api73);
    return test_api73;
}

std::shared_ptr<AbstractTestApi74> OLinkFactory::createTestApi74(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api74 = std::make_shared<OLinkTestApi74>();
    m_client.linkObjectSource(test_api74);
    return test_api74;
}

std::shared_ptr<AbstractTestApi75> OLinkFactory::createTestApi75(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api75 = std::make_shared<OLinkTestApi75>();
    m_client.linkObjectSource(test_api75);
    return test_api75;
}

std::shared_ptr<AbstractTestApi76> OLinkFactory::createTestApi76(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api76 = std::make_shared<OLinkTestApi76>();
    m_client.linkObjectSource(test_api76);
    return test_api76;
}

std::shared_ptr<AbstractTestApi77> OLinkFactory::createTestApi77(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api77 = std::make_shared<OLinkTestApi77>();
    m_client.linkObjectSource(test_api77);
    return test_api77;
}

std::shared_ptr<AbstractTestApi78> OLinkFactory::createTestApi78(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api78 = std::make_shared<OLinkTestApi78>();
    m_client.linkObjectSource(test_api78);
    return test_api78;
}

std::shared_ptr<AbstractTestApi79> OLinkFactory::createTestApi79(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api79 = std::make_shared<OLinkTestApi79>();
    m_client.linkObjectSource(test_api79);
    return test_api79;
}

std::shared_ptr<AbstractTestApi80> OLinkFactory::createTestApi80(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api80 = std::make_shared<OLinkTestApi80>();
    m_client.linkObjectSource(test_api80);
    return test_api80;
}

std::shared_ptr<AbstractTestApi81> OLinkFactory::createTestApi81(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api81 = std::make_shared<OLinkTestApi81>();
    m_client.linkObjectSource(test_api81);
    return test_api81;
}

std::shared_ptr<AbstractTestApi82> OLinkFactory::createTestApi82(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api82 = std::make_shared<OLinkTestApi82>();
    m_client.linkObjectSource(test_api82);
    return test_api82;
}

std::shared_ptr<AbstractTestApi83> OLinkFactory::createTestApi83(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api83 = std::make_shared<OLinkTestApi83>();
    m_client.linkObjectSource(test_api83);
    return test_api83;
}

std::shared_ptr<AbstractTestApi84> OLinkFactory::createTestApi84(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api84 = std::make_shared<OLinkTestApi84>();
    m_client.linkObjectSource(test_api84);
    return test_api84;
}

std::shared_ptr<AbstractTestApi85> OLinkFactory::createTestApi85(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api85 = std::make_shared<OLinkTestApi85>();
    m_client.linkObjectSource(test_api85);
    return test_api85;
}

std::shared_ptr<AbstractTestApi86> OLinkFactory::createTestApi86(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api86 = std::make_shared<OLinkTestApi86>();
    m_client.linkObjectSource(test_api86);
    return test_api86;
}

std::shared_ptr<AbstractTestApi87> OLinkFactory::createTestApi87(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api87 = std::make_shared<OLinkTestApi87>();
    m_client.linkObjectSource(test_api87);
    return test_api87;
}

std::shared_ptr<AbstractTestApi88> OLinkFactory::createTestApi88(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api88 = std::make_shared<OLinkTestApi88>();
    m_client.linkObjectSource(test_api88);
    return test_api88;
}

std::shared_ptr<AbstractTestApi89> OLinkFactory::createTestApi89(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api89 = std::make_shared<OLinkTestApi89>();
    m_client.linkObjectSource(test_api89);
    return test_api89;
}

std::shared_ptr<AbstractTestApi90> OLinkFactory::createTestApi90(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api90 = std::make_shared<OLinkTestApi90>();
    m_client.linkObjectSource(test_api90);
    return test_api90;
}

std::shared_ptr<AbstractTestApi91> OLinkFactory::createTestApi91(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api91 = std::make_shared<OLinkTestApi91>();
    m_client.linkObjectSource(test_api91);
    return test_api91;
}

std::shared_ptr<AbstractTestApi92> OLinkFactory::createTestApi92(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api92 = std::make_shared<OLinkTestApi92>();
    m_client.linkObjectSource(test_api92);
    return test_api92;
}

std::shared_ptr<AbstractTestApi93> OLinkFactory::createTestApi93(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api93 = std::make_shared<OLinkTestApi93>();
    m_client.linkObjectSource(test_api93);
    return test_api93;
}

std::shared_ptr<AbstractTestApi94> OLinkFactory::createTestApi94(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api94 = std::make_shared<OLinkTestApi94>();
    m_client.linkObjectSource(test_api94);
    return test_api94;
}

std::shared_ptr<AbstractTestApi95> OLinkFactory::createTestApi95(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api95 = std::make_shared<OLinkTestApi95>();
    m_client.linkObjectSource(test_api95);
    return test_api95;
}

std::shared_ptr<AbstractTestApi96> OLinkFactory::createTestApi96(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api96 = std::make_shared<OLinkTestApi96>();
    m_client.linkObjectSource(test_api96);
    return test_api96;
}

std::shared_ptr<AbstractTestApi97> OLinkFactory::createTestApi97(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api97 = std::make_shared<OLinkTestApi97>();
    m_client.linkObjectSource(test_api97);
    return test_api97;
}

std::shared_ptr<AbstractTestApi98> OLinkFactory::createTestApi98(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api98 = std::make_shared<OLinkTestApi98>();
    m_client.linkObjectSource(test_api98);
    return test_api98;
}

std::shared_ptr<AbstractTestApi99> OLinkFactory::createTestApi99(QObject *parent)
{
    qDebug() << Q_FUNC_INFO;
    auto test_api99 = std::make_shared<OLinkTestApi99>();
    m_client.linkObjectSource(test_api99);
    return test_api99;
}

} //namespace api