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

#include "tb_simple/api/api.h"
#include "olink/iobjectsink.h"

#include <nlohmann/json.hpp>

namespace ApiGear {
namespace ObjectLink {
class IClientNode;
}}


using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_simple {

class OLinkSimpleInterface : public AbstractSimpleInterface, public IObjectSink
{
    Q_OBJECT
public:
    explicit OLinkSimpleInterface(QObject *parent = nullptr);
    virtual ~OLinkSimpleInterface() = default;

    void applyState(const nlohmann::json& fields);
    bool propBool() const override;
    void setPropBool(bool propBool) override;
    void setPropBoolLocal(bool propBool);
    int propInt() const override;
    void setPropInt(int propInt) override;
    void setPropIntLocal(int propInt);
    qreal propFloat() const override;
    void setPropFloat(qreal propFloat) override;
    void setPropFloatLocal(qreal propFloat);
    QString propString() const override;
    void setPropString(const QString& propString) override;
    void setPropStringLocal(const QString& propString);
    bool funcBool(bool paramBool) override;
    QtPromise::QPromise<bool> funcBoolAsync(bool paramBool);
    int funcInt(int paramInt) override;
    QtPromise::QPromise<int> funcIntAsync(int paramInt);
    qreal funcFloat(qreal paramFloat) override;
    QtPromise::QPromise<qreal> funcFloatAsync(qreal paramFloat);
    QString funcString(const QString& paramString) override;
    QtPromise::QPromise<QString> funcStringAsync(const QString& paramString);
signals:
    void isReady();
public:
    virtual std::string olinkObjectName() override;
    virtual void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override;
    virtual void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override;
    virtual void olinkOnInit(const std::string& objectId, const nlohmann::json& props, ::ApiGear::ObjectLink::IClientNode *node) override;
    virtual void olinkOnRelease() override;
private:
    bool m_propBool;
    int m_propInt;
    qreal m_propFloat;
    QString m_propString;
    bool m_isReady;
    IClientNode *m_node;
};

} //namespace tb_simple
