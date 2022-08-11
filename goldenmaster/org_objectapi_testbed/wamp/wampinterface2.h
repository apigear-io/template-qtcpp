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
#include <QtPromise>

#include "../api/api.h"
#include "../shared/wampclient.h"

using namespace ApiGear;

class WampInterface2 : public AbstractInterface2
{
    Q_OBJECT
public:
    explicit WampInterface2(QObject *parent = nullptr);
    virtual ~WampInterface2() override;

    void applyState(const json& fields);
    int prop200() const override;
    void setProp200(int prop200) override;
    void setProp200Local(int prop200);
    int prop201() const override;
    void setProp201(int prop201) override;
    void setProp201Local(int prop201);
    int prop202() const override;
    void setProp202(int prop202) override;
    void setProp202Local(int prop202);
    qreal prop203() const override;
    void setProp203(qreal prop203) override;
    void setProp203Local(qreal prop203);
    qreal prop204() const override;
    void setProp204(qreal prop204) override;
    void setProp204Local(qreal prop204);
    QString prop205() const override;
    void setProp205(const QString& prop205) override;
    void setProp205Local(const QString& prop205);

private:
    int m_prop200;
    int m_prop201;
    int m_prop202;
    qreal m_prop203;
    qreal m_prop204;
    QString m_prop205;
};
