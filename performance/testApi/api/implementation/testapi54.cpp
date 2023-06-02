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


#include "testapi54.h"

#include <QtQml>

namespace api {

TestApi54::TestApi54(QObject *parent)
    : AbstractTestApi54(parent)
    , m_propInt(0)
    , m_propFloat(0.0f)
    , m_propString(QString())
{
}

TestApi54::~TestApi54()
{
}

void TestApi54::setPropInt(int propInt)
{
    if (m_propInt != propInt) {
        m_propInt = propInt;
        emit propIntChanged(propInt);
    }
}

int TestApi54::propInt() const
{
    return m_propInt;
}

void TestApi54::setPropFloat(qreal propFloat)
{
    if (m_propFloat != propFloat) {
        m_propFloat = propFloat;
        emit propFloatChanged(propFloat);
    }
}

qreal TestApi54::propFloat() const
{
    return m_propFloat;
}

void TestApi54::setPropString(const QString& propString)
{
    if (m_propString != propString) {
        m_propString = propString;
        emit propStringChanged(propString);
    }
}

QString TestApi54::propString() const
{
    return m_propString;
}

int TestApi54::funcInt(int paramInt)
{
    qDebug() << Q_FUNC_INFO;
    return 0;
}

qreal TestApi54::funcFloat(qreal paramFloat)
{
    qDebug() << Q_FUNC_INFO;
    return 0.0f;
}

QString TestApi54::funcString(const QString& paramString)
{
    qDebug() << Q_FUNC_INFO;
    return QString();
}
} //namespace api
