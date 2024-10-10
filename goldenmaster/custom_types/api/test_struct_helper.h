#pragma once

#include "api.h"

#include <QDataStream>
#include <QtCore/QtGlobal>
#include <QtCore>

#if defined(CUSTOM_TYPES_API_LIBRARY)
#  define CUSTOM_TYPES_API_EXPORT Q_DECL_EXPORT
#else
#  define CUSTOM_TYPES_API_EXPORT Q_DECL_IMPORT
#endif

namespace custom_types {

CUSTOM_TYPES_API_EXPORT void fillTestVector3D(Vector3D& test_vector3_d);

}
