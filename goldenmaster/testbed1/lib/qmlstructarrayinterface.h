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

#include "structarrayinterface.h"

namespace testbed1 {

class TESTBED1_LIB_EXPORT QmlStructArrayInterface : public AbstractStructArrayInterface
{
    Q_OBJECT
    Q_PROPERTY(QList<StructBool> propBool READ propBool NOTIFY propBoolChanged)
    Q_PROPERTY(QList<StructInt> propInt READ propInt NOTIFY propIntChanged)
    Q_PROPERTY(QList<StructFloat> propFloat READ propFloat NOTIFY propFloatChanged)
    Q_PROPERTY(QList<StructString> propString READ propString NOTIFY propStringChanged)
public:
    explicit QmlStructArrayInterface(QObject *parent = nullptr);
    virtual ~QmlStructArrayInterface() override;
    QList<StructBool> propBool() const override;
    void setPropBool(const QList<StructBool>& propBool) override;
    QList<StructInt> propInt() const override;
    void setPropInt(const QList<StructInt>& propInt) override;
    QList<StructFloat> propFloat() const override;
    void setPropFloat(const QList<StructFloat>& propFloat) override;
    QList<StructString> propString() const override;
    void setPropString(const QList<StructString>& propString) override;
    Q_INVOKABLE StructBool funcBool(const QList<StructBool>& paramBool) override;
    Q_INVOKABLE StructBool funcInt(const QList<StructInt>& paramInt) override;
    Q_INVOKABLE StructBool funcFloat(const QList<StructFloat>& paramFloat) override;
    Q_INVOKABLE StructBool funcString(const QList<StructString>& paramString) override;

Q_SIGNALS:
    void sigBool(const QList<StructBool>& paramBool);
    void sigInt(const QList<StructInt>& paramInt);
    void sigFloat(const QList<StructFloat>& paramFloat);
    void sigString(const QList<StructString>& paramString);
    void propBoolChanged(const QList<StructBool>& propBool);
    void propIntChanged(const QList<StructInt>& propInt);
    void propFloatChanged(const QList<StructFloat>& propFloat);
    void propStringChanged(const QList<StructString>& propString);
private:
	AbstractStructArrayInterface *m_obj;
};

} //namespace testbed1
