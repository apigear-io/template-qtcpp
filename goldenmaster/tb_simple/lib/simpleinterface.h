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

#include "tb_simple/api/api.h"

#if defined(TB_SIMPLE_LIB_LIBRARY)
#  define TB_SIMPLE_LIB_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_LIB_EXPORT Q_DECL_IMPORT
#endif

namespace tb_simple {

class TB_SIMPLE_LIB_EXPORT SimpleInterface : public AbstractSimpleInterface
{
    Q_OBJECT
public:
    explicit SimpleInterface(QObject *parent = nullptr);
    virtual ~SimpleInterface() override;
    bool propBool() const override;
    void setPropBool(bool propBool) override;
    int propInt() const override;
    void setPropInt(int propInt) override;
    qreal propFloat() const override;
    void setPropFloat(qreal propFloat) override;
    QString propString() const override;
    void setPropString(const QString& propString) override;
    bool funcBool(bool paramBool) override;
    int funcInt(int paramInt) override;
    qreal funcFloat(qreal paramFloat) override;
    QString funcString(const QString& paramString) override;

private:
    bool m_propBool;
    int m_propInt;
    qreal m_propFloat;
    QString m_propString;
};
} //namespace tb_simple
