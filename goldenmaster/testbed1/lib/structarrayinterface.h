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

#include "testbed1/api/api.h"

#if defined(TESTBED1_LIB_LIBRARY)
#  define TESTBED1_LIB_EXPORT Q_DECL_EXPORT
#else
#  define TESTBED1_LIB_EXPORT Q_DECL_IMPORT
#endif

class TESTBED1_LIB_EXPORT StructArrayInterface : public AbstractStructArrayInterface
{
    Q_OBJECT
public:
    explicit StructArrayInterface(QObject *parent = nullptr);
    virtual ~StructArrayInterface() override;
    QList<StructBool> propBool() const override;
    void setPropBool(const QList<StructBool>& propBool) override;
    QList<StructInt> propInt() const override;
    void setPropInt(const QList<StructInt>& propInt) override;
    QList<StructFloat> propFloat() const override;
    void setPropFloat(const QList<StructFloat>& propFloat) override;
    QList<StructString> propString() const override;
    void setPropString(const QList<StructString>& propString) override;
    StructBool funcBool(const QList<StructBool>& paramBool) override;
    StructBool funcInt(const QList<StructInt>& paramInt) override;
    StructBool funcFloat(const QList<StructFloat>& paramFloat) override;
    StructBool funcString(const QList<StructString>& paramString) override;

private:
    QList<StructBool> m_propBool;
    QList<StructInt> m_propInt;
    QList<StructFloat> m_propFloat;
    QList<StructString> m_propString;
};
