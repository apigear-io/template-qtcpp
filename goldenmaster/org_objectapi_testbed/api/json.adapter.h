#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include <nlohmann/json.hpp>
#include <QtCore>

inline void from_json(const nlohmann::json& j, QString& p) {
    p = QString::fromStdString(j.get<std::string>());
}

inline void to_json(nlohmann::json& j, const QString& value) {
    j = value.toStdString();
}

inline void from_json(const nlohmann::json& j, Struct1& p) {
    if(j.contains("field1")) {
        p.setField1(j["field1"].get<bool>());
    }
    if(j.contains("field2")) {
        p.setField2(j["field2"].get<int>());
    }
    if(j.contains("field3")) {
        p.setField3(j["field3"].get<qreal>());
    }
    if(j.contains("field4")) {
        p.setField4(j["field4"].get<QString>());
    }
}

inline void to_json(nlohmann::json& j, const Struct1& p) {
    j = nlohmann::json{
        {"field1", p.field1()},
        {"field2", p.field2()},
        {"field3", p.field3()},
        {"field4", p.field4()}
        };
}
