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
#include <QtPromise>

#include "../api/api.h"
#include "objectlink/olink/clientnode.h"

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

class OLinkEnumInterface : public AbstractEnumInterface, public IObjectSink
{
    Q_OBJECT
public:
    explicit OLinkEnumInterface(QObject *parent = nullptr);
    virtual ~OLinkEnumInterface() override;

    void applyState(const nlohmann::json& fields);
    Enum0::Enum0Enum prop0() const override;
    void setProp0(const Enum0::Enum0Enum prop0) override;
    void setProp0Local(const Enum0::Enum0Enum prop0);
    Enum1::Enum1Enum prop1() const override;
    void setProp1(const Enum1::Enum1Enum prop1) override;
    void setProp1Local(const Enum1::Enum1Enum prop1);
    Enum2::Enum2Enum prop2() const override;
    void setProp2(const Enum2::Enum2Enum prop2) override;
    void setProp2Local(const Enum2::Enum2Enum prop2);
    Enum3::Enum3Enum prop3() const override;
    void setProp3(const Enum3::Enum3Enum prop3) override;
    void setProp3Local(const Enum3::Enum3Enum prop3);
    Enum0::Enum0Enum func0(const Enum0::Enum0Enum param0) override;
    QtPromise::QPromise<Enum0::Enum0Enum> func0Async(const Enum0::Enum0Enum param0);
    Enum1::Enum1Enum func1(const Enum1::Enum1Enum param1) override;
    QtPromise::QPromise<Enum1::Enum1Enum> func1Async(const Enum1::Enum1Enum param1);
    Enum2::Enum2Enum func2(const Enum2::Enum2Enum param2) override;
    QtPromise::QPromise<Enum2::Enum2Enum> func2Async(const Enum2::Enum2Enum param2);
    Enum3::Enum3Enum func3(const Enum3::Enum3Enum param3) override;
    QtPromise::QPromise<Enum3::Enum3Enum> func3Async(const Enum3::Enum3Enum param3);
signals:
    void isReady();
public:
    virtual std::string olinkObjectName() override;
    virtual void olinkOnSignal(std::string name, nlohmann::json args) override;
    virtual void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    virtual void olinkOnInit(std::string name, nlohmann::json props, IClientNode *node) override;
    virtual void olinkOnRelease() override;
private:
    Enum0::Enum0Enum m_prop0;
    Enum1::Enum1Enum m_prop1;
    Enum2::Enum2Enum m_prop2;
    Enum3::Enum3Enum m_prop3;
    bool m_isReady;
    IClientNode *m_node;
};
