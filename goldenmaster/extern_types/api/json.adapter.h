#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include "api.h"
#include "apigear/utilities/qt_native.json.adapter.h"
#include <nlohmann/json.hpp>
#include <QtCore>
namespace nlohmann {

template<>
struct EXTERN_TYPES_API_EXPORT adl_serializer<QVector3D> {
    static void to_json(nlohmann::json& j, const QVector3D& p)
	{
		// Do serialization here
		j = nlohmann::json{
			//{"member_name", p.member }, ...
		};
    }

    static void from_json(const nlohmann::json& j, QVector3D& p)
    {
	    // Do deserialization here, e.g.
	    // p.xyz = j.at("xyz").get<Int>();
	    p = QVector3D();
    }
};

} //namespace nlohmann

namespace extern_types {
} //namespace extern_types
