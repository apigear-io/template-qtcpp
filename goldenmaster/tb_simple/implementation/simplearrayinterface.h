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

#if defined(TB_SIMPLE_IMPL_LIBRARY)
#  define TB_SIMPLE_IMPL_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_IMPL_EXPORT Q_DECL_IMPORT
#endif

namespace tb_simple {

/**
* The SimpleArrayInterface implementation.
*/
class TB_SIMPLE_IMPL_EXPORT SimpleArrayInterface : public AbstractSimpleArrayInterface
{
    Q_OBJECT
public:
    explicit SimpleArrayInterface(QObject *parent = nullptr);
    virtual ~SimpleArrayInterface() override;


    /** @return value of the property propBool */
    QList<bool> propBool() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propBool 
    */
    void setPropBool(const QList<bool>& propBool) override;
    /** @return value of the property propInt */
    QList<int> propInt() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propInt 
    */
    void setPropInt(const QList<int>& propInt) override;
    /** @return value of the property propInt32 */
    QList<qint32> propInt32() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propInt32 
    */
    void setPropInt32(const QList<qint32>& propInt32) override;
    /** @return value of the property propInt64 */
    QList<qint64> propInt64() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propInt64 
    */
    void setPropInt64(const QList<qint64>& propInt64) override;
    /** @return value of the property propFloat */
    QList<qreal> propFloat() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propFloat 
    */
    void setPropFloat(const QList<qreal>& propFloat) override;
    /** @return value of the property propFloat32 */
    QList<float> propFloat32() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propFloat32 
    */
    void setPropFloat32(const QList<float>& propFloat32) override;
    /** @return value of the property propFloat64 */
    QList<double> propFloat64() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propFloat64 
    */
    void setPropFloat64(const QList<double>& propFloat64) override;
    /** @return value of the property propString */
    QList<QString> propString() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propString 
    */
    void setPropString(const QList<QString>& propString) override;
    /** @return value of the property propReadOnlyString */
    QString propReadOnlyString() const override;
    /** Use to change a property value.
    * if the property is changed, a signal {.Name}}Changed is emitted.
    * @param value to set for the property propReadOnlyString 
    */
    void setPropReadOnlyString(const QString& propReadOnlyString) override;
    QList<bool> funcBool(const QList<bool>& paramBool) override;
    QList<int> funcInt(const QList<int>& paramInt) override;
    QList<qint32> funcInt32(const QList<qint32>& paramInt32) override;
    QList<qint64> funcInt64(const QList<qint64>& paramInt64) override;
    QList<qreal> funcFloat(const QList<qreal>& paramFloat) override;
    QList<float> funcFloat32(const QList<float>& paramFloat32) override;
    QList<double> funcFloat64(const QList<double>& paramFloat) override;
    QList<QString> funcString(const QList<QString>& paramString) override;

private:
    /** propBool property */
    QList<bool> m_propBool;
    /** propInt property */
    QList<int> m_propInt;
    /** propInt32 property */
    QList<qint32> m_propInt32;
    /** propInt64 property */
    QList<qint64> m_propInt64;
    /** propFloat property */
    QList<qreal> m_propFloat;
    /** propFloat32 property */
    QList<float> m_propFloat32;
    /** propFloat64 property */
    QList<double> m_propFloat64;
    /** propString property */
    QList<QString> m_propString;
    /** propReadOnlyString property */
    QString m_propReadOnlyString;
};
} //namespace tb_simple
