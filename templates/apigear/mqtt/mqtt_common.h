#pragma once

#if defined(APIGEAR_MQTT_QT)
#  define APIGEAR_MQTT_EXPORT Q_DECL_EXPORT
#else
#  define APIGEAR_MQTT_EXPORT Q_DECL_IMPORT
#endif
