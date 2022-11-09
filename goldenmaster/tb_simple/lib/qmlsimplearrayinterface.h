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

#include "simplearrayinterface.h"

class TB_SIMPLE_LIB_EXPORT QmlSimpleArrayInterface : public AbstractSimpleArrayInterface
{
    Q_OBJECT
    Q_PROPERTY(QList<bool> propBool READ propBool NOTIFY propBoolChanged)
    Q_PROPERTY(QList<int> propInt READ propInt NOTIFY propIntChanged)
    Q_PROPERTY(QList<double> propFloat READ propFloat NOTIFY propFloatChanged)
    Q_PROPERTY(QList<QString> propString READ propString NOTIFY propStringChanged)
public:
    explicit QmlSimpleArrayInterface(QObject *parent = nullptr);
    virtual ~QmlSimpleArrayInterface() override;
    QList<bool> propBool() const override;
    void setPropBool(const QList<bool>& propBool) override;
    QList<int> propInt() const override;
    void setPropInt(const QList<int>& propInt) override;
    QList<double> propFloat() const override;
    void setPropFloat(const QList<double>& propFloat) override;
    QList<QString> propString() const override;
    void setPropString(const QList<QString>& propString) override;
    Q_INVOKABLE QList<bool> funcBool(const QList<bool>& paramBool) override;
    Q_INVOKABLE QList<int> funcInt(const QList<int>& paramInt) override;
    Q_INVOKABLE QList<double> funcFloat(const QList<double>& paramFloat) override;
    Q_INVOKABLE QList<QString> funcString(const QList<QString>& paramString) override;

Q_SIGNALS:
    void sigBool(const QList<bool>& paramBool);
    void sigInt(const QList<int>& paramInt);
    void sigFloat(const QList<double>& paramFloat);
    void sigString(const QList<QString>& paramString);
    void propBoolChanged(const QList<bool>& propBool);
    void propIntChanged(const QList<int>& propInt);
    void propFloatChanged(const QList<double>& propFloat);
    void propStringChanged(const QList<QString>& propString);
private:
	AbstractSimpleArrayInterface *m_obj;
};
