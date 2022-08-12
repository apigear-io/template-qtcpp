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

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

OLinkSimpleInterface::OLinkSimpleInterface(QObject *parent)
    : AbstractSimpleInterface(parent)
    , m_propBool(false)
    , m_propInt(0)
    , m_propFloat(0.0)
    , m_propString(QString())
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
    m_node = ClientRegistry::get().addObjectSink(this);
}

OLinkSimpleInterface::~OLinkSimpleInterface()
{
    ClientRegistry::get().removeObjectSink(this);
}

void OLinkSimpleInterface::applyState(const json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<bool>());
    }
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
        SimpleInterfaceAgent::trace_state(this);
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
        SimpleInterfaceAgent::trace_state(this);
    }
}

int OLinkSimpleInterface::propInt() const
{
    return m_propInt;
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
        SimpleInterfaceAgent::trace_state(this);
    }
}

qreal OLinkSimpleInterface::propFloat() const
{
    return m_propFloat;
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
        SimpleInterfaceAgent::trace_state(this);
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
            m_node->invokeRemote("tb.simple.SimpleInterface/funcBool", json::array({paramBool}), [resolve](InvokeReplyArg arg) {                
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
            m_node->invokeRemote("tb.simple.SimpleInterface/funcInt", json::array({paramInt}), [resolve](InvokeReplyArg arg) {                
                const int& value = arg.value.get<int>();
                resolve(value);
            });
        }
    };
}

qreal OLinkSimpleInterface::funcFloat(qreal paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return 0.0;
    }
    qreal value{ 0.0 };
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
            m_node->invokeRemote("tb.simple.SimpleInterface/funcFloat", json::array({paramFloat}), [resolve](InvokeReplyArg arg) {                
                const qreal& value = arg.value.get<qreal>();
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
            m_node->invokeRemote("tb.simple.SimpleInterface/funcString", json::array({paramString}), [resolve](InvokeReplyArg arg) {                
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

void OLinkSimpleInterface::olinkOnSignal(std::string name, json args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "sigBool") {
        emit sigBool(args[0].get<bool>());   
        return;
    }
    if(path == "sigInt") {
        emit sigInt(args[0].get<int>());   
        return;
    }
    if(path == "sigFloat") {
        emit sigFloat(args[0].get<qreal>());   
        return;
    }
    if(path == "sigString") {
        emit sigString(args[0].get<QString>());   
        return;
    }
}

void OLinkSimpleInterface::olinkOnPropertyChanged(std::string name, json value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkSimpleInterface::olinkOnInit(std::string name, json props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
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


