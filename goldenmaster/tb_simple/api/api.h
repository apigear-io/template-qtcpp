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
#include <QtCore/QtGlobal>

#if defined(TB_SIMPLE_LIBRARY)
#  define TB_SIMPLE_EXPORT Q_DECL_EXPORT
#else
#  define TB_SIMPLE_EXPORT Q_DECL_IMPORT
#endif

// ********************************************************************
// AbstractSimpleInterface pure interface
// ********************************************************************


class TB_SIMPLE_EXPORT AbstractSimpleInterface : public QObject {
    Q_OBJECT
public:
    AbstractSimpleInterface(QObject * parent=nullptr);
    virtual void setPropBool(bool propBool) = 0;
    virtual bool propBool() const = 0;
    virtual void setPropInt(int propInt) = 0;
    virtual int propInt() const = 0;
    virtual void setPropFloat(qreal propFloat) = 0;
    virtual qreal propFloat() const = 0;
    virtual void setPropString(const QString& propString) = 0;
    virtual QString propString() const = 0;
    virtual bool funcBool(bool paramBool) = 0;
    virtual int funcInt(int paramInt) = 0;
    virtual qreal funcFloat(qreal paramFloat) = 0;
    virtual QString funcString(const QString& paramString) = 0;
signals:
    void sigBool(bool paramBool);
    void sigInt(int paramInt);
    void sigFloat(qreal paramFloat);
    void sigString(const QString& paramString);
    void propBoolChanged(bool propBool);
    void propIntChanged(int propInt);
    void propFloatChanged(qreal propFloat);
    void propStringChanged(const QString& propString);
};

// ********************************************************************
// AbstractSimpleArrayInterface pure interface
// ********************************************************************


class TB_SIMPLE_EXPORT AbstractSimpleArrayInterface : public QObject {
    Q_OBJECT
public:
    AbstractSimpleArrayInterface(QObject * parent=nullptr);
    virtual void setPropBool(const QList<bool>& propBool) = 0;
    virtual QList<bool> propBool() const = 0;
    virtual void setPropInt(const QList<int>& propInt) = 0;
    virtual QList<int> propInt() const = 0;
    virtual void setPropFloat(const QList<qreal>& propFloat) = 0;
    virtual QList<qreal> propFloat() const = 0;
    virtual void setPropString(const QList<QString>& propString) = 0;
    virtual QList<QString> propString() const = 0;
    virtual QList<bool> funcBool(const QList<bool>& paramBool) = 0;
    virtual QList<int> funcInt(const QList<int>& paramInt) = 0;
    virtual QList<qreal> funcFloat(const QList<qreal>& paramFloat) = 0;
    virtual QList<QString> funcString(const QList<QString>& paramString) = 0;
signals:
    void sigBool(const QList<bool>& paramBool);
    void sigInt(const QList<int>& paramInt);
    void sigFloat(const QList<qreal>& paramFloat);
    void sigString(const QList<QString>& paramString);
    void propBoolChanged(const QList<bool>& propBool);
    void propIntChanged(const QList<int>& propInt);
    void propFloatChanged(const QList<qreal>& propFloat);
    void propStringChanged(const QList<QString>& propString);
};


// ********************************************************************
// Interface Factory
// ********************************************************************

class TB_SIMPLE_EXPORT ApiFactoryInterface
{
public:
    virtual AbstractSimpleInterface* createSimpleInterface(QObject *parent) = 0;
    virtual AbstractSimpleArrayInterface* createSimpleArrayInterface(QObject *parent) = 0;
};

