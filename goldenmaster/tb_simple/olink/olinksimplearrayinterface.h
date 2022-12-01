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

class OLinkSimpleArrayInterface : public AbstractSimpleArrayInterface, public IObjectSink
{
    Q_OBJECT
public:
    explicit OLinkSimpleArrayInterface(QObject *parent = nullptr);
    virtual ~OLinkSimpleArrayInterface() = default;

    void applyState(const nlohmann::json& fields);
    QList<bool> propBool() const override;
    void setPropBool(const QList<bool>& propBool) override;
    void setPropBoolLocal(const QList<bool>& propBool);
    QList<int> propInt() const override;
    void setPropInt(const QList<int>& propInt) override;
    void setPropIntLocal(const QList<int>& propInt);
    QList<qreal> propFloat() const override;
    void setPropFloat(const QList<qreal>& propFloat) override;
    void setPropFloatLocal(const QList<qreal>& propFloat);
    QList<QString> propString() const override;
    void setPropString(const QList<QString>& propString) override;
    void setPropStringLocal(const QList<QString>& propString);
    QList<bool> funcBool(const QList<bool>& paramBool) override;
    QtPromise::QPromise<QList<bool>> funcBoolAsync(const QList<bool>& paramBool);
    QList<int> funcInt(const QList<int>& paramInt) override;
    QtPromise::QPromise<QList<int>> funcIntAsync(const QList<int>& paramInt);
    QList<qreal> funcFloat(const QList<qreal>& paramFloat) override;
    QtPromise::QPromise<QList<qreal>> funcFloatAsync(const QList<qreal>& paramFloat);
    QList<QString> funcString(const QList<QString>& paramString) override;
    QtPromise::QPromise<QList<QString>> funcStringAsync(const QList<QString>& paramString);
signals:
    void isReady();
public:
    virtual std::string olinkObjectName() override;
    virtual void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override;
    virtual void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override;
    virtual void olinkOnInit(const std::string& objectId, const nlohmann::json& props, ::ApiGear::ObjectLink::IClientNode *node) override;
    virtual void olinkOnRelease() override;
private:
    QList<bool> m_propBool;
    QList<int> m_propInt;
    QList<qreal> m_propFloat;
    QList<QString> m_propString;
    bool m_isReady;
    IClientNode *m_node;
};

} //namespace tb_simple
