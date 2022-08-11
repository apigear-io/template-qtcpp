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
#include "olinkinterface2.h"

#include "../api/agent.h"
#include "../api/json.adapter.h"
#include <QtCore>

using namespace ApiGear;

OLinkInterface2::OLinkInterface2(QObject *parent)
    : AbstractInterface2(parent)
    , m_prop200(0)
    , m_prop201(0)
    , m_prop202(0)
    , m_prop203(0.0)
    , m_prop204(0.0)
    , m_prop205(QString())
    , m_isReady(false)
    , m_node(nullptr)
{        
    qDebug() << Q_FUNC_INFO;
    m_node = ClientRegistry::get().addObjectSink(this);
}

OLinkInterface2::~OLinkInterface2()
{
    ClientRegistry::get().removeObjectSink(this);
}

void OLinkInterface2::applyState(const json& fields) 
{
    qDebug() << Q_FUNC_INFO;
    if(fields.contains("prop200")) {
        setProp200Local(fields["prop200"].get<int>());
    }
    if(fields.contains("prop201")) {
        setProp201Local(fields["prop201"].get<int>());
    }
    if(fields.contains("prop202")) {
        setProp202Local(fields["prop202"].get<int>());
    }
    if(fields.contains("prop203")) {
        setProp203Local(fields["prop203"].get<qreal>());
    }
    if(fields.contains("prop204")) {
        setProp204Local(fields["prop204"].get<qreal>());
    }
    if(fields.contains("prop205")) {
        setProp205Local(fields["prop205"].get<QString>());
    }
}

void OLinkInterface2::setProp200(int prop200)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface2/prop200", prop200);
}

void OLinkInterface2::setProp200Local(int prop200)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop200 != prop200) {
        m_prop200 = prop200;
        emit prop200Changed(prop200);
        Interface2Agent::trace_state(this);
    }
}

int OLinkInterface2::prop200() const
{
    return m_prop200;
}

void OLinkInterface2::setProp201(int prop201)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface2/prop201", prop201);
}

void OLinkInterface2::setProp201Local(int prop201)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop201 != prop201) {
        m_prop201 = prop201;
        emit prop201Changed(prop201);
        Interface2Agent::trace_state(this);
    }
}

int OLinkInterface2::prop201() const
{
    return m_prop201;
}

void OLinkInterface2::setProp202(int prop202)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface2/prop202", prop202);
}

void OLinkInterface2::setProp202Local(int prop202)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop202 != prop202) {
        m_prop202 = prop202;
        emit prop202Changed(prop202);
        Interface2Agent::trace_state(this);
    }
}

int OLinkInterface2::prop202() const
{
    return m_prop202;
}

void OLinkInterface2::setProp203(qreal prop203)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface2/prop203", prop203);
}

void OLinkInterface2::setProp203Local(qreal prop203)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop203 != prop203) {
        m_prop203 = prop203;
        emit prop203Changed(prop203);
        Interface2Agent::trace_state(this);
    }
}

qreal OLinkInterface2::prop203() const
{
    return m_prop203;
}

void OLinkInterface2::setProp204(qreal prop204)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface2/prop204", prop204);
}

void OLinkInterface2::setProp204Local(qreal prop204)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop204 != prop204) {
        m_prop204 = prop204;
        emit prop204Changed(prop204);
        Interface2Agent::trace_state(this);
    }
}

qreal OLinkInterface2::prop204() const
{
    return m_prop204;
}

void OLinkInterface2::setProp205(const QString& prop205)
{
    qDebug() << Q_FUNC_INFO;
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface2/prop205", prop205);
}

void OLinkInterface2::setProp205Local(const QString& prop205)
{
    qDebug() << Q_FUNC_INFO;
    if (m_prop205 != prop205) {
        m_prop205 = prop205;
        emit prop205Changed(prop205);
        Interface2Agent::trace_state(this);
    }
}

QString OLinkInterface2::prop205() const
{
    return m_prop205;
}


std::string OLinkInterface2::olinkObjectName()
{
    return "org.objectapi.testbed.Interface2";
}

void OLinkInterface2::olinkOnSignal(std::string name, json args)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
}

void OLinkInterface2::olinkOnPropertyChanged(std::string name, json value)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    std::string path = Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkInterface2::olinkOnInit(std::string name, json props, IClientNode *node)
{
    qDebug() << Q_FUNC_INFO << QString::fromStdString(name);
    m_isReady = true;
    m_node = node;
    applyState(props);
    emit isReady();
}

void OLinkInterface2::olinkOnRelease()
{
    qDebug() << Q_FUNC_INFO;
    m_isReady = false;
    m_node = nullptr;
}


