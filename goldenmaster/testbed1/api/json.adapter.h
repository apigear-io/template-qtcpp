#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include "api.h"
#include "apigear/utilities/qt_native.json.adapter.h"

#include <nlohmann/json.hpp>
#include <QtCore>


namespace testbed1 {

inline void from_json(const nlohmann::json& j, StructBool& p) {
    if(j.contains("fieldBool")) {
        p.m_fieldBool = j["fieldBool"].get<bool>();
    }
}

inline void to_json(nlohmann::json& j, const StructBool& p) {
    j = nlohmann::json{
        {"fieldBool", p.m_fieldBool }
        };
}

inline void from_json(const nlohmann::json& j, StructInt& p) {
    if(j.contains("fieldInt")) {
        p.m_fieldInt = j["fieldInt"].get<int>();
    }
}

inline void to_json(nlohmann::json& j, const StructInt& p) {
    j = nlohmann::json{
        {"fieldInt", p.m_fieldInt }
        };
}

inline void from_json(const nlohmann::json& j, StructFloat& p) {
    if(j.contains("fieldFloat")) {
        p.m_fieldFloat = j["fieldFloat"].get<qreal>();
    }
}

inline void to_json(nlohmann::json& j, const StructFloat& p) {
    j = nlohmann::json{
        {"fieldFloat", p.m_fieldFloat }
        };
}

inline void from_json(const nlohmann::json& j, StructString& p) {
    if(j.contains("fieldString")) {
        p.m_fieldString = j["fieldString"].get<QString>();
    }
}

inline void to_json(nlohmann::json& j, const StructString& p) {
    j = nlohmann::json{
        {"fieldString", p.m_fieldString }
        };
}
} //namespace testbed1
