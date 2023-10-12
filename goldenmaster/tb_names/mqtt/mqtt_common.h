
#pragma once

#if defined(TB_NAMES_MQTT_LIBRARY)
#  define TB_NAMES_MQTT_LIBRARY_EXPORT Q_DECL_EXPORT
#else
#  define TB_NAMES_MQTT_LIBRARY_EXPORT Q_DECL_IMPORT
#endif
