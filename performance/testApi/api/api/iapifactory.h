/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include <QtCore>
#include <QtCore/QtGlobal>

#include <memory>

#if defined(API_API_LIBRARY)
#  define API_API_EXPORT Q_DECL_EXPORT
#else
#  define API_API_EXPORT Q_DECL_IMPORT
#endif

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
* An interface for a Factory of interfaces in api
* May be used to provide different implementations of your interfaces.
* Check the usage of IApiFactory in Qml versions of interface implementation.
* See also the ApiFactory, where you can set this factory as an IApiFactory implementation.
*/
class API_API_EXPORT IApiFactory
{
public:
    /** 
    * Create an instance of TestApi0
    * @return The implementation of a AbstractTestApi0.
    */
    virtual std::shared_ptr<AbstractTestApi0> createTestApi0(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi1
    * @return The implementation of a AbstractTestApi1.
    */
    virtual std::shared_ptr<AbstractTestApi1> createTestApi1(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi2
    * @return The implementation of a AbstractTestApi2.
    */
    virtual std::shared_ptr<AbstractTestApi2> createTestApi2(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi3
    * @return The implementation of a AbstractTestApi3.
    */
    virtual std::shared_ptr<AbstractTestApi3> createTestApi3(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi4
    * @return The implementation of a AbstractTestApi4.
    */
    virtual std::shared_ptr<AbstractTestApi4> createTestApi4(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi5
    * @return The implementation of a AbstractTestApi5.
    */
    virtual std::shared_ptr<AbstractTestApi5> createTestApi5(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi6
    * @return The implementation of a AbstractTestApi6.
    */
    virtual std::shared_ptr<AbstractTestApi6> createTestApi6(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi7
    * @return The implementation of a AbstractTestApi7.
    */
    virtual std::shared_ptr<AbstractTestApi7> createTestApi7(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi8
    * @return The implementation of a AbstractTestApi8.
    */
    virtual std::shared_ptr<AbstractTestApi8> createTestApi8(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi9
    * @return The implementation of a AbstractTestApi9.
    */
    virtual std::shared_ptr<AbstractTestApi9> createTestApi9(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi10
    * @return The implementation of a AbstractTestApi10.
    */
    virtual std::shared_ptr<AbstractTestApi10> createTestApi10(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi11
    * @return The implementation of a AbstractTestApi11.
    */
    virtual std::shared_ptr<AbstractTestApi11> createTestApi11(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi12
    * @return The implementation of a AbstractTestApi12.
    */
    virtual std::shared_ptr<AbstractTestApi12> createTestApi12(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi13
    * @return The implementation of a AbstractTestApi13.
    */
    virtual std::shared_ptr<AbstractTestApi13> createTestApi13(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi14
    * @return The implementation of a AbstractTestApi14.
    */
    virtual std::shared_ptr<AbstractTestApi14> createTestApi14(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi15
    * @return The implementation of a AbstractTestApi15.
    */
    virtual std::shared_ptr<AbstractTestApi15> createTestApi15(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi16
    * @return The implementation of a AbstractTestApi16.
    */
    virtual std::shared_ptr<AbstractTestApi16> createTestApi16(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi17
    * @return The implementation of a AbstractTestApi17.
    */
    virtual std::shared_ptr<AbstractTestApi17> createTestApi17(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi18
    * @return The implementation of a AbstractTestApi18.
    */
    virtual std::shared_ptr<AbstractTestApi18> createTestApi18(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi19
    * @return The implementation of a AbstractTestApi19.
    */
    virtual std::shared_ptr<AbstractTestApi19> createTestApi19(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi20
    * @return The implementation of a AbstractTestApi20.
    */
    virtual std::shared_ptr<AbstractTestApi20> createTestApi20(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi21
    * @return The implementation of a AbstractTestApi21.
    */
    virtual std::shared_ptr<AbstractTestApi21> createTestApi21(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi22
    * @return The implementation of a AbstractTestApi22.
    */
    virtual std::shared_ptr<AbstractTestApi22> createTestApi22(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi23
    * @return The implementation of a AbstractTestApi23.
    */
    virtual std::shared_ptr<AbstractTestApi23> createTestApi23(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi24
    * @return The implementation of a AbstractTestApi24.
    */
    virtual std::shared_ptr<AbstractTestApi24> createTestApi24(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi25
    * @return The implementation of a AbstractTestApi25.
    */
    virtual std::shared_ptr<AbstractTestApi25> createTestApi25(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi26
    * @return The implementation of a AbstractTestApi26.
    */
    virtual std::shared_ptr<AbstractTestApi26> createTestApi26(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi27
    * @return The implementation of a AbstractTestApi27.
    */
    virtual std::shared_ptr<AbstractTestApi27> createTestApi27(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi28
    * @return The implementation of a AbstractTestApi28.
    */
    virtual std::shared_ptr<AbstractTestApi28> createTestApi28(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi29
    * @return The implementation of a AbstractTestApi29.
    */
    virtual std::shared_ptr<AbstractTestApi29> createTestApi29(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi30
    * @return The implementation of a AbstractTestApi30.
    */
    virtual std::shared_ptr<AbstractTestApi30> createTestApi30(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi31
    * @return The implementation of a AbstractTestApi31.
    */
    virtual std::shared_ptr<AbstractTestApi31> createTestApi31(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi32
    * @return The implementation of a AbstractTestApi32.
    */
    virtual std::shared_ptr<AbstractTestApi32> createTestApi32(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi33
    * @return The implementation of a AbstractTestApi33.
    */
    virtual std::shared_ptr<AbstractTestApi33> createTestApi33(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi34
    * @return The implementation of a AbstractTestApi34.
    */
    virtual std::shared_ptr<AbstractTestApi34> createTestApi34(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi35
    * @return The implementation of a AbstractTestApi35.
    */
    virtual std::shared_ptr<AbstractTestApi35> createTestApi35(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi36
    * @return The implementation of a AbstractTestApi36.
    */
    virtual std::shared_ptr<AbstractTestApi36> createTestApi36(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi37
    * @return The implementation of a AbstractTestApi37.
    */
    virtual std::shared_ptr<AbstractTestApi37> createTestApi37(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi38
    * @return The implementation of a AbstractTestApi38.
    */
    virtual std::shared_ptr<AbstractTestApi38> createTestApi38(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi39
    * @return The implementation of a AbstractTestApi39.
    */
    virtual std::shared_ptr<AbstractTestApi39> createTestApi39(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi40
    * @return The implementation of a AbstractTestApi40.
    */
    virtual std::shared_ptr<AbstractTestApi40> createTestApi40(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi41
    * @return The implementation of a AbstractTestApi41.
    */
    virtual std::shared_ptr<AbstractTestApi41> createTestApi41(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi42
    * @return The implementation of a AbstractTestApi42.
    */
    virtual std::shared_ptr<AbstractTestApi42> createTestApi42(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi43
    * @return The implementation of a AbstractTestApi43.
    */
    virtual std::shared_ptr<AbstractTestApi43> createTestApi43(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi44
    * @return The implementation of a AbstractTestApi44.
    */
    virtual std::shared_ptr<AbstractTestApi44> createTestApi44(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi45
    * @return The implementation of a AbstractTestApi45.
    */
    virtual std::shared_ptr<AbstractTestApi45> createTestApi45(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi46
    * @return The implementation of a AbstractTestApi46.
    */
    virtual std::shared_ptr<AbstractTestApi46> createTestApi46(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi47
    * @return The implementation of a AbstractTestApi47.
    */
    virtual std::shared_ptr<AbstractTestApi47> createTestApi47(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi48
    * @return The implementation of a AbstractTestApi48.
    */
    virtual std::shared_ptr<AbstractTestApi48> createTestApi48(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi49
    * @return The implementation of a AbstractTestApi49.
    */
    virtual std::shared_ptr<AbstractTestApi49> createTestApi49(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi50
    * @return The implementation of a AbstractTestApi50.
    */
    virtual std::shared_ptr<AbstractTestApi50> createTestApi50(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi51
    * @return The implementation of a AbstractTestApi51.
    */
    virtual std::shared_ptr<AbstractTestApi51> createTestApi51(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi52
    * @return The implementation of a AbstractTestApi52.
    */
    virtual std::shared_ptr<AbstractTestApi52> createTestApi52(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi53
    * @return The implementation of a AbstractTestApi53.
    */
    virtual std::shared_ptr<AbstractTestApi53> createTestApi53(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi54
    * @return The implementation of a AbstractTestApi54.
    */
    virtual std::shared_ptr<AbstractTestApi54> createTestApi54(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi55
    * @return The implementation of a AbstractTestApi55.
    */
    virtual std::shared_ptr<AbstractTestApi55> createTestApi55(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi56
    * @return The implementation of a AbstractTestApi56.
    */
    virtual std::shared_ptr<AbstractTestApi56> createTestApi56(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi57
    * @return The implementation of a AbstractTestApi57.
    */
    virtual std::shared_ptr<AbstractTestApi57> createTestApi57(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi58
    * @return The implementation of a AbstractTestApi58.
    */
    virtual std::shared_ptr<AbstractTestApi58> createTestApi58(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi59
    * @return The implementation of a AbstractTestApi59.
    */
    virtual std::shared_ptr<AbstractTestApi59> createTestApi59(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi60
    * @return The implementation of a AbstractTestApi60.
    */
    virtual std::shared_ptr<AbstractTestApi60> createTestApi60(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi61
    * @return The implementation of a AbstractTestApi61.
    */
    virtual std::shared_ptr<AbstractTestApi61> createTestApi61(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi62
    * @return The implementation of a AbstractTestApi62.
    */
    virtual std::shared_ptr<AbstractTestApi62> createTestApi62(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi63
    * @return The implementation of a AbstractTestApi63.
    */
    virtual std::shared_ptr<AbstractTestApi63> createTestApi63(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi64
    * @return The implementation of a AbstractTestApi64.
    */
    virtual std::shared_ptr<AbstractTestApi64> createTestApi64(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi65
    * @return The implementation of a AbstractTestApi65.
    */
    virtual std::shared_ptr<AbstractTestApi65> createTestApi65(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi66
    * @return The implementation of a AbstractTestApi66.
    */
    virtual std::shared_ptr<AbstractTestApi66> createTestApi66(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi67
    * @return The implementation of a AbstractTestApi67.
    */
    virtual std::shared_ptr<AbstractTestApi67> createTestApi67(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi68
    * @return The implementation of a AbstractTestApi68.
    */
    virtual std::shared_ptr<AbstractTestApi68> createTestApi68(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi69
    * @return The implementation of a AbstractTestApi69.
    */
    virtual std::shared_ptr<AbstractTestApi69> createTestApi69(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi70
    * @return The implementation of a AbstractTestApi70.
    */
    virtual std::shared_ptr<AbstractTestApi70> createTestApi70(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi71
    * @return The implementation of a AbstractTestApi71.
    */
    virtual std::shared_ptr<AbstractTestApi71> createTestApi71(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi72
    * @return The implementation of a AbstractTestApi72.
    */
    virtual std::shared_ptr<AbstractTestApi72> createTestApi72(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi73
    * @return The implementation of a AbstractTestApi73.
    */
    virtual std::shared_ptr<AbstractTestApi73> createTestApi73(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi74
    * @return The implementation of a AbstractTestApi74.
    */
    virtual std::shared_ptr<AbstractTestApi74> createTestApi74(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi75
    * @return The implementation of a AbstractTestApi75.
    */
    virtual std::shared_ptr<AbstractTestApi75> createTestApi75(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi76
    * @return The implementation of a AbstractTestApi76.
    */
    virtual std::shared_ptr<AbstractTestApi76> createTestApi76(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi77
    * @return The implementation of a AbstractTestApi77.
    */
    virtual std::shared_ptr<AbstractTestApi77> createTestApi77(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi78
    * @return The implementation of a AbstractTestApi78.
    */
    virtual std::shared_ptr<AbstractTestApi78> createTestApi78(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi79
    * @return The implementation of a AbstractTestApi79.
    */
    virtual std::shared_ptr<AbstractTestApi79> createTestApi79(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi80
    * @return The implementation of a AbstractTestApi80.
    */
    virtual std::shared_ptr<AbstractTestApi80> createTestApi80(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi81
    * @return The implementation of a AbstractTestApi81.
    */
    virtual std::shared_ptr<AbstractTestApi81> createTestApi81(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi82
    * @return The implementation of a AbstractTestApi82.
    */
    virtual std::shared_ptr<AbstractTestApi82> createTestApi82(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi83
    * @return The implementation of a AbstractTestApi83.
    */
    virtual std::shared_ptr<AbstractTestApi83> createTestApi83(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi84
    * @return The implementation of a AbstractTestApi84.
    */
    virtual std::shared_ptr<AbstractTestApi84> createTestApi84(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi85
    * @return The implementation of a AbstractTestApi85.
    */
    virtual std::shared_ptr<AbstractTestApi85> createTestApi85(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi86
    * @return The implementation of a AbstractTestApi86.
    */
    virtual std::shared_ptr<AbstractTestApi86> createTestApi86(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi87
    * @return The implementation of a AbstractTestApi87.
    */
    virtual std::shared_ptr<AbstractTestApi87> createTestApi87(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi88
    * @return The implementation of a AbstractTestApi88.
    */
    virtual std::shared_ptr<AbstractTestApi88> createTestApi88(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi89
    * @return The implementation of a AbstractTestApi89.
    */
    virtual std::shared_ptr<AbstractTestApi89> createTestApi89(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi90
    * @return The implementation of a AbstractTestApi90.
    */
    virtual std::shared_ptr<AbstractTestApi90> createTestApi90(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi91
    * @return The implementation of a AbstractTestApi91.
    */
    virtual std::shared_ptr<AbstractTestApi91> createTestApi91(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi92
    * @return The implementation of a AbstractTestApi92.
    */
    virtual std::shared_ptr<AbstractTestApi92> createTestApi92(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi93
    * @return The implementation of a AbstractTestApi93.
    */
    virtual std::shared_ptr<AbstractTestApi93> createTestApi93(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi94
    * @return The implementation of a AbstractTestApi94.
    */
    virtual std::shared_ptr<AbstractTestApi94> createTestApi94(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi95
    * @return The implementation of a AbstractTestApi95.
    */
    virtual std::shared_ptr<AbstractTestApi95> createTestApi95(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi96
    * @return The implementation of a AbstractTestApi96.
    */
    virtual std::shared_ptr<AbstractTestApi96> createTestApi96(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi97
    * @return The implementation of a AbstractTestApi97.
    */
    virtual std::shared_ptr<AbstractTestApi97> createTestApi97(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi98
    * @return The implementation of a AbstractTestApi98.
    */
    virtual std::shared_ptr<AbstractTestApi98> createTestApi98(QObject *parent = nullptr) = 0;
    /** 
    * Create an instance of TestApi99
    * @return The implementation of a AbstractTestApi99.
    */
    virtual std::shared_ptr<AbstractTestApi99> createTestApi99(QObject *parent = nullptr) = 0;
};

} //namespace api
