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
#include "olinktestapi63.h"

#include "api/api/json.adapter.h"

#include "olink/iclientnode.h"

#include <QtCore>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace api {

OLinkTestApi63::OLinkTestApi63(QObject *parent)
    : AbstractTestApi63(parent)
    , m_propInt(0)
    , m_propFloat(0.0f)
    , m_propString(QString())
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
}

void OLinkTestApi63::applyState(const nlohmann::json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<int>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<qreal>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<QString>());
    }
}

void OLinkTestApi63::setPropInt(int propInt)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("api.TestApi63/propInt", propInt);
}

void OLinkTestApi63::setPropIntLocal(int propInt)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

int OLinkTestApi63::propInt() const
{
    return m_propInt;
}

void OLinkTestApi63::setPropFloat(qreal propFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("api.TestApi63/propFloat", propFloat);
}

void OLinkTestApi63::setPropFloatLocal(qreal propFloat)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

qreal OLinkTestApi63::propFloat() const
{
    return m_propFloat;
}

void OLinkTestApi63::setPropString(const QString& propString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("api.TestApi63/propString", propString);
}

void OLinkTestApi63::setPropStringLocal(const QString& propString)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

QString OLinkTestApi63::propString() const
{
    return m_propString;
}

int OLinkTestApi63::funcInt(int paramInt)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return 0;
    }
    int value{ 0 };
    funcIntAsync(paramInt)
        .then([&](int result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<int> OLinkTestApi63::funcIntAsync(int paramInt)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<int>::reject("not initialized");
    }
    return QtPromise::QPromise<int>{[&](
        const QtPromise::QPromiseResolve<int>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramInt}), [resolve](InvokeReplyArg arg) {                
                const int& value = arg.value.get<int>();
                resolve(value);
            });
        }
    };
}

qreal OLinkTestApi63::funcFloat(qreal paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return 0.0f;
    }
    qreal value{ 0.0f };
    funcFloatAsync(paramFloat)
        .then([&](qreal result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<qreal> OLinkTestApi63::funcFloatAsync(qreal paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<qreal>::reject("not initialized");
    }
    return QtPromise::QPromise<qreal>{[&](
        const QtPromise::QPromiseResolve<qreal>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat}), [resolve](InvokeReplyArg arg) {                
                const qreal& value = arg.value.get<qreal>();
                resolve(value);
            });
        }
    };
}

QString OLinkTestApi63::funcString(const QString& paramString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QString();
    }
    QString value{ QString() };
    funcStringAsync(paramString)
        .then([&](QString result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QString> OLinkTestApi63::funcStringAsync(const QString& paramString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<QString>::reject("not initialized");
    }
    return QtPromise::QPromise<QString>{[&](
        const QtPromise::QPromiseResolve<QString>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramString}), [resolve](InvokeReplyArg arg) {                
                const QString& value = arg.value.get<QString>();
                resolve(value);
            });
        }
    };
}


std::string OLinkTestApi63::olinkObjectName()
{
    return "api.TestApi63";
}

void OLinkTestApi63::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sigInt") {
        emit sigInt(args[0].get<int>());   
        return;
    }
    if(signalName == "sigFloat") {
        emit sigFloat(args[0].get<qreal>());   
        return;
    }
    if(signalName == "sigString") {
        emit sigString(args[0].get<QString>());   
        return;
    }
}

void OLinkTestApi63::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyState({ {propertyName, value} });
}
void OLinkTestApi63::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkTestApi63::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}

} //namespace api
