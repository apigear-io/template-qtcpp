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

#include "../api/api.h"

#if defined(TB_SIMPLE_LIB_LIBRARY)
#  define TB_SIMPLE_LIB_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_LIB_EXPORT Q_DECL_IMPORT
#endif

class TB_SIMPLE_LIB_EXPORT SimpleArrayInterface : public AbstractSimpleArrayInterface
{
    Q_OBJECT
public:
    explicit SimpleArrayInterface(QObject *parent = nullptr);
    virtual ~SimpleArrayInterface() override;
    QList<bool> propBool() const override;
    void setPropBool(const QList<bool>& propBool) override;
    QList<int> propInt() const override;
    void setPropInt(const QList<int>& propInt) override;
    QList<qreal> propFloat() const override;
    void setPropFloat(const QList<qreal>& propFloat) override;
    QList<QString> propString() const override;
    void setPropString(const QList<QString>& propString) override;
    QList<bool> funcBool(const QList<bool>& paramBool) override;
    QList<int> funcInt(const QList<int>& paramInt) override;
    QList<qreal> funcFloat(const QList<qreal>& paramFloat) override;
    QList<QString> funcString(const QList<QString>& paramString) override;

private:
    QList<bool> m_propBool;
    QList<int> m_propInt;
    QList<qreal> m_propFloat;
    QList<QString> m_propString;
};
