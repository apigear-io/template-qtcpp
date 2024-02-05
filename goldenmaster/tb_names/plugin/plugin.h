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

#include <QtQml>

#if defined(TB_NAMES_PLUGIN_LIBRARY)
#  define TB_NAMES_PLUGIN_EXPORT Q_DECL_EXPORT
#else
#  define TB_NAMES_PLUGIN_EXPORT Q_DECL_IMPORT
#endif


/** A QML extension plugin for tb.names */
class TB_NAMES_PLUGIN_EXPORT Plugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    /** Registers all the enums, sturcts and QML versions of implementation for interfaces in this module. */
    void registerTypes(const char *uri) override;
};
