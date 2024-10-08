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
#include <QtTest/QtTest>

class TestTbSimpleSimpleInterface: public QObject
{
    Q_OBJECT
    // setup your test
    void initTestCase();
    void initTestCase_data();
    void cleanupTestCase();
    void init();
    void cleanup();

private slots:
    void funcNoReturnValue();
    void funcBool();
    void funcInt();
    void funcInt32();
    void funcInt64();
    void funcFloat();
    void funcFloat32();
    void funcFloat64();
    void funcString();
    void propBool();
    void propInt();
    void propInt32();
    void propInt64();
    void propFloat();
    void propFloat32();
    void propFloat64();
    void propString();
};
