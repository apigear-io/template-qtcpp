
#pragma once

#if defined(CUSTOM_TYPES_MQTT_LIBRARY)
#  define CUSTOM_TYPES_MQTT_LIBRARY_EXPORT Q_DECL_EXPORT
#else
#  define CUSTOM_TYPES_MQTT_LIBRARY_EXPORT Q_DECL_IMPORT
#endif