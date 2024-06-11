#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include "api.h"
#include "apigear/utilities/qt_native.json.adapter.h"

#include <nlohmann/json.hpp>
#include <QtCore>


namespace custom_types {

inline void from_json(const nlohmann::json& j, Vector3D& p) {
    if(j.contains("x")) {
        p.m_x = j["x"].get<qreal>();
    }
    if(j.contains("y")) {
        p.m_y = j["y"].get<qreal>();
    }
    if(j.contains("z")) {
        p.m_z = j["z"].get<qreal>();
    }
}

inline void to_json(nlohmann::json& j, const Vector3D& p) {
    j = nlohmann::json{
        {"x", p.m_x },
        {"y", p.m_y },
        {"z", p.m_z }
        };
}
} //namespace custom_types
