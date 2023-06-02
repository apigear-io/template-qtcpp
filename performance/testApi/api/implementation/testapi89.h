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

#include "api/api/api.h"

#if defined(API_IMPL_LIBRARY)
#  define API_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define API_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace api {

/**
* The TestApi89 implementation.
*/
class API_IMPL_EXPORT TestApi89 : public AbstractTestApi89
{
    Q_OBJECT
public:
    explicit TestApi89(QObject *parent = nullptr);
    virtual ~TestApi89() override;


    /** @return value of the property propInt */
    int propInt() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propInt 
    */
    void setPropInt(int propInt) override;
    /** @return value of the property propFloat */
    qreal propFloat() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propFloat 
    */
    void setPropFloat(qreal propFloat) override;
    /** @return value of the property propString */
    QString propString() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propString 
    */
    void setPropString(const QString& propString) override;
    int funcInt(int paramInt) override;
    qreal funcFloat(qreal paramFloat) override;
    QString funcString(const QString& paramString) override;

private:
    /** propInt property */
    int m_propInt;
    /** propFloat property */
    qreal m_propFloat;
    /** propString property */
    QString m_propString;
};
} //namespace api
