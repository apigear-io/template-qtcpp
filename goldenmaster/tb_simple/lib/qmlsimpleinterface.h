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

#include "simpleinterface.h"

namespace tb_simple {

/**
* A QML wrapper of the SimpleInterface implementation.
* Uses a SimpleInterface provided by an ApiFactory.
* See ApiFactory and factories that implement the ApiFactoryInterface.
*/
class TB_SIMPLE_LIB_EXPORT QmlSimpleInterface : public AbstractSimpleInterface
{
    Q_OBJECT
    Q_PROPERTY(bool propBool READ propBool NOTIFY propBoolChanged)
    Q_PROPERTY(int propInt READ propInt NOTIFY propIntChanged)
    Q_PROPERTY(qreal propFloat READ propFloat NOTIFY propFloatChanged)
    Q_PROPERTY(QString propString READ propString NOTIFY propStringChanged)
public:
    explicit QmlSimpleInterface(QObject *parent = nullptr);
    ~QmlSimpleInterface() override;
    bool propBool() const override;
    void setPropBool(bool propBool) override;
    int propInt() const override;
    void setPropInt(int propInt) override;
    qreal propFloat() const override;
    void setPropFloat(qreal propFloat) override;
    QString propString() const override;
    void setPropString(const QString& propString) override;
    Q_INVOKABLE bool funcBool(bool paramBool) override;
    Q_INVOKABLE int funcInt(int paramInt) override;
    Q_INVOKABLE qreal funcFloat(qreal paramFloat) override;
    Q_INVOKABLE QString funcString(const QString& paramString) override;

Q_SIGNALS:
    void sigBool(bool paramBool);
    void sigInt(int paramInt);
    void sigFloat(qreal paramFloat);
    void sigString(const QString& paramString);
    void propBoolChanged(bool propBool);
    void propIntChanged(int propInt);
    void propFloatChanged(qreal propFloat);
    void propStringChanged(const QString& propString);
private:
	AbstractSimpleInterface *m_obj;
};

} //namespace tb_simple
