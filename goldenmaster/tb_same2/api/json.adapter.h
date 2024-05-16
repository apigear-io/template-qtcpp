#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include "api.h"
#include "apigear/utilities/qt_native.json.adapter.h"
#include <nlohmann/json.hpp>
#include <QtCore>

namespace tb_same2 {

inline void from_json(const nlohmann::json& j, Struct1& p) {
    if(j.contains("field1")) {
        p.m_field1 = j["field1"].get<int>();
    }
    if(j.contains("field2")) {
        p.m_field2 = j["field2"].get<int>();
    }
    if(j.contains("field3")) {
        p.m_field3 = j["field3"].get<int>();
    }
}

inline void to_json(nlohmann::json& j, const Struct1& p) {
    j = nlohmann::json{
        {"field1", p.m_field1 },
        {"field2", p.m_field2 },
        {"field3", p.m_field3 }
        };
}

inline void from_json(const nlohmann::json& j, Struct2& p) {
    if(j.contains("field1")) {
        p.m_field1 = j["field1"].get<int>();
    }
    if(j.contains("field2")) {
        p.m_field2 = j["field2"].get<int>();
    }
    if(j.contains("field3")) {
        p.m_field3 = j["field3"].get<int>();
    }
}

inline void to_json(nlohmann::json& j, const Struct2& p) {
    j = nlohmann::json{
        {"field1", p.m_field1 },
        {"field2", p.m_field2 },
        {"field3", p.m_field3 }
        };
}
} //namespace tb_same2
