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
#include <QtNetwork>

#include "testbed2/api/api.h"

namespace testbed2 {

class HttpManyParamInterface : public AbstractManyParamInterface
{
    Q_OBJECT
public:
    explicit HttpManyParamInterface(QNetworkAccessManager *network, QObject *parent = nullptr);
    virtual ~HttpManyParamInterface() override;
    int prop1() const override;
    void setProp1(int prop1) override;
    int prop2() const override;
    void setProp2(int prop2) override;
    int prop3() const override;
    void setProp3(int prop3) override;
    int prop4() const override;
    void setProp4(int prop4) override;
    int func1(int param1) override;
    int func2(int param1, int param2) override;
    int func3(int param1, int param2, int param3) override;
    int func4(int param1, int param2, int param3, int param4) override;
private:
    QJsonObject post(const QString& path, const QJsonObject &payload);
    void applyState(const QJsonObject &state);
private:
    QNetworkAccessManager *m_network;
    int m_prop1;
    int m_prop2;
    int m_prop3;
    int m_prop4;
};

} // namespace testbed2 