#pragma once

#include "api.h"

#include <QDataStream>
#include <QVector3D>
#include <QtCore/QtGlobal>
#include <QtCore>

#if defined(EXTERN_TYPES_API_LIBRARY)
#  define EXTERN_TYPES_API_EXPORT Q_DECL_EXPORT
#else
#  define EXTERN_TYPES_API_EXPORT Q_DECL_IMPORT
#endif

namespace extern_types {

}
