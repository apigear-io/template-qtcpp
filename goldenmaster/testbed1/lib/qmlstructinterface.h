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

#include "structinterface.h"

namespace testbed1 {

/**
* A QML wrapper of the StructInterface implementation.
* Uses a StructInterface provided by an ApiFactory.
* See ApiFactory and factories that implement the ApiFactoryInterface.
*/
class TESTBED1_LIB_EXPORT QmlStructInterface : public AbstractStructInterface
{
    Q_OBJECT
    Q_PROPERTY(StructBool propBool READ propBool NOTIFY propBoolChanged)
    Q_PROPERTY(StructInt propInt READ propInt NOTIFY propIntChanged)
    Q_PROPERTY(StructFloat propFloat READ propFloat NOTIFY propFloatChanged)
    Q_PROPERTY(StructString propString READ propString NOTIFY propStringChanged)
public:
    explicit QmlStructInterface(QObject *parent = nullptr);
    ~QmlStructInterface() override;
    StructBool propBool() const override;
    void setPropBool(const StructBool& propBool) override;
    StructInt propInt() const override;
    void setPropInt(const StructInt& propInt) override;
    StructFloat propFloat() const override;
    void setPropFloat(const StructFloat& propFloat) override;
    StructString propString() const override;
    void setPropString(const StructString& propString) override;
    Q_INVOKABLE StructBool funcBool(const StructBool& paramBool) override;
    Q_INVOKABLE StructBool funcInt(const StructInt& paramInt) override;
    Q_INVOKABLE StructFloat funcFloat(const StructFloat& paramFloat) override;
    Q_INVOKABLE StructString funcString(const StructString& paramString) override;

Q_SIGNALS:
    void sigBool(const StructBool& paramBool);
    void sigInt(const StructInt& paramInt);
    void sigFloat(const StructFloat& paramFloat);
    void sigString(const StructString& paramString);
    void propBoolChanged(const StructBool& propBool);
    void propIntChanged(const StructInt& propInt);
    void propFloatChanged(const StructFloat& propFloat);
    void propStringChanged(const StructString& propString);
private:
	AbstractStructInterface *m_obj;
};

} //namespace testbed1
