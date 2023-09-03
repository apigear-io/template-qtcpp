
#pragma once

#if defined(TB_SAME2_MQTT_LIBRARY)
#  define TB_SAME2_MQTT_LIBRARY_EXPORT Q_DECL_EXPORT
#else
#  define TB_SAME2_MQTT_LIBRARY_EXPORT Q_DECL_IMPORT
#endif
