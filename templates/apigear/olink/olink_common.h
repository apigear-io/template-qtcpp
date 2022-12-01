#pragma once

#if defined(OLINK_QT)
#  define OLINKQT_EXPORT Q_DECL_EXPORT
#else
#  define OLINKQT_EXPORT Q_DECL_IMPORT
#endif