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
#include "olinksimpleinterface.h"

#include "tb_simple/api/json.adapter.h"

#include "olink/iclientnode.h"

#include <QtCore>

using namespace ApiGear;
using namespace ApiGear::ObjectLink;

namespace tb_simple {

OLinkSimpleInterface::OLinkSimpleInterface(QObject *parent)
    : AbstractSimpleInterface(parent)
    , m_propBool(false)
    , m_propInt(0)
    , m_propInt32(0)
    , m_propInt64(0LL)
    , m_propFloat(0.0f)
    , m_propFloat32(0.0f)
    , m_propFloat64(0.0)
    , m_propString(QString())
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
}

void OLinkSimpleInterface::applyState(const nlohmann::json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<bool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<int>());
    }
    if(fields.contains("propInt32")) {
        setPropInt32Local(fields["propInt32"].get<qint32>());
    }
    if(fields.contains("propInt64")) {
        setPropInt64Local(fields["propInt64"].get<qint64>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<qreal>());
    }
    if(fields.contains("propFloat32")) {
        setPropFloat32Local(fields["propFloat32"].get<float>());
    }
    if(fields.contains("propFloat64")) {
        setPropFloat64Local(fields["propFloat64"].get<double>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<QString>());
    }
}

void OLinkSimpleInterface::setPropBool(bool propBool)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propBool", propBool);
}

void OLinkSimpleInterface::setPropBoolLocal(bool propBool)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propBool != propBool) {
        m_propBool = propBool;
        emit propBoolChanged(propBool);
    }
}

bool OLinkSimpleInterface::propBool() const
{
    return m_propBool;
}

void OLinkSimpleInterface::setPropInt(int propInt)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propInt", propInt);
}

void OLinkSimpleInterface::setPropIntLocal(int propInt)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

int OLinkSimpleInterface::propInt() const
{
    return m_propInt;
}

void OLinkSimpleInterface::setPropInt32(qint32 propInt32)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propInt32", propInt32);
}

void OLinkSimpleInterface::setPropInt32Local(qint32 propInt32)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propInt32 != propInt32) {
        m_propInt32 = propInt32;
        emit propInt32Changed(propInt32);
    }
}

qint32 OLinkSimpleInterface::propInt32() const
{
    return m_propInt32;
}

void OLinkSimpleInterface::setPropInt64(qint64 propInt64)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propInt64", propInt64);
}

void OLinkSimpleInterface::setPropInt64Local(qint64 propInt64)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propInt64 != propInt64) {
        m_propInt64 = propInt64;
        emit propInt64Changed(propInt64);
    }
}

qint64 OLinkSimpleInterface::propInt64() const
{
    return m_propInt64;
}

void OLinkSimpleInterface::setPropFloat(qreal propFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propFloat", propFloat);
}

void OLinkSimpleInterface::setPropFloatLocal(qreal propFloat)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

qreal OLinkSimpleInterface::propFloat() const
{
    return m_propFloat;
}

void OLinkSimpleInterface::setPropFloat32(float propFloat32)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propFloat32", propFloat32);
}

void OLinkSimpleInterface::setPropFloat32Local(float propFloat32)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propFloat32 != propFloat32) {
        m_propFloat32 = propFloat32;
        emit propFloat32Changed(propFloat32);
    }
}

float OLinkSimpleInterface::propFloat32() const
{
    return m_propFloat32;
}

void OLinkSimpleInterface::setPropFloat64(double propFloat64)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propFloat64", propFloat64);
}

void OLinkSimpleInterface::setPropFloat64Local(double propFloat64)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propFloat64 != propFloat64) {
        m_propFloat64 = propFloat64;
        emit propFloat64Changed(propFloat64);
    }
}

double OLinkSimpleInterface::propFloat64() const
{
    return m_propFloat64;
}

void OLinkSimpleInterface::setPropString(const QString& propString)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propString", propString);
}

void OLinkSimpleInterface::setPropStringLocal(const QString& propString)
{
    qDebug() << Q_FUNC_INFO;
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

QString OLinkSimpleInterface::propString() const
{
    return m_propString;
}

bool OLinkSimpleInterface::funcBool(bool paramBool)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return false;
    }
    bool value{ false };
    funcBoolAsync(paramBool)
        .then([&](bool result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<bool> OLinkSimpleInterface::funcBoolAsync(bool paramBool)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<bool>::reject("not initialized");
    }
    return QtPromise::QPromise<bool>{[&](
        const QtPromise::QPromiseResolve<bool>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcBool");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramBool}), [resolve](InvokeReplyArg arg) {                
                const bool& value = arg.value.get<bool>();
                resolve(value);
            });
        }
    };
}

int OLinkSimpleInterface::funcInt(int paramInt)
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

QtPromise::QPromise<int> OLinkSimpleInterface::funcIntAsync(int paramInt)
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

qint32 OLinkSimpleInterface::funcInt32(qint32 paramInt32)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return 0;
    }
    qint32 value{ 0 };
    funcInt32Async(paramInt32)
        .then([&](qint32 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<qint32> OLinkSimpleInterface::funcInt32Async(qint32 paramInt32)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<qint32>::reject("not initialized");
    }
    return QtPromise::QPromise<qint32>{[&](
        const QtPromise::QPromiseResolve<qint32>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt32");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramInt32}), [resolve](InvokeReplyArg arg) {                
                const qint32& value = arg.value.get<qint32>();
                resolve(value);
            });
        }
    };
}

qint64 OLinkSimpleInterface::funcInt64(qint64 paramInt64)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return 0LL;
    }
    qint64 value{ 0LL };
    funcInt64Async(paramInt64)
        .then([&](qint64 result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<qint64> OLinkSimpleInterface::funcInt64Async(qint64 paramInt64)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<qint64>::reject("not initialized");
    }
    return QtPromise::QPromise<qint64>{[&](
        const QtPromise::QPromiseResolve<qint64>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcInt64");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramInt64}), [resolve](InvokeReplyArg arg) {                
                const qint64& value = arg.value.get<qint64>();
                resolve(value);
            });
        }
    };
}

qreal OLinkSimpleInterface::funcFloat(qreal paramFloat)
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

QtPromise::QPromise<qreal> OLinkSimpleInterface::funcFloatAsync(qreal paramFloat)
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

float OLinkSimpleInterface::funcFloat32(float paramFloat32)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return 0.0f;
    }
    float value{ 0.0f };
    funcFloat32Async(paramFloat32)
        .then([&](float result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<float> OLinkSimpleInterface::funcFloat32Async(float paramFloat32)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<float>::reject("not initialized");
    }
    return QtPromise::QPromise<float>{[&](
        const QtPromise::QPromiseResolve<float>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat32");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat32}), [resolve](InvokeReplyArg arg) {                
                const float& value = arg.value.get<float>();
                resolve(value);
            });
        }
    };
}

double OLinkSimpleInterface::funcFloat64(double paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return 0.0;
    }
    double value{ 0.0 };
    funcFloat64Async(paramFloat)
        .then([&](double result) {
            value = result;
        })
        .wait();
    return value;
}

QtPromise::QPromise<double> OLinkSimpleInterface::funcFloat64Async(double paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return QtPromise::QPromise<double>::reject("not initialized");
    }
    return QtPromise::QPromise<double>{[&](
        const QtPromise::QPromiseResolve<double>& resolve) {
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "funcFloat64");
            m_node->invokeRemote(operationId, nlohmann::json::array({paramFloat}), [resolve](InvokeReplyArg arg) {                
                const double& value = arg.value.get<double>();
                resolve(value);
            });
        }
    };
}

QString OLinkSimpleInterface::funcString(const QString& paramString)
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

QtPromise::QPromise<QString> OLinkSimpleInterface::funcStringAsync(const QString& paramString)
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


std::string OLinkSimpleInterface::olinkObjectName()
{
    return "tb.simple.SimpleInterface";
}

void OLinkSimpleInterface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(signalId);
    auto signalName = Name::getMemberName(signalId);
    if(signalName == "sigBool") {
        emit sigBool(args[0].get<bool>());   
        return;
    }
    if(signalName == "sigInt") {
        emit sigInt(args[0].get<int>());   
        return;
    }
    if(signalName == "sigInt32") {
        emit sigInt32(args[0].get<qint32>());   
        return;
    }
    if(signalName == "sigInt64") {
        emit sigInt64(args[0].get<qint64>());   
        return;
    }
    if(signalName == "sigFloat") {
        emit sigFloat(args[0].get<qreal>());   
        return;
    }
    if(signalName == "sigFloat32") {
        emit sigFloat32(args[0].get<float>());   
        return;
    }
    if(signalName == "sigFloat64") {
        emit sigFloat64(args[0].get<double>());   
        return;
    }
    if(signalName == "sigString") {
        emit sigString(args[0].get<QString>());   
        return;
    }
}

void OLinkSimpleInterface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(propertyId);
    std::string propertyName = Name::getMemberName(propertyId);
    applyState({ {propertyName, value} });
}
void OLinkSimpleInterface::olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(objectId);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkSimpleInterface::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}

} //namespace tb_simple
