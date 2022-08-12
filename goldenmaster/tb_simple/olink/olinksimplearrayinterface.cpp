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

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

OLinkSimpleArrayInterface::OLinkSimpleArrayInterface(QObject *parent)
    : AbstractSimpleArrayInterface(parent)
    , m_propBool(QList<bool>())
    , m_propInt(QList<int>())
    , m_propFloat(QList<qreal>())
    , m_propString(QList<QString>())
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
    m_node = ClientRegistry::get().addObjectSink(this);
}

OLinkSimpleArrayInterface::~OLinkSimpleArrayInterface()
{
    ClientRegistry::get().removeObjectSink(this);
}

void OLinkSimpleArrayInterface::applyState(const json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<QList<bool>>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<QList<int>>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<QList<qreal>>());
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
    QList<bool> value(QList<bool>());
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
            m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcBool", json::array({paramBool}), [resolve](InvokeReplyArg arg) {                
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
    QList<int> value(QList<int>());
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
            m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcInt", json::array({paramInt}), [resolve](InvokeReplyArg arg) {                
                const QList<int>& value = arg.value.get<QList<int>>();
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
    QList<qreal> value(QList<qreal>());
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
            m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcFloat", json::array({paramFloat}), [resolve](InvokeReplyArg arg) {                
                const QList<qreal>& value = arg.value.get<QList<qreal>>();
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
    QList<QString> value(QList<QString>());
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
            m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcString", json::array({paramString}), [resolve](InvokeReplyArg arg) {                
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

void OLinkSimpleArrayInterface::olinkOnSignal(std::string name, json args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    if(path == "sigBool") {
        emit sigBool(args[0].get<QList<bool>>());   
        return;
    }
    if(path == "sigInt") {
        emit sigInt(args[0].get<QList<int>>());   
        return;
    }
    if(path == "sigFloat") {
        emit sigFloat(args[0].get<QList<qreal>>());   
        return;
    }
    if(path == "sigString") {
        emit sigString(args[0].get<QList<QString>>());   
        return;
    }
}

void OLinkSimpleArrayInterface::olinkOnPropertyChanged(std::string name, json value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkSimpleArrayInterface::olinkOnInit(std::string name, json props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
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


