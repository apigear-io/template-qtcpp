#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include "api.h"
#include <nlohmann/json.hpp>
#include <QtCore>

inline void from_json(const nlohmann::json& j, QString& p) {
    p = QString::fromStdString(j.get<std::string>());
}

inline void to_json(nlohmann::json& j, const QString& value) {
    j = value.toStdString();
}

namespace tb_names {
} //namespace tb_names
