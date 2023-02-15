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
#include "olinksimplearrayinterface.h"

#include "tb_simple/api/agent.h"
#include "tb_simple/api/json.adapter.h"

#include "olink/iclientnode.h"

#include <QtCore>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_simple {

OLinkSimpleArrayInterface::OLinkSimpleArrayInterface(QObject *parent)
    : AbstractSimpleArrayInterface(parent)
    , m_propBool(QList<bool>())
    , m_propInt(QList<int>())
    , m_propInt32(QList<qint32>())
    , m_propInt64(QList<qint64>())
    , m_propFloat(QList<qreal>())
    , m_propFloat32(QList<float>())
    , m_propFloat64(QList<double>())
    , m_propString(QList<QString>())
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
}

void OLinkSimpleArrayInterface::applyState(const nlohmann::json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<QList<bool>>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<QList<int>>());
    }
    if(fields.contains("propInt32")) {
        setPropInt32Local(fields["propInt32"].get<QList<qint32>>());
    }
    if(fields.contains("propInt64")) {
        setPropInt64Local(fields["propInt64"].get<QList<qint64>>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<QList<qreal>>());
    }
    if(fields.contains("propFloat32")) {
        setPropFloat32Local(fields["propFloat32"].get<QList<float>>());
    }
    if(fields.contains("propFloat64")) {
        setPropFloat64Local(fields["propFloat64"].get<QList<double>>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<QList<QString>>());
    }
}

void OLinkSimpleArrayInterface::setPropBool(const QList<bool>& propBool)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propBool", propBool);
}

void OLinkSimpleArrayInterface::setPropBoolLocal(const QList<bool>& propBool)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<bool> OLinkSimpleArrayInterface::propBool() const
{
    return m_propBool;
}

void OLinkSimpleArrayInterface::setPropInt(const QList<int>& propInt)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propInt", propInt);
}

void OLinkSimpleArrayInterface::setPropIntLocal(const QList<int>& propInt)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<int> OLinkSimpleArrayInterface::propInt() const
{
    return m_propInt;
}

void OLinkSimpleArrayInterface::setPropInt32(const QList<qint32>& propInt32)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propInt32", propInt32);
}

void OLinkSimpleArrayInterface::setPropInt32Local(const QList<qint32>& propInt32)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propInt32 != propInt32) {
        m_propInt32 = propInt32;
        emit propInt32Changed(propInt32);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<qint32> OLinkSimpleArrayInterface::propInt32() const
{
    return m_propInt32;
}

void OLinkSimpleArrayInterface::setPropInt64(const QList<qint64>& propInt64)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propInt64", propInt64);
}

void OLinkSimpleArrayInterface::setPropInt64Local(const QList<qint64>& propInt64)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propInt64 != propInt64) {
        m_propInt64 = propInt64;
        emit propInt64Changed(propInt64);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<qint64> OLinkSimpleArrayInterface::propInt64() const
{
    return m_propInt64;
}

void OLinkSimpleArrayInterface::setPropFloat(const QList<qreal>& propFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propFloat", propFloat);
}

void OLinkSimpleArrayInterface::setPropFloatLocal(const QList<qreal>& propFloat)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<qreal> OLinkSimpleArrayInterface::propFloat() const
{
    return m_propFloat;
}

void OLinkSimpleArrayInterface::setPropFloat32(const QList<float>& propFloat32)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propFloat32", propFloat32);
}

void OLinkSimpleArrayInterface::setPropFloat32Local(const QList<float>& propFloat32)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propFloat32 != propFloat32) {
        m_propFloat32 = propFloat32;
        emit propFloat32Changed(propFloat32);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<float> OLinkSimpleArrayInterface::propFloat32() const
{
    return m_propFloat32;
}

void OLinkSimpleArrayInterface::setPropFloat64(const QList<double>& propFloat64)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propFloat64", propFloat64);
}

void OLinkSimpleArrayInterface::setPropFloat64Local(const QList<double>& propFloat64)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propFloat64 != propFloat64) {
        m_propFloat64 = propFloat64;
        emit propFloat64Changed(propFloat64);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<double> OLinkSimpleArrayInterface::propFloat64() const
{
    return m_propFloat64;
}

void OLinkSimpleArrayInterface::setPropString(const QList<QString>& propString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propString", propString);
}

void OLinkSimpleArrayInterface::setPropStringLocal(const QList<QString>& propString)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
        SimpleArrayInterfaceAgent::trace_state(this);
    }
}

QList<QString> OLinkSimpleArrayInterface::propString() const
{
    return m_propString;
}

QList<bool> OLinkSimpleArrayInterface::funcBool(const QList<bool>& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QList<bool>();
    }
    QList<bool> value{ QList<bool>() };
    funcBoolAsync(paramBool)
        .then([&](QList<bool> result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QList<bool>> OLinkSimpleArrayInterface::funcBoolAsync(const QList<bool>& paramBool)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<QList<bool>>::reject("not initialized");
    }
    return QtPromise::QPromise<QList<bool>>{[&](
        const QtPromise::QPromiseResolve<QList<bool>>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramBool}), [resolve](InvokeReplyArg arg) {                
                const QList<bool>& value = arg.value.get<QList<bool>>();
                resolve(value);
            });
        }
    };
}

QList<int> OLinkSimpleArrayInterface::funcInt(const QList<int>& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QList<int>();
    }
    QList<int> value{ QList<int>() };
    funcIntAsync(paramInt)
        .then([&](QList<int> result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QList<int>> OLinkSimpleArrayInterface::funcIntAsync(const QList<int>& paramInt)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<QList<int>>::reject("not initialized");
    }
    return QtPromise::QPromise<QList<int>>{[&](
        const QtPromise::QPromiseResolve<QList<int>>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramInt}), [resolve](InvokeReplyArg arg) {                
                const QList<int>& value = arg.value.get<QList<int>>();
                resolve(value);
            });
        }
    };
}

QList<qint32> OLinkSimpleArrayInterface::funcInt32(const QList<qint32>& paramInt32)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QList<qint32>();
    }
    QList<qint32> value{ QList<qint32>() };
    funcInt32Async(paramInt32)
        .then([&](QList<qint32> result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QList<qint32>> OLinkSimpleArrayInterface::funcInt32Async(const QList<qint32>& paramInt32)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<QList<qint32>>::reject("not initialized");
    }
    return QtPromise::QPromise<QList<qint32>>{[&](
        const QtPromise::QPromiseResolve<QList<qint32>>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt32");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramInt32}), [resolve](InvokeReplyArg arg) {                
                const QList<qint32>& value = arg.value.get<QList<qint32>>();
                resolve(value);
            });
        }
    };
}

QList<qint64> OLinkSimpleArrayInterface::funcInt64(const QList<qint64>& paramInt64)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QList<qint64>();
    }
    QList<qint64> value{ QList<qint64>() };
    funcInt64Async(paramInt64)
        .then([&](QList<qint64> result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QList<qint64>> OLinkSimpleArrayInterface::funcInt64Async(const QList<qint64>& paramInt64)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<QList<qint64>>::reject("not initialized");
    }
    return QtPromise::QPromise<QList<qint64>>{[&](
        const QtPromise::QPromiseResolve<QList<qint64>>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt64");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramInt64}), [resolve](InvokeReplyArg arg) {                
                const QList<qint64>& value = arg.value.get<QList<qint64>>();
                resolve(value);
            });
        }
    };
}

QList<qreal> OLinkSimpleArrayInterface::funcFloat(const QList<qreal>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QList<qreal>();
    }
    QList<qreal> value{ QList<qreal>() };
    funcFloatAsync(paramFloat)
        .then([&](QList<qreal> result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QList<qreal>> OLinkSimpleArrayInterface::funcFloatAsync(const QList<qreal>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<QList<qreal>>::reject("not initialized");
    }
    return QtPromise::QPromise<QList<qreal>>{[&](
        const QtPromise::QPromiseResolve<QList<qreal>>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat}), [resolve](InvokeReplyArg arg) {                
                const QList<qreal>& value = arg.value.get<QList<qreal>>();
                resolve(value);
            });
        }
    };
}

QList<float> OLinkSimpleArrayInterface::funcFloat32(const QList<float>& paramFloat32)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QList<float>();
    }
    QList<float> value{ QList<float>() };
    funcFloat32Async(paramFloat32)
        .then([&](QList<float> result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QList<float>> OLinkSimpleArrayInterface::funcFloat32Async(const QList<float>& paramFloat32)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<QList<float>>::reject("not initialized");
    }
    return QtPromise::QPromise<QList<float>>{[&](
        const QtPromise::QPromiseResolve<QList<float>>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat32");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat32}), [resolve](InvokeReplyArg arg) {                
                const QList<float>& value = arg.value.get<QList<float>>();
                resolve(value);
            });
        }
    };
}

QList<double> OLinkSimpleArrayInterface::funcFloat64(const QList<double>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QList<double>();
    }
    QList<double> value{ QList<double>() };
    funcFloat64Async(paramFloat)
        .then([&](QList<double> result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QList<double>> OLinkSimpleArrayInterface::funcFloat64Async(const QList<double>& paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<QList<double>>::reject("not initialized");
    }
    return QtPromise::QPromise<QList<double>>{[&](
        const QtPromise::QPromiseResolve<QList<double>>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat64");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat}), [resolve](InvokeReplyArg arg) {                
                const QList<double>& value = arg.value.get<QList<double>>();
                resolve(value);
            });
        }
    };
}

QList<QString> OLinkSimpleArrayInterface::funcString(const QList<QString>& paramString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QList<QString>();
    }
    QList<QString> value{ QList<QString>() };
    funcStringAsync(paramString)
        .then([&](QList<QString> result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<QList<QString>> OLinkSimpleArrayInterface::funcStringAsync(const QList<QString>& paramString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<QList<QString>>::reject("not initialized");
    }
    return QtPromise::QPromise<QList<QString>>{[&](
        const QtPromise::QPromiseResolve<QList<QString>>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcString");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramString}), [resolve](InvokeReplyArg arg) {                
                const QList<QString>& value = arg.value.get<QList<QString>>();
                resolve(value);
            });
        }
    };
}


std::string OLinkSimpleArrayInterface::olinkObjectName()
{
    return "tb.simple.SimpleArrayInterface";
}

void OLinkSimpleArrayInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sigBool") {
        emit sigBool(args[0].get<QList<bool>>());   
        return;
    }
    if(signalName == "sigInt") {
        emit sigInt(args[0].get<QList<int>>());   
        return;
    }
    if(signalName == "sigInt32") {
        emit sigInt32(args[0].get<QList<qint32>>());   
        return;
    }
    if(signalName == "sigInt64") {
        emit sigInt64(args[0].get<QList<qint64>>());   
        return;
    }
    if(signalName == "sigFloat") {
        emit sigFloat(args[0].get<QList<qreal>>());   
        return;
    }
    if(signalName == "sigFloat32") {
        emit sigFloat32(args[0].get<QList<float>>());   
        return;
    }
    if(signalName == "sigFloat64") {
        emit sigFloat64(args[0].get<QList<double>>());   
        return;
    }
    if(signalName == "sigString") {
        emit sigString(args[0].get<QList<QString>>());   
        return;
    }
}

void OLinkSimpleArrayInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyState({ {propertyName, value} });
}
void OLinkSimpleArrayInterface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkSimpleArrayInterface::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}

} //namespace tb_simple
