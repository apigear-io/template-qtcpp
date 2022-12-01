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

namespace testbed1 {

inline void from_json(const nlohmann::json& j, StructBool& p) {
    if(j.contains("fieldBool")) {
        p.setFieldBool(j["fieldBool"].get<bool>());
    }
}

inline void to_json(nlohmann::json& j, const StructBool& p) {
    j = nlohmann::json{
        {"fieldBool", p.fieldBool()}
        };
}

inline void from_json(const nlohmann::json& j, StructInt& p) {
    if(j.contains("fieldInt")) {
        p.setFieldInt(j["fieldInt"].get<int>());
    }
}

inline void to_json(nlohmann::json& j, const StructInt& p) {
    j = nlohmann::json{
        {"fieldInt", p.fieldInt()}
        };
}

inline void from_json(const nlohmann::json& j, StructFloat& p) {
    if(j.contains("fieldFloat")) {
        p.setFieldFloat(j["fieldFloat"].get<qreal>());
    }
}

inline void to_json(nlohmann::json& j, const StructFloat& p) {
    j = nlohmann::json{
        {"fieldFloat", p.fieldFloat()}
        };
}

inline void from_json(const nlohmann::json& j, StructString& p) {
    if(j.contains("fieldString")) {
        p.setFieldString(j["fieldString"].get<QString>());
    }
}

inline void to_json(nlohmann::json& j, const StructString& p) {
    j = nlohmann::json{
        {"fieldString", p.fieldString()}
        };
}
} //namespace testbed1
