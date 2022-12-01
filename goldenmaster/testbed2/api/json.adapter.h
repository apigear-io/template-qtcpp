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

namespace testbed2 {

inline void from_json(const nlohmann::json& j, Struct1& p) {
    if(j.contains("field1")) {
        p.setField1(j["field1"].get<int>());
    }
}

inline void to_json(nlohmann::json& j, const Struct1& p) {
    j = nlohmann::json{
        {"field1", p.field1()}
        };
}

inline void from_json(const nlohmann::json& j, Struct2& p) {
    if(j.contains("field1")) {
        p.setField1(j["field1"].get<int>());
    }
    if(j.contains("field2")) {
        p.setField2(j["field2"].get<int>());
    }
}

inline void to_json(nlohmann::json& j, const Struct2& p) {
    j = nlohmann::json{
        {"field1", p.field1()},
        {"field2", p.field2()}
        };
}

inline void from_json(const nlohmann::json& j, Struct3& p) {
    if(j.contains("field1")) {
        p.setField1(j["field1"].get<int>());
    }
    if(j.contains("field2")) {
        p.setField2(j["field2"].get<int>());
    }
    if(j.contains("field3")) {
        p.setField3(j["field3"].get<int>());
    }
}

inline void to_json(nlohmann::json& j, const Struct3& p) {
    j = nlohmann::json{
        {"field1", p.field1()},
        {"field2", p.field2()},
        {"field3", p.field3()}
        };
}

inline void from_json(const nlohmann::json& j, Struct4& p) {
    if(j.contains("field1")) {
        p.setField1(j["field1"].get<int>());
    }
    if(j.contains("field2")) {
        p.setField2(j["field2"].get<int>());
    }
    if(j.contains("field3")) {
        p.setField3(j["field3"].get<int>());
    }
    if(j.contains("field4")) {
        p.setField4(j["field4"].get<int>());
    }
}

inline void to_json(nlohmann::json& j, const Struct4& p) {
    j = nlohmann::json{
        {"field1", p.field1()},
        {"field2", p.field2()},
        {"field3", p.field3()},
        {"field4", p.field4()}
        };
}

inline void from_json(const nlohmann::json& j, NestedStruct1& p) {
    if(j.contains("field1")) {
        p.setField1(j["field1"].get<Struct1>());
    }
}

inline void to_json(nlohmann::json& j, const NestedStruct1& p) {
    j = nlohmann::json{
        {"field1", p.field1()}
        };
}

inline void from_json(const nlohmann::json& j, NestedStruct2& p) {
    if(j.contains("field1")) {
        p.setField1(j["field1"].get<Struct1>());
    }
    if(j.contains("field2")) {
        p.setField2(j["field2"].get<Struct2>());
    }
}

inline void to_json(nlohmann::json& j, const NestedStruct2& p) {
    j = nlohmann::json{
        {"field1", p.field1()},
        {"field2", p.field2()}
        };
}

inline void from_json(const nlohmann::json& j, NestedStruct3& p) {
    if(j.contains("field1")) {
        p.setField1(j["field1"].get<Struct1>());
    }
    if(j.contains("field2")) {
        p.setField2(j["field2"].get<Struct2>());
    }
    if(j.contains("field3")) {
        p.setField3(j["field3"].get<Struct3>());
    }
}

inline void to_json(nlohmann::json& j, const NestedStruct3& p) {
    j = nlohmann::json{
        {"field1", p.field1()},
        {"field2", p.field2()},
        {"field3", p.field3()}
        };
}
} //namespace testbed2
