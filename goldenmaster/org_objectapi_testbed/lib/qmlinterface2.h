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

#include "interface2.h"

class ORG_OBJECTAPI_TESTBED_LIB_EXPORT QmlInterface2 : public AbstractInterface2
{
    Q_OBJECT
    Q_PROPERTY(int prop200 READ prop200 NOTIFY prop200Changed)
    Q_PROPERTY(int prop201 READ prop201 NOTIFY prop201Changed)
    Q_PROPERTY(int prop202 READ prop202 NOTIFY prop202Changed)
    Q_PROPERTY(qreal prop203 READ prop203 NOTIFY prop203Changed)
    Q_PROPERTY(qreal prop204 READ prop204 NOTIFY prop204Changed)
    Q_PROPERTY(QString prop205 READ prop205 NOTIFY prop205Changed)
public:
    explicit QmlInterface2(QObject *parent = nullptr);
    virtual ~QmlInterface2() override;
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

Q_SIGNALS:
    void prop200Changed(int prop200);
    void prop201Changed(int prop201);
    void prop202Changed(int prop202);
    void prop203Changed(qreal prop203);
    void prop204Changed(qreal prop204);
    void prop205Changed(const QString& prop205);
private:
	AbstractInterface2 *m_obj;
};
