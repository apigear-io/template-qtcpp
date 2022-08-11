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

#if defined(ORG_OBJECTAPI_TESTBED_LIB_LIBRARY)
#  define ORG_OBJECTAPI_TESTBED_LIB_EXPORT Q_DECL_EXPORT
#else
#  define ORG_OBJECTAPI_TESTBED_LIB_EXPORT Q_DECL_IMPORT
#endif

class ORG_OBJECTAPI_TESTBED_LIB_EXPORT Interface2 : public AbstractInterface2
{
    Q_OBJECT
public:
    explicit Interface2(QObject *parent = nullptr);
    virtual ~Interface2() override;
    int prop200() const override;
    void setProp200(int prop200) override;
    int prop201() const override;
    void setProp201(int prop201) override;
    int prop202() const override;
    void setProp202(int prop202) override;
    qreal prop203() const override;
    void setProp203(qreal prop203) override;
    qreal prop204() const override;
    void setProp204(qreal prop204) override;
    QString prop205() const override;
    void setProp205(const QString& prop205) override;

private:
    int m_prop200;
    int m_prop201;
    int m_prop202;
    qreal m_prop203;
    qreal m_prop204;
    QString m_prop205;
};
